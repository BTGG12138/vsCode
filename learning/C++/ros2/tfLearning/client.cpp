#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/transform_stamped.hpp"
#include "tf2/LinearMath/Quaternion.h"
#include "tf2_geometry_msgs/tf2_geometry_msgs.hpp"
#include "tf2_ros/transform_listener.h"
#include "tf2/utils.h"
#include "tf2_ros/buffer.h"
class TF : public rclcpp::Node
{
private:
    std::shared_ptr<tf2_ros::TransformListener> listener_;
    rclcpp::TimerBase::SharedPtr timer_;
    std::shared_ptr<tf2_ros::Buffer> buffer_;
public:
    TF():Node("client_tf")
{
    this->buffer_=std::make_shared<tf2_ros::Buffer>(this->get_clock());
    this->listener_=std::make_shared<tf2_ros::TransformListener>(*buffer_,this);
    timer_=create_wall_timer(std::chrono::seconds(1),std::bind(&TF::listen,this));
}
    void listen()
    {
        try
        {
            const auto transform=buffer_->lookupTransform("base_link","target_point",this->get_clock()->now(),
            rclcpp::Duration::from_seconds(0.5f));
            auto translation=transform.transform.translation;
            auto rotation=transform.transform.rotation;
            double y,p,r;
            tf2::getEulerYPR(rotation,y,p,r);
            RCLCPP_INFO(get_logger(),"平移:%f,%f,%f",translation.x,translation.y,translation.z);
            RCLCPP_INFO(get_logger(),"旋转%F,%f,%f",y,p,r);
        }
        catch(const std::exception& e)
        {
            RCLCPP_INFO(get_logger(),"%s",e.what());
        }
    }
};
int main(int argc,char **argv)
{
    rclcpp::init(argc,argv);
    auto node=std::make_shared<TF>();
    rclcpp::spin(node);
    rclcpp::shutdown();
}
