#include <iostream>
#include <cmath>

#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include <opencv2/opencv.hpp>
#include "opencv2/core.hpp"

using namespace std;

#define PI 3.14159265358979323846

// Define a struct for a 2D point
struct Point
{
    int x;
    int y;
};

// Define a struct for a 2x2 matrix
struct Matrix2x2
{
    float a11, a12;
    float a21, a22;
};

// Function to compute the rotation matrix for a given angle
Matrix2x2 compute_rotation_matrix(float angle)
{
    Matrix2x2 rotation_matrix;
    float radians = angle * PI / 180.0;
    rotation_matrix.a11 = cos(radians);
    rotation_matrix.a12 = -sin(radians);
    rotation_matrix.a21 = sin(radians);
    rotation_matrix.a22 = cos(radians);
    return rotation_matrix;
}

// Function to rotate a point using a rotation matrix
Point rotate_point(Point p, Matrix2x2 rotation_matrix)
{
    Point q;
    q.x = round(rotation_matrix.a11 * p.x + rotation_matrix.a12 * p.y);
    q.y = round(rotation_matrix.a21 * p.x + rotation_matrix.a22 * p.y);
    return q;
}

// Function to rotate an image using a rotation matrix
void rotate_image(unsigned char* image, int width, int height, float angle)
{
    // Compute the rotation matrix
    Matrix2x2 rotation_matrix = compute_rotation_matrix(angle);

    // Compute the coordinates of the center of the image
    int center_x = width / 2;
    int center_y = height / 2;

    // Loop over all pixels in the image
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            // Compute the coordinates of the current pixel relative to the center of the image
            int dx = x - center_x;
            int dy = y - center_y;

            // Rotate the coordinates of the pixel using the rotation matrix
            Point q = rotate_point({dx, dy}, rotation_matrix);

            // Translate the coordinates of the pixel back to the top-left corner of the image
            q.x += center_x;
            q.y += center_y;

            // Check if the rotated pixel is within the bounds of the image
            if (q.x >= 0 && q.x < width && q.y >= 0 && q.y < height)
            {
                // Compute the index of the current pixel in the image array
                int index = y * width + x;

                // Compute the index of the rotated pixel in the image array
                int rotated_index = q.y * width + q.x;

                // Swap the values of the current pixel and the rotated pixel
                unsigned char temp = image[index];
                image[index] = image[rotated_index];
                image[rotated_index] = temp;
            }
        }
    }
}

int main()
{
    // Load the input image
    int width = 640;
    int height = 480;
    unsigned char* image = new unsigned char[width * height];
    // Fill the image with some test data
    for (int i = 0; i < width * height; i++)
    {
        image[i] = i % 256;
    }

    // Rotate the image by 45 degrees
    rotate_image(image, width, height, 45.0);

int main()
{
    // Load the input image
    Mat image = imread("input.jpg", IMREAD_GRAYSCALE);

    // Rotate the image by 45 degrees
    Mat rotated_image;
    Point2f center(image.cols/2.0, image.rows/2.0);
    Mat rotation_matrix = getRotationMatrix2D(center, 45.0, 1.0);
    warpAffine(image, rotated_image, rotation_matrix, image.size());

    // Display the rotated image
    imshow("Rotated Image", rotated_image);
    waitKey(0);

    return 0;
}