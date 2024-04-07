#include <opencv2/opencv.hpp>

int main() {
  
  cv::Mat input_image = cv::imread("Robot.jpg");

  cv::Mat gray_image;
  cv::cvtColor(input_image, gray_image, cv::COLOR_BGR2GRAY);

  cv::Mat binary_image;
  cv::threshold(gray_image, binary_image, 127, 255, cv::THRESH_BINARY_INV);

  cv::Mat kernel = cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(5,5));
  
  cv::Mat closing;
  cv::morphologyEx(binary_image, closing, cv::MORPH_CLOSE, kernel);

  std::vector<std::vector<cv::Point>> contours;
  cv::findContours(closing, contours, cv::RETR_TREE, cv::CHAIN_APPROX_SIMPLE);

  cv::Mat drawing = input_image.clone();
  for (auto& c : contours) {
    cv::Rect boundRect = cv::boundingRect(c);
    cv::rectangle(drawing, boundRect, cv::Scalar(0,255,255), 2);
  }

  cv::imshow("Drawing", drawing);
  cv::waitKey(0);

  return 0;
}