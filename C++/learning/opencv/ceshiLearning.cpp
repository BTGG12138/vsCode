#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
    // 打开默认摄像头，0=本机内置摄像头；CAP_DSHOW是Windows专用后端，解决Windows经常打不开摄像头的坑
    VideoCapture cap(0, CAP_DSHOW);

    // 判断摄像头是否成功打开
    if (!cap.isOpened())
    {
        cout << "❌ 摄像头打开失败！检查权限/设备占用" << endl;
        return -1;
    }
    cout << "✅ 摄像头打开成功！按 q 关闭窗口" << endl;

    Mat frame;
    while (true)
    {
        // 读取一帧画面
        cap >> frame;
        if (frame.empty())
        {
            cout << "读取画面失败" << endl;
            break;
        }

        // 显示画面，窗口名字叫 Camera
        imshow("Camera", frame);

        // waitKey(1) 等待1ms；按q退出
        int key = waitKey(1) & 0xFF;
        if (key == 'q')
        {
            break;
        }
    }

    // 释放摄像头资源 + 销毁窗口（非常重要，不然摄像头一直被占用）
    cap.release();
    destroyAllWindows();
    return 0;
}
