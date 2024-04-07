#include <opencv2/opencv.hpp>
#include <opencv2/dnn.hpp>
#include <iostream>
#include <fstream>
#include <vector>

using namespace cv;
using namespace dnn;
using namespace std;

int main() {
    // Load the pre-trained model and class names
    Net net = readNetFromTensorflow("frozen_inference_graph.pb", "ssd_mobilenet_v2_coco_2018_03_29.pbtxt");

    ifstream classes_file("object_detection_classes_coco.txt");
    vector<string> class_names;
    string line;
    while (getline(classes_file, line)) {
        class_names.push_back(line);
    }

    // Generate random colors for each class
    vector<Scalar> COLORS;
    for (size_t i = 0; i < class_names.size(); ++i) {
        Scalar color(rand() % 255, rand() % 255, rand() % 255);
        COLORS.push_back(color);
    }

    // Load and process the image
    Mat image = imread("test.jpg");
    int image_height = image.rows;
    int image_width = image.cols;

    // Optimize the input size (you can experiment with different sizes)
    Size input_size(300, 300);
    Mat blob = blobFromImage(image, 1.0, input_size, Scalar(127.5, 127.5, 127.5), true, false);
    net.setInput(blob);

    // Run the forward pass
    Mat output = net.forward();

    // Initialize lists to store results
    vector<Rect> detections;
    vector<float> scores;

    // Loop through the detected objects and draw bounding boxes
    Mat detection_results(output.size[2], output.size[3], CV_32F, output.ptr<float>());
    for (int i = 0; i < detection_results.rows; ++i) {
        float score = detection_results.at<float>(i, 2);
        if (score > 0.3) {
            int class_id = static_cast<int>(detection_results.at<float>(i, 1));
            string class_name = class_names[class_id - 1];
            Scalar color = COLORS[class_id];

            int left = static_cast<int>(detection_results.at<float>(i, 3) * image_width);
            int top = static_cast<int>(detection_results.at<float>(i, 4) * image_height);
            int right = static_cast<int>(detection_results.at<float>(i, 5) * image_width);
            int bottom = static_cast<int>(detection_results.at<float>(i, 6) * image_height);

            detections.push_back(Rect(left, top, right - left, bottom - top));
            scores.push_back(score);
        }
    }

    // Non-Maximum Suppression (NMS) to remove overlapping bounding boxes
    vector<int> indices;
    NMSBoxes(detections, scores, 0.3, 0.5, indices);

    // Draw the final bounding boxes
    for (int i : indices) {
        int left = detections[i].x;
        int top = detections[i].y;
        int right = left + detections[i].width;
        int bottom = top + detections[i].height;
        float score = scores[i];
        string class_name = class_names[static_cast<int>(detection_results.at<float>(i, 1)) - 1];
        Scalar color = COLORS[static_cast<int>(detection_results.at<float>(i, 1))];

        rectangle(image, Point(left, top), Point(right, bottom), color, 2);
        putText(image, class_name + ": " + to_string(score * 100) + "%", Point(left, top - 5), FONT_HERSHEY_SIMPLEX, 0.5, color, 2);
    }

    // Display the annotated image
    imshow("Object Detection", image);
    waitKey(0);

    return 0;
}
