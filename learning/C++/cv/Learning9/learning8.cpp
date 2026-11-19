#include <cstdio>

// 主模板 primary template
template<typename T>
constexpr bool is_array = false;

// 偏特化1：未知边界数组 Tp[]
template<typename Tp>
constexpr bool is_array<Tp[]> = true;

// 偏特化2：固定大小数组 Tp[N]
template<typename Tp, int N>
constexpr bool is_array<Tp[N]> = true;

// 全特化 full specialization：T = void
template<>
constexpr bool is_array<void> = true;

int main()
{
    printf("%d\n", is_array<int>);         // false
    printf("%d\n", is_array<int[5]>);      // true，匹配 Tp[N]
    printf("%d\n", is_array<int[]>);       // true，匹配 Tp[]
    printf("%d\n", is_array<void>);        // true，匹配全特化
    return 0;
}
