#include <iostream>
#include <vector>
#include <numeric> // std::accumulate 需要的头文件

// 模板定义（补上了 = 10）
template <typename T, int N = 10>
T accumulateVector(T value) {
    std::vector<T> vec(N, value); 
    
    // 打印一下生成的数组内容，方便观察
    std::cout << "数组大小: " << N << ", 元素: ";
    for (const auto& v : vec) std::cout << v << " ";
    std::cout << "\n";

    return std::accumulate(vec.begin(), vec.end(), T{0});
}

int main() {
    auto result1 = accumulateVector(2); 
    std::cout << "result1: " << result1 << "\n\n";

    auto result2 = accumulateVector<float>(2.0); 
    std::cout << "result2: " << result2 << "\n\n";

    auto result3 = accumulateVector<float, 5>(2.0); 
    std::cout << "result3: " << result3 << "\n";

    return 0;
}