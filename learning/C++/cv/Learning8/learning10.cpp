#include <iostream>
#include <memory>

class Widget : public std::enable_shared_from_this<Widget> {
public:
    std::shared_ptr<Widget> getSelf() {
        return shared_from_this();
    }
    void hello() {
        std::cout << "Hello Widget\n";
    }
};

int main() {
    auto w1 = std::make_shared<Widget>();
    auto w2 = w1->getSelf(); // 从对象内部拿到 shared_ptr，引用计数+1

    std::cout << "use_count: " << w1.use_count() << "\n";
    w2->hello();
    return 0;
}
