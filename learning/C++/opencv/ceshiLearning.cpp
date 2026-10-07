#include <opencv2/opencv.hpp>
#include <iostream>

int main()
{
    // 打开默认摄像头，0=本机内置摄像头；CAP_DSHOW是Windows专用后端，解决Windows经常打不开摄像头的坑
    cv::VideoCapture cap(0, cv::CAP_DSHOW);
    cv::Mat frame;
    while (1)
    {
        // 读取一帧画面
        cap >> frame;
        // 显示画面，窗口名字叫 Camera
        imshow("Camera", frame);
        // waitKey(1) 等待1ms；按q退出
        int key = cv::waitKey(1) & 0xFF;
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
