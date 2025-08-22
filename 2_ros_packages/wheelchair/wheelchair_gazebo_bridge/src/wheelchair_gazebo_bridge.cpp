#include "rclcpp/rclcpp.hpp"
#include "nav_msgs/msg/odometry.hpp"
#include "geometry_msgs/msg/twist_stamped.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "geometry_msgs/msg/pose.hpp"
#include "gazebo_msgs/msg/model_states.hpp"
#include <rclcpp/qos.hpp>

#include <unordered_map>
#include <string>
#include <vector>

using std::placeholders::_1;

class WheelchairBridge : public rclcpp::Node
{
public:
  WheelchairBridge() : Node("wheelchair_gazebo_bridge")
  {
    rclcpp::QoS sensor_qos{rclcpp::KeepLast(1)};
    sensor_qos.best_effort().durability_volatile();
    odom_sub_ = this->create_subscription<nav_msgs::msg::Odometry>("/wheelchair/diff_drive_controller/odom", sensor_qos, 
                  std::bind(&WheelchairBridge::odom_callback, this, _1));
    // cmd_vel_pub_ = this->create_publisher<geometry_msgs::msg::Twist>("/wheelchair/diff_drive_controller/cmd_vel", 10);
    // cmd_vel_sub_ = this->create_subscription<geometry_msgs::msg::Twist>("/wheelchair/diff_drive_controller/cmd_vel", sensor_qos, 
    //                 std::bind(&WheelchairBridge::cmd_vel_callback, this, _1));
    cmd_vel_sub_ = this->create_subscription<geometry_msgs::msg::TwistStamped>("/wheelchair/diff_drive_controller/cmd_vel", sensor_qos, 
                    std::bind(&WheelchairBridge::cmd_vel_callback, this, _1));
    pose_pub_ = this->create_publisher<geometry_msgs::msg::Pose>("/wheelchair/pose", sensor_qos);//rclcpp::QoS(10).best_effort());

    odom_pub_ = this->create_publisher<nav_msgs::msg::Odometry>(
      "/wheelchair/odom", sensor_qos);

    // cmd_vel_pub_ = this->create_publisher<geometry_msgs::msg::Twist>(
    //   "/wheelchair/cmd_vel", sensor_qos);
    cmd_vel_pub_ = this->create_publisher<geometry_msgs::msg::TwistStamped>(
      "/wheelchair/cmd_vel", sensor_qos);

    model_states_sub_ = this->create_subscription<gazebo_msgs::msg::ModelStates>(
      "/wheelchair/model_states", sensor_qos,
      std::bind(&WheelchairBridge::model_states_callback, this, _1));

    // obstacle用のPublisherをまとめて作成
    for (int i : get_obstacle_ids()) {
      std::string name = (i < 10 ? "obstacle" + std::to_string(i) : "obstacle" + std::to_string(100 + i));
      std::string odom_topic = "/" + name + "/odom";
      std::string cmd_vel_topic = "/" + name + "/diff_drive_controller/cmd_vel";
      std::string pose_topic = "/" + name + "/obs_pose" + std::to_string(i < 10 ? i : 100 + i);

      obstacle_odom_pubs_[name] = this->create_publisher<nav_msgs::msg::Odometry>(odom_topic, 10);
      // obstacle_cmd_vel_pubs_[name] = this->create_publisher<geometry_msgs::msg::Twist>(cmd_vel_topic, 10);
      obstacle_cmd_vel_pubs_[name] = this->create_publisher<geometry_msgs::msg::TwistStamped>(cmd_vel_topic, 10);
      obstacle_pose_pubs_[name] = this->create_publisher<geometry_msgs::msg::Pose>(pose_topic, 10);

      std::string odom_sub_topic = "/" + name + "/diff_drive_controller/odom";
      std::string cmd_vel_sub_topic = "/" + name + "/cmd_vel";

      auto odom_cb = [this, name](nav_msgs::msg::Odometry::SharedPtr msg) {
        obstacle_odom_pubs_[name]->publish(*msg);
      };
      // auto cmd_vel_cb = [this, name](geometry_msgs::msg::Twist::SharedPtr msg) {
      //   obstacle_cmd_vel_pubs_[name]->publish(*msg);
      // };
      auto cmd_vel_cb = [this, name](geometry_msgs::msg::TwistStamped::SharedPtr msg) {
        obstacle_cmd_vel_pubs_[name]->publish(*msg);
      };

      obstacle_odom_subs_.push_back(this->create_subscription<nav_msgs::msg::Odometry>(odom_sub_topic, 10, odom_cb));
      // obstacle_cmd_vel_subs_.push_back(this->create_subscription<geometry_msgs::msg::Twist>(cmd_vel_sub_topic, 10, cmd_vel_cb));
      obstacle_cmd_vel_subs_.push_back(this->create_subscription<geometry_msgs::msg::TwistStamped>(cmd_vel_sub_topic, 10, cmd_vel_cb));
    }
  }

private:
  void odom_callback(const nav_msgs::msg::Odometry::SharedPtr msg)
  { 
    // ログがうるさかったのでコメントアウトしました。by井本
    // RCLCPP_INFO(this->get_logger(),
    // "Bridge got odom, seq=%u, frame_id=%s",
    // msg->header.stamp.sec, msg->header.frame_id.c_str());
    odom_pub_->publish(*msg);
  }

  // void cmd_vel_callback(const geometry_msgs::msg::Twist::SharedPtr msg)
  void cmd_vel_callback(const geometry_msgs::msg::TwistStamped::SharedPtr msg)
  {
    cmd_vel_pub_->publish(*msg);
  }

  void model_states_callback(const gazebo_msgs::msg::ModelStates::SharedPtr msg)
  {
    for (size_t i = 0; i < msg->name.size(); ++i)
    {
      const std::string &name = msg->name[i];
      if (name == "wheelchair") {
        pose_pub_->publish(msg->pose[i]);
        // RCLCPP_INFO(this->get_logger(), "Published pose for wheelchair");
      } else if (obstacle_pose_pubs_.find(name) != obstacle_pose_pubs_.end()) {
        obstacle_pose_pubs_[name]->publish(msg->pose[i]);
      }
    }
  }

  std::vector<int> get_obstacle_ids()
  {
    std::vector<int> ids;
    for (int i = 1; i <= 9; ++i) ids.push_back(i);
    for (int i = 101; i <= 110; ++i) ids.push_back(i - 100);
    return ids;
  }

  // Publishers
  rclcpp::Publisher<nav_msgs::msg::Odometry>::SharedPtr odom_pub_;
  // rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr cmd_vel_pub_;
  rclcpp::Publisher<geometry_msgs::msg::TwistStamped>::SharedPtr cmd_vel_pub_;
  rclcpp::Publisher<geometry_msgs::msg::Pose>::SharedPtr pose_pub_;

  std::unordered_map<std::string, rclcpp::Publisher<nav_msgs::msg::Odometry>::SharedPtr> obstacle_odom_pubs_;
  // std::unordered_map<std::string, rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr> obstacle_cmd_vel_pubs_;
  std::unordered_map<std::string, rclcpp::Publisher<geometry_msgs::msg::TwistStamped>::SharedPtr> obstacle_cmd_vel_pubs_;
  std::unordered_map<std::string, rclcpp::Publisher<geometry_msgs::msg::Pose>::SharedPtr> obstacle_pose_pubs_;

  // Subscribers
  rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr odom_sub_;
  // rclcpp::Subscription<geometry_msgs::msg::Twist>::SharedPtr cmd_vel_sub_;
  rclcpp::Subscription<geometry_msgs::msg::TwistStamped>::SharedPtr cmd_vel_sub_;
  rclcpp::Subscription<gazebo_msgs::msg::ModelStates>::SharedPtr model_states_sub_;

  std::vector<rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr> obstacle_odom_subs_;
  // std::vector<rclcpp::Subscription<geometry_msgs::msg::Twist>::SharedPtr> obstacle_cmd_vel_subs_;
  std::vector<rclcpp::Subscription<geometry_msgs::msg::TwistStamped>::SharedPtr> obstacle_cmd_vel_subs_;
};

int main(int argc, char *argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<WheelchairBridge>());
  rclcpp::shutdown();
  return 0;
}