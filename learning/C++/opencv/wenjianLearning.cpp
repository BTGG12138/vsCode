#include<iostream>
#include<opencv2/opencv.hpp>

int main()
{
    cv::Mat src00,src01,src02;
    cv::VideoCapture cap(0, cv::CAP_DSHOW);

    while(1)
    {
        cap.read(src00);
        cv::imshow("result",src00);
        char key=cv::waitKey(10);
        if(key=='q')
        {
            break;
        }
    }
    cap.release();
    cv::destroyAllWindows();
    return 0;
}