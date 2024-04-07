# Coin Detection with Hough Transform (HoughCircle)

This project demonstrates coin detection using the Hough Circle Transform in Python. The algorithm detects circular objects (coins) in an input image and displays the result along with the count of detected coins.

## Table of Contents

- [Introduction](#introduction)
- [Installation](#installation)
- [Usage](#usage)
- [Contributing](#contributing)
- [License](#license)

## Introduction

The Coin Detection with Hough Transform project uses the Hough Circle Transform algorithm implemented in OpenCV to detect circular objects (coins) in an image. The main steps of the algorithm are as follows:

1. Read the input image.
1. Convert the image to grayscale.
1. Apply median blur to reduce noise.
1. Perform the Hough Circle Transform to detect circles in the image.
1. Iterate over the detected circles and draw them on the original image.
1. Display the image with detected circles.
1. Print the count of detected coins.

## Installation

To run the Coin Detection with Hough Transform project, follow these steps:

1. Ensure that Python is installed on your system (version 3.6 or higher).

1. Install the required dependencies by running the following command:

   ```bash
   pip install opencv-python matplotlib
   ```

## Usage

1. Clone or download the project repository to your local machine.

1. Navigate to the project directory.

1. Modify the source code to specify the path of the input image (replace `"03.jpg"` with the path to your image).

1. Run the Python script using the following command:

   ```bash
   python CoinDetectionHoughCircle.py
   ```

1. The script will display the image with detected circles drawn on it.

1. The count of detected coins will be printed in the console.

Feel free to experiment with different input images or adjust the parameters of the Hough Circle Transform (`param1`, `param2`, `minRadius`, `maxRadius`) to suit your specific needs.

## Code Explanation

The source code provided performs the following tasks:

1. Loads an image and converts it to grayscale.

   - `src = cv2.imread("03.jpg")`
   - `gray = cv2.cvtColor(src, cv2.COLOR_BGR2GRAY)`

1. Applies median blur to the grayscale image to reduce noise.

   - `gray = cv2.medianBlur(gray, 5)`

1. Performs the Hough Circle Transform to detect circles in the image.

   - `circles = cv2.HoughCircles(gray, cv2.HOUGH_GRADIENT, 1, rows / 8, param1=100, param2=30, minRadius=60, maxRadius=100)`

1. Iterates over the detected circles and draws them on the original image.

   - `for c in circles[0, :]`
     - Extracts the center coordinates and radius of each circle.
     - Draws a circle to represent the center of the coin.
     - Draws a circle to outline the detected coin.

1. Displays the image with detected circles.

   - `plt.imshow(src[...,::-1])`

1. Prints the count of detected coins.

   - `print("Number of coins:", len(circles[0,:]))`

Please note that the parameters used in the Hough Circle Transform (`param1`, `param2`, `minRadius`, `maxRadius`) can be adjusted based on the characteristics of the input image to achieve the best detection results.

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
