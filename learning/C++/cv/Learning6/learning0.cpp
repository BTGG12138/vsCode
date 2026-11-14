/*
class String {
public:
    String(const char* ch) {
        _text = new char[strlen(ch) + 1]; // 构造函数中动态分配内存
        // ... 复制内容
    }
    ~String() { // 析构函数
        delete[] _text; // 释放之前分配的内存，防止内存泄漏
    }
private:
    char* _text;
};
*/
#include <iostream>
#include <string>
using namespace std;
class Student {
public:
    Student(int id, string name) : id_{id}, name_{name} {}
    int id() const { return id_; }
    const string& name() const { return name_; }
private:
    int id_;
    string name_;
};
int main() {
    Student s(1, "Tom");
    cout << s.id() << endl;      // 1
    cout << s.name() << endl;    // Tom
    const Student cs(2, "Jerry");
    cout << cs.id() << endl;     // 2，因为 id() 是 const 成员函数
    cout << cs.name() << endl;   // Jerry
}
/*
Classes as modules
类作为模块
倾向于将属于一起的信息封装到一个类中。
将类的声明和定义分离到头文件和源文件中。
通常，类 SomeClass 在 some_class.hpp 中声明，并在 some_class.cpp 中定义。

Intuition lvalues, rvalues
左值、右值的直觉理解
每个表达式要么是左值，要么是右值。
左值可以写在赋值运算符（=）的左边。
右值是所有其他表达式。
显式右值使用 && 定义。
使用 std::move(…) 将左值显式转换为右值。

std::move
std::move 用于表示对象 t 可能被“移动走”，即允许将资源从 t 高效地转移到另一个对象。
特别地，std::move 产生一个 xvalue 表达式，该表达式标识其参数 t。它完全等价于向一种右值引用类型进行 static_cast。
*/