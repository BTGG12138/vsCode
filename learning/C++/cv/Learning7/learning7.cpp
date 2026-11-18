#include <cmath>
#include <iostream>
using namespace std;

class Point {
public:
    // 构造函数，初始化坐标 x_ y_
    Point(int x, int y) : x_{x}, y_{y} {}

    // 普通成员函数：this对象 到 other 对象的距离
    float Distance(const Point& other) const {
        float x_diff = x_ - other.x_;
        float y_diff = y_ - other.y_;
        return sqrt(x_diff * x_diff + y_diff * y_diff);
    }

    // 静态成员函数：接收两个点，计算a、b两点距离
    static float Distance(const Point& a, const Point& b) {
        cout << a.x_ << endl;
        return a.Distance(b);
    }

private:
    int x_ = 0;
    int y_ = 0;
};

int main() {
    Point a(1, 1);
    Point b(4, 5);

    // 两种调用方式
    // 方式1：普通成员函数调用（必须通过对象调用）
    cout << a.Distance(b) << endl;
    // 方式2：静态成员函数调用（类名:: 直接调用，不需要对象）
    cout << Point::Distance(a, b) << endl;

    return 0;
}
