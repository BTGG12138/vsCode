#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

void part1()
{
    Mat image = imread("C:\\opencv\\opencv\\12138.bmp");

    Mat hsv, hs_hist;
    cvtColor(image, hsv, COLOR_BGR2HSV);

    int hbins = 30, sbins = 32;
    int hist_bins[] = {hbins, sbins};
    float h_range[] = {0, 180};
    float s_range[] = {0, 256};
    const float* hs_ranges[] = {h_range, s_range};
    int hs_channels[] = {0, 1};

    calcHist(&hsv, 1, hs_channels, Mat(), hs_hist, 2, hist_bins, hs_ranges, true, false);

    double maxVal = 0;
    minMaxLoc(hs_hist, 0, &maxVal, 0, 0);

    int scale = 10;
    Mat hist2d_image = Mat::zeros(sbins * scale, hbins * scale, CV_8UC3);

    for (int h = 0; h < hbins; h++)
    {
        for (int s = 0; s < sbins; s++)
        {
            float binVal = hs_hist.at<float>(h, s);
            int intensity = cvRound(binVal * 255 / maxVal);

            rectangle(hist2d_image,
                Point(h * scale, s * scale),
                Point((h + 1) * scale - 1, (s + 1) * scale - 1),
                Scalar::all(intensity),
                -1);
        }
    }

    imshow("src", image);
    imshow("H-S Histogram", hist2d_image);

    waitKey(0);
}
void part2()
{
    Mat hsv;
    Mat image = imread("C:\\opencv\\opencv\\12138.bmp");
    cvtColor(image, hsv, COLOR_BGR2HSV);
    vector<Mat> hsv_split;
    split(hsv, hsv_split);
    // 只均衡V通道（亮度通道），H、S保持不变
    equalizeHist(hsv_split[2], hsv_split[2]);
    merge(hsv_split, hsv);
    Mat result;
    cvtColor(hsv, result, COLOR_HSV2BGR);
    imshow("result", result);
    waitKey(0);
}
void part3()
{
    Mat src00,src01;
    src00=imread("C:\\opencv\\opencv\\12138.bmp");
    blur(src00,src01,Size(3,3),Point(-1,-1));
    imshow("result",src01);
    waitKey(0);
}
void part4()
{
    Mat src00,src01;
    src00=imread("C:\\opencv\\opencv\\12138.bmp");
    GaussianBlur(src00,src01,Size(0,0),15);
    imshow("result",src01);
    waitKey(0);
}
int main()
{
    //part1();
    //part2();
    //part3();
    part4();
}
