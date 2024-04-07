# Simple Coin Detection with Counter

This project demonstrates a simple coin detection algorithm implemented in Python using the OpenCV library. The algorithm detects circular objects (coins) in an input image and displays the result along with a count of the detected coins.

## Table of Contents

- [Introduction](#introduction)
- [Installation](#installation)
- [Usage](#usage)
- [Contributing](#contributing)
- [License](#license)

## Introduction

The Simple Coin Detection with Counter project uses image processing techniques to detect coins in an input image. The algorithm performs the following steps:

1. Read the input image.
1. Convert the image to grayscale.
1. Apply Gaussian blur to remove noise.
1. Perform adaptive thresholding to create a binary image.
1. Apply morphological closing to fill gaps and smooth the edges.
1. Find contours of objects in the image.
1. Filter contours based on area and number of vertices.
1. Fit ellipses to the filtered contours.
1. Draw ellipses on a copy of the original image.
1. Display the original image, the binary image after closing, and the result with detected coins.

## Installation

To run the Simple Coin Detection with Counter project, follow these steps:

1. Make sure you have Python installed on your system (version 3.6 or higher).

1. Install the required dependencies by running the following command:

   ```bash
   pip install opencv-python matplotlib
   ```

## Usage

1. Clone or download the project repository to your local machine.

1. Navigate to the project directory.

1. Modify the source code to specify the path of the input image (replace `"02.jpg"` with the path to your image).

1. Run the Python script using the following command:

   ```bash
   python SimpleCoinCounter.py
   ```

1. The script will display three images: the original image, the binary image after closing, and the result image with detected coins and ellipses.

1. The detected coins will be highlighted with green ellipses.

1. The script will print the count of the detected coins in the console.

Feel free to experiment with different input images or modify the code to suit your specific requirements.

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
