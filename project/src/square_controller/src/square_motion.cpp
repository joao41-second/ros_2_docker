#include <chrono>
#include <memory>
#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"

using namespace std::chrono_literals;

class SquareDriver :  public rclcpp::Node
{
public:
  SquareDriver() : Node("square_driver"), state_(0)
  {
    this->declare_parameter("linear_speed", 0.5);
    this->declare_parameter("angular_speed", 0.785);
    this->declare_parameter("side_length", 1.5);
    
    linear_speed_ = this->get_parameter("linear_speed").as_double();
    angular_speed_ = this->get_parameter("angular_speed").as_double();
    side_length_ = this->get_parameter("side_length").as_double();
    
    // Calcular tempo para cada lado e rotação
    side_duration_ = side_length_ / linear_speed_;
    turn_duration_ = (3.14159 / 2.0) / angular_speed_;  // 90 graus em radianos
    
    publisher_ = this->create_publisher<geometry_msgs::msg::Twist>("cmd_vel", 10);
    timer_ = this->create_wall_timer(100ms, std:: bind(&SquareDriver::timer_callback, this));
    start_time_ = this->now();
    
    RCLCPP_INFO(this->get_logger(), "Square Driver iniciado!");
    RCLCPP_INFO(this->get_logger(), "Velocidade linear: %.2f m/s", linear_speed_);
    RCLCPP_INFO(this->get_logger(), "Velocidade angular: %.2f rad/s", angular_speed_);
    RCLCPP_INFO(this->get_logger(), "Comprimento do lado: %.2f m", side_length_);
  }

private:
  void timer_callback()
  {
    auto message = geometry_msgs::msg::Twist();
    double elapsed = (this->now() - start_time_).seconds();
    
    if (state_ == 0) {
      // Andar em frente
      message.linear.x = linear_speed_;
      message.angular.z = 0.0;
      
      if (elapsed >= side_duration_) {
        state_ = 1;
        start_time_ = this->now();
        RCLCPP_INFO(this->get_logger(), "Virando.. .");
      }
    }
    else if (state_ == 1) {
      // Rodar 90 graus
      message.linear.x = 0.0;
      message. angular.z = angular_speed_;
      
      if (elapsed >= turn_duration_) {
        state_ = 0;
        start_time_ = this->now();
        side_count_++;
        RCLCPP_INFO(this->get_logger(), "Lado %d completado", side_count_);
      }
    }
    
    publisher_->publish(message);
  }

  rclcpp::TimerBase:: SharedPtr timer_;
  rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher_;
  rclcpp::Time start_time_;
  int state_;
  int side_count_ = 0;
  double linear_speed_;
  double angular_speed_;
  double side_length_;
  double side_duration_;
  double turn_duration_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<SquareDriver>());
  rclcpp::shutdown();
  return 0;
}
