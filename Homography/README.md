# Finding Objects with Feature Matching and Homography

This project demonstrates how to find and match objects in images using feature matching and homography techniques. The code provided utilizes the SIFT (Scale-Invariant Feature Transform) algorithm to detect and compute keypoints and descriptors for two input images. It then performs feature matching using the FLANN (Fast Library for Approximate Nearest Neighbors) algorithm and applies a homography transformation to align the objects.

## Installation

To run the code, you need to have the following dependencies installed:

- numpy
- opencv-python
- matplotlib

You can install these dependencies using pip:

```
pip install numpy opencv-python matplotlib
```

## Usage

To use the code, follow these steps:

1. Place the query image (the image containing the object you want to find) in the file `pahlavi.jpg`.
1. Place the train image (the image in which you want to find the object) in the file `coins.jpg`.
1. Run the script.

## How it Works

1. The code reads the query image and the train image using OpenCV's `imread` function.
1. The images are converted to grayscale using `cv2.cvtColor` for further processing.
1. The SIFT detector is initialized using `cv2.SIFT_create()`.
1. Keypoints and descriptors are computed for both images using the SIFT algorithm: `sift.detectAndCompute`.
1. The FLANN parameters, index parameters, and search parameters are set up for feature matching using `cv2.FlannBasedMatcher`.
1. Feature matching is performed by comparing the descriptors of the query and train images: `flann.knnMatch`.
1. The matches are filtered based on the Lowe's ratio test, and only the good matches are stored.
1. If the number of good matches is above a predefined threshold (`MIN_MATCH_COUNT`), the code proceeds with object detection and alignment.
1. Homography matrix estimation is performed using RANSAC: `cv2.findHomography`.
1. The corners of the query image are transformed using the homography matrix: `cv2.perspectiveTransform`.
1. The transformed corners are used to draw a polygon around the detected object in the train image: `cv2.polylines`.
1. The result image is displayed using `matplotlib.pyplot`.

## Examples

Here are a few examples of how the code can be used:

1. Example :

   - Query Image: ![Query Image](<https://github.com/Awrsha/Homography/blob/master/pahlavi.jpg>)
   - Train Image: ![Train Image](<https://github.com/Awrsha/Homography/blob/master/coins.jpg>)
   - Result: ![Result](<https://github.com/Awrsha/Homography/blob/master/result.jpg>)

## Troubleshooting

- **Not enough matches are found:** If the code prints "Not enough matches are found," it means the number of good matches is below the `MIN_MATCH_COUNT` threshold. This can happen if the object is not present in the train image or if the quality of the images is low. Consider adjusting the threshold or using different images.

## Acknowledgements

This project utilizes the following libraries:

- [NumPy](https://numpy.org/)
- [OpenCV](https://opencv.org/)
- [Matplotlib](https://matplotlib.org/)

## Contact Information

For any questions, issues, or feedback, please contact \[official.parvizi@gmail.com\].

**Note:** Remember to replace `[official.parvizi@gmail.com]` with your actual email address.

## Contributing

This is an open-source project and contributions are welcome. To contribute, please fork this repository and submit a pull request with your changes.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Developers 👨🏻‍💻

<p align="center">
<a href="https://github.com/Awrsha"><img src="https://avatars.githubusercontent.com/u/89135083?v=4" width="100;" alt="Awrsha Parvizi"/><br /><sub><b>.:: Amir M. Parvizi ::.</b></sub></a>
</p>

## System & Hardware 🛠  
<br> <summary><b>⚙️ Things I use to get stuff done</b></summary> <ul> <li><b>OS:</b> Windows 11</li> <li><b>Laptop: </b>TUF Gaming</li> <li><b>Code Editor:</b> Visual Studio Code - The best editor out there.</li> <li><b>To Stay Updated:</b> Medium, Linkedin and Instagram.</li> <br /> ⚛️ Checkout Our VSCode Configrations <a href="">Here</a>. </ul> <p align="center">💙 If you like my projects, Give them ⭐ and Share it with friends!</p></p><p align="center"><img height="27" src="https://raw.githubusercontent.com/mayhemantt/mayhemantt/Update/svg/Bottom.svg" alt="Github Stats" /></p>

<p align="center">
<img src="https://raw.githubusercontent.com/mayhemantt/mayhemantt/Update/svg/Bottom.svg" alt="Github Stats" />
</p>
