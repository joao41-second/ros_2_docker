#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"

using namespace std::chrono_literals;

class SquareMotion : public rclcpp::Node
{
public:
  SquareMotion() : Node("square_motion")
  {
    publisher_ = this->create_publisher<geometry_msgs::msg::Twist>("cmd_vel", 10);
    timer_ = this->create_wall_timer(100ms, std::bind(&SquareMotion::control_loop, this));
  }

private:
  void control_loop()
  {
    geometry_msgs::msg::Twist msg;

    if (step_ < 50) {
      // Anda para frente
      msg.linear.x = 0.3;
      msg.angular.z = 0.0;
    } else if (step_ < 70) {
      // Gira 90 graus
      msg.linear.x = 0.0;
      msg.angular.z = 0.8;
    } else {
      step_ = 0;
      side_++;
    }

    if (side_ == 4) {
      msg.linear.x = 0.0;
      msg.angular.z = 0.0;
    }

    publisher_->publish(msg);
    step_++;
  }

  rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher_;
  rclcpp::TimerBase::SharedPtr timer_;
  int step_ = 0;
  int side_ = 0;
};

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<SquareMotion>());
  rclcpp::shutdown();
  return 0;
}

