#include <opencv2/opencv.hpp>
#include <iostream>

int main()
{
    // 打开默认摄像头，0=本机内置摄像头；CAP_DSHOW是Windows专用后端，解决Windows经常打不开摄像头的坑
    cv::VideoCapture cap(0, cv::CAP_DSHOW);
    cv::Mat src01,src02,src03,src04;
    src02=cv::Mat::zeros(src01.size(),src01.type());
    bool isW=false;
    double light=1.0,lightAdd=0.01;
    cap >> src02;
    while (1)
    {
        // 读取一帧画面
        cap >> src01;
        int key = cv::waitKey(1);
        if(key == 'w')
        {
            isW=true;
            light+=lightAdd;
        }
        
        if(isW)
        {
            cv::addWeighted(src01,light,src01,0.0,0,src02);
            cv::imshow("Camera", src02);
        }
        else
        {
            cv::imshow("Camera", src01);
        }

        if (key == 'q')
        {
            break;
        }
    }
    // 释放摄像头资源 + 销毁窗口（非常重要，不然摄像头一直被占用）
    cap.release();
    cv::destroyAllWindows();
    return 0;
}
