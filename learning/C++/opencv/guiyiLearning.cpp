#include<iostream>
#include<opencv2/opencv.hpp>

int main()
{
    cv::Mat src00,src01;
    src00=cv::imread("C:\\opencv\\opencv\\12138.bmp");
    cv::namedWindow("result",cv::WINDOW_AUTOSIZE);

    std::cout << src00.type() << std::endl;
    src00.convertTo(src00, CV_32F);
    std::cout << src00.type() << std::endl;
    normalize(src00,src01, 1.0, 0, cv::NORM_MINMAX);
    std::cout <<src01.type() << std::endl;
    cv::imshow("result",src01);
    cv::waitKey(0);
    return 0;
}