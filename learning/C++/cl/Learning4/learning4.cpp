#include <iostream>
void func(int x) {
    std::cout << "调用了 func(int)\n";
}
void func(char* ptr) {
    std::cout << "调用了 func(char*)\n";
}
int main() {
    //func(NULL); // 猜猜会调用哪个？
    func(nullptr); // 猜猜会调用哪个？
}