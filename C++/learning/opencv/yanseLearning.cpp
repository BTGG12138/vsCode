#include <iostream>cmap_list
#include <opencv2/opencv.hpp>

int main()
{
    cv::Mat src01,src02,src03;
    src01=cv::imread("C:\\opencv\\opencv\\12138.bmp");
    src02=cv::Mat::zeros(src01.size(),src01.type());
    cv::namedWindow("result",cv::WINDOW_AUTOSIZE);
    cv::imshow("result",src01);
    cv::waitKey(0);

    int COLORMAP []={
    cv::COLORMAP_AUTUMN,
    cv::COLORMAP_BONE,
    cv::COLORMAP_JET,
    cv::COLORMAP_WINTER,
    cv::COLORMAP_RAINBOW,
    cv::COLORMAP_OCEAN,
    cv::COLORMAP_SUMMER,
    cv::COLORMAP_SPRING,
    cv::COLORMAP_COOL,
    cv::COLORMAP_HSV,
    cv::COLORMAP_PINK,
    cv::COLORMAP_HOT,
    cv::COLORMAP_PARULA,
    cv::COLORMAP_MAGMA,
    cv::COLORMAP_INFERNO,
    cv::COLORMAP_PLASMA,
    cv::COLORMAP_VIRIDIS,
    cv::COLORMAP_CIVIDIS,
    cv::COLORMAP_TWILIGHT,
    },
    count=0;
    while(1)
    {
        char key=cv::waitKey(200);
        if(key=='r')
        {
            break;
        }
        cv::applyColorMap(src01,src02,COLORMAP [count++%19]);
        cv::imshow("result",src02);
    }
    return 0;
}