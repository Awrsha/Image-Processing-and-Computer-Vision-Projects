# Face Detection and Recognition

This Python project is designed for face detection and recognition using pre-trained models and the OpenCV library. It provides the functionality to detect faces in images, visualize the detected faces, and align and crop the faces for recognition. This readme file will guide you through the project structure and usage.

## Prerequisites

Before using this project, ensure that you have the following dependencies installed:

- Python (3.x recommended)
- OpenCV (Open Source Computer Vision Library)
- NumPy
- Matplotlib

You can install the necessary packages using pip:

```bash
pip install opencv-python numpy matplotlib
```

## Project Structure

The project consists of a Python script that performs the following tasks:

1. **Face Detection**: It uses a pre-trained face detection model to detect faces in input images.
2. **Face Visualization**: After detecting faces, it visualizes the detected faces by drawing bounding boxes and key facial landmarks on the input images.
3. **Face Alignment and Cropping**: The script aligns and crops the detected faces for recognition purposes.
4. **Face Recognition**: While the project includes face recognition functionality, it requires a pre-trained model not included in this repository. You need to replace `"face_recognition_sface_2021dec.onnx"` [Download](https://drive.google.com/file/d/1d_7waWWxP0WcUQznbWK49CBeP_swTXNM/view?usp=sharing) with your own face recognition model if you intend to use this feature.

## Usage

To use this project, follow these steps:

1. Clone the repository to your local machine:

```bash
git clone https://github.com/awrsha/simple-deep-face=recognition.git
```

2. Navigate to the project directory:

```bash
cd simple-deep-face-recognition
```

3. Place your input images in the project directory. Make sure they are named `"1.jpg"` and `"3.jpg"` or adjust the script to use your image names.

4. Run the Python script:

```bash
python DeepFaceRecognition.py
```

This will execute the script, perform face detection, visualization, and alignment on the input images, and display the results using Matplotlib.

## Important Notes

- The project uses pre-trained models for face detection and recognition. Ensure you have the necessary model files for your specific use case.
- You can adjust the threshold values and other parameters in the script according to your requirements.
- For face recognition, replace the face recognition model file (`"face_recognition_sface_2021dec.onnx"`) with your own model file if needed.

Feel free to customize and extend this project to suit your face detection and recognition needs. If you have any questions or encounter issues, please refer to the documentation of the libraries used or seek assistance from the community.

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
