#include <cstdio>

template<typename T>
void f(T&& t)
{
    puts(__PRETTY_FUNCTION__);
}

int main()
{
    int i;
    f(i);    // 左值：T = int&，参数类型 int&
    f(10);   // 右值：T = int， 参数类型 int&&
    return 0;
}
