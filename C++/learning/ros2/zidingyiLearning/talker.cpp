#include "rclcpp/rclcpp.hpp"
#include "cpp_demo/msg/student.hpp"   // 自定义消息头文件

using namespace std::chrono_literals;
using cpp_demo::msg::Student;

class MinimalPublisher : public rclcpp::Node
{
public:
    MinimalPublisher()
    : Node("student_publisher"), count_(0)
    {
        // 创建发布者，话题名 topic_stu
        publisher_ = this->create_publisher<Student>("topic_stu", 10);
        // 500ms定时器，周期性发布消息
        timer_ = this->create_wall_timer(500ms, std::bind(&MinimalPublisher::timer_callback, this));
    }

private:
    void timer_callback()
    {
        auto stu = Student();
        stu.name = "张三";
        stu.age = count_++;
        stu.height = 1.65;
        RCLCPP_INFO(this->get_logger(),"学生信息:name=%s,age=%d,height=%.2f", stu.name.c_str(),stu.age,stu.height);
        publisher_->publish(stu);
    }

    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<Student>::SharedPtr publisher_;
    size_t count_;
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<MinimalPublisher>());
    rclcpp::shutdown();
    return 0;
}
