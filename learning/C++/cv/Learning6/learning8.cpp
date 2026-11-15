#include <memory>
#include <utility>
#include <iostream>

struct Tracked {
    Tracked()                        { std::cout << "  默认构造\n"; }
    Tracked(const Tracked&)          { std::cout << "  拷贝构造\n"; }
    Tracked(Tracked&&) noexcept      { std::cout << "  移动构造\n"; }
};

// 正确：完美转发
template <typename T, typename... Args>
std::unique_ptr<T> make_impl(Args&&... args) {
    return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}

// 错误示范：不转发
template <typename T, typename... Args>
std::unique_ptr<T> make_no_forward(Args&&... args) {
    return std::unique_ptr<T>(new T(args...));
}

int main() {
    std::cout << "make_impl<Tracked>():\n";
    auto p1 = make_impl<Tracked>();

    std::cout << "make_impl<Tracked>(Tracked{}):\n";
    auto p2 = make_impl<Tracked>(Tracked{});

    std::cout << "make_no_forward<Tracked>(Tracked{}):\n";
    auto p3 = make_no_forward<Tracked>(Tracked{});
}