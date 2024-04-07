#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
    cv::Mat image = cv::imread("02.jpg");
    cv::Mat gray;
    cv::cvtColor(image, gray, cv::COLOR_BGR2GRAY);
    cv::Mat gray_blur;
    cv::GaussianBlur(gray, gray_blur, cv::Size(31, 31), 0);
    cv::Mat thresh;
    cv::adaptiveThreshold(gray_blur, thresh, 255, cv::ADAPTIVE_THRESH_GAUSSIAN_C, cv::THRESH_BINARY_INV, 11, 1);
    cv::Mat kernel = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(5, 5));
    cv::Mat closing;
    cv::morphologyEx(thresh, closing, cv::MORPH_CLOSE, kernel);
    std::vector<std::vector<cv::Point>> contours;
    std::vector<cv::Vec4i> hierarchy;
    cv::findContours(closing, contours, hierarchy, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);
    cv::Mat drawing_image = image.clone();
    for (int i = 0; i < contours.size(); i++) {
        double area = cv::contourArea(contours[i]);
        if (area < 5000 || area > 50000) {
            continue;
        }
        if (contours[i].size() < 5) {
            continue;
        }
        cv::RotatedRect ellipse = cv::fitEllipse(contours[i]);
        cv::ellipse(drawing_image, ellipse, cv::Scalar(0, 255, 0), 2);
    }
    cv::imshow("Original", image);
    cv::imshow("closing", closing);
    cv::imshow("result", drawing_image);
    cv::waitKey(0);
    return 0;
}