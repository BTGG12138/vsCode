#include <opencv2/opencv.hpp>
#include <iostream>
#include <cstdlib>

int main()
{
    // 完整绝对路径
    cv::Mat src = cv::imread("C:\\opencv\\opencv\\12138.bmp");
    std::cout << "cols:" << src.cols << ", rows:" << src.rows << std::endl;

    if (src.empty())
    {
        std::cout << "cant see" << std::endl;
        system("pause");
        return 1;
    }
    cv::namedWindow("input", cv::WINDOW_AUTOSIZE);
    cv::imshow("input", src);
    cv::waitKey(0);
    system("pause");
    return 0;
}
