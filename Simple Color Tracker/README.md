# Color Tracker for Video and Webcam with `findContours` and `minEnclosingCircle`

This project demonstrates color tracking in videos and webcam streams using `findContours` and `minEnclosingCircle` functions. It provides implementations in both Python and C++ languages.

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Dependencies](#dependencies)
- [Installation](#installation)
- [Usage](#usage)
- [Contributing](#contributing)
- [License](#license)

## Introduction

Color tracking is a fundamental task in computer vision that involves detecting and tracking objects of a specific color in an image or video. This project utilizes the `findContours` function to detect contours of a specific color range, and the `minEnclosingCircle` function to find the minimum enclosing circle around the detected contour. It provides implementations in both Python and C++ languages.

## Languages  
<code>
<img align="center" src="https://github.com/devicons/devicon/blob/v2.15.1/icons/python/python-original-wordmark.svg" width="50" height="50" /> <img align="center" src="https://github.com/devicons/devicon/blob/v2.15.1/icons/vscode/vscode-original-wordmark.svg" width="50" height="50"/><img align="center" src="https://github.com/devicons/devicon/blob/v2.15.1/icons/numpy/numpy-original.svg" width="50" height="50"/><img align="center" src="https://github.com/devicons/devicon/blob/v2.15.1/icons/opencv/opencv-original-wordmark.svg" width="50" height="50" /> <img align="center" src="https://github.com/devicons/devicon/blob/v2.15.1/icons/pycharm/pycharm-original.svg" width="50" height="50"/>
</code>

## Features

- **Color Tracking**: Detect and track objects of a specific color in real-time video or webcam streams.
- **HSV Color Space**: Utilize the HSV color space for better color segmentation and tracking accuracy.
- **Contour Detection**: Use the `findContours` function to detect contours of the tracked color range.
- **Minimum Enclosing Circle**: Employ the `minEnclosingCircle` function to find the minimum enclosing circle around the detected contour.
- **Cross-Language Support**: Choose between Python and C++ implementations based on your preference and requirements.

## Dependencies

The project requires the following dependencies:

- **Python**:

  - Python 3.x

  - NumPy: A fundamental package for scientific computing with Python. It can be installed using pip:

    ```
    pip install numpy
    ```

  - OpenCV: An open-source computer vision library that provides various image and video processing functionalities. It can be installed using pip:

    ```
    pip install opencv-python
    ```

- **C++**:

  - C++ compiler (e.g., GCC, Clang)
  - OpenCV: Install OpenCV library based on your operating system and preferred installation method. Refer to the official OpenCV documentation for installation instructions.

## Installation

To use this project, follow these steps:

1. Clone the repository to your local machine:

```
git clone https://github.com/Awrsha/Simple-Color-Tracker.git
```

2. Install the required dependencies based on your chosen language (Python or C++).

## Usage

### Python

To run the color tracker using Python, follow these steps:

1. Open the Python script file (`color_tracker.py`) in your preferred Python IDE or text editor.

1. Adjust the color range:

   - Modify the `lower_blue` and `upper_blue` values to define the desired color range to track.
   - The values represent the lower and upper bounds for the blue color range in the HSV color space.

1. Run the Python script.

1. The script will open the specified video file (`blue-track.mp4`) or capture frames from the webcam if no video file is specified.

1. The script will track the specified color range in each frame, detect contours, and draw the minimum enclosing circle around the contour.

1. The output video or webcam stream with the tracked object and minimum enclosing circle will be displayed.

1. Press the `Esc` key to exit the script.

### C++

To run the color tracker using C++, follow these steps:

1. Open the C++ source file (`color_tracker.cpp`) in your preferred C++ IDE or text editor.

1. Adjust the color range:

   - Modify the `lower_blue` and `upper_blue` values to define the desired color range to track.
   - The values represent the lower and upper bounds for the blue color range in the HSV color space.

1. Build and compile the C++ source file using your preferred C++ compiler.

1. Execute the compiled binary.

1. The program will open the specified video file (`blue-track.mp4`) or capture frames from the webcam if no video file is specified.

1. The program will track the specified color range in each frame, detect contours, and draw the minimum enclosing circle around the contour.

1. The output video or webcam stream with the tracked object and minimum enclosing circle will be displayed.

1. Press any key to exit the program.

Feel free to modify the color range values and experiment with different video files or webcam streams to track objects of different colors.

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
