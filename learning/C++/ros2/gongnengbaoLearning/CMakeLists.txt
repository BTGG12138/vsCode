cmake_minimum_required(VERSION 3.8)
#检查版本要求
project(cpp_demo)
#包体命名，替代后面的${PROJECT_NAME}占位符
if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()
#检查警告功能，可以不加
find_package(ament_cmake REQUIRED)
#ROS2 的编译工具核心包
find_package(rclcpp REQUIRED)
#ROS2 C++ 客户端库
add_executable(Learning src/Learning.cpp)
#生成程序名称，生成程序原文件
ament_target_dependencies(Learning PUBLIC rclcpp)
#ROS2合并后的简要表达，添加依赖
install(TARGETS
  Learning
  DESTINATION lib/${PROJECT_NAME}
)
#安装到指定位置
ament_package()
#提交包体，结束