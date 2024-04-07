#include <opencv2/opencv.hpp>
#include <opencv2/dnn.hpp>
#include <iostream>
#include <vector>

using namespace cv;
using namespace dnn;
using namespace std;

int main() {
    // Initialize face detector once
    Net detector = cv2::FaceDetectorYN::create("face_detection_yunet_2023mar.onnx", "", Size(320, 320), 0.3, 0.2, 5000);

    // Read image once
    Mat image = imread("test.jpg");
    int height = image.rows;
    int width = image.cols;

    // Set input size once
    detector.setInputSize(Size(width, height));

    // Detect faces
    Mat inputBlob = blobFromImage(image, 1.0, Size(320, 320), Scalar(127.5, 127.5, 127.5), true, false);
    detector.setInput(inputBlob);
    Mat detections = detector.forward();
    Mat faces = detections.row(0).colRange(1, detections.cols);

    // Draw detections
    int thickness = 2;
    for (int i = 0; i < faces.rows; ++i) {
        Mat face = faces.row(i);
        Rect rect(face.ptr<float>(0)[0], face.ptr<float>(0)[1], face.ptr<float>(0)[2], face.ptr<float>(0)[3]);

        // Draw bounding box
        rectangle(image, rect, Scalar(0, 255, 0), thickness);

        // Draw landmarks
        for (int j = 4; j < face.cols; j += 2) {
            Point landmark(face.ptr<float>(0)[j], face.ptr<float>(0)[j + 1]);
            circle(image, landmark, 2, Scalar(0, 255, 0), thickness);
        }
    }

    // Display image
    imshow("Face Detection", image);
    waitKey(0);

    return 0;
}
