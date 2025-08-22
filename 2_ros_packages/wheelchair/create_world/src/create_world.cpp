#include "rclcpp/rclcpp.hpp"

int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);
  auto node = std::make_shared<rclcpp::Node>("create_world_node");
  RCLCPP_INFO(node->get_logger(), "create_world_node started.");
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}