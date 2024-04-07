#include <opencv2/opencv.hpp>
#include <vector>

int main() {

  cv::Mat img = cv::imread("front.jpg", 0);

  cv::Mat th1;
  cv::threshold(img, th1, 127, 255, cv::THRESH_BINARY);
  
  cv::Mat th2;
  cv::threshold(img, th2, 0, 255, cv::THRESH_BINARY | cv::THRESH_OTSU);

  cv::Mat blur;
  cv::GaussianBlur(img, blur, cv::Size(3,3), 0);

  cv::Mat th3;
  cv::threshold(blur, th3, 0, 255, cv::THRESH_BINARY | cv::THRESH_OTSU);

  std::vector<cv::Mat> images = {img, th1, blur, th2, th3};

  for (int i = 0; i < images.size(); i++) {
    cv::imshow("Image", images[i]);
    cv::waitKey(0);
  }

  cv::destroyAllWindows();
  
  return 0;
}