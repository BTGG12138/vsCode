#include "rclcpp/rclcpp.hpp"
#include "cpp_demo/msg/student.hpp"

using cpp_demo::msg::Student;

class MinimalSubscriber : public rclcpp::Node
{
public:
    MinimalSubscriber()
    : Node("student_subscriber")
    {
        // 创建订阅，话题名 topic_stu，和发布端一致
        subscription_ = this->create_subscription<Student>(
            "topic_stu",
            10,
            std::bind(&MinimalSubscriber::topic_callback, 
            this, std::placeholders::_1)
        );
    }

private:
    // 回调函数收到消息自动执行，msg就是收到的消息对象
    void topic_callback(const Student & msg) const
    {
        RCLCPP_INFO(this->get_logger(), "订阅的学生消息：name=%s,age=%d,height=%.2f",
        msg.name.c_str(), msg.age, msg.height);
    }
    rclcpp::Subscription<Student>::SharedPtr subscription_;
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<MinimalSubscriber>());
    rclcpp::shutdown();
    return 0;
}
