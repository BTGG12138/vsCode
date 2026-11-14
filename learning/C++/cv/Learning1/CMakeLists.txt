
#必须叫做CMakeLists.txt
cmake_minimum_required(VERSION 3.10)
project(MyLearningProject)
#设定项目的“全局变量”
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
# 1. 把 Learning0.cpp 打包成一个叫 mylib 的静态库
add_library(mylib Learning0.cpp)
# 2. 生成主程序 MyApp
add_executable(MyApp Learning1.cpp)
# 3. 把主程序和库链接起来
target_link_libraries(MyApp mylib)
#cmake -B build
#cmake --build build