#include <iostream>
#include <opencv2/opencv.hpp>
#include <cstdlib>

int main()
{
    cv::Mat src=cv::imread("C:\\opencv\\opencv\\12138.bmp");

    if(src.empty())
    {
        std::cout<<"can not read"<<std::endl;
        system("pause");
        return 1;
    }
    cv::namedWindow("mc",cv::WINDOW_AUTOSIZE);
    cv::imshow("mc",src);
    cv::Mat gray,hsv;
    cv::cvtColor(src,hsv,cv::COLOR_BGR2HSV);
    cv::cvtColor(src,gray,cv::COLOR_BGR2GRAY);
    cv::imshow("HSV",hsv);
    cv::imshow("GRAY",gray);
    cv::waitKey(0);
    system("pause");
    return 0;
}