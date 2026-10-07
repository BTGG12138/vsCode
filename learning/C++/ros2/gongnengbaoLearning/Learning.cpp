#include "rclcpp/rclcpp.hpp"
class PersonNode : public rclcpp::Node
{
    private:
        std::string name;
        int age;
    public:
    PersonNode(const std::string &node_name,const std::string &name,const int &age)
    :Node(node_name)
    {
        this->name=name;
        this->age=age;
    };
    void eat(const std::string &food_name)
    {
        RCLCPP_INFO(this->get_logger(),"Im %s,%d years old,love to eat %s",this->name.c_str(),
        this->age,food_name.c_str());
    };
};
int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<PersonNode>("jiedian_learning_node","fengcheng",48);
    RCLCPP_INFO(node->get_logger(), "Node has been started.");
    node->eat("fish soup");
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}