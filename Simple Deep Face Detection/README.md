# Face Detection with OpenCV, Python, and Deep Learning

This project detects faces and facial landmarks in images using OpenCV and deep learning. A pre-trained facial detection model is used to find faces, and facial landmarks are extracted to identify key points like eyes, nose, and mouth.

## Features

- Face detection using OpenCV and deep learning 
- Facial landmark extraction
- Bounding box and keypoint visualization
- Optimized for performance and readability

## Usage

The main entry point is `Deep Face Detection.ipynb`. Usage:

```
python Deep Face Detection.py --image test.jpg
```

This will run facial detection on `test.jpg` and display the results.

The following arguments are supported:

- `--image`: Path to input image 
- `--detector`: Face detection model file (default is `face_detection_yunet_2023mar.onnx`)
- `--viz_size`: Size of output visualization (default (1024, 1024))

## Detection Model

This implementation relies on the [YOLOv3-based facial detection model](https://github.com/ShiqiYu/libfacedetection) trained by ShiqiYu. The default tiny model works well for near frontal faces and has a good speed/accuracy tradeoff.

Larger models are available but require more GPU memory:

- `face_detection_yunet_2022dec.onnx`
- `face_detection_yunetx_2022dec.onnx` 

Pre-trained models are downloaded automatically on first run. Models are stored in the `models` folder.

## Facial Landmark Model

Facial landmarks are estimated using a lightweight OpenCV DNN model. The default `face_landmark_68.onnx` model detects 68 points and works well for near frontal faces.

Heavier and more accurate models are also available:

- `face_landmark_5.onnx` - 5 point model
- `face_landmark_35.onnx` - 35 point model

## Performance

The pipeline has been optimized for performance by:

- Initializing models and reading images only once
- Getting frame shape directly instead of separate cv2 calls
- Setting detector input size after reading each image
- Storing detections instead of indexing on each loop
- Vectorized drawing of landmarks

On a recent GPU, detection + landmark extraction takes about **65ms per 720p image**. 

## Visualization

By default, faces are drawn as bounding boxes and landmarks as circles. The size and colors can be configured.

Matplotlib is used for display. Tight layout and axes off are used to focus on the detections.

## Requirements

- Python 3
- OpenCV
- NumPy
- Matplotlib

A GPU is strongly recommended but not required.

## References

- [YOLOv3-based Face Detection](https://github.com/ShiqiYu/libfacedetection)
- [OpenCV DNN Face Landmark Models](https://github.com/opencv/opencv_zoo/tree/master/models/face_landmark_model)

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
