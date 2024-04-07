#include <opencv2/opencv.hpp>

int main() {

  cv::VideoCapture cap("blue-track.mp4");

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

    std::vector<std::vector<cv::Point> > contours;
    cv::findContours(mask, contours, cv::RETR_TREE, cv::CHAIN_APPROX_SIMPLE);

    if (contours.size() > 0) {
      cv::Point2f center; 
      float radius;
      cv::minEnclosingCircle(contours[0], center, radius);

      int x = (int)center.x;
      int y = (int)center.y;
      int r = (int)radius;

      cv::circle(frame, cv::Point(x,y), r, cv::Scalar(0,0,255), 2);
    }

    cv::imshow("image", frame);

    char k = (char)cv::waitKey(5);
    if (k == 27) {
      break;
    }
  }

  cv::destroyAllWindows();
  cap.release();

  return 0;
}