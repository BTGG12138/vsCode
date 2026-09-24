#include<iostream>
#include<opencv2/opencv.hpp>

bool isDown=false;
cv::Point p1(0,0),p2(0,0);
cv::Mat src00;

void callMouse(int event,int x,int y,int flags,void*userdata)
{
    cv::Mat src01=*((cv::Mat*)userdata);
    cv::Mat src02=src01.clone();
    if(event==cv::EVENT_LBUTTONDOWN&&!isDown)
    {
        p1=cv::Point(x,y);
        isDown=true;
    }
    if(event==cv::EVENT_MOUSEMOVE&&isDown)
    {
        p2=cv::Point(x,y);
        cv::rectangle(src02,cv::Rect(p1,p2),cv::Scalar(0,0,255),2);
        cv::imshow("result",src02);
    }
    if(event==cv::EVENT_LBUTTONUP&&isDown)
    {
        isDown=false;
        p2=cv::Point(x,y);
        cv::rectangle(src02,cv::Rect(p1,p2),cv::Scalar(0,0,255),2);
        src02.copyTo(src00); // 将带框图像复制回原图，永久保留
        cv::imshow("result",src00);
    }
}
int main()
{
    src00=cv::imread("C:\\opencv\\opencv\\12138.bmp");
    cv::namedWindow("result",cv::WINDOW_AUTOSIZE);
    cv::setMouseCallback("result",callMouse,(void*)(&src00));
    cv::imshow("result",src00);
    cv::waitKey(0);
    return 0;
}