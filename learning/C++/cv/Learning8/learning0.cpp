#include <iostream>

// 1. 定义抽象基类 (接口)
class Vehicle {
public:
    virtual ~Vehicle() {} // 重要：基类必须有虚析构函数
    virtual int getFuelAmount() = 0; // 纯虚函数
    virtual int getCapacity() = 0;
    virtual void applyBrakes() = 0;
};

// 2. 定义具体派生类
class Bus : public Vehicle { 
public:
    // 重写纯虚函数，提供具体实现
    int getFuelAmount() override { 
        return 100; // 假设公交车有 100 升油
    }
    
    int getCapacity() override { 
        return 50;  // 假设公交车能坐 50 人
    }
    
    void applyBrakes() override { 
        std::cout << "公交车：气压刹车系统启动，车辆减速。\n"; 
    }
};

// 3. 测试多态
int main() {
    // 错误示例：抽象类不能被实例化
    // Vehicle v; // ❌ 编译报错：cannot instantiate abstract class

    // 正确示例：创建具体类对象
    Bus myBus;
    
    std::cout << "公交车油量: " << myBus.getFuelAmount() << " L\n";
    std::cout << "公交车容量: " << myBus.getCapacity() << " 人\n";
    myBus.applyBrakes();

    std::cout << "------------------------\n";

    // 💡 多态的真正威力：用基类指针指向派生类对象
    Vehicle* ptr = &myBus; 
    
    // 虽然 ptr 是 Vehicle 指针，但它实际调用的是 Bus 的实现
    std::cout << "通过基类指针调用: \n";
    ptr->applyBrakes(); 
    
    return 0;
}