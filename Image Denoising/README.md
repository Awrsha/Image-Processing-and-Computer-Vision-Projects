# Image Denoising using Bilateral Filter

## Introduction

This repository contains an implementation of image denoising using the Bilateral Filter in both Python and C++. The Bilateral Filter is a non-linear, edge-preserving, and noise-reducing filter commonly used for image processing tasks. This project demonstrates how to apply the Bilateral Filter to remove noise from images using two different programming languages.

## Table of Contents

- [Requirements](#requirements)
- [Usage](#usage)
  - [Python Implementation](#python-implementation)
  - [C++ Implementation](#c-implementation)
- [Examples](#examples)
- [Contributing](#contributing)
- [License](#license)

## Requirements

Before you can use this code, ensure you have the following dependencies installed:

- **Python Implementation**:
  - Python 3
  - OpenCV (Open Source Computer Vision Library)
  
- **C++ Implementation**:
  - C++ Compiler (e.g., g++)
  - OpenCV (Open Source Computer Vision Library)

You can install the required Python packages using `pip`:

```bash
pip install opencv-python
```

For the C++ implementation, you need to ensure you have OpenCV installed on your system. You can usually install it through a package manager like `apt` on Linux or download it from the [OpenCV website](https://opencv.org/).

## Usage

### Python Implementation

To use the Python implementation of the Bilateral Filter for image denoising, follow these steps:

1. Clone this repository:

   ```bash
   git clone https://github.com/yourusername/image-denoising-bilateral-filter.git
   cd image-denoising-bilateral-filter
   ```

2. Place the noisy image you want to denoise in the `input` directory.

3. Run the Python script:

   ```bash
   python denoise.py
   ```

4. The denoised image will be saved in the `output` directory.

### C++ Implementation

To use the C++ implementation of the Bilateral Filter for image denoising, follow these steps:

1. Clone this repository:

   ```bash
   git clone https://github.com/awrsha/image-denoising.git
   cd image-denoising
   ```

2. Place the noisy image you want to denoise in the `input` directory.

3. Compile the C++ code:

   ```bash
   g++ -o denoise denoise.cpp `pkg-config --cflags --libs opencv`
   ```

4. Run the compiled C++ executable:

   ```bash
   ./denoise
   ```

5. The denoised image will be saved in the `output` directory.

## Examples

You can find example noisy images and their denoised counterparts in the `examples` directory. These examples can help you understand how the Bilateral Filter performs in different scenarios.

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
