#include <iostream>
//enum class（也叫强类型枚举）
//强作用域 Color::RED
//强制整容 int x = static_cast<int>(Color::RED);合法（x 为 0）
int main() {
    enum class RGB { RED, GREEN, BLUE };
    RGB color = RGB::GREEN;
    switch (color) {
    case RGB::RED:   std::cout << "red\n"; break;
    case RGB::GREEN: std::cout << "green\n"; break;
    case RGB::BLUE:  std::cout << "blue\n"; break;
    }
    return 0;
}
/*
for (int score : scores) 
{
    std::cout << score << std::endl; // 直接用 score
}
    
类似于 Python 的 for-in 循环，可以直接遍历容器中的元素，而不需要使用索引或迭代器。
{
    // 1. 创建一个字典（map）：键是字符，值是整数
    std::map<char, int> my_dict{{'a', 27}, {'b', 3}};
    // 2. 使用结构化绑定遍历字典
    for (const auto& [key, value] : my_dict) {
        std::cout << key << " has value " << value << std::endl;
}

const float var = 84.78;
在 C++ 中，不带后缀 f 的小数字面量（如 84.78），默认是 double（双精度浮点数），占 64 位（8字节）。
而左边的 var 是 float（单精度浮点数），占 32 位（4字节）。
当你把 64 位的 84.78 强行塞进 32 位的 float 盒子里时，会发生精度截断（丢失数据）。
float 只能保存一个非常接近 84.78 的近似值，比如底层可能是 84.77999877929688。
*/