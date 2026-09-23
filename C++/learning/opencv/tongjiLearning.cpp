#include<iostream>
#include<opencv2/opencv.hpp>

int main()
{
    cv::Mat src011,src012,src02,src03,src04;
    src011=cv::imread("C:\\opencv\\opencv\\12138.bmp");
    cv::imshow("mc",src011);
    double min,max;
    cv::Point minloc,maxloc;
    std::vector<cv::Mat>mc;
    cv::split(src011,mc);
    for(int i=0;i<mc.size();i++)
    {
        cv::minMaxLoc(mc[i],&min,&max,&minloc,&maxloc,cv::Mat());
        std::cout<<"No channels "<<i<<" min "<<min<<" max "<<max<<std::endl;
    }
    cv::meanStdDev(src011,src02,src03);
    std::cout<<std::endl<<"mean "<<std::endl<<src02<<std::endl;
    std::cout<<std::endl<<"stddev "<<std::endl<<src03<<std::endl;
    cv::waitKey(0);
    system("pause");
    return 0;
}