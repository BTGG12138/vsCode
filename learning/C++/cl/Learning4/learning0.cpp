#include <array>
#include <iostream>
int main() {
    std::array<int, 5> a{1, 2, 3}; // 后两个元素被值初始化为 0
    a[3] = 4;
    a.at(4) = 5;                   // 带越界检查，越界抛 std::out_of_range
    for (int x : a) std::cout << x << ' '; // 1 2 3 4 5
    std::cout << a.size() << '\n'; // 5
    std::cout << a.front() << ' ' << a.back() << '\n'; // 1 5
    std::cout << a.data()[2] << '\n'; // 3
}
/*
void print_size(int arr[]) {
    // 这里的 arr 已经变成了指针，sizeof(arr) 通常是指针的大小（如 8 字节）
    // 计算结果将是 8 / 4 = 2，完全错误！
    printf("%zu\n", sizeof(arr) / sizeof(arr[0])); 
}

char letters[5] = {'n', 'a', 'c', 'h', 'o'};
memset(letters, 0, sizeof(letters));

std::array<char, 5> letters{};
// 或者初始化后用 fill 方法：
std::array<char, 5> letters = {'n', 'a', 'c', 'h', 'o'};
letters.fill(0); // 自动按元素清零，不需要算 sizeof，极其安全
*/