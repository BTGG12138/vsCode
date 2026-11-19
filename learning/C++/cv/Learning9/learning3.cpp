#include <vector>
#include <type_traits> // std::is_same_v

// C++03 typedef
typedef std::vector<int> myvec_int;

// C++11 using 普通别名
using myvec_double = std::vector<double>;

// C++11 别名模板（Alias template）
template<typename T>
using myvec = std::vector<T>;

int main()
{
    static_assert(std::is_same_v<myvec_int, std::vector<int>>);
    static_assert(std::is_same_v<myvec_double, std::vector<double>>);
    static_assert(std::is_same_v<myvec<float>, std::vector<float>>);

    // ✅ 正确用法：别名模板必须带模板参数
    myvec<int> v1{1,2,3};
    myvec<double> v2{1.1,2.2};
    myvec<float> v3{3.14f, 2.718f};

    return 0;
}
