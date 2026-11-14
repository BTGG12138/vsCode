#include <fstream>
#include <iostream>
#include <string>
using namespace std;
int main() {
    string line, file_name;
    // 打开文件
    ifstream input("test_bel.txt", ios_base::in);
    // 检查文件是否成功打开
    if (!input.is_open()) {
        cout << "无法打开文件 test_bel.txt!" << endl;
        return 1;
    }
    // 逐行读取数据
    while (getline(input, line)) {
        cout << "Read: " << line << endl;
        // 查找 "filename" 出现的位置
        string::size_type loc = line.find("filename", 0);
        // 如果 loc 不是 npos（即找到了）
        if (loc != string::npos) {
            // 找到等号，并截取等号后面的所有内容作为文件名
            // 原图代码在这里有漏洞，如果没等号会出错，这里我稍微加个判断会更好
            string::size_type eq_loc = line.find("=", 0);
            if (eq_loc != string::npos) {
                file_name = line.substr(eq_loc + 1, string::npos);
            }
        }
    }
    // 输出最后找到的文件名
    cout << "Filename found: " << file_name << endl;
    return 0;
}