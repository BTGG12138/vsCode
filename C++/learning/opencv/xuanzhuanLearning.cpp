#include<iostream>
#include<opencv2/opencv.hpp>

int angle=0;

void callMouse(int event,int x,int y,int flags,void*userdata)
{
    int flag = cv::getMouseWheelDelta(flags);
    if(event==cv::EVENT_MOUSEWHEEL)
    {
        if(flag>0)
        {
            angle+=5;
        }
        if(flag<0)
        {
            angle-=5;
        }
    }
}
int main()
{
    cv::Mat src00,src01,src02;
    src00=cv::imread("C:\\opencv\\opencv\\12138.bmp");
    cv::namedWindow("result",cv::WINDOW_AUTOSIZE);
    cv::setMouseCallback("result",callMouse,(void*)(&src00));
    cv::imshow("result",src00);
    int col=src00.cols;
    int row=src00.rows;
    while(1)
    {
        char key=cv::waitKey(10);
        if(key=='q')
        {
            break;
        }
        src01=cv::getRotationMatrix2D(cv::Point2f(col/2,row/2),angle,1.0);
        double cos=abs(src01.at<double>(0,0));
        double sin=abs(src01.at<double>(0,1));
        int colNew=cos*col+sin*row;
        int rowNew=cos*row+sin*col;
        src01.at<double>(0,2)+=(colNew/2-col/2);
        src01.at<double>(1,2)+=(rowNew/2-row/2);
        cv::warpAffine(src00,src02,src01,cv::Size(colNew,rowNew));
        cv::imshow("result",src02);
    }
    return 0;
}