# Pose Detection with OpenCV and Caffe

![Example Image](https://github.com/Awrsha/Simple-Open-Pose/blob/master/volleyball.jpg)

This project demonstrates how to perform pose detection using OpenCV and Caffe. It detects keypoints on a person's body and visualizes them as a skeleton on the input image.

## Table of Contents

- [Introduction](#introduction)
- [Requirements](#requirements)
- [Installation](#installation)
- [Usage](#usage)
- [Demo](#demo)
- [Results](#results)
- [Contributing](#contributing)
- [License](#license)

## Introduction

Pose detection is a computer vision task that involves identifying key body parts, such as joints, on a human body. In this project, we use OpenCV and the Caffe deep learning framework to perform real-time pose detection on images.

## Requirements

Before you begin, ensure you have met the following requirements:

- Python 3.x
- OpenCV
- Caffe (Make sure the Caffe model files are downloaded and configured correctly)
- NumPy
- Matplotlib

## Installation

To install the required packages, you can use `pip`:

```bash
pip install opencv-python numpy matplotlib
```

Please refer to the official OpenCV and Caffe documentation for installation instructions specific to your platform.

## Usage

1. Clone this repository:

   ```bash
   git clone https://github.com/awrsha/simple-open-pose.git
   cd pose-detection
   ```

2. Download the Caffe model files (`pose_deploy_linevec_faster_4_stages.prototxt` and `pose_iter_160000.caffemodel`) and place them in the `model/caffe/` directory.

3. Run the pose detection script:

   ```bash
   python OpenPose.py
   ```

   Replace `volleyball.jpg` with the path to your own image.

## Demo

Here's an example of what the pose detection can achieve:

![Example Image with Skeleton](https://github.com/Awrsha/Simple-Open-Pose/blob/master/output.png)

## Results

The script will load the image, perform pose detection, and display the result with keypoints and a skeleton overlay. You can customize the threshold and other parameters in the script to fine-tune the detection.

## Contributing

Contributions are welcome! If you want to contribute to this project, please follow these steps:

1. Fork the project.
2. Create your feature branch (`git checkout -b feature/your-feature`).
3. Commit your changes (`git commit -m 'Add some feature'`).
4. Push to the branch (`git push origin feature/your-feature`).
5. Open a pull request.

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
