#include <opencv2/opencv.hpp>
#include <iostream>

void detectPose(const std::string& image_path, const std::string& protoFile, const std::string& weightsFile,
               int nPoints, const std::vector<std::vector<int>>& POSE_PAIRS, float threshold) {
    // Load the image
    cv::Mat image = cv::imread(image_path);

    // Load the Caffe model and perform a forward pass
    cv::dnn::Net net = cv::dnn::readNetFromCaffe(protoFile, weightsFile);
    cv::Mat blob = cv::dnn::blobFromImage(image, 1.0 / 255, cv::Size(368, 368), cv::Scalar(0, 0, 0), false, false);
    net.setInput(blob);
    cv::Mat output = net.forward();

    // Get the dimensions of the input image
    int height = image.rows;
    int width = image.cols;
    float scaleX = static_cast<float>(width) / output.size[3];
    float scaleY = static_cast<float>(height) / output.size[2];

    // Create an empty vector to store detected keypoints
    std::vector<cv::Point> points(nPoints);

    for (int i = 0; i < nPoints; ++i) {
        // Obtain the probability map
        cv::Mat probMap = output[0][i];

        // Find the global maximum of the probMap
        cv::Point maxLoc;
        double maxVal;
        cv::minMaxLoc(probMap, nullptr, &maxVal, nullptr, &maxLoc);

        // Scale the point to fit on the original image
        int x = static_cast<int>(scaleX * maxLoc.x);
        int y = static_cast<int>(scaleY * maxLoc.y);

        if (maxVal > threshold) {
            // Add the point to the list if the probability is greater than the threshold
            points[i] = cv::Point(x, y);
        } else {
            points[i] = cv::Point(-1, -1); // Set invalid points to (-1, -1)
        }
    }

    // Draw the skeleton on a copy of the image
    cv::Mat imSkeleton = image.clone();
    for (const auto& pair : POSE_PAIRS) {
        int partA = pair[0];
        int partB = pair[1];

        if (points[partA] != cv::Point(-1, -1) && points[partB] != cv::Point(-1, -1)) {
            cv::line(imSkeleton, points[partA], points[partB], cv::Scalar(255, 255, 0), 2);
            cv::circle(imSkeleton, points[partA], 8, cv::Scalar(255, 0, 0), -1);
        }
    }

    // Display the image with the skeleton
    cv::imshow("Pose Detection", imSkeleton);
    cv::waitKey(0);
}

int main() {
    // Define the paths to the Caffe model files
    std::string protoFile = "model/caffe/pose_deploy_linevec_faster_4_stages.prototxt";
    std::string weightsFile = "model/caffe/pose_iter_160000.caffemodel";

    // Number of keypoints and connections
    int nPoints = 15;
    std::vector<std::vector<int>> POSE_PAIRS = {
        {0,1}, {1,2}, {2,3}, {3,4}, {1,5}, {5,6}, {6,7}, {1,14}, {14,8}, {8,9}, {9,10}, {14,11}, {11,12}, {12,13}
    };

    // Threshold for keypoint detection
    float threshold = 0.1;

    // Path to the input image
    std::string image_path = "volleyball.jpg";

    // Detect and visualize the pose
    detectPose(image_path, protoFile, weightsFile, nPoints, POSE_PAIRS, threshold);

    return 0;
}