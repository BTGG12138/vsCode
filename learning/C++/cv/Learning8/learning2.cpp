#include <iostream>

class Singleton {
private:
    Singleton() = default; // 私有构造函数
    ~Singleton() = default; // 私有析构函数
    Singleton(const Singleton&) = delete; // 禁止拷贝构造
    Singleton& operator=(const Singleton&) = delete; // 禁止拷贝赋值

    int data{0}; // 示例数据成员

public:
    // 静态方法，获取唯一实例的引用
    static Singleton& getInstance() {
        static Singleton instance; // C++11保证局部静态变量初始化是线程安全的
        return instance;
    }

    // 提供对数据的访问（示例）
    int getData() const { return data; }
    void setData(int value) { data = value; }
};

// 使用方式
int main() {
    Singleton& s1 = Singleton::getInstance();
    s1.setData(42);

    Singleton& s2 = Singleton::getInstance();
    std::cout << "s2 获取的数据: " << s2.getData() << std::endl; // 输出 42，s1和s2是同一个实例
    
    // 下面的代码如果取消注释，会导致编译报错，这就是单例的威力
    // Singleton s3; // ❌ 错误：构造函数私有
    // Singleton s4 = s1; // ❌ 错误：拷贝构造函数被删除

    return 0;
}