# Object Detection using OpenCV and TensorFlow

This repository contains a Python script that demonstrates object detection using OpenCV and TensorFlow. The script loads a pre-trained object detection model and uses it to detect objects in an input image, drawing bounding boxes and labels around the detected objects.

## Prerequisites

Before you can run the script, you'll need the following:

1. **Python**: Make sure you have Python installed. You can download it from [python.org](https://www.python.org/downloads/).

2. **OpenCV**: Install OpenCV using pip:

   ```shell
   pip install opencv-python
   ```

3. **NumPy**: Install NumPy using pip:

   ```shell
   pip install numpy
   ```

4. **Matplotlib**: Install Matplotlib using pip:

   ```shell
   pip install matplotlib
   ```

5. **Download Pre-trained Model**: You will need to download the pre-trained model and class names. Use the following links to download the required files:

   - [Download `frozen_inference_graph.pb`](https://drive.google.com/file/d/1qscnbsFyFVoJv6V02WUoAja8XY0rASfZ/view?usp=drive_link)
   - [Download `ssd_mobilenet_v2_coco_2018_03_29.pbtxt`](https://github.com/opencv/opencv/blob/master/samples/dnn/ssd_mobilenet_v2_coco_2018_03_29.pbtxt)
   - [Download `object_detection_classes_coco.txt`](https://github.com/pjreddie/darknet/blob/master/data/coco.names)

## Usage

1. **Clone the Repository**:

   ```shell
   git clone https://github.com/awrsha/object-detection.git
   cd object-detection
   ```

2. **Run the Script**:

   ```shell
   python object_detection.py
   ```

   Replace `object_detection.py` with the name of your script if it's different.

3. **View the Output**: The script will process the `test.jpg` image and display it with bounding boxes and labels around detected objects.

## Customization

You can customize the script by modifying the following parameters:

- `input_size`: Adjust the input size for the model. Smaller sizes may improve performance but reduce accuracy.
- `conf_threshold`: Change the confidence threshold to control the detection confidence level.
- `nms_threshold`: Adjust the Non-Maximum Suppression (NMS) threshold to control the number of overlapping bounding boxes.

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
