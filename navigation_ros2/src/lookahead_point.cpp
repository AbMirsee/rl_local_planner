#include <rclcpp/rclcpp.hpp>
#include <geometry_msgs/msg/pose_stamped.hpp>
#include <geometry_msgs/msg/pose_with_covariance_stamped.hpp>
#include <geometry_msgs/msg/twist.hpp>
#include <nav_msgs/msg/odometry.hpp>
#include <nav_msgs/msg/path.hpp>
#include <ackermann_msgs/msg/ackermann_drive_stamped.hpp>
#include <visualization_msgs/msg/marker.hpp>
#include <tf2_ros/transform_listener.h>
#include <tf2_ros/buffer.h>

class LookAhead : public rclcpp::Node
{
public:
  LookAhead() : Node("lookahead")
  {
    this->declare_parameter<double>("Lfw", 3.0);
    this->declare_parameter<int>("controller_freq", 30);

    odom_sub_ = this->create_subscription<nav_msgs::msg::Odometry>(
      "odom", 10,
      std::bind(&LookAhead::odomCB, this, std::placeholders::_1));

    timer_ = this->create_wall_timer(
      std::chrono::milliseconds(1000 / controller_freq_),
      std::bind(&LookAhead::controlLoopCB, this));
  }

private:
  void odomCB(const nav_msgs::msg::Odometry::SharedPtr msg)
  {
    odom_ = *msg;
  }

  void controlLoopCB()
  {
    // TODO: implement lookahead logic for ROS2
  }

  nav_msgs::msg::Odometry odom_;
  rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr odom_sub_;
  rclcpp::TimerBase::SharedPtr timer_;
  int controller_freq_{30};
};

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  auto node = std::make_shared<LookAhead>();
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}
