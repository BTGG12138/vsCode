#include<iostream>
#include<opencv2/opencv.hpp>

cv::Mat src01,src02,src03;

static void track(int lightDivide,void*)
{
    src02=cv::Scalar(lightDivide,lightDivide,lightDivide);
    cv::multiply(src01,src02,src03);
    cv::imshow("result",src03);
}

int main()
{
    src01=cv::imread("C:\\opencv\\opencv\\12138.bmp");
    cv::namedWindow("result",cv::WINDOW_AUTOSIZE);
    src02=cv::Mat::zeros(src01.size(),src01.type());
    src03=cv::Mat::zeros(src01.size(),src01.type());
    cv::createTrackbar("Value","result",nullptr,5,track);
    track(1, nullptr);
    cv::waitKey(0);
    system("pause");
    return 0;
}
