#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"

class turtle:public rclcpp::Node
{   
    private:
        rclcpp::TimerBase::SharedPtr timer_;
        rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher_;
        void time_call_back()
        {
            auto msg=geometry_msgs::msg::Twist();
            msg.linear.x=1.0;
            msg.angular.z=0.5;
            publisher_->publish(msg);
        }
    public:
        explicit turtle ():Node("turtle_node")
        {
            publisher_=this->create_publisher<geometry_msgs::msg::Twist>("/turtle1/cmd_vel",10);
            timer_=this->create_wall_timer(std::chrono::milliseconds(500),
            std::bind(&turtle::time_call_back,this));
        }
};
int main(int argc,char**argv)
{
    rclcpp::init(argc,argv);
    auto node=std::make_shared<turtle>();
    rclcpp::spin(node);
    rclcpp::shutdown();
}