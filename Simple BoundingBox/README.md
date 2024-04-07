# Simple BoundingBox with Contour and Enclosing Circle

This project is a simple implementation of bounding boxes with contours and enclosing circles using OpenCV and matplotlib in Python. It takes an input image, performs image processing operations, and generates bounding boxes around objects detected in the image.

## Table of Contents

- [Introduction](#introduction)
- [Dependencies](#dependencies)
- [Installation](#installation)
- [Usage](#usage)
- [Contributing](#contributing)
- [License](#license)

## Introduction

The Simple BoundingBox with Contour and Enclosing Circle project processes an input image and applies image processing techniques to detect objects within the image. It uses contours to identify the boundaries of objects and generates bounding boxes and enclosing circles around those objects. The resulting image with the bounding boxes and enclosing circles is displayed using matplotlib.

## Languages  
<code>
<img align="center" src="https://github.com/devicons/devicon/blob/v2.15.1/icons/python/python-original-wordmark.svg" width="50" height="50" /> <img align="center" src="https://github.com/devicons/devicon/blob/v2.15.1/icons/vscode/vscode-original-wordmark.svg" width="50" height="50"/><img align="center" src="https://github.com/devicons/devicon/blob/v2.15.1/icons/numpy/numpy-original.svg" width="50" height="50"/><img align="center" src="https://github.com/devicons/devicon/blob/v2.15.1/icons/opencv/opencv-original-wordmark.svg" width="50" height="50" /> <img align="center" src="https://github.com/devicons/devicon/blob/v2.15.1/icons/pycharm/pycharm-original.svg" width="50" height="50"/>
</code>

## Dependencies

This project requires the following dependencies:

- Python 3.x
- OpenCV: An open-source computer vision library. It can be installed using pip:

```bash
pip install opencv-python
```

- Matplotlib: A plotting library for Python. It can be installed using pip:

```bash
pip install matplotlib
```

## Installation

To use this project, follow these steps:

1. Clone the repository to your local machine:

```bash
git clone https://github.com/Awrsha/Simple-BoundingBox.git
```

2. Install the required dependencies:

```bash
pip install opencv-python matplotlib
```

## Usage

To run the Simple BoundingBox with Contour and Enclosing Circle project, follow these steps:

1. Place the input image file (`Robot.jpg`) in the same directory as the Python script.

1. Open the Python script file (`bounding_box_contour_enclosing_circle.py`) in your preferred Python IDE or text editor.

1. Run the Python script.

1. The script will perform the following steps:

   - Read the input image file (`Robot.jpg`).
   - Convert the image to grayscale.
   - Invert the image to have black and white.
   - Define a kernel for morphological operations.
   - Perform morphological closing on the binary image.
   - Find contours in the processed image.
   - Draw bounding boxes around the detected contours.
   - Display the resulting image with bounding boxes and enclosing circles using matplotlib.

1. The resulting image with bounding boxes and enclosing circles will be displayed.

Feel free to modify the script or incorporate it into your own projects to perform object detection and visualization using bounding boxes and enclosing circles.

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
