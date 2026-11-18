#include <iostream>

// 1. 定义强类型枚举
enum class FileMode { Read, Write, Append };
enum class StatusCode { OK = 200, NotFound = 404, Error = 500 };

int main() {
    // 2. 创建并初始化枚举变量
    FileMode mode = FileMode::Read;

    // 3. 演示禁止隐式转换
    // int i = mode; // ❌ 如果你把这行的注释去掉，编译器会报错！
    
    // 4. 演示显式转换（强转）
    int i = static_cast<int>(mode); 
    std::cout << "FileMode::Read 的底层整数值是: " << i << "\n\n";

    // 5. 演示安全的比较
    // 这里我们把原本的 "..." 替换成了具体的逻辑
    if (mode == FileMode::Write) {
        std::cout << "当前模式: 写入 (Write)\n";
    } else if (mode == FileMode::Read) {
        std::cout << "当前模式: 读取 (Read)\n";
    } else if (mode == FileMode::Append) {
        std::cout << "当前模式: 追加 (Append)\n";
    }

    // 6. 演示 StatusCode 的用法
    StatusCode status = StatusCode::NotFound;
    std::cout << "StatusCode::NotFound 的 HTTP 状态码是: " 
              << static_cast<int>(status) << "\n";

    // 7. 演示作用域隔离，不会冲突
    // 即使两个枚举里都有类似的概念，加上作用域就一目了然
    if (status == StatusCode::OK) {
        std::cout << "请求成功\n";
    } else {
        std::cout << "请求失败，请检查网络\n";
    }

    return 0;
}