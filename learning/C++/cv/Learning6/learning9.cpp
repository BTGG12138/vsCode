#include <chrono>
#include <iostream>
int main() {
auto start = std::chrono::high_resolution_clock::now();
// ... 执行一些操作 ...
auto end = std::chrono::high_resolution_clock::now();
auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
std::cout << "操作耗时: " << duration.count() << " 毫秒" << std::endl;
}