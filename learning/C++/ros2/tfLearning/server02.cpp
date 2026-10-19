#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/transform_stamped.hpp"
#include "tf2/LinearMath/Quaternion.h"
#include "tf2_geometry_msgs/tf2_geometry_msgs.hpp"
#include "tf2_ros/transform_broadcaster.h"
class TF : public rclcpp::Node
{
private:
    std::shared_ptr<tf2_ros::TransformBroadcaster> broadcaster_;
    rclcpp::TimerBase::SharedPtr timer_;
public:
    TF():Node("server02_tf")
{
    this->broadcaster_=std::make_shared<tf2_ros::TransformBroadcaster>(this);
    timer_=create_wall_timer(std::chrono::milliseconds(100),std::bind(&TF::publish,this));
}
    void publish()
    {
        geometry_msgs::msg::TransformStamped transform;
        transform.header.stamp=this->get_clock()->now();
        transform.header.frame_id="map";
        transform.child_frame_id="base_link";
        transform.transform.translation.x=2.0;
        transform.transform.translation.y=1.0;
        transform.transform.translation.z=2.0;
        tf2::Quaternion quaternion;
        quaternion.setRPY(0.0,0.0,60*M_PI/180.0);
        transform.transform.rotation=tf2::toMsg(quaternion);
        this->broadcaster_->sendTransform(transform);
    }
};
int main(int argc,char **argv)
{
    rclcpp::init(argc,argv);
    auto node=std::make_shared<TF>();
    rclcpp::spin(node);
    rclcpp::shutdown();
}
