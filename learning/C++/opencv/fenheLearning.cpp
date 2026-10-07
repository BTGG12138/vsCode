#include<iostream>
#include<opencv2/opencv.hpp>

int main()
{
    cv::Mat src01,src02,src03;
    src01=cv::imread("C:\\opencv\\opencv\\12138.bmp");
    std::vector<cv::Mat> mc;
    //split(src01,mc);
    //cv::imshow("blue",mc[0]);
    //cv::imshow("green",mc[1]);
    //cv::imshow("red",mc[2]);

    split(src01,mc);
    mc[0]=cv::Mat::zeros(src01.size(), CV_8UC1);
    mc[1]=cv::Mat::zeros(src01.size(), CV_8UC1);
    cv::merge(mc,src02);
    cv::imshow("red",src02);

    split(src01,mc);
    mc[0]=cv::Mat::zeros(src01.size(), CV_8UC1);
    mc[2]=cv::Mat::zeros(src01.size(), CV_8UC1);
    cv::merge(mc,src02);
    cv::imshow("green",src02);

    src02=cv::Mat::zeros(src01.size(),src01.type());
    int channelNum01[]={0,0};
    cv::mixChannels(&src01,1,&src02,1,channelNum01,1);
    cv::imshow("blue",src02);

    int channelNum02[]={1,2,2,0,0,1};
    cv::mixChannels(&src01,1,&src02,1,channelNum02,3);
    cv::imshow("mix",src02);
    cv::waitKey(0);
    system("pause");
    return 0;
}