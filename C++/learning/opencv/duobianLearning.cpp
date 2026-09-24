#include<iostream>
#include<opencv2/opencv.hpp>

int main()
{
    cv::RNG rng(time(0));
    cv::Mat src01,src02,src03;
    bool isW=false;
    int z=0;
    int num=rng.uniform(2,8);
    std::vector<std::vector<cv::Point>> pointss;

    src01=cv::Mat::zeros(cv::Size(512,512),CV_8UC3);
    cv::imshow("result",src01);
    while(1)
    {
        char key=cv::waitKey(10);
        if(key=='q'||z==num)
        {
            break;
        }
        if(key=='w'&&isW)
        {
            cv::drawContours(src01,pointss,z++,cv::Scalar(255,0,0),-1);
            cv::imshow("result",src01);
        }
        if(key=='e'&&!isW)
        {
            isW=true;
            std::vector<cv::Point> points;
            int x,y;
            cv::Point p;
            for(int j=0;j<num;j++)
            {
                for(int i=0;i<4;i++)
                {
                    x=rng.uniform(16,496);
                    y=rng.uniform(16,496);
                    p={x,y};
                    points.push_back(p);
                }
                pointss.push_back(points);
            }
        }
    }
    return 0;
}