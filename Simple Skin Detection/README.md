# Simple Skin Detection

Skin detection is the process of identifying regions of human skin in an image or video.

## How it Works

The code performs skin detection using color-based thresholding in two color spaces: YCrCb and HSV.

1. The image is first converted from the BGR color space to the YCrCb color space using `cv2.cvtColor()` function.
1. The image is also converted to the HSV color space using `cv2.cvtColor()` function.
1. Lower and upper thresholds are defined for skin color in both YCrCb and HSV color spaces.
1. Thresholding is applied to create binary masks for skin color in both color spaces using `cv2.inRange()` function.
1. The binary masks from both color spaces are combined using `cv2.bitwise_and()` function.
1. A series of erosions and dilations are applied to the mask using an elliptical kernel to reduce noise using `cv2.erode()` and `cv2.dilate()` functions.
1. The mask is blurred using Gaussian blur to further reduce noise using `cv2.GaussianBlur()` function.
1. Finally, the skin mask is applied to the original image using `cv2.bitwise_and()` function to obtain the skin detection result.

## Languages  
<code>
<img align="center" src="https://github.com/devicons/devicon/blob/v2.15.1/icons/python/python-original-wordmark.svg" width="50" height="50" /> <img align="center" src="https://github.com/devicons/devicon/blob/v2.15.1/icons/vscode/vscode-original-wordmark.svg" width="50" height="50"/><img align="center" src="https://github.com/devicons/devicon/blob/v2.15.1/icons/numpy/numpy-original.svg" width="50" height="50"/><img align="center" src="https://github.com/devicons/devicon/blob/v2.15.1/icons/opencv/opencv-original-wordmark.svg" width="50" height="50" /> <img align="center" src="https://github.com/devicons/devicon/blob/v2.15.1/icons/pycharm/pycharm-original.svg" width="50" height="50"/>
</code>

## Installation

1. Clone the repository to your local machine:

   ```shell
   git clone https://github.com/Awrsha/Simple-Skin-Detection.git
   ```

1. Install the required libraries using pip:

   ```shell
   pip install opencv-python
   ```

   ```shell
   pip install numpy
   ```

   ```shell
   pip install matplotlib.pyplot
   ```
   
## Usage

1. Make sure you have OpenCV and NumPy installed in your Python environment.
1. Save the code in a Python file (e.g., `SkinDetection.py`).
1. Replace the `"ME.JPG"` with the path to your input image.
1. Run the script using a Python interpreter.
1. The script will display the original image and the skin detection result using Matplotlib.

```python
import cv2
import numpy as np
import matplotlib.pyplot as plt

# Function for skin detection
def skin_detection(image):
    # Convert image to YCrCb color space
    ycrcb = cv2.cvtColor(image, cv2.COLOR_BGR2YCrCb)
    # Convert image to hsv color space
    hsv = cv2.cvtColor(image, cv2.COLOR_BGR2HSV)

    # Define lower and upper thresholds for skin color in YCrCb space
    lower_threshold_ycrcb = np.array([0, 133, 77], dtype=np.uint8)
    upper_threshold_ycrcb = np.array([255, 173, 127], dtype=np.uint8)

    # Define lower and upper thresholds for skin color in HSV space
    lower_threshold_hsv = np.array([0, 48, 80], dtype=np.uint8)
    upper_threshold_hsv = np.array([20, 255, 255], dtype=np.uint8)

    # Apply skin color thresholding in YCrCb space
    skin_mask_ycrcb = cv2.inRange(ycrcb, lower_threshold_ycrcb, upper_threshold_ycrcb)

    # Apply skin color thresholding in HSV space
    skin_mask_hsv = cv2.inRange(hsv, lower_threshold_hsv, upper_threshold_hsv)

    # Combine skin detection from ycrcb and hsv
    skin_mask = cv2.bitwise_and(skin_mask_ycrcb, skin_mask_hsv)

    # Apply a series of erosions and dilations to the mask using an elliptical kernel
    kernel = cv2.getStructuringElement(cv2.MORPH_ELLIPSE, (3, 3))
    skin_mask = cv2.erode(skin_mask, kernel, iterations=2)
    skin_mask = cv2.dilate(skin_mask, kernel, iterations=2)

    # Blur the mask to help remove noise, then apply the mask to the frame
    skin_mask = cv2.GaussianBlur(skin_mask, (3, 3), 0)
    skin = cv2.bitwise_and(image, image, mask=skin_mask)

    return skin


# Load the image
image = cv2.imread("ME.JPG")

# Perform skin detection
skin_detected = skin_detection(image)

# Convert BGR to RGB for matplotlib
skin_detected_rgb = cv2.cvtColor(skin_detected, cv2.COLOR_BGR2RGB)

# Display the original image and the skin detection result using Matplotlib
fig, axes = plt.subplots(1, 2, figsize=(10, 5))
axes[0].imshow(cv2.cvtColor(image, cv2.COLOR_BGR2RGB))
axes[0].set_title("Original Image")
axes[0].axis("off")
axes[1].imshow(skin_detected_rgb)
axes[1].set_title("Skin Detection Result")
axes[1].axis("off")
plt.show()
```

## Further Improvements

This code provides a basic implementation of skin detection. However, skin color can vary across individuals and lighting conditions, which may affect the accuracy of the detection. Here are some potential improvements:

1. Fine-tune the color thresholds for skin detection basedon the specific characteristics of the target population or application.
1. Explore alternative color spaces or feature representations that may better capture skin color variations.
1. Utilize machine learning techniques, such as training a skin classifier using labeled skin/non-skin samples, to improve the accuracy of skin detection.
1. Consider incorporating additional image processing techniques, such as edge detection or texture analysis, to enhance the skin detection algorithm.
1. Implement real-time skin detection by integrating the code into a video processing pipeline.

Remember that skin detection is a challenging task, and the performance of the algorithm may vary depending on the specific application and environmental conditions. It's important to evaluate and fine-tune the algorithm based on the specific requirements and constraints of your project.

## Conclusion

Skin detection is a fundamental step in many computer vision applications, such as face detection, gesture recognition, and image-based biometrics. This code snippet provides a starting point for implementing a simple skin detection algorithm using OpenCV. By understanding the underlying principles and experimenting with different techniques, you can further enhance the accuracy and robustness of the skin detection process in your own projects.

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
