#include <iostream>
int main()
{
    bool a = true;
    bool b = false;

    std::cout << a << std::endl; // 输出：1
    std::cout << std::boolalpha; // 开启格式化
    std::cout << a << std::endl; // 输出：true
    std::cout << b << std::endl; // 输出：false（依然生效！）

    // 如果你想恢复成输出 1 和 0，需要关闭它：
    std::cout << std::noboolalpha; 
    std::cout << a << std::endl; // 输出：1
}
