#include <iostream>
#include <stdexcept> // 包含标准异常
#include <string>
void doDangerousWork(bool fail) {
    if (fail) {
        // 第1、5点：抛出异常，并带上错误信息字符串
        throw std::runtime_error("哎呀，出大问题了！"); 
    }
    std::cout << "工作顺利完成。\n";
}
int main() {
    try {
        // 第4点：try 块包裹可能出错的代码
        doDangerousWork(true); 
    } 
    catch (const std::exception& e) { 
        // 第2点：捕获继承自 std::exception 的异常
        // 第6点：用 what() 打印出错误信息
        std::cout << "捕获到异常: " << e.what() << '\n'; 
    }
    return 0;
}