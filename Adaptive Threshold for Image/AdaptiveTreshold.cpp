#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include <opencv2/opencv.hpp>
#include "opencv2/core.hpp"

using namespace cv;

int main() {

  Mat original = imread("imagessudoku.jpg", IMREAD_GRAYSCALE);
  
  // Noise removal
  Mat noise_removed;
  medianBlur(original, noise_removed, 5);

  Mat output1;
  threshold(original, output1, 127, 255, THRESH_BINARY);

  Mat output2;
  adaptiveThreshold(original, output2, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 11, 2);

  Mat output3;
  adaptiveThreshold(original, output3, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY, 11, 2);

  Mat output4;
  threshold(noise_removed, output4, 127, 255, THRESH_BINARY);

  Mat output5;
  adaptiveThreshold(noise_removed, output5, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 11, 2);

  Mat output6;
  adaptiveThreshold(noise_removed, output6, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY, 11, 2);

  // Display results
  namedWindow("Original", WINDOW_AUTOSIZE);
  imshow("Original", original);
  
  namedWindow("Noise removed", WINDOW_AUTOSIZE);
  imshow("Noise removed", noise_removed);
  
  namedWindow("Global Thresholding (v = 127)", WINDOW_AUTOSIZE);
  imshow("Global Thresholding (v = 127)", output1);
  
  namedWindow("Adaptive Mean Thresholding", WINDOW_AUTOSIZE);
  imshow("Adaptive Mean Thresholding", output2);
  
  namedWindow("Adaptive Gaussian Thresholding", WINDOW_AUTOSIZE);
  imshow("Adaptive Gaussian Thresholding", output3);
  
  namedWindow("Global Thresholding + noise removal", WINDOW_AUTOSIZE);
  imshow("Global Thresholding + noise removal", output4);
  
  namedWindow("Adaptive Mean + noise removal", WINDOW_AUTOSIZE);
  imshow("Adaptive Gaussian Thresholding", output5);
  
  namedWindow("Adaptive Gaussian + noise removal", WINDOW_AUTOSIZE);
  imshow("Adaptive Gaussian + noise removal", output6);


  waitKey(0);

  return 0;
}