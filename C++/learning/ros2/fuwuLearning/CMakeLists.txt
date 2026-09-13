cmake_minimum_required(VERSION 3.8)
project(cpp_demo)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

find_package(rosidl_default_generators REQUIRED)

rosidl_generate_interfaces(${PROJECT_NAME}
  "srv/AddInts.srv"
)

rosidl_get_typesupport_target(cpp_demo_typesupport 
${PROJECT_NAME} "rosidl_typesupport_cpp")

add_executable(server src/server.cpp)
ament_target_dependencies(server "rclcpp")
target_link_libraries(server "${cpp_demo_typesupport}")
add_executable(client src/client.cpp)
ament_target_dependencies(client "rclcpp")
target_link_libraries(client "${cpp_demo_typesupport}")
install(TARGETS 
  server
  client
  DESTINATION lib/${PROJECT_NAME})
ament_package()

