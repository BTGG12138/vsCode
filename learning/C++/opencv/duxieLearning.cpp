#include <iostream>
#include <opencv2/opencv.hpp>

int main()
{
    cv::Mat src01=cv::imread("C:\\opencv\\opencv\\12138.bmp");
    cv::imshow("mc",src01);
    cv::waitKey(0);
    int row=src01.rows;
    int col=src01.cols;
    int channel=src01.channels();
    for(int r=0;r<row;r++)
    {
        for(int c=0;c<col;c++)
        {
            if(channel==1)
            {
                int channel1=src01.at<uchar>(r,c);
                src01.at<uchar>(r,c)=255-channel1;
            }
            if(channel==3)
            {
                cv::Vec3b channel3=src01.at<cv::Vec3b>(r,c);
                src01.at<cv::Vec3b>(r,c)[0]=255-channel3[0];
                src01.at<cv::Vec3b>(r,c)[1]=255-channel3[1];
                src01.at<cv::Vec3b>(r,c)[2]=255-channel3[2];
            }
        }
    }
    cv::imshow("cm",src01);
    cv::waitKey(0);
    system("pause");
    return 0;
}