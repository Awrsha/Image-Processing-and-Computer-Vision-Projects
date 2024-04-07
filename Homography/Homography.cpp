#include <iostream>
#include <opencv2/opencv.hpp>

cv::Mat rgb_to_gray(const cv::Mat &image) {
    cv::Mat gray_image;
    cv::cvtColor(image, gray_image, cv::COLOR_BGR2GRAY);
    return gray_image;
}

std::vector<cv::KeyPoint> detect_sift(const cv::Mat &image) {
    cv::Ptr<cv::SIFT> sift = cv::SIFT::create();
    std::vector<cv::KeyPoint> keypoints;
    sift->detect(image, keypoints);
    return keypoints;
}

cv::Mat compute_sift_descriptors(const cv::Mat &image, std::vector<cv::KeyPoint> &keypoints) {
    cv::Ptr<cv::SIFT> sift = cv::SIFT::create();
    cv::Mat descriptors;
    sift->compute(image, keypoints, descriptors);
    return descriptors;
}

std::vector<cv::DMatch> match_keypoints(const cv::Mat &descriptors1, const cv::Mat &descriptors2) {
    cv::FlannBasedMatcher matcher;
    std::vector<std::vector<cv::DMatch>> knn_matches;
    matcher.knnMatch(descriptors1, descriptors2, knn_matches, 2);

    std::vector<cv::DMatch> good_matches;
    for (size_t i = 0; i < knn_matches.size(); ++i) {
        if (knn_matches[i][0].distance < 0.7 * knn_matches[i][1].distance) {
            good_matches.push_back(knn_matches[i][0]);
        }
    }
    return good_matches;
}

cv::Mat find_homography(const std::vector<cv::Point2f> &src_pts, const std::vector<cv::Point2f> &dst_pts) {
    cv::Mat H = cv::findHomography(src_pts, dst_pts, cv::RANSAC);
    return H;
}

std::vector<cv::Point2f> perspective_transform(const std::vector<cv::Point2f> &pts, const cv::Mat &H) {
    std::vector<cv::Point2f> transformed_pts;
    for (const cv::Point2f &pt : pts) {
        float x = pt.x;
        float y = pt.y;
        float denominator = H.at<double>(2, 0) * x + H.at<double>(2, 1) * y + H.at<double>(2, 2);
        float u = (H.at<double>(0, 0) * x + H.at<double>(0, 1) * y + H.at<double>(0, 2)) / denominator;
        float v = (H.at<double>(1, 0) * x + H.at<double>(1, 1) * y + H.at<double>(1, 2)) / denominator;
        transformed_pts.push_back(cv::Point2f(u, v));
    }
    return transformed_pts;
}

void draw_polyline(cv::Mat &image, const std::vector<cv::Point2f> &pts) {
    for (size_t i = 0; i < pts.size(); ++i) {
        cv::line(image, pts[i], pts[(i + 1) % pts.size()], cv::Scalar(0, 255, 0), 3, cv::LINE_AA);
    }
}

int main() {
    cv::Mat original_img1 = cv::imread("pahlavi.jpg");
    cv::Mat original_img2 = cv::imread("coins.jpg");

    cv::Mat img1 = rgb_to_gray(original_img1);
    cv::Mat img2 = rgb_to_gray(original_img2);

    std::vector<cv::KeyPoint> kp1 = detect_sift(img1);
    std::vector<cv::KeyPoint> kp2 = detect_sift(img2);

    cv::Mat des1 = compute_sift_descriptors(img1, kp1);
    cv::Mat des2 = compute_sift_descriptors(img2, kp2);

    std::vector<cv::DMatch> matches = match_keypoints(des1, des2);

    const int MIN_MATCH_COUNT = 10;
    if (matches.size() > MIN_MATCH_COUNT) {
        std::vector<cv::Point2f> src_pts, dst_pts;
        for (const cv::DMatch &m : matches) {
            src_pts.push_back(kp1[m.queryIdx].pt);
            dst_pts.push_back(kp2[m.trainIdx].pt);
        }

        cv::Mat M = find_homography(src_pts, dst_pts);

        int h = img1.rows;
        int w = img1.cols;
        std::vector<cv::Point2f> pts = {cv::Point2f(0, 0), cv::Point2f(0, h - 1),
                                        cv::Point2f(w - 1, h - 1), cv::Point2f(w - 1, 0)};
        std::vector<cv::Point2f> transformed_pts = perspective_transform(pts, M);

        draw_polyline(original_img2, transformed_pts);

        cv::Mat result = original_img2;
    } else {
        std::cout << "Not enough matches are found - " << matches.size() << "/" << MIN_MATCH_COUNT << std::endl;
        cv::Mat result = original_img2;
    }

    cv::imshow("Image1", original_img1);
    cv::imshow("Image2", original_img2);
    cv::imshow("Result", result);
    cv::waitKey(0);

    return 0;
}