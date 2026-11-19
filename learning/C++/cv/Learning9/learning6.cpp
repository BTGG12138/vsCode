#include <cstdio>

template<typename R, typename A>
void foo(R (*fptr)(A))
{
    puts(__PRETTY_FUNCTION__);
}

int main()
{
    // foo( [](double x) { return int(x); } ); // ❌ 报错，推导失败
    foo( +[](double x) { return int(x); } );  // ✅ 可以编译
    return 0;
}
