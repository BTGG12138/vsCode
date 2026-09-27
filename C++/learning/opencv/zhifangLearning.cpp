#include <iostream>
#include <opencv2/opencv.hpp>

int main()
{
    cv::Mat src00;
    src00=cv::imread("C:\\opencv\\opencv\\12138.bmp");
    cv::namedWindow("mc",cv::WINDOW_AUTOSIZE);
    cv::imshow("mc",src00);

    std::vector<cv::Mat> bgr;
    split(src00,bgr);
    int channels[1]={0};
    int bins[1]={256};
    float hranges[2]={0,256};
    const float *ranges[1]={hranges};
    cv::Mat b,g,r;
    cv::calcHist(&bgr[0],1,0,cv::noArray(),b,1,bins,ranges);
    cv::calcHist(&bgr[1],1,0,cv::noArray(),g,1,bins,ranges);
    cv::calcHist(&bgr[2],1,0,cv::noArray(),r,1,bins,ranges);

    int row=512;
    int col=512;
    int bin=cvRound((double)col/bins[0]);
    cv::Mat src01=cv::Mat::zeros(row,col,CV_8UC3);
    cv::normalize(b,b,0,src01.rows,cv::NORM_MINMAX,-1,cv::Mat());
    cv::normalize(g,g,0,src01.rows,cv::NORM_MINMAX,-1,cv::Mat());
    cv::normalize(r,r,0,src01.rows,cv::NORM_MINMAX,-1,cv::Mat());
    for(int i=1;i<bins[0];i++)
    {
        cv::line(src01,cv::Point(bin*(i-1),col-cvRound(b.at<float>(i-1))),
        cv::Point(bin*(i),row-cvRound(b.at<float>(i))),cv::Scalar(255,0,0),2,8,0);
        cv::line(src01,cv::Point(bin*(i-1),col-cvRound(g.at<float>(i-1))),
        cv::Point(bin*(i),row-cvRound(g.at<float>(i))),cv::Scalar(0,255,0),2,8,0);
        cv::line(src01,cv::Point(bin*(i-1),col-cvRound(r.at<float>(i-1))),
        cv::Point(bin*(i),row-cvRound(r.at<float>(i))),cv::Scalar(0,0,255),2,8,0);
    }
    cv::namedWindow("result",cv::WINDOW_AUTOSIZE);
    imshow("result",src01);
    cv::waitKey(0);
    return 0;
}