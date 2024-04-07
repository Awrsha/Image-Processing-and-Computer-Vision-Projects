# Adaptive Gaussian Threshold With Noise Removal (for Webcam) (Jupyter Notebook)

This repository provides an advanced implementation of the Adaptive Gaussian Thresholding algorithm with noise removal for webcam image processing in a Jupyter Notebook. The algorithm is designed to segment webcam video frames by thresholding pixel values and adaptively estimating the threshold based on local image statistics. It incorporates noise removal techniques to enhance the accuracy of the thresholding process.

## Contents

- [Introduction](#introduction)
- [Getting Started](#getting-started)
- [Usage](#usage)
- [Algorithm](#algorithm)
- [Example](#example)
- [Contributing](#contributing)
- [License](#license)

## Introduction

The Adaptive Gaussian Thresholding algorithm for webcam images is widely used in computer vision applications for real-time segmentation. This implementation extends the basic algorithm by incorporating noise removal techniques to handle noisy video frames effectively. The algorithm provides configurable parameters for fine-tuning the thresholding process and noise removal.

## Languages  
<code>
<img align="center" src="https://github.com/devicons/devicon/blob/v2.15.1/icons/python/python-original-wordmark.svg" width="50" height="50" /> <img align="center" src="https://github.com/devicons/devicon/blob/v2.15.1/icons/vscode/vscode-original-wordmark.svg" width="50" height="50"/><img align="center" src="https://github.com/devicons/devicon/blob/v2.15.1/icons/numpy/numpy-original.svg" width="50" height="50"/><img align="center" src="https://github.com/devicons/devicon/blob/v2.15.1/icons/opencv/opencv-original-wordmark.svg" width="50" height="50" /> <img align="center" src="https://github.com/devicons/devicon/blob/v2.15.1/icons/pycharm/pycharm-original.svg" width="50" height="50"/>
</code>

## Getting Started

To use this Adaptive Gaussian Thresholding implementation for webcam images in your Jupyter Notebook, follow these steps:

1. Clone this repository to your local machine or download the Jupyter Notebook file.
1. Open the Jupyter Notebook file using Jupyter Notebook or JupyterLab.
1. Execute the notebook cells to run the Adaptive Gaussian Thresholding algorithm and view the results.

## Usage

To use the Adaptive Gaussian Thresholding algorithm for webcam images in your Jupyter Notebook, follow these steps:

1. Configure the algorithm parameters such as the block size, constant offset, and noise removal parameters.
1. Run the algorithm by calling the adaptive_gaussian_threshold_webcam() function.
1. The webcam will start capturing frames, and the algorithm will apply adaptive thresholding and noise removal to each frame in real-time.
1. Press 'Q' to stop the webcam capture and exit the algorithm.

Refer to the example section for a more detailed demonstration of the usage.

## Algorithm

The Adaptive Gaussian Thresholding algorithm implemented in this notebook for webcam images follows these steps:

1. Initialize the webcam capture using the OpenCV library.
1. Continuously capture frames from the webcam.
1. For each frame, convert it to grayscale.
1. Divide the frame into blocks of a specified size.
1. Compute the local mean and standard deviation of each block.
1. Calculate the threshold for each block based on the local mean and standard deviation, using the constant offset.
1. Apply the calculated thresholds to the corresponding block of the frame to obtain the thresholded frame.
1. Perform noise removal techniques, such as morphological operations or filtering, to enhance the quality of the thresholded frame.
1. Display the thresholded frame in real-time.
1. Repeat steps 3-9 until the user stops the webcam capture.

## Example

Here's an example demonstrating the usage of the Adaptive Gaussian Thresholding algorithm for webcam images:

``` python
# Import the required functions from the AdaptiveGaussianThresholdWebcam.ipynb notebook
from AdaptiveGaussianThresholdWebcam import adaptive_gaussian_threshold_webcam

# Configure the algorithm parameters
block_size = 51
constant_offset = 10
noise_removal_method = 'morphological'

# Apply Adaptive Gaussian Thresholding to webcam frames
adaptive_gaussian_threshold_webcam(block_size, constant_offset, noise_removal_method)

```

Adjust the block_size and constant_offset parameters to fine-tune the thresholding process. You can choose different noise removal methods, such as 'morphological' or 'filtering', based on the characteristics of your video frames and noise.

Press 'Q' or 'Esc' to stop the webcam capture and exit the algorithm.

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