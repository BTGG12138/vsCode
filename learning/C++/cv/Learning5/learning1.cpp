#include <iostream>
#include <any> // 必须包含这个头文件
int main() {
    std::any a; // any type (任意类型)
    a = 1; // int
    std::cout << std::any_cast<int>(a) << std::endl; // 输出 1
    a = 3.14; // double
    std::cout << std::any_cast<double>(a) << std::endl; // 输出 3.14
    a = true; // bool
    std::cout << std::boolalpha << std::any_cast<bool>(a) << std::endl; // 输出 true
}