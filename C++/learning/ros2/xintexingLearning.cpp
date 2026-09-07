#include <iostream>
#include <memory>
#include <algorithm>
#include <functional>   
#include <string>
void part1()
{
    auto p1 = std::make_shared<std::string>("This is a str."); 
    // std::make_shared<数据类型/类>(参数); 返回值，对应类的共享指针 
    //std::shared_ptr<std::string> 写成 auto
    std::cout<< "p1的引用计数:"<< p1.use_count() << ",指向内存地址:"<< p1.get() << std::endl; // 1
    auto p2 = p1;
    std::cout<< "p1的引用计数:"<< p1.use_count() << ",指向内存地址:"<< p1.get() << std::endl; // 2
    std::cout<< "p2的引用计数:"<< p2.use_count() << ",指向内存地址:"<< p2.get() << std::endl; // 2
    p1.reset(); // 释放引用，不指向 "This is a str." 所在内存
    std::cout<< "p1的引用计数:"<< p1.use_count() << ",指向内存地址:"<< p1.get() << std::endl; // 0
    std::cout<< "p2的引用计数:"<< p2.use_count() << ",指向内存地址:"<< p2.get() << std::endl; // 2-1=1
    std::cout<< "p2的指向内存地址数据:"<< p2->c_str() << std::endl; 
    // 调用成员方法 "This is a str."
    system("pause");
}
void part2()
{
    auto add = [](int a, int b) -> int
    { return a + b; };
    int sum = add(200, 50);
    auto print_sum = [&]() -> void
    {
        std::cout << sum << std::endl;
    };
    print_sum();
    std::cout<<sum<<std::endl;
    system("pause");
}
void save_with_free_fun(const std::string& file_name)
{
    std::cout<<"自由函数: "<<file_name<<std::endl;
}
class FileSave
{
public:
    FileSave(/* args */) = default;
    ~FileSave() = default;
    void save_with_member_fun(const std::string &file_name)
    {
        std::cout << "成员方法:" << file_name << std::endl;
    }
};
void part3()
{
    FileSave file_save;
    // Lambda函数
    auto save_with_lambda_fun = [](const std::string &file_name) -> void 
    {
        std::cout << "Lambda函数:" << file_name << std::endl;
    };
    std::function<void(const std::string&)> save1 = save_with_free_fun;
    std::function<void(const std::string&)> save2 = save_with_lambda_fun;
    std::function<void(const std::string&)> save3 
    = std::bind(&FileSave::save_with_member_fun,&file_save,std::placeholders::_1);
    save1("file.txt");
    save2("file.txt");
    save3("file.txt");
    system("pause");
}
int main()
{
    //part1();
    //part2();
    part3();
}
