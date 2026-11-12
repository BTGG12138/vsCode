//在 Google C++ 规范中，函数名首字母大写，单词之间不用下划线。比如：GetUserName(), CalculateArea()。
//注：你之前学的变量名是用小写 + 下划线（snake_case），比如 user_name，别搞混了。
#include <iostream>
#include <tuple>       // 必须包含此头文件才能使用 tuple
using namespace std;
// 1. 打包数据：返回一个包含字符串和整数的元组
auto Foo() {
    return make_tuple("Super Variable", 5);
}
int main() {
    // 2. 优雅解包：使用结构化绑定直接接收
    auto [name, value] = Foo();
    // 3. 直接使用解包后的变量
    cout << name << " has value : " << value << endl;
    return 0;
}
/*
静态局部变量（函数内）：长命。只在第一次调用时初始化，函数结束时不销毁，活到程序结束。（这也是为什么返回它的引用是安全的）
静态全局变量/函数（文件内）：私有。只能被当前 .cpp 文件访问，其他文件看不见（防止重名冲突）。
静态数据成员（类内）：共享。属于类本身，不属于具体对象，所有对象共用同一份内存。
静态成员函数（类内）：无状态。没有 this 指针，不能访问非静态成员，只能操作静态成员。

所以，现在加 inline 更多是出于工程规范：
告诉阅读代码的人：“这是一个高频且短小的函数，放心用。”
避免头文件冲突：如果你在头文件 .h 里写了一个函数，必须加 inline，否则多个 .cpp 文件引用它时，会报“重定义（multiple definition）”错误。
绝对禁止：在头文件中使用 using namespace

避免“命名空间污染”（Name Pollution）
让代码的“出处”一目了然
支持库的“模块化”演进
*/