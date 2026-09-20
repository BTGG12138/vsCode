#include <iostream>
#include <opencv2/opencv.hpp>
#include <cstdlib>
int main()
{
    cv::Mat src01=cv::imread("C:\\opencv\\opencv\\12138.bmp");
    if(src01.empty())
    {
        std::cout<<"can not read"<<std::endl;
        return 1;
    }
    cv::Mat src02,src03,src04;
    src02=src01.clone();
    src01.copyTo(src03);
    //赋值会共享内存空间，clone和copyTo是不同的空间

    cv::imshow("01",src01);
    cv::imshow("02",src02);
    cv::imshow("03",src03);
    cv::waitKey(0);

    src04=cv::Mat::zeros(cv::Size(400,400),CV_8UC3);
    src04.setTo(cv::Scalar(48,91,78));
    //std::cout<<src04<<std::endl;
    cv::imshow("LPL",src04);
    cv::waitKey(0);

    std::cout<<"cols: "<<src04.cols<<std::endl
    <<"height: "<<src04.rows<<std::endl
    <<"channels: "<<src04.channels()<<std::endl;

    system("pause");
    return 0;
}