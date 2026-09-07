#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

// std::placeholders::_1：占位符，代表回调收到的消息参数
using std::placeholders::_1;

class MinimalSubscriber : public rclcpp::Node
{
public:
    MinimalSubscriber()
    : Node("minimal_subscriber")
    {
        // 创建订阅者：话题名topic，队列10，绑定回调函数topic_callback
        subscription_ = this->create_subscription<std_msgs::msg::String>(
            "topic",
            10,
            std::bind(&MinimalSubscriber::topic_callback, this, _1)
        );
    }

private:
    // 订阅回调：收到消息自动调用，msg为收到的消息引用
    void topic_callback(const std_msgs::msg::String & msg) const
    {
        RCLCPP_INFO(this->get_logger(), "订阅的消息: '%s'", msg.data.c_str());
    }

    // 订阅者智能指针对象
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<MinimalSubscriber>());
    rclcpp::shutdown();
    return 0;
}
