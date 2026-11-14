#include <iostream>
#include <optional>
#include <string>
// 这是一个“工厂函数”，参数 create 决定要不要生产字符串
std::optional<std::string> StringFactory(bool create) {
    if (create) {
        return "Modern C++ is Awesome"; // 盒子里装了东西
    }
    return {}; // 返回一个空盒子（代表什么都没有）
}
int main() {
    std::cout << StringFactory(true).value() << '\n';
    // 为了不报错，用 .value_or("默认值")，意思是：如果空着，就给我返回 ":(" 吧
    std::cout << StringFactory(false).value_or(":(") << '\n';
    return 0;
}
/*
// 给整数类型起个外号叫 Int
using Int = int; 
Int a = 10; // 实际上就是 int a = 10;

// 复杂一点：给一个指向函数的指针起外号
using FuncPtr = void (*)(int, int); 
*/