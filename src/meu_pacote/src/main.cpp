#include "rclcpp/rclcpp.hpp"

class OlaMundo : public rclcpp::Node
{
public:
    OlaMundo() : Node("ola_mundo")
    {
        RCLCPP_INFO(this->get_logger(), "Olá Mundo do ROS 2!");
    }
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<OlaMundo>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}

