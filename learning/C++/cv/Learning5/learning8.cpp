#include <algorithm>    // std::clamp, std::sample
#include <iostream>     // std::cout
#include <random>       // std::mt19937, std::random_device
#include <string>       // std::string
#include <vector>       // std::vector
#include <iterator>     // std::back_inserter
/// @brief 演示 std::clamp：把值限制在 [lo, hi] 区间内。
/// @param v  待限制的值。
/// @param lo 下界。
/// @param hi 上界。
/// @return   限制后的值。
int clamp_demo(int v, int lo, int hi) {
    return std::clamp(v, lo, hi);
}
/// @brief 演示 std::sample：从字符串中无放回随机采样 n 个字符。
/// @param in 采样来源。
/// @param n  采样个数。
/// @param gen 随机数引擎。
/// @return   采样得到的字符串。
std::string sample_demo(const std::string& in, std::size_t n, std::mt19937& gen) {
    std::string out;
    std::sample(in.begin(), in.end(), std::back_inserter(out), n, gen);
    return out;
}
int main() {
    std::cout << "===== std::clamp 演示 =====\n";
    std::cout << "clamp(5, 0, 10)   = " << clamp_demo(5, 0, 10)   << "  (在区间内，原样返回)\n";
    std::cout << "clamp(-3, 0, 10)  = " << clamp_demo(-3, 0, 10)  << "  (低于下界，返回下界)\n";
    std::cout << "clamp(42, 0, 10)  = " << clamp_demo(42, 0, 10)  << "  (高于上界，返回上界)\n";
    std::cout << "clamp(0, 0, 10)   = " << clamp_demo(0, 0, 10)   << "  (等于下界，原样返回)\n";
    std::cout << "clamp(10, 0, 10)  = " << clamp_demo(10, 0, 10)  << "  (等于上界，原样返回)\n";
    std::cout << "\n===== std::sample 演示 =====\n";
    const std::string in = "C++ is cool";
    std::cout << "原始字符串: \"" << in << "\"  (长度 " << in.size() << ")\n";
    // 1) 固定种子：每次运行结果相同，便于调试和验证
    std::mt19937 gen_fixed(42);
    std::string out_fixed = sample_demo(in, 5, gen_fixed);
    std::cout << "固定种子(42)采样 5 个: \"" << out_fixed << "\"\n";
    // 2) 真随机：每次运行结果不同
    std::random_device rd;
    std::mt19937 gen_random(rd());
    std::string out_random = sample_demo(in, 5, gen_random);
    std::cout << "真随机采样 5 个:       \"" << out_random << "\"\n";
    // 3) n 大于区间长度：不报错，全部选取
    std::string out_all = sample_demo(in, 100, gen_random);
    std::cout << "采样 100 个(超过长度):  \"" << out_all << "\"  (长度 " << out_all.size() << ")\n";
    std::cout << "\n===== std::sample 输入顺序 vs 输出顺序 =====\n";
    // 标准不保证输出保持输入相对顺序，但 libstdc++ 通常保持
    std::vector<int> nums{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<int> picked;
    std::mt19937 gen2(123);
    std::sample(nums.begin(), nums.end(), std::back_inserter(picked), 4, gen2);
    std::cout << "原始: ";
    for (int x : nums) std::cout << x << ' ';
    std::cout << "\n采样: ";
    for (int x : picked) std::cout << x << ' ';
    std::cout << "\n(注意：不要依赖采样结果的顺序，换标准库可能不同)\n";
    return 0;
}