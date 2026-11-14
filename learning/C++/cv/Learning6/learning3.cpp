#include <algorithm>
#include <cstddef>
#include <utility>
class Buffer {
public:
    explicit Buffer(std::size_t size)
        : size_{size}, data_{new int[size]{}} {}

    ~Buffer() { delete[] data_; }
    // 拷贝构造
    Buffer(const Buffer& other)
        : size_{other.size_}, data_{new int[other.size_]} {
        std::copy(other.data_, other.data_ + size_, data_);
    }
    // 移动构造
    Buffer(Buffer&& other) noexcept
        : size_{other.size_}, data_{other.data_} {
        other.size_ = 0;
        other.data_ = nullptr;
    }
    // 拷贝赋值
    Buffer& operator=(const Buffer& other) {
        if (this != &other) {
            Buffer tmp(other);          // 拷贝构造临时对象
            std::swap(size_, tmp.size_); // 交换后 tmp 持有旧资源
            std::swap(data_, tmp.data_); // tmp 析构时释放旧资源
        }
        return *this;
    }
    // 移动赋值
    Buffer& operator=(Buffer&& other) noexcept {
        if (this != &other) {
            delete[] data_;             // 1. 释放自己的旧资源
            size_ = other.size_;        // 2. 接管 other 的资源
            data_ = other.data_;
            other.size_ = 0;            // 3. 把 other 置为有效但空的状态
            other.data_ = nullptr;
        }
        return *this;                   // 4. 返回自身引用
    }
private:
    std::size_t size_;
    int* data_;
};