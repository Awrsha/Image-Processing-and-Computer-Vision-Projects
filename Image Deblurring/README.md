# Image Deblurring with Python

![Image blurring](https://github.com/Awrsha/Image-Deblurring/blob/master/Image%20Deblurring%20using%20Blind%20Deconvolution/blurred_image.jpg)

This repository contains Python code and examples for image deblurring using three different algorithms: Blind Deconvolution, Wiener Filter, and Lucy-Richardson Algorithm. These techniques are used to restore images that have been blurred due to various factors such as motion blur, camera shake, or lens imperfections.

## Table of Contents

- [Introduction](#introduction)
- [Algorithms](#algorithms)
- [Getting Started](#getting-started)
- [Usage](#usage)
- [Contributing](#contributing)
- [License](#license)

## Introduction

Image deblurring is the process of removing blur from a degraded image to recover the original, sharp image. This repository provides Python implementations of three popular deblurring algorithms:

1. **Blind Deconvolution**: A technique for deblurring when no prior information about the blur kernel is available. The algorithm simultaneously estimates the sharp image and the point-spread function (PSF).

2. **Wiener Filter**: A frequency-domain deblurring method that uses a known or estimated PSF to restore the image. It is effective when the blur kernel is known or can be estimated.

3. **Lucy-Richardson Algorithm**: An iterative deblurring algorithm that is useful when some knowledge about the PSF is available. It iteratively estimates the sharp image.

## Algorithms

- **Blind Deconvolution**:
  - Implementation using the Richardson-Lucy algorithm.
  - Simultaneously estimates the sharp image and the PSF.
  - Suitable for scenarios where no prior knowledge of the blur kernel is available.

- **Wiener Filter**:
  - Frequency-domain deblurring method.
  - Effective when the PSF is known or can be estimated.
  - Minimizes the trade-off between noise reduction and image sharpening.

- **Lucy-Richardson Algorithm**:
  - Iterative deblurring method.
  - Requires some knowledge or estimation of the PSF.
  - Restores the image by iteratively estimating the sharp image.

## Getting Started

1. Clone this repository to your local machine:

   ```bash
   git clone https://github.com/awrsha/image-deblurring.git
   ```

2. Install the required Python packages:

   ```bash
   pip install numpy, opencv-python, scipy, matplotlib.pyplot
   ```

## Usage

- Navigate to the specific algorithm directory (e.g., `blind_deconvolution`, `wiener_filter`, or `lucy_richardson`).
- Follow the instructions in the respective README files to run and experiment with each algorithm.

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
