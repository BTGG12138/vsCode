cmake_minimum_required(VERSION 3.8)
project(cpp_demo)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(tf2_ros REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(tf2_geometry_msgs REQUIRED)

add_executable(server01 src/server01.cpp)
add_executable(server02 src/server02.cpp)
add_executable(client src/client.cpp)

ament_target_dependencies(server01
  rclcpp
  tf2_ros
  geometry_msgs
  tf2_geometry_msgs
)

ament_target_dependencies(server02
  rclcpp
  tf2_ros
  geometry_msgs
  tf2_geometry_msgs
)

ament_target_dependencies(client
  rclcpp
  tf2_ros
  geometry_msgs
  tf2_geometry_msgs
)

install(TARGETS
  server01
  server02
  client
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
