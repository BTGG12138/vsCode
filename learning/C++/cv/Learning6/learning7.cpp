#include <initializer_list>
#include <vector>
struct Point {
    int x, y;
    Point(int x, int y) : x(x), y(y) {}
}; 
class Polygon {
public:
    Polygon(std::initializer_list<Point> pts) : points_(pts) {}
    // 或者手动遍历：
    // Polygon(std::initializer_list<Point> pts) {
    //     for (const auto& p : pts) points_.push_back(p);
    // }
private:
    std::vector<Point> points_;
};
Polygon tri{{0,0}, {1,0}, {0,1}};   // 用花括号构造