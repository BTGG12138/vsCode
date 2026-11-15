#include <type_traits>
template <typename T>
void process(T&& value) {
    if constexpr (std::is_trivially_copyable_v<T>) {
        // 小类型：按值用
    } else {
        // 大类型：按引用用
    }
}