#include <iostream>
#include <vector>
#include <numeric>   // std::partial_sum
#include <algorithm> // std::all_of
// 辅助函数：用来打印数组
void Print(const std::vector<int>& v) {
    for (int x : v) std::cout << x << " ";
    std::cout << "\n";
}
inline bool even(int i) { return i % 2 == 0; };
int main() {
    std::vector<int> v(10, 2);
    // 计算前缀和
    std::partial_sum(v.cbegin(), v.cend(), v.begin());
    Print(v); // 输出: 2 4 6 8 10 12 14 16 18 20 
    // 判断是否全为偶数
    bool all_even = std::all_of(v.cbegin(), v.cend(), even);
    if (all_even) {
        std::cout << "All numbers are even\n"; // 使用 \n 更高效
    }
    return 0;
}
/*
非修改序列算法（只读）：
    std::find, std::find_if（查找）
    std::count, std::count_if（计数）
    std::all_of, std::any_of, std::none_of（就是你上一张截图里的判断）
修改序列算法（原地修改）：
    std::copy, std::move（拷贝/移动）
    std::replace（替换）
    std::reverse（反转）
    std::remove / std::remove_if（配合 erase 实现删除）
    std::transform（对每个元素做转换）
排序与查找（极为重要）：
    std::sort（快速排序，最常用）
    std::stable_sort（稳定排序）
    std::binary_search, std::lower_bound（二分查找，前提是数组已排好序）
数值算法（<numeric>）：
    std::accumulate（求和/折叠）
    std::partial_sum（前缀和）
    std::iota（用连续的值填充数组，比如 0, 1, 2, 3...）
最值：
    std::min, std::max, std::minmax_element
*/