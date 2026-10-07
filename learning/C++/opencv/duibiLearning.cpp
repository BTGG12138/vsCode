#include<iostream>
#include<opencv2/opencv.hpp>

static void lightTrack(int light,void* src00)
{
    cv::Mat src01=*((cv::Mat*)src00);
    cv::Mat src02=cv::Mat::zeros(src01.size(),src01.type());
    cv::Mat src03=cv::Mat::zeros(src01.size(),src01.type());
    cv::addWeighted(src01,1.0,src02,0,light,src03);
    cv::imshow("duibi",src03);
}

static void contrastTrack(int contrast,void* src00)
{
    cv::Mat src01=*((cv::Mat*)src00);
    cv::Mat src02=cv::Mat::zeros(src01.size(),src01.type());
    cv::Mat src03=cv::Mat::zeros(src01.size(),src01.type());
    double contrastNum=contrast/100.0;
    cv::addWeighted(src01,contrastNum,src02,0.0,0,src03);
    cv::imshow("duibi",src03);
}
int main()
{
    cv::Mat src01=cv::imread("C:\\opencv\\opencv\\12138.bmp");
    cv::namedWindow("duibi",cv::WINDOW_AUTOSIZE);
    cv::createTrackbar("light","duibi",nullptr,100,lightTrack,(void*)(&src01));
    cv::setTrackbarPos("light", "duibi", 50);
    cv::createTrackbar("contrast","duibi",nullptr,200,contrastTrack,(void*)(&src01));
    cv::setTrackbarPos("contrast", "duibi", 100);
    cv::waitKey(0);
    system("pause");
    return 0;
}