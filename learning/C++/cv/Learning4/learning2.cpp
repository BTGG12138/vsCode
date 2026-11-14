#include <iostream>
#include <type_traits>
int main() {
    char c = 'A';
    signed char sc = -1;
    unsigned char uc = 255;
    // 1. 验证它们是否是不同的类型
    std::cout << std::boolalpha;
    // 下面这行输出 true 还是 false 取决于编译器（GCC/MSVC 通常是 false）
    std::cout << "Is char same as signed char? " 
              << std::is_same<char, signed char>::value << std::endl; 
    // 输出 false：unsigned char 绝对是另一种类型
    std::cout << "Is char same as unsigned char? " 
              << std::is_same<char, unsigned char>::value << std::endl; 
    // 2. 转换与提升的坑
    unsigned char u = 200;
    int i = u; // 正常提升，i 的值为 200
    signed char s = -1;
    unsigned int ui = s; // 坑！有符号向无符号隐式转换，ui 变成 4294967295 (0xFFFFFFFF)
    // 3. 流输出（cout）的差异
    // 当用 cout 打印它们时，编译器会怎么处理？
    std::cout << "Print unsigned char 200: " << u << std::endl; 
    // 输出不是 200，而是字符 'È' (因为 cout 把 unsigned char 当作字符打印) 
    // 如果要打印它的数值，必须强转为 int
    std::cout << "Print cast to int: " << static_cast<int>(u) << std::endl; // 输出 200
}