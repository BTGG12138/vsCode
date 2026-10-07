#include<iostream>
#include<opencv2/opencv.hpp>

int main()
{
    cv::Mat src011,src012,src02,src03,src04;
    src011=cv::imread("C:\\opencv\\opencv\\12147.bmp");
    cv::namedWindow("mask",cv::WINDOW_NORMAL);
    cv::namedWindow("result",cv::WINDOW_NORMAL);
    cv::cvtColor(src011,src012,cv::COLOR_BGR2HSV);
    inRange(src012,cv::Scalar(0,0,0),cv::Scalar(179,255,60),src02);
    cv::imshow("mask",src02);
    cv::bitwise_not(src02,src03);

    src04=cv::Mat::zeros(src011.size(),src011.type());
    src04.setTo(cv::Scalar(0,117,64));
    src011.copyTo(src04,src03);
    /*
    src011（原图图标） → 复制到 src04（绿色画布）
    规则看mask(src03):
        mask像素=255(图标位置)：复制原图，保留图标原样
        mask像素=0(背景位置)：不复制，src04保持绿色不变
    */
    cv::imshow("result",src04);

    cv::waitKey(0);
    system("pause");
    return 0;
}
