// main.cpp
#include <cstdio>

struct ascii{};
struct utf8{};

// ========== 模拟 .h 内容 ==========
template<typename Cs> 
int mblen(const char *, int);

template<> int mblen<ascii>(const char *, int);
template<> int mblen<utf8>(const char *, int);

template<typename Cs> 
int reverse(const char *, int) { return 0; }

// ========== 模拟另一个TU（xxx.cpp）的定义 ==========
template<> 
int mblen<ascii>(const char *p, int n) {
    return 1;
}
template<> 
int mblen<utf8>(const char *p, int n) {
    return 2;
}

int main()
{
    printf("%d\n", mblen<ascii>("abc", 3));
    printf("%d\n", mblen<utf8>("abc", 3));
    return 0;
}
