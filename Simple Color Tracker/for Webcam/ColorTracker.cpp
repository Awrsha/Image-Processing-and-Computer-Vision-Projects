#include <opencv2/opencv.hpp>

int main() {

  cv::VideoCapture cap(0); 

  while (true) {
    
    cv::Mat frame;
    cap >> frame;
    if (frame.empty()) {
      break;
    }
    
    cv::Mat hsv;
    cv::cvtColor(frame, hsv, cv::COLOR_BGR2HSV);

    cv::Scalar lower_blue(100,50,50);
    cv::Scalar upper_blue(130,255,255); 

    cv::Mat mask;
    cv::inRange(hsv, lower_blue, upper_blue, mask);

    cv::Mat res;
    cv::bitwise_and(frame, frame, res, mask);

    cv::imshow("frame", frame);
    cv::imshow("mask", mask);   
    cv::imshow("res", res);

    char k = (char)cv::waitKey(5);
    if (k == 27) {
      break;
    }
  
  }

  cv::destroyAllWindows();
  cap.release();

  return 0;
}