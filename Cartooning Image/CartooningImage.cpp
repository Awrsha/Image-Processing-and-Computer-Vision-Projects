#include <iostream>

#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include <opencv2/opencv.hpp>
#include "opencv2/core.hpp"

using namespace cv;

class Cartoonizer {
public:
  void render(Mat img_rgb) {
    
    Mat img_color;
    img_rgb.copyTo(img_color);
    resize(img_rgb, img_color, Size(1366,768));
    
    int numDownSamples = 2;
    int numBilateralFilters = 50;
    
    // Step 1
    for(int i = 0; i < numDownSamples; i++) {
      pyrDown(img_color, img_color); 
    }
    
    for(int i = 0; i < numBilateralFilters; i++) {
      bilateralFilter(img_color, img_color, 9, 9, 7);
    }
    
    for(int i = 0; i < numDownSamples; i++) {
      pyrUp(img_color, img_color);
    }
    
    // Steps 2 and 3
    Mat img_gray;
    cvtColor(img_rgb, img_gray, COLOR_RGB2GRAY);
    medianBlur(img_gray, img_gray, 3);
    
    // Step 4
    Mat img_edge;
    adaptiveThreshold(img_gray, img_edge, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 9, 2);

    // Step 5 
    cvtColor(img_edge, img_edge, COLOR_GRAY2RGB);
    
    Mat result;
    bitwise_and(img_color, img_edge, result);
    
    imwrite("Cartoon version.jpg", result);
    imshow("Cartoon version", result);
    waitKey(0);
  }
};

int main() {

  Mat img = imread("Screenshot.png");
  
  Cartoonizer cartoonizer;
  cartoonizer.render(img);
  
  return 0;
}