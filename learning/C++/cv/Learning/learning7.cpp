/*
program1 > out.log 2>&1
> out.log：把 stdout (1) 重定向到 out.log。此时，文件只被打开了一次。
2>&1：意思是“把 stderr (2) 重定向到 stdout (1) 当前指向的位置”。
2 -> stderr。
> -> 重定向。
& -> 复制。
1 -> stdout。

GDB（GNU Debugger）是 Linux 下最强大、最核心的命令行代码调试工具。它主要用于调试 C 和 C++ 程序。

GCC：GNU 编译器集合 (GNU Compiler Collection)
本质：它是一个庞大的底层编译工具链。它包含了 C 的编译器（cc1）、C++ 的编译器（cc1plus）、汇编器（as）、链接器（ld）等等。
g++：GCC 提供给 C++ 的“驱动程序”
它负责调用底层的 C++ 编译器，并自动帮你连上 C++ 的标准库。

# 找到当前目录及子目录下所有 .cpp, .h, .hpp 文件，批量格式化
find . -regex '.*\.\(cpp\|hpp\|h\)' -exec clang-format -i {} \;

sudo nano /etc/apt/sources.list.d/gitlab_gitlab-ce.list
deb [signed-by=/etc/apt/keyrings/gitlab_gitlab-ce-archive-keyring.gpg] https://mirrors.tuna.tsinghua.edu.cn/gitlab-ce/ubuntu noble main

# 终端运行，一键清空所有缓存
rm -rf ~/.cache/*
sudo apt clean
sudo apt autoremove -y
# 只保留最近 7 天的日志
sudo journalctl --vacuum-time=7d
sudo snap set system refresh.retain=2

CV_：固定前缀（OpenCV 的缩写）。
<bit_count>：每个数字占多少个二进制位（bit）。比如 8 代表 8 位（1 字节），32 代表 32 位。
<identifier>：数据类型标识符。
    U = Unsigned integer（无符号整数，对应 C++ 的 unsigned char）
    S = Signed integer（有符号整数，对应 short）
    F = Float（浮点数，对应 float）
<num_of_channels>：通道数（Channels）。1 代表单通道（灰度），3 代表三通道（RGB/BGR），4 代表四通道（带透明度 RGBA）。

你之前问的 clang-tidy 是“静态检查”：代码不运行，光看代码长得对不对。
你现在问的 gtest / Python assert 是“动态断言”：代码跑起来了，验证结果对不对。

// 使用初始化列表
Point(int x, int y) : x_(x), y_(y) {}
: 后面的部分 x_(x), y_(y) 叫做“成员初始化列表”。
它表示：用传入的参数 x 来初始化成员变量 x_，用参数 y 来初始化成员变量 y_。

你可以使用 = default 让编译器生成默认实现，或使用 = delete 来禁用某个函数。

int& 是左值引用，它只能绑定到左值。
int&& 是右值引用，它只能绑定到右值。

this解决命名冲突
*/