# Otsu Binarization with Gaussian Filter for Car Plate (Jupyter Notebook)

This repository provides an advanced implementation of the Otsu Binarization algorithm with Gaussian filtering for car plate recognition in a Jupyter Notebook. The algorithm is designed to enhance the readability of car plates by applying a Gaussian filter for noise reduction and then performing Otsu binarization to separate the foreground (car plate) from the background.

## Contents

- [Introduction](#introduction)
- [Getting Started](#getting-started)
- [Usage](#usage)
- [Algorithm](#algorithm)
- [Example](#example)
- [Contributing](#contributing)
- [License](#license)

## Introduction

The Otsu Binarization algorithm with Gaussian filtering is commonly used in optical character recognition (OCR) systems for car plate recognition. This implementation extends the basic algorithm by incorporating Gaussian filtering to remove noise and enhance the quality of the car plate image. The algorithm provides configurable parameters for fine-tuning the binarization process and noise reduction.

## Languages  
<code>
<img align="center" src="https://github.com/devicons/devicon/blob/v2.15.1/icons/python/python-original-wordmark.svg" width="50" height="50" /> <img align="center" src="https://github.com/devicons/devicon/blob/v2.15.1/icons/vscode/vscode-original-wordmark.svg" width="50" height="50"/><img align="center" src="https://github.com/devicons/devicon/blob/v2.15.1/icons/numpy/numpy-original.svg" width="50" height="50"/><img align="center" src="https://github.com/devicons/devicon/blob/v2.15.1/icons/opencv/opencv-original-wordmark.svg" width="50" height="50" /> <img align="center" src="https://github.com/devicons/devicon/blob/v2.15.1/icons/pycharm/pycharm-original.svg" width="50" height="50"/>
</code>

## Getting Started

To use this Otsu Binarization implementation for car plate recognition in your Jupyter Notebook, follow these steps:

1. Clone this repository to your local machine or download the Jupyter Notebook file.
1. Open the Jupyter Notebook file using Jupyter Notebook or JupyterLab.
1. Execute the notebook cells to run the Otsu Binarization algorithm with Gaussian filtering and view the results.

## Usage

To use the Otsu Binarization algorithm with Gaussian filtering for car plate recognition in your Jupyter Notebook, follow these steps:

1. Load an image containing a car plate using the provided utility function or by specifying the image path.
1. Configure the algorithm parameters such as the Gaussian filter size, standard deviation, and Otsu thresholding.
1. Run the algorithm by calling the otsu_binarization_with_gaussian_filter() function, passing the loaded image and the desired parameters.
1. The algorithm will return the binarized car plate image.
1. You can visualize the binarized car plate image using the provided utility function or customize the visualization based on your needs.

Refer to the example section for a more detailed demonstration of the usage.

## Algorithm

The Otsu Binarization algorithm with Gaussian filtering implemented in this notebook follows these steps:

1. Load the car plate image and convert it to grayscale.
1. Apply a Gaussian filter to the grayscale image to reduce noise and enhance the quality of the car plate image.
1. Calculate the Otsu threshold for the filtered image to determine the optimal threshold for binarization.
1. Binarize the filtered image using the Otsu threshold, where pixel values below the threshold are set to 0 (black) and pixel values above the threshold are set to 255 (white).
1. Return the binarized car plate image.

## Example

Here's an example demonstrating the usage of the Otsu Binarization algorithm with Gaussian filtering for car plate recognition:

``` python
# Import the required functions from the OtsuBinarizationWithGaussianFilter.ipynb notebook
from OtsuBinarizationWithGaussianFilter import load_image, otsu_binarization_with_gaussian_filter, visualize_binarized_image

# Load the car plate image
image_path = 'path_to_image.jpg'
image = load_image(image_path)

# Configure the algorithm parameters
gaussian_filter_size = (5, 5)
gaussian_filter_sigma = 1.0
otsu_thresholding = True

# Apply Otsu Binarization with Gaussian filtering
binarized_image = otsu_binarization_with_gaussian_filter(image, gaussian_filter_size, gaussian_filter_sigma, otsu_thresholding)

# Visualize the binarized car plate image
visualize_binarized_image(binarized_image)

```

Make sure to replace 'path_to_image.jpg' with the actual path to your car plate image file. Adjust the gaussian_filter_size and gaussian_filter_sigma parameters to control the amount of noise reduction. Set otsu_thresholding to True for automatic threshold determination using Otsu's method or False to use a fixed threshold.

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
