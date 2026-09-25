#include<iostream>
#include<opencv2/opencv.hpp>

cv::Mat src00,src01;

void callMouse(int event,int x,int y,int flags,void*userdata)
{
    if(event==cv::EVENT_MOUSEWHEEL)
    {
        double num=1.0;
        int flag = cv::getMouseWheelDelta(flags);
        if(flag > 0)
        {
            num*=1.1;
        }
        if(flag < 0)
        {
            num*=0.9;
        }
        //resize(src00,src00,cv::Size(src00.cols*num,src00.rows*num),0,0,cv::INTER_LINEAR);
        resize(src00,src01,cv::Size(),num,num,cv::INTER_LINEAR);
        cv::imshow("result",src01);
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