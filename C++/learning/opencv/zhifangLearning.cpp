#include <iostream>
#include <opencv2/opencv.hpp>

int main()
{
    cv::Mat src01,src02,src03;
    src01=cv::imread("C:\\opencv\\opencv\\12138.bmp");
    cv::namedWindow("result",cv::WINDOW_AUTOSIZE);
    cv::imshow("result",src01);
    
    cv::waitKey(0);
    return 0;
}