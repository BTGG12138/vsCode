#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/transform_stamped.hpp"
#include "tf2/LinearMath/Quaternion.h"
#include "tf2_geometry_msgs/tf2_geometry_msgs.hpp"
#include "tf2_ros/static_transform_broadcaster.h"
class StaticTF : public rclcpp::Node
{
private:
    std::shared_ptr<tf2_ros::StaticTransformBroadcaster> broadcaster_;
public:
    StaticTF():Node("server01_tf")
{
    this->broadcaster_=std::make_shared<tf2_ros::StaticTransformBroadcaster>(this);
    this->publish();
}
    void publish()
    {
        geometry_msgs::msg::TransformStamped transform;
        transform.header.stamp=this->get_clock()->now();
        transform.header.frame_id="map";
        transform.child_frame_id="target_point";
        transform.transform.translation.x=5.0;
        transform.transform.translation.y=3.0;
        transform.transform.translation.z=0.0;
        tf2::Quaternion quaternion;
        quaternion.setRPY(0.0,0.0,60*M_PI/180.0);
        transform.transform.rotation=tf2::toMsg(quaternion);
        this->broadcaster_->sendTransform(transform);
    }
};
int main(int argc,char **argv)
{
    rclcpp::init(argc,argv);
    auto node=std::make_shared<StaticTF>();
    rclcpp::spin(node);
    rclcpp::shutdown();
}
