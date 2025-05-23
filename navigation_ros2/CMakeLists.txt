cmake_minimum_required(VERSION 3.5)
project(gazebo_rl_test_ros2)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(nav_msgs REQUIRED)
find_package(std_msgs REQUIRED)
find_package(ackermann_msgs REQUIRED)
find_package(tf2_ros REQUIRED)
find_package(tf2_geometry_msgs REQUIRED)
find_package(visualization_msgs REQUIRED)

add_executable(lookahead_point src/lookahead_point.cpp)
ament_target_dependencies(lookahead_point
  rclcpp
  geometry_msgs
  nav_msgs
  std_msgs
  ackermann_msgs
  tf2_ros
  tf2_geometry_msgs
  visualization_msgs
)

install(TARGETS lookahead_point DESTINATION lib/${PROJECT_NAME})

ament_package()
