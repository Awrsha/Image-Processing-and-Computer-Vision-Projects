#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;
using namespace std;

int main()
{
    // Initialize the webcam
    VideoCapture cap(0);
    if (!cap.isOpened())
        return -1;

    Mat original_image, noise_removed_image, output1, output2, output3, output4, output5, output6;

    while (true)
    {
        // Read a frame from the webcam
        bool ret = cap.read(original_image);
        if (!ret)
            break;

        // Convert the image to grayscale
        cvtColor(original_image, original_image, COLOR_BGR2GRAY);

        // Noise removal
        medianBlur(original_image, noise_removed_image, 5);  // or GaussianBlur(original_image, noise_removed_image, Size(5,5), 0)

        // Thresholding
        threshold(original_image, output1, 127, 255, THRESH_BINARY);
        adaptiveThreshold(original_image, output2, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 11, 2);
        adaptiveThreshold(original_image, output3, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY, 11, 2);

        // Thresholding with noise removal
        threshold(noise_removed_image, output4, 127, 255, THRESH_BINARY);
        adaptiveThreshold(noise_removed_image, output5, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 11, 2);
        adaptiveThreshold(noise_removed_image, output6, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY, 11, 2);

        // Display the results in separate windows
        imshow("Original", original_image);
        imshow("Noise removed", noise_removed_image);
        imshow("Global Thresholding (v = 127)", output1);
        imshow("Adaptive Mean Thresholding", output2);
        imshow("Adaptive Gaussian Thresholding", output3);
        imshow("Global Thresholding + noise removal", output4);
        imshow("Adaptive Mean + noise removal", output5);
        imshow("Adaptive Gaussian + noise removal", output6);

        // Exit if the 'q' key is pressed
        if (waitKey(1) == 'q')
            break;
    }

    // Release the webcam and close all windows
    cap.release();
    destroyAllWindows();

    return 0;
}