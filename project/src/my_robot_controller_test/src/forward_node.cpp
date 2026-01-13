#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"

class ForwardController : public rclcpp::Node
{
public:
    ForwardController() : Node("forward_controller")
    {
        // Criar o publisher para /cmd_vel (o robô do Gazebo escuta neste tópico)
        publisher_ = this->create_publisher<geometry_msgs::msg::Twist>("cmd_vel", 10);
        
        // Timer que publica a cada 100ms
        // timer_ = this->create_wall_timer(
        //    std::chrono::milliseconds(100),
        //   std::bind(&ForwardController::publish_velocity, this));
        
        RCLCPP_INFO(this->get_logger(), "/cmd_vel ligado");
    }

private:
    void publish_velocity()
    {
        auto message = geometry_msgs::msg:: Twist();
        
        // Velocidade linear para frente (ajuste o valor conforme necessário)
        message.linear.x = 1.5;   // 0.5 m/s para frente
        message.linear. y = 0.0;
        message.linear.z = 0.0;
        
        // Sem rotação (para andar reto)
        message.angular.x = 0.0;
        message.angular.y = 0.0;
        message.angular.z = 0.0;  // Se quiser girar, mude este valor
        
        publisher_->publish(message);
    }
    
    rclcpp:: Publisher<geometry_msgs::msg:: Twist>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std:: make_shared<ForwardController>());
    rclcpp::shutdown();
    return 0;
}
