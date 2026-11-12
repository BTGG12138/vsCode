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