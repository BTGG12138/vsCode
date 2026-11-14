#include <iostream>
#include <string>
#include <utility>
using namespace std;
int main() {
    string a = "hello world, this is a long string";
    // 拷贝：a 之后还要用
    string b = a;
    cout << "a = " << a << "\n";   // a 仍然完整
    // 移动：a 之后不再用
    string c = std::move(a);
    cout << "c = " << c << "\n";   // c 拿到内容
    cout << "a = " << a << "\n";   // a 变成空串（有效但未指定）
}