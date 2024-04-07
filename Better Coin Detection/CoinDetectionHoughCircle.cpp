#include <opencv2/opencv.hpp>

int main() {
    cv::Mat src = cv::imread("03.jpg");
    cv::Mat gray;
    cv::cvtColor(src, gray, cv::COLOR_BGR2GRAY);
    cv::medianBlur(gray, gray, 5);
    int rows = gray.rows;
    std::vector<cv::Vec3f> circles;
    cv::HoughCircles(gray, circles, cv::HOUGH_GRADIENT, 1, rows / 8,
                     100, 30, 60, 100);
    if (!circles.empty()) {
        for (size_t i = 0; i < circles.size(); i++) {
            cv::Vec3i c = circles[i];
            int center_x = c[0];
            int center_y = c[1];
            int radius = c[2];
            cv::Point center(center_x, center_y);
            cv::circle(src, center, 1, cv::Scalar(0, 100, 100), 3);
            cv::circle(src, center, radius, cv::Scalar(255, 0, 255), 3);
        }
    }
    cv::imshow("Result", src);
    cv::waitKey(0);
    std::cout << "Number of coins: " << circles.size() << std::endl;
    return 0;
}
