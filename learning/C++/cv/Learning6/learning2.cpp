#include <algorithm>
#include <vector>
#include <iostream>
class Human {
public:
    explicit Human(int kindness) : kindness_{kindness} {}
    int kindness() const { return kindness_; }
    bool operator<(const Human& other) const {
        return kindness_ < other.kindness_;
    }
private:
    int kindness_;
};
int main() {
    std::vector<Human> humans = {Human{10}, Human{0}, Human{5}};
    std::sort(humans.begin(), humans.end());
    for (const auto& h : humans) {
        std::cout << h.kindness() << " ";
    }
    std::cout << "\n";
    return 0;
}