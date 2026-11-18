#include <iostream>
#include <memory>
using namespace std;

int main() {
    auto sp = make_shared<int>(666);
    weak_ptr<int> wp = sp;

    // 尝试获取资源
    if (auto temp = wp.lock()) {
        cout << *temp << endl; // 资源还在，输出666
    } else {
        cout << "资源已经释放" << endl;
    }

    sp.reset(); // shared_ptr释放，ref变成0，堆对象销毁

    if (auto temp = wp.lock()) {
        cout << *temp << endl;
    } else {
        cout << "资源已经释放" << endl; // 走这里
    }
    return 0;
}
