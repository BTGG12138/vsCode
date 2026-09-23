#include<iostream>
#include<opencv2/opencv.hpp>

int main()
{
    cv::Mat src01,src02,src03;
    bool isW=false;
    src01=cv::Mat::zeros(cv::Size(512,512),CV_8UC3);
    cv::imshow("result",src01);
    cv::RNG rng(time(0));
    while(1)
    {
        char key=cv::waitKey(10);
        int x1=rng.uniform(16,496);
        int y1=rng.uniform(16,496);
        int x2=rng.uniform(16,496);
        int y2=rng.uniform(16,496);
        if(key=='q')
        {
            break;
        }
        if(key=='w')
        {
            isW=!isW;
        }
        if(isW)
        {
            cv::line(src01,cv::Point(x1,y1),cv::Point(x2,y2),cv::Scalar(x1%255,y1%255,x2%255),8,cv::LINE_AA);
            cv::imshow("result",src01);
        }
        if(key=='e')
        {
            cv::line(src01,cv::Point(x1,y1),cv::Point(x2,y2),cv::Scalar(x1%255,y1%255,x2%255),8,cv::LINE_AA);
            cv::imshow("result",src01);
        }
    }
    return 0;
}