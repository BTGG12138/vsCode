#include <iostream>
using std::cout;
using std::endl;
class Rectangle
{
public:
    Rectangle(int w, int h) : width_{w}, height_{h} {}
    int width() const { return width_; }
    int height() const { return height_; }

protected:
    int width_ = 0;
    int height_ = 0;
};
class Square : public Rectangle
{
public:
    explicit Square(int size) : Rectangle{size, size} {}
};
int main()
{
    Square sq(10);
    cout << sq.width() << " " << sq.height() << endl;
    return 0;
}