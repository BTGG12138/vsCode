#include <iostream>

// 图中的 default_delete
template<class T>
struct default_delete {
    void operator()(T* p) const {
        delete p;
    }
};

// 简化版 unique_ptr，对应幻灯片代码
template<class T, class Deleter = default_delete<T>>
class my_unique_ptr {
private:
    T* p_ = nullptr;
    Deleter d_;
public:
    // 构造
    explicit my_unique_ptr(T* p = nullptr) : p_(p) {}

    // 析构：和幻灯片 ~unique_ptr 逻辑一致
    ~my_unique_ptr() {
        if (p_) {
            d_(p_);
        }
    }

    // 禁止拷贝（unique_ptr核心：独占所有权）
    my_unique_ptr(const my_unique_ptr&) = delete;
    my_unique_ptr& operator=(const my_unique_ptr&) = delete;

    // 移动构造
    my_unique_ptr(my_unique_ptr&& other) noexcept {
        p_ = other.p_;
        other.p_ = nullptr;
    }

    // 移动赋值
    my_unique_ptr& operator=(my_unique_ptr&& other) noexcept {
        if (this != &other) {
            // 先释放当前资源
            if (p_) d_(p_);
            p_ = other.p_;
            other.p_ = nullptr;
        }
        return *this;
    }

    // 重载 -> * 模仿指针
    T* operator->() const { return p_; }
    T& operator*() const { return *p_; }

    // release：交出所有权
    T* release() {
        T* tmp = p_;
        p_ = nullptr;
        return tmp;
    }
};

struct Test {
    Test() { std::cout << "Test 构造\n"; }
    ~Test() { std::cout << "Test 析构\n"; }
    void hello() { std::cout << "hello\n"; }
};

int main() {
    my_unique_ptr<Test> ptr(new Test);
    ptr->hello();

    // 移动测试
    my_unique_ptr<Test> ptr2 = std::move(ptr);
    if (!ptr.release()) {
        std::cout << "ptr 已经空了\n";
    }
    return 0;
}
