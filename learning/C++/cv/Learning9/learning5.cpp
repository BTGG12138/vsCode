#include <cstdio>
#include <array>

template<typename T, typename U>
void foo(std::array<T, sizeof(U)> x,
         std::array<U, sizeof(T)> y,
         int z)
{
    puts(__PRETTY_FUNCTION__);
}

int main()
{
    // 第1次调用 ✅ 推导成功
    foo(std::array<int,8>{}, std::array<double,4>{}, 0.0);

    // 第2次调用 ❌ 编译报错！
    // foo(std::array<int,9>{}, std::array<double,4>{}, 0.0);
    return 0;
}
