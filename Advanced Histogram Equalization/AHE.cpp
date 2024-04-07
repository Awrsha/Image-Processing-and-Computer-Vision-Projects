#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
    Mat image = imread("images/statue.png");

    vector<Mat> channels;
    split(image, channels);

    Ptr<CLAHE> clahe = createCLAHE(2.0, Size(8, 8));
    vector<Mat> eq_channels;
    for (Mat ch : channels) {
        Mat eq_ch;
        clahe->apply(ch, eq_ch);
        eq_channels.push_back(eq_ch);
    }
    Mat eq_clahe_image;
    merge(eq_channels, eq_clahe_image);

    eq_channels.clear();
    for (Mat ch : channels) {
        Mat eq_ch;
        equalizeHist(ch, eq_ch);
        eq_channels.push_back(eq_ch);
    }
    Mat eq_image;
    merge(eq_channels, eq_image);

    namedWindow("Original", WINDOW_NORMAL);
    imshow("Original", image);

    namedWindow("After Adaptive histogram equalization", WINDOW_NORMAL);
    imshow("After Adaptive histogram equalization", eq_clahe_image);

    namedWindow("After global histogram equalization", WINDOW_NORMAL);
    imshow("After global histogram equalization", eq_image);

    vector<Scalar> color = {Scalar(255, 0, 0), Scalar(0, 255, 0), Scalar(0, 0, 255)};

    Mat hist_image(256, 256, CV_8UC3, Scalar(0, 0, 0));
    for (int i = 0; i < 3; i++) {
        vector<Mat> hist;
        calcHist(&image, 1, &i, Mat(), hist, 1, &256, false);
        for (int j = 0; j < 256; j++) {
            line(hist_image, Point(j, 255), Point(j, 255 - hist.at<float>(j)), color[i], 1, 8, 0);
        }
    }
    namedWindow("Original Histogram", WINDOW_NORMAL);
    imshow("Original Histogram", hist_image);

    hist_image = Mat(256, 256, CV_8UC3, Scalar(0, 0, 0));
    for (int i = 0; i < 3; i++) {
        vector<Mat> hist;
        calcHist(&eq_clahe_image, 1, &i, Mat(), hist, 1, &256, false);
        for (int j = 0; j < 256; j++) {
            line(hist_image, Point(j, 255), Point(j, 255 - hist.at<float>(j)), color[i], 1, 8, 0);
        }
    }
    namedWindow("After Adaptive histogram equalization Histogram", WINDOW_NORMAL);
    imshow("After Adaptive histogram equalization Histogram", hist_image);

    hist_image = Mat(256, 256, CV_8UC3, Scalar(0, 0, 0));
    for (int i = 0; i < 3; i++) {
        vector<Mat> hist;
        calcHist(&eq_image, 1, &i, Mat(), hist, 1, &256, false);
        for (int j = 0; j < 256; j++) {
            line(hist_image, Point(j, 255), Point(j, 255 - hist.at<float>(j)), color[i], 1, 8, 0);
        }
    }
    namedWindow("After global histogram equalization Histogram", WINDOW_NORMAL);
    imshow("After global histogram equalization Histogram", hist_image);

    waitKey(0);
    return 0;
}