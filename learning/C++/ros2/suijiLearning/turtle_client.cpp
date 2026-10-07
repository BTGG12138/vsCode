#include "rclcpp/rclcpp.hpp"
#include "cpp_demo/srv/turtle_server.hpp"
#include <cstdlib>
#include <ctime>
using TurtleServer=cpp_demo::srv::TurtleServer;

class Turtle_Client : public rclcpp::Node
{
    public:
    Turtle_Client() : Node("turtle_client_node")
    {
    client_=this->create_client<TurtleServer>("turtle_server");
    timer_=this->create_wall_timer(std::chrono::milliseconds(500),[this]()->void
    {
        if(!this->client_->service_is_ready())
        {
            RCLCPP_INFO(this->get_logger(),"等待服务中");
            return;
        }
        if(!isSend)
        {
            return;
        }
        auto request=std::make_shared<TurtleServer::Request>();
        std::srand((unsigned int)time(NULL)); // 设置随机种子
        request->x_target=rand()%4+4;
        request->y_target=rand()%4+4;
        isSend=false;
        this->client_->async_send_request(request,[this,request]
        (rclcpp::Client<TurtleServer>::SharedFuture future_result)->void {
            auto response=future_result.get();
            if(response->result==TurtleServer::Response::SUCCESS)
            {
                RCLCPP_INFO(this->get_logger(),"到达目的地");
                RCLCPP_INFO(this->get_logger(),"新目的地为X%f,Y%f",request->x_target,request->y_target);
            }
            isSend=true;
        });
    });
}
    private:

    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Client<TurtleServer>::SharedPtr client_;
    bool isSend=true;
};
int main(int argc,char**argv)
{
    rclcpp::init(argc,argv);
    auto node=std::make_shared<Turtle_Client>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}