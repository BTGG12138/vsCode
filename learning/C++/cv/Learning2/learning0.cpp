//静态数据成员（Static Data Member） 一句话简述：它是属于“类”本身，被该类的所有对象共享的变量。
//左边是实实在在的对象，就用点（.）。左边是指针（星号 * 定义的），就用箭头（->）
#include <compare> // 必须包含这个头文件
#include <iostream>
struct Point {
    int x, y;
    // 让编译器自动生成所有比较运算符
    auto operator<=>(const Point&) const = default; 
};
int main() {
    Point p1{1, 2};
    Point p2{1, 3};
    //<=> 加 = default 的默认比较规则，采用的是“字典序比较”
    if (p1 < p2) { /* 自动生成的 */ }
    // 也可以直接使用宇宙飞船的结果
    auto result = p1 <=> p2;
    if (result < 0) {
        std::cout << "p1 小于 p2" << std::endl;
    }
}