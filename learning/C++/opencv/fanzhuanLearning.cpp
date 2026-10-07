#include<iostream>
#include<opencv2/opencv.hpp>

int main()
{
    cv::Mat src00;
    src00=cv::imread("C:\\opencv\\opencv\\12138.bmp");
    cv::namedWindow("result",cv::WINDOW_AUTOSIZE);
    cv::imshow("result",src00);
    while(1)
    {
        char key=cv::waitKey(10);
        if(key=='q')
        {
            break;
        }
        if(key=='w')
        {
            cv::flip(src00,src00,0);
            cv::imshow("result",src00);
        }
        if(key=='e')
        {
            cv::flip(src00,src00,1);
            cv::imshow("result",src00);
        }
    }
    return 0;
}