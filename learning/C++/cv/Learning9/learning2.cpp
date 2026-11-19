#include <iostream>

// 场景4：全局变量
int value = 1000;

// 场景2、3：普通类，演示静态成员 + 类外定义成员函数
class Widget {
public:
    static int static_num;
    void sayHello(); // 声明，类外实现
};
// 场景3：类外定义成员函数 Widget::
void Widget::sayHello() {
    std::cout << "Widget::sayHello\n";
}
// 场景2：静态变量类外初始化 Widget::
int Widget::static_num = 666;

// 场景5：CRTP 模板基类，两阶段查找需要 Base<Derived>::xxx
template<typename Derived>
struct BaseCRTP {
    void baseFunc() {
        std::cout << "BaseCRTP::baseFunc\n";
    }
};
struct Child : BaseCRTP<Child> {
    void test() {
        // 模板继承，必须显式写 BaseCRTP<Child>::，否则查找失败
        BaseCRTP<Child>::baseFunc();
    }
};


int main() {
    // 场景1：命名空间::  std::
    std::cout << "===== 命名空间 std:: =====\n";

    // 场景4：::value 代表全局作用域的value，避开局部遮蔽
    int value = 99;
    std::cout << "局部value = " << value << "\n";
    std::cout << "全局::value = " << ::value << "\n\n";

    // 场景2：类静态成员 Widget::
    std::cout << "===== 静态成员 Widget:: =====\n";
    std::cout << "Widget::static_num = " << Widget::static_num << "\n";
    Widget::static_num += 100;
    std::cout << "Widget::static_num after +=100 = " << Widget::static_num << "\n\n";

    // 场景3：调用类外实现的成员函数 Widget::sayHello
    std::cout << "===== 类外定义函数 Widget::sayHello =====\n";
    Widget w;
    w.sayHello();
    std::cout << "\n";

    // 场景5：CRTP模板继承，BaseCRTP<Child>::baseFunc
    std::cout << "===== CRTP Base<Derived>::func =====\n";
    Child c;
    c.test();

    return 0;
}
