#include <iostream>

// C++14 之后，constexpr 函数可以包含局部变量、if 语句和循环了
constexpr int factorial(int n) {
    int res = 1;
    for (int i = 2; i <= n; ++i) {
        res *= i;
    }
    return res;
}

int main() {
    // 1. 编译期计算
    constexpr int compile_time_result = factorial(5);
    // 证明是编译期算的：
    static_assert(compile_time_result == 120, "Error");

    // 2. 运行期计算
    int runtime_val = 6;
    int runtime_result = factorial(runtime_val);

    std::cout << "编译期结果: " << compile_time_result << std::endl;
    std::cout << "运行期结果: " << runtime_result << std::endl;

    return 0;
}