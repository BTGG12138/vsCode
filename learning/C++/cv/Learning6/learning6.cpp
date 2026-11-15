#include <memory>
#include <string>
class Image {
public:
    Image(const std::string& filename) {
        // 加载图片文件
    }
    int width() const {
        return 800; // 示例宽度
    } 
};
int main() {
    // 创建：优先用 make_unique（C++14）
    auto p1 = std::make_unique<int>(42);          // 指向一个 int，值为 42
    auto p2 = std::make_unique<Image>("a.png");   // 调用 Image 的构造函数
    // 访问
    *p1 = 100;              // 解引用
    p2->width();            // 成员访问，和裸指针一样
    // 获取裸指针（不转移所有权）
    Image* raw = p2.get();  // 只借出去用，不要 delete，不要保存长期使用
    // 释放所有权（返回裸指针，unique_ptr 变空）
    Image* released = p2.release();  // 之后要自己 delete released
    // 替换所管理的对象
    p1.reset();             // 释放当前对象，p1 变空
    p1.reset(new int(7));   // 释放旧对象，管理新对象
}