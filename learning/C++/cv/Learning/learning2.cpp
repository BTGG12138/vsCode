/*
1. 预处理
预处理步骤负责处理 #include 指令（将头文件内容复制到源文件中）、展开宏定义以及删除注释。
clang++ -E main.cpp -o main.i
现在你可以查看 main.i 文件。你会发现文件变得非常长（例如，可能超过28000行），因为 #include <iostream> 的内容被包含了进来。同时，你写的注释也消失了。
2. 编译
这是真正的“编译”步骤，编译器将预处理后的代码（main.i）转换为汇编代码。
clang++ -S main.i -o main.s
生成的 main.s 文件包含汇编指令，这对人类来说难以阅读，但机器可以理解。
3. 汇编
汇编器将汇编代码（main.s）转换为目标文件（二进制代码）。
clang++ -c main.s -o main.o
main.o 是目标文件，包含机器码。直接打开它看到的将是乱码。
4. 链接
链接器将一个或多个目标文件（以及库）组合起来，生成最终的可执行文件。
clang++ main.o -o main
现在，运行 ./main 就可以执行程序了。

cmake_minimum_required(VERSION 3.10)
project(FirstProject)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# 添加一个名为 `tools` 的库，其源文件是 tools.cpp
add_library(tools tools.cpp)
# 添加一个名为 `main` 的可执行文件，其源文件是 main.cpp
add_executable(main main.cpp)
# 将可执行文件 `main` 与库 `tools` 链接
target_link_libraries(main tools)
*/