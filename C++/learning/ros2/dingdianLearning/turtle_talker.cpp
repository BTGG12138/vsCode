#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "turtlesim/msg/pose.hpp"
class turtle:public rclcpp::Node
{   
    private:
        rclcpp::TimerBase::SharedPtr timer_;
        rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher_;
        rclcpp::Subscription<turtlesim::msg::Pose>::SharedPtr subscription_;
        double x_target=11.0;
        double y_target=11.0;
        double angel_k_target=1.2;
        double speed_k_target=0.4;
        double speed_max_target=1.0;
        void on_pose_received(const turtlesim::msg::Pose::SharedPtr pose)
        {
            auto x_now=pose->x;
            auto y_now=pose->y;
            auto theta_now=pose->theta;
            RCLCPP_INFO(get_logger(),"当前朝向x-%f,y=%f,theta=%f",x_now,y_now,theta_now);
            auto distance=std::sqrt(
            (x_target-x_now)*(x_target-x_now)+
            (y_target-y_now)*(y_target-y_now) 
            );
            double angle_minus=std::atan2((y_target-y_now),(x_target-x_now))-theta_now;
            while(angle_minus>M_PI)angle_minus-=2*M_PI;
            while(angle_minus<-M_PI)angle_minus+=2*M_PI;
            geometry_msgs::msg::Twist msg;
            if(distance > 0.01)
            {
                msg.angular.z=angel_k_target*angle_minus;
                double speed_k_now=1.0-std::fabs(angle_minus)/M_PI;
                if(speed_k_now<0) speed_k_now=0;
                msg.linear.x=speed_k_now*speed_k_target*distance;
                if(msg.linear.x>speed_max_target) msg.linear.x=speed_max_target;
            }
            else
            {
                msg.linear.x=0.0;
                msg.angular.z=0.0;
            }
            publisher_->publish(msg);
        }

    public:
        explicit turtle ():Node("turtle_node")
        {
            publisher_=this->create_publisher<geometry_msgs::msg::Twist>("/turtle1/cmd_vel",10);
            subscription_=this->create_subscription<turtlesim::msg::Pose>("/turtle1/pose",10,
            std::bind(&turtle::on_pose_received,this,std::placeholders::_1));
        }
};
int main(int argc,char**argv)
{
    rclcpp::init(argc,argv);
    auto node=std::make_shared<turtle>();
    rclcpp::spin(node);
    rclcpp::shutdown();
}