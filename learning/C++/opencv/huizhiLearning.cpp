#include<iostream>
#include<opencv2/opencv.hpp>

int main()
{
    cv::Mat src011,src012,src02,src03,src04;
    src011=cv::imread("C:\\opencv\\opencv\\12138.bmp");

    cv::Rect rect;
    rect.x=330;
    rect.y=320;
    rect.width=400;
    rect.height=210;
    cv::rectangle(src011,rect,cv::Scalar(0,0,255),0,8,0);
    cv::imshow("mc",src011);

    cv::waitKey(0);
    system("pause");
    return 0;
}