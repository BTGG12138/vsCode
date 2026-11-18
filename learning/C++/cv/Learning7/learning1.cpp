#include <iostream>
using std::cout;
using std::endl;
class Shape
{
public:
    virtual ~Shape() = default;
    // 纯虚函数：Shape 是抽象类
    virtual double area() const = 0;
    // 普通虚函数：派生类可以重写
    virtual void describe() const
    {
        cout << "Shape" << endl;
    }
};
class Rectangle : public Shape
{
public:
    Rectangle(double w, double h) : width_{w}, height_{h} {}
    double area() const override
    {
        return width_ * height_;
    }
    void describe() const override
    {
        cout << "Rectangle area = " << area() << endl;
    }

private:
    double width_;
    double height_;
};
class Square : public Rectangle
{
public:
    explicit Square(double size) : Rectangle{size, size} {}
    void describe() const override
    {
        cout << "Square area = " << area() << endl;
    }
};
int main()
{
    // Shape s;  // 错误：Shape 是抽象类，不能实例化
    Square sq(4);
    Shape &ref = sq; // 基类引用指向派生类对象
    ref.describe();
    cout << ref.area() << endl;
    return 0;
}