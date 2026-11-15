/*
// 返回一个包含两个值的std::pair
auto getField() {
    std::string name = "answer";
    int value = 42;
    return std::pair{name, value}; // C++17可省略模板参数
}

int main() {
    auto [name, val] = getField(); // 结构化绑定
    std::cout << name << " is " << val << std::endl; // 输出：answer is 42
    return 0;
}

匿名命名空间：用于使文件内的标识符具有内部链接性（仅在本文件内可见），替代C风格的static。

namespace { // 匿名命名空间
    const int MAX_SIZE = 100;
    void helper()  ///< 只在本文件内可用 ///
}
*/