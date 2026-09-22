#include<iostream>
#include<opencv2/opencv.hpp>

static void track(int lightDivide,void* src00)
{
    cv::Mat src01=*((cv::Mat*)src00);
    cv::Mat src02=cv::Mat::zeros(src01.size(),src01.type());
    cv::Mat src03=cv::Mat::zeros(src01.size(),src01.type());
    src02=cv::Scalar(lightDivide,lightDivide,lightDivide);
    cv::add(src01,src02,src03);
    cv::imshow("result",src03);
}

int main()
{
    cv::Mat src01,src02,src03;
    src01=cv::imread("C:\\opencv\\opencv\\12138.bmp");
    cv::namedWindow("result",cv::WINDOW_AUTOSIZE);
    cv::createTrackbar("Value","result",nullptr,50,track,(void*)(&src01));
    cv::setTrackbarPos("Value", "result", 5);
    cv::waitKey(0);
    system("pause");
    return 0;
}
