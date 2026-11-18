#include <iostream>
#include <vector>
#include <memory> // 必须包含这个头文件才能用 unique_ptr 和 make_unique

// 1. 定义接口（抽象类）
class Shape {
public:
    virtual ~Shape() = default; // 黄金法则：多态基类必须有虚析构函数
    virtual void draw() const = 0; // 纯虚函数
};

// 2. 具体类：圆
class Circle : public Shape {
public:
    void draw() const override {
        std::cout << "画一个圆形 🔴" << std::endl;
    }
};

// 3. 具体类：方块
class Square : public Shape {
public:
    void draw() const override {
        std::cout << "画一个方块 🟦" << std::endl;
    }
};

// 4. 主函数
int main() {
    // 创建一个存放 Shape 智能指针的“百宝箱”
    std::vector<std::unique_ptr<Shape>> shapes;
    
    // 往箱子里塞入不同的图形（隐式向上转型）
    shapes.push_back(std::make_unique<Circle>());
    shapes.push_back(std::make_unique<Square>());
    shapes.push_back(std::make_unique<Circle>()); // 再塞一个圆

    // 统一遍历，多态调用
    for (const auto& shape : shapes) {
        shape->draw(); 
    }

    // 离开 main 函数时，shapes 容器自动销毁，里面的智能指针自动 delete，完美！
    return 0;
}