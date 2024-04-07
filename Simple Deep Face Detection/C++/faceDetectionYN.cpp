#include <opencv2/opencv.hpp>
#include <opencv2/dnn.hpp>

using namespace cv;
using namespace dnn;
using namespace std;

int main() {
    // Initialize face detector once
    Ptr<FaceDetectorYN> detector = FaceDetectorYN::create(
        "face_detection_yunet_2023mar.onnx", "", Size(320, 320), 0.3f, 0.2f, 5000);

    // Read image once
    Mat image = imread("test.jpg");
    int height = image.rows;
    int width = image.cols;

    // Set input size once
    detector->setInputSize(Size(width, height));

    // Detect faces
    vector<Mat> results;
    detector->detect(image, results);
    Mat faces = results[1];

    // Draw detections
    int thickness = 2;
    for (int i = 0; i < faces.rows; ++i) {
        Rect faceRect(faces.at<int>(i, 0), faces.at<int>(i, 1),
                      faces.at<int>(i, 2), faces.at<int>(i, 3));

        // Draw bounding box
        rectangle(image, faceRect, Scalar(0, 255, 0), thickness);

        // Draw landmarks
        for (int j = 4; j < faces.cols; j += 2) {
            Point landmark(faces.at<int>(i, j), faces.at<int>(i, j + 1));
            circle(image, landmark, 2, Scalar(0, 255, 0), thickness);
        }
    }

    // Display image
    imshow("Face Detection", image);
    waitKey(0);

    return 0;
}
