#include<iostream>
#include<opencv2/opencv.hpp>

int main()
{
    cv::VideoCapture capture("C:\\opencv\\opencv\\12138.mp4");
    int width=capture.get(cv::CAP_PROP_FRAME_WIDTH);
    int height=capture.get(cv::CAP_PROP_FRAME_HEIGHT);
    int count=capture.get(cv::CAP_PROP_FRAME_COUNT);
    int fps=capture.get(cv::CAP_PROP_FPS);
    std::cout<<"width"<<width<<std::endl;
    std::cout<<"height"<<height<<std::endl;
    std::cout<<"count"<<count<<std::endl;
    std::cout<<"fps"<<fps<<std::endl;
    int fourcc = cv::VideoWriter::fourcc('m','p','4','v');
    cv::VideoWriter writer("C:\\opencv\\opencv\\12147.mp4",
    fourcc,fps,cv::Size(width,height),true);

    cv::Mat src01;
    while(1)
    {
        capture.read(src01);
        if(src01.empty())
        {
            break;
        }
        cv::flip(src01,src01,1);
        writer.write(src01);
        cv::imshow("src01",src01);
        if(cv::waitKey(20) == 27)
        {
            break;
        }
    }
    capture.release();
    writer.release();
    cv::destroyAllWindows();
    cv::waitKey(0);
    return 0;
}