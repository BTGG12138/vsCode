#include <iostream>
#include <memory>
#include <vector>

using Vec = std::vector<int>;

std::shared_ptr<int> foo_safe() {
    auto elts = {0, 1, 2, 3, 4};
    std::shared_ptr<Vec> pvec = std::make_shared<Vec>(elts);
    std::shared_ptr<int> sub_ptr(pvec, &(*pvec)[2]);
    std::cout << "sub_ptr value: " << *sub_ptr << '\n';
    return sub_ptr;
}

int main() {
    auto p = foo_safe();
    std::cout << "After foo, value: " << *p << '\n';
    return 0;
}
