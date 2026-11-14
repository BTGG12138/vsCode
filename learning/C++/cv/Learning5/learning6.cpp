#include <iostream>
#include <iomanip>  // 用于 setprecision
#include <fstream>  // 用于文件流
#include <cstdlib>  // 用于 EXIT_FAILURE
using namespace std;
int main() {
    string filename = "out.txt";
    ofstream outfile(filename); // 创建输出文件流
    // 检查文件是否成功打开
    if (!outfile.is_open()) { 
        return EXIT_FAILURE; 
    }
    double a = 1.123123123;
    // 写入一行普通字符串并换行
    outfile << "Just string" << endl;
    // 设置精度为 20，并写入小数 a
    outfile << setprecision(20) << a << endl;
    // 但也展示了盲目追求高精度（超出硬件极限）会导致数据失真。如果你想打印指定的小数位数，请务必写成：
    outfile << fixed << setprecision(5) << a << endl; // 输出 1.12312
    outfile.close(); // 养成好习惯，用完关掉
    return 0;
}
/*
file.write(reinterpret_cast<char*>(&a), sizeof(a));
file.write：是 ofstream 的成员函数，用于写入字节流。
&a：获取变量 a 的内存起始地址。
reinterpret_cast<char*>：重新解释转换。write 函数需要接收一个 const char* 类型的指针（指向字节流）。
我们用这个操作符强制告诉编译器：“别管 a 原本是 double 还是结构体，把它当成一串 char（字节）来看待”。
sizeof(a)：计算变量 a 所占用的总字节数。write 函数需要知道要写多少个字节。

filename() 只是纯文本的字符串截取，它不会去检查这个文件在硬盘上是否真实存在。它完全是基于你给的字符串进行逻辑推理。
如果你想获取不带扩展名的文件名（比如把 bar.txt 变成 bar），可以再套一个方法：.stem()。
如果你想单独获取扩展名（比如 txt），可以用：.extension()。
*/