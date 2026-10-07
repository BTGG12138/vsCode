#include <iostream>
#include <opencv2/opencv.hpp>

int main()
{
    cv::Mat src01=cv::imread("C:\\opencv\\opencv\\12138.bmp");
    if(src01.empty())
    {
        std::cout<<"can not read"<<std::endl;
        return 1;
    }
    cv::Mat src02=src01.clone(),src03;
    int row=src01.rows;
    int col=src01.cols;
    src02=src01+cv::Scalar(50,50,50);
    src03=cv::Mat::zeros(cv::Size(col,row),CV_8UC3);
    src03.setTo(cv::Scalar(5,5,5));
    divide(src01,src03,src03);
    cv::imshow("origin",src01);
    cv::imshow("plus",src02);
    cv::imshow("divide",src03);
    cv::waitKey(0);
    system("pause");
    return 0;
}