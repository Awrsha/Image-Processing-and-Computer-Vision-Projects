# Image Rotation with Python

This project demonstrates image rotation using Python. It provides a flexible and efficient way to rotate images by a specified angle.

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Dependencies](#dependencies)
- [Installation](#installation)
- [Usage](#usage)
- [Contributing](#contributing)
- [License](#license)

## Introduction

Image rotation is a common operation in image processing and computer vision. It involves rotating an image by a certain angle. This project provides a Python implementation to rotate images using the provided source code.

## Languages  
<code>
<img align="center" src="https://github.com/devicons/devicon/blob/v2.15.1/icons/python/python-original-wordmark.svg" width="50" height="50" /> <img align="center" src="https://github.com/devicons/devicon/blob/v2.15.1/icons/vscode/vscode-original-wordmark.svg" width="50" height="50"/><img align="center" src="https://github.com/devicons/devicon/blob/v2.15.1/icons/numpy/numpy-original.svg" width="50" height="50"/><img align="center" src="https://github.com/devicons/devicon/blob/v2.15.1/icons/opencv/opencv-original-wordmark.svg" width="50" height="50" /> <img align="center" src="https://github.com/devicons/devicon/blob/v2.15.1/icons/pycharm/pycharm-original.svg" width="50" height="50"/>
</code>

## Features

- **Arbitrary Angle Rotation**: Rotate images by any specified angle in degrees.
- **Efficient Implementation**: The implementation optimizes the rotation process for performance and memory efficiency.
- **Flexible Center Point**: Define the center point of rotation to control the pivot around which the image is rotated.
- **OpenCV Integration**: Utilizes OpenCV, a popular computer vision library, for image loading, manipulation, and display.

## Dependencies

The project requires the following dependencies:

- **Python**: The project is intended to be run using Python programming language. The recommended version is Python 3.6 or higher.

- **OpenCV**: OpenCV is an open-source computer vision library that provides various image processing functionalities. The project utilizes OpenCV for image loading, manipulation, and display. It can be installed using pip:

```
pip install opencv-python
```

## Installation

To use this project, follow these steps:

1. Clone the repository to your local machine:

```
git clone https://github.com/Awrsha/Image-Rotation.git
```

2. Install the required dependencies using pip:

```
pip install -r requirements.txt
```

3. Place your input image(s) in the appropriate location within the project directory.

## Usage

To rotate an image using this project, follow these steps:

1. Import the necessary modules:

```python
import cv2
import numpy as np
```

2. Define the `rotate_image` function:

```python
def rotate_image(image, angle):
    # Convert the angle to radians
    theta = np.radians(angle)

    # Get the image shape
    height, width = image.shape[:2]

    # Calculate the coordinates of the center of the image
    center_x, center_y = width/2, height/2

    # Calculate the rotation matrix
    rotation_matrix = np.array([[np.cos(theta), -np.sin(theta), (1-np.cos(theta))*center_x + np.sin(theta)*center_y],
                                [np.sin(theta), np.cos(theta), (1-np.cos(theta))*center_y - np.sin(theta)*center_x],
                                [0, 0, 1]])

    # Apply the rotation matrix to the image
    rotated_image = cv2.warpPerspective(image, rotation_matrix, (width, height))

    return rotated_image
```

3. Load the input image:

```python
image = cv2.imread("path/to/your/image.jpg")

if image is None:
    print("Could not read the image")
    exit()
```

4. Rotate the image:

```python
rotated_image = rotate_image(image, angle)
```

5. Display the output image:

```python
cv2.imshow("Rotated Image", rotated_image)
cv2.waitKey(0)
cv2.destroyAllWindows()
```

6. Customize the angle variable with the desired rotation angle in degrees.

1. Run the script and observe the rotated image.

For more information on function parameters and options, please refer to the project documentation or the function's docstring.

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
