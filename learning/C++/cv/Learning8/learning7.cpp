#include <memory>
#include <iostream>

struct Test {
    void hello() { std::cout << "hello\n"; }
};

// ✅ 1. 值接收unique_ptr：转移所有权（幻灯片推荐）
void take_owner(std::unique_ptr<Test> p) {
    p->hello();
}

// ✅ 2. 仅访问对象：传裸指针/引用（推荐，无所有权语义）
void observe(Test* p) {
    p->hello();
}
void observe_ref(Test& p) {
    p.hello();
}

// ❌ 幻灯片说的 code smell：传unique_ptr引用，仅用来访问对象
void bad_style(const std::unique_ptr<Test>& p) {
    p->hello();
}

int main() {
    auto ptr = std::make_unique<Test>();
    observe(ptr.get());
    observe_ref(*ptr);

    take_owner(std::move(ptr)); // move，交出所有权
    return 0;
}
