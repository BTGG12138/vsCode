#include <iostream>
#include <sstream>
#include <string>
int main() {
    std::string filename = "img00205.txt";
    std::stringstream ss(filename);
    int number;
    std::string extension;
    // 利用字符串流自动“解析”，忽略前导的“img”
    // 并按照类型提取到相应变量
    ss >> number >> extension; // number = 205, extension = ".txt"
    std::cout << "Number is: " << number << std::endl;
    std::cout << "Extension is: " << extension << std::endl;
    // 现在可以对 number 进行算术运算
    number += 100;
    std::cout << "Modified number: " << number << std::endl;
    return 0;
}