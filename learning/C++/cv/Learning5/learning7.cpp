#include <vector>
#include <string>
#include <array>
std::vector<int> v{10, 20, 30};
int a = v.at(1);          // 20，正常
// int b = v.at(5);       // 抛出 std::out_of_range
std::string s = "hello";
char c = s.at(0);         // 'h'
// char d = s.at(10);     // 抛出 std::out_of_range
std::array<double, 3> arr{1.0, 2.0, 3.0};
double x = arr.at(2);     // 3.0