#include <iostream>
#include <utility>

template<typename T>
struct ControlBlockAnd {
    long shared_cnt = 1;
    T obj;

    template<typename... Args>
    ControlBlockAnd(Args&&... args)
        : obj(std::forward<Args>(args)...) {}
};

template<typename T>
struct my_shared_ptr {
    ControlBlockAnd<T>* cb_ = nullptr;

    explicit my_shared_ptr(ControlBlockAnd<T>* p) : cb_(p) {}

    my_shared_ptr(const my_shared_ptr& other) {
        cb_ = other.cb_;
        if(cb_) cb_->shared_cnt++;
    }

    ~my_shared_ptr() {
        if (cb_) {
            cb_->shared_cnt--;
            if (cb_->shared_cnt == 0) {
                cb_->obj.~T();
                delete cb_;
            }
        }
    }

    T& operator*() { return cb_->obj; }
    // 补上 -> 重载
    T* operator->() { return &cb_->obj; }
};

template<class T, class... Args>
my_shared_ptr<T> my_make_shared(Args&&... args) {
    auto* rawptr = new ControlBlockAnd<T>(std::forward<Args>(args)...);
    return my_shared_ptr<T>(rawptr);
}

struct Foo {
    int x;
    Foo(int v) : x(v) { std::cout << "Foo construct " << v << "\n"; }
    ~Foo() { std::cout << "Foo destroy " << x << "\n"; }
};

int main() {
    auto p = my_make_shared<Foo>(100);
    std::cout << p->x << "\n";
    auto p2 = p;
    std::cout << p2->x << "\n";
    return 0;
}
