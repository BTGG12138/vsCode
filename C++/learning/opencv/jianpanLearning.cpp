#include <iostream>
#include <opencv2/opencv.hpp>

int main()
{
    cv::Mat src01,src02,src03;
    src01=cv::imread("C:\\opencv\\opencv\\12138.bmp");
    cv::namedWindow("result",cv::WINDOW_AUTOSIZE);
    cv::imshow("result",src01);
    cv::waitKey(0);

    src02=cv::Mat::zeros(src01.size(),src01.type());
    src02=cv::Scalar(5,5,5);
    src03=src01.clone();

    while(1)
    {
        char key=cv::waitKey(100);
        if(key=='q')
        {
            cv::cvtColor(src01,src01,cv::COLOR_BGR2GRAY);
            cv::imshow("result",src01);
        }
        if(key=='w')
        {
            cv::add(src01,src02,src01);
            cv::imshow("result",src01);
        }
        if(key=='e')
        {
            cv::addWeighted(src03,1.8,src03,0.0,0,src01);
            cv::imshow("result",src01);
        }
        if(key=='r')
        {
            break;
        }
    }

    return 0;
}