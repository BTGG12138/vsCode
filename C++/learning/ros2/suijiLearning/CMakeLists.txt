cmake_minimum_required(VERSION 3.8)
project(cpp_demo)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)

find_package(geometry_msgs REQUIRED)
find_package(turtlesim REQUIRED)

rosidl_generate_interfaces(${PROJECT_NAME}
"srv/TurtleServer.srv")

rosidl_get_typesupport_target(cpp_demo_typesupport_target ${PROJECT_NAME} "rosidl_typesupport_cpp")

add_executable(turtle_talker src/turtle_talker.cpp)
ament_target_dependencies(turtle_talker rclcpp geometry_msgs turtlesim)
target_link_libraries(turtle_talker "${cpp_demo_typesupport_target}")
add_executable(turtle_client src/turtle_client.cpp)
ament_target_dependencies(turtle_client rclcpp geometry_msgs turtlesim)
target_link_libraries(turtle_client "${cpp_demo_typesupport_target}")
#自定义文件的时候需要写

install(TARGETS 
turtle_talker 
turtle_client
DESTINATION lib/${PROJECT_NAME})
ament_package()
