#include <iostream>
#include <unordered_map>
#include <string>
int main() {
    // 声明一个 unordered_map
    std::unordered_map<std::string, int> ages;
    // 插入元素
    ages["Alice"] = 25;
    ages["Bob"] = 30;
    ages.insert({"Charlie", 28}); // 另一种插入方式
    // 查找元素
    if (ages.find("Bob") != ages.end()) {
        std::cout << "Bob is " << ages["Bob"] << " years old.\n";
    }
    // 遍历（注意：输出的顺序是不确定的，每次运行可能不同）
    for (const auto& [name, age] : ages) {
        std::cout << name << ": " << age << "\n";
    }
}