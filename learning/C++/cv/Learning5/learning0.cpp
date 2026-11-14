/*
std::size_t             专门表示大小或数量的无符号整数类型
std::shared_ptr         智能指针，自动管理堆内存的释放
std::exception          异常类和断言宏，用于处理程序运行时的错误
std::vector{1, 2}       支持用花括号 {} 初始化标准库容器
std::abort              直接调用它让程序立刻彻底停止
std::chrono::duration   专门用来表示时间长度
std::variant            它规定了一个盒子里可以装几种指定的不同类型，但同一时间只能装其中一种
std::tuple              可以把不同类型的值组合在一起，形成一个整体
*/
#include <iostream>
#include <variant>
int main() {
    std::variant<int, float> v1;
    v1 = 12; // v1 包含 int
    std::cout << std::get<int>(v1) << std::endl;
    std::variant<int, float> v2{3.14F};
    std::cout << std::get<1>(v2) << std::endl;
    v2 = std::get<int>(v1); // 将 v1 赋值给 v2
    v2 = std::get<0>(v1); // 与上一行相同
    v2 = v1; // 与上一行相同
    std::cout << std::get<int>(v2) << std::endl;
    return 0;
}