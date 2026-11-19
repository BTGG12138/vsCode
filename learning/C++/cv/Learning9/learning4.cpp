#include <iostream>

// 自己实现 type_identity，C++11 可用
template<typename T>
struct type_identity {
    using type = T;
};
template<typename T>
using type_identity_t = typename type_identity<T>::type;


template<typename T>
void f(T a, T b)
{
    std::cout << __PRETTY_FUNCTION__ << "\n";
}

template<typename T>
void g(T a, type_identity_t<T> b)
{
    std::cout << __PRETTY_FUNCTION__ << "\n";
}

template<typename T>
void h()
{
    std::cout << __PRETTY_FUNCTION__ << "\n";
}

int main()
{
    f(1, 2);
    g(1, 2.0);
    h<double>();

    // f(1, 2.0);   // 取消注释 → 冲突推导报错
    // h();         // 取消注释 → 无法推导T报错
    return 0;
}
