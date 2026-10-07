#include<iostream>
#include<opencv2/opencv.hpp>
int main()
{
    cv::Mat src01,src02,src03;
    src02=cv::Mat::zeros(cv::Size(256,256),CV_8UC3);
    src03=cv::Mat::zeros(cv::Size(256,256),CV_8UC3);
    cv::rectangle(src02,cv::Rect(100,100,80,80),cv::Scalar(255,255,0),-1,cv::LINE_8,0);
    cv::rectangle(src03,cv::Rect(150,150,80,80),cv::Scalar(0,255,255),-1,cv::LINE_8,0);
    cv::imshow("src02",src02);
    cv::imshow("src03",src03);

    cv::Mat xor,and,or;

    cv::bitwise_xor(src02,src03,xor);
    cv::imshow("xor",xor);

    cv::bitwise_and(src02,src03,and);
    cv::imshow("and",and);

    cv::bitwise_or(src02,src03,or);
    cv::imshow("or",or);

    cv::waitKey(0);
    system("pause");
    return 0;
}
 