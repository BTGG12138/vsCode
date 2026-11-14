#include <iostream>
#include <fstream>
#include <string>
int main() {
    // 1. 只读（抽水）：打开 "input.txt" 准备读
    std::ifstream f_in("input.txt"); 
    // 2. 只写（排水）：打开（或新建） "output.txt" 准备写，默认会覆盖原内容
    std::ofstream f_out("output.txt"); 
    // 3. 读写双向：打开 "data.txt"，同时允许读和写
    std::fstream f_in_out("data.txt", std::ios::in | std::ios::out); 
    // ... 后续配合 << 和 >> 操作符进行读写 ...
    return 0; 
}
/*
1. ios_base::app (追加模式)
    作用：打开文件用于写入时，强制将所有写操作定位到文件末尾。无论文件指针当前在何处，写入的数据均追加至文件末尾，不会覆盖原有内容。
2. ios_base::ate (末尾定位模式)
    作用：文件打开后，立即将文件指针（读写位置）定位到文件末尾。
    注意：与 app 的区别在于，ate 仅在打开时初始定位在末尾，后续可以通过 seekp 或 seekg 改变指针位置，从而覆盖前面的内容；而 app 强制每次写入都在末尾。
3. ios_base::binary (二进制模式)
    作用：以纯字节流的形式读写文件，禁用任何平台相关的字符转换（例如 Windows 下不将 \n 转换为 \r\n）。通常用于处理图片、音频、可执行文件等非文本数据，防止数据损坏。
4. ios_base::in (输入模式)
    作用：以只读方式打开文件。要求文件必须已经存在，若文件不存在，打开操作将失败。
5. ios_base::out (输出模式)
    作用：以只写方式打开文件。若文件不存在，系统会自动创建该文件。
6. ios_base::trunc (截断模式)
    作用：打开文件时，若文件已存在，则将其原有内容全部清空（长度截断为 0）。通常与 out 配合使用。
    */