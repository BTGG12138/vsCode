#include <type_traits>

// template<class T> void f() {
//     static_assert(sizeof(int) == 0);
// }

template<class T> void g() {
    static_assert(sizeof(T) == 0);
}

int main() {
    // g<int>(); // 取消注释这一行，才会触发断言失败
    return 0;
}
