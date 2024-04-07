#include <opencv2/opencv.hpp>

cv::Mat skinDetection(cv::Mat image) {
    // Convert image to YCrCb color space
    cv::Mat ycrcb;
    cv::cvtColor(image, ycrcb, cv::COLOR_BGR2YCrCb);

    // Convert image to HSV color space
    cv::Mat hsv;
    cv::cvtColor(image, hsv, cv::COLOR_BGR2HSV);

    // Define lower and upper thresholds for skin color in YCrCb space
    cv::Scalar lowerThresholdYCrCb(0, 133, 77);
    cv::Scalar upperThresholdYCrCb(255, 173, 127);

    // Define lower and upper thresholds for skin color in HSV space
    cv::Scalar lowerThresholdHSV(0, 48, 80);
    cv::Scalar upperThresholdHSV(20, 255, 255);

    // Apply skin color thresholding in YCrCb space
    cv::Mat skinMaskYCrCb;
    cv::inRange(ycrcb, lowerThresholdYCrCb, upperThresholdYCrCb, skinMaskYCrCb);

    // Apply skin color thresholding in HSV space
    cv::Mat skinMaskHSV;
    cv::inRange(hsv, lowerThresholdHSV, upperThresholdHSV, skinMaskHSV);

    // Combine skin detection from YCrCb and HSV
    cv::Mat skinMask;
    cv::bitwise_and(skinMaskYCrCb, skinMaskHSV, skinMask);

    // Apply a series of erosions and dilations to the mask using an elliptical kernel
    cv::Mat kernel = cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(3, 3));
    cv::erode(skinMask, skinMask, kernel, cv::Point(-1, -1), 2);
    cv::dilate(skinMask, skinMask, kernel, cv::Point(-1, -1), 2);

    // Blur the mask to help remove noise, then apply the mask to the frame
    cv::GaussianBlur(skinMask, skinMask, cv::Size(3, 3), 0);
    cv::Mat skin;
    cv::bitwise_and(image, image, skin, skinMask);

    return skin;
}

int main() {
    // Load the image
    cv::Mat image = cv::imread("ME.JPG");

    // Perform skin detection
    cv::Mat skinDetected = skinDetection(image);

    // Display the original image and the skin detection result
    cv::imshow("Original Image", image);
    cv::imshow("Skin Detection Result", skinDetected);
    cv::waitKey(0);

    return 0;
}