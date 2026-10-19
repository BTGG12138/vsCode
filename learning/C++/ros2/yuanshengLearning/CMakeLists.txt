cmake_minimum_required(VERSION 3.22)
project(cpp_demo)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
#ROS2 基础消息包，xml要加上<depend>std_msgs</depend>
add_executable(talker src/talker.cpp)
ament_target_dependencies(talker rclcpp std_msgs)
add_executable(listener src/listener.cpp)
ament_target_dependencies(listener rclcpp std_msgs)

install(TARGETS
  talker
  listener 
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
