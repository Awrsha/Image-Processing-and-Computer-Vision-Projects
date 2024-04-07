# Mask RCNN Object Detection

This project demonstrates the use of the Mask RCNN (Region-based Convolutional Neural Network) model for object detection and instance segmentation. The Mask RCNN model is a powerful tool for identifying and segmenting objects in images and videos.

## Prerequisites

Before you begin, make sure you have the following prerequisites in place:

- Python 3.7 or higher
- OpenCV (`cv2`)
- NumPy (`numpy`)
- Matplotlib (`matplotlib`)
- TensorFlow (1.x or 2.x)
- Pretrained Mask RCNN model (downloaded from [TensorFlow Model Zoo](http://download.tensorflow.org/models/object_detection/mask_rcnn_inception_v2_coco_2018_01_28.tar.gz))

## Getting Started

1. **Download the Pretrained Model**

   Download the Mask RCNN model from the TensorFlow website using the following link: [Mask RCNN Inception v2 COCO Model](http://download.tensorflow.org/models/object_detection/mask_rcnn_inception_v2_coco_2018_01_28.tar.gz). Extract the contents of the archive to your project directory.

2. **Install Dependencies**

   Install the required Python packages if you haven't already by running the following command:

   ```shell
   pip install opencv-python-headless numpy matplotlib tensorflow
   ```

3. **Clone or Download the Project**

   Clone this GitHub repository or download the project files to your local machine.

4. **Run the Project**

   Open a terminal and navigate to the project directory. Run the script using the following command:

   ```shell
   python project_script_name.py
   ```

   Replace `your_script_name.py` with the name of the script where you've implemented the Mask RCNN code.

## Code Overview

The project code provides a basic example of how to use the Mask RCNN model for object detection and instance segmentation. Here's a brief overview of the main components of the code:

- **Loading the Model**: The code loads the pretrained Mask RCNN model from the downloaded files (`mask_rcnn_inception_v2_coco_2018_01_28.pbtxt` and `mask_rcnn_frozen_inference_graph.pb`) using OpenCV's `cv2.dnn` module.

- **Setting Parameters**: Parameters like confidence threshold (`confThreshold`) and mask threshold (`maskThreshold`) are initialized.

- **Drawing Bounding Boxes and Masks**: The `drawBox` function is responsible for drawing bounding boxes and masks around detected objects. It also labels the objects with their class names.

- **Postprocessing**: The `postprocess` function extracts bounding boxes and masks for each detected object and calls the `drawBox` function to visualize the results.

- **Loading Class Names and Colors**: The code loads class names from `mscoco_labels.names` and colors from `colors.txt`.

- **Running Inference**: The code reads an example image (`pedestrian.jpg`), processes it using the Mask RCNN model, and displays the results using Matplotlib.

## Customization

You can customize this code to work with your own images and adapt it for various object detection and segmentation tasks. Additionally, you can fine-tune the confidence and mask thresholds to adjust the detection sensitivity.

Feel free to explore and build upon this project to suit your specific needs.

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
