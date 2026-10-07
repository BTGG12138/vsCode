cmake_minimum_required(VERSION 3.22)
project(cpp_demo)

# find dependencies

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

#找到消息代码生成器接口包
find_package(rosidl_default_generators REQUIRED)

# 为接口文件生成源码
rosidl_generate_interfaces( ${PROJECT_NAME}
  "msg/Student.msg"
)

# 可执行文件，cpp文件名严格匹配
add_executable(talker src/talker.cpp)
ament_target_dependencies(talker rclcpp std_msgs)
add_executable(listener src/listener.cpp)
ament_target_dependencies(listener rclcpp std_msgs)

install(TARGETS
  talker
  listener 
  DESTINATION lib/${PROJECT_NAME}
)

rosidl_get_typesupport_target(cpp_typesupport_target ${PROJECT_NAME} "rosidl_typesupport_cpp")
target_link_libraries(talker "${cpp_typesupport_target}")
target_link_libraries(listener "${cpp_typesupport_target}")

ament_package()
