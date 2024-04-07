# Image Inpainting with FMM (TELEA) and NS

This project demonstrates the application of inpainting techniques using the Fast Marching Method (TELEA) and Navier-Stokes (NS) algorithms to restore missing or damaged parts of an image. Inpainting is a process of filling in the missing regions of an image based on the surrounding information.

## Prerequisites

- Python 3
- OpenCV (cv2) library
- NumPy library

## Languages  
<code>
<img align="center" src="https://github.com/devicons/devicon/blob/v2.15.1/icons/python/python-original-wordmark.svg" width="50" height="50" /> <img align="center" src="https://github.com/devicons/devicon/blob/v2.15.1/icons/vscode/vscode-original-wordmark.svg" width="50" height="50"/><img align="center" src="https://github.com/devicons/devicon/blob/v2.15.1/icons/numpy/numpy-original.svg" width="50" height="50"/><img align="center" src="https://github.com/devicons/devicon/blob/v2.15.1/icons/opencv/opencv-original-wordmark.svg" width="50" height="50" /> <img align="center" src="https://github.com/devicons/devicon/blob/v2.15.1/icons/pycharm/pycharm-original.svg" width="50" height="50"/>
</code>

## Installation

1. Clone the repository to your local machine:

   ```shell
   git clone https://github.com/Awrsha/image-inpainting.git
   ```

1. Install the required libraries using pip:

   ```shell
   pip install opencv-python
   ```

   ```shell
   pip install numpy
   ```

## Usage

1. Place the image file you want to inpaint in the project directory. Ensure that the image file is in a supported format (e.g., PNG, JPEG).

1. Open the `ImageInpainting.py` file in a text editor.

1. Modify the following line of code to specify the image file name:

   ```python
   img = cv.imread("your_image.png", cv.IMREAD_COLOR)
   ```

1. Run the script:

   ```shell
   python ImageInpainting.py
   ```

1. The image window will open, displaying the original image. Use the mouse to sketch over the areas you want to inpaint.

1. Press the following keys to perform inpainting:

   - Press 't' to use the Fast Marching Method (TELEA) algorithm for inpainting.
   - Press 'n' to use the Navier-Stokes (NS) algorithm for inpainting.
   - Press 'r' to reset the sketch and start over.

1. The inpainted result will be displayed in a separate window.

1. Press 'Esc' key to exit the program.

## Examples

The following example demonstrates the input image, the generated mask, and the segmented output:

![Example](<https://github.com/Awrsha/Image-Inpainting/blob/master/blemish.png>)
<br>
![Example](<https://github.com/Awrsha/Image-Inpainting/blob/master/inpaintMask.png>)

## References

- Fast Marching Method (TELEA) algorithm: [An Image Inpainting Technique Based on the Fast Marching Method](https://www.semanticscholar.org/paper/An-Image-Inpainting-Technique-Based-on-the-Fast-Telea/67d0cb47d14150daff08980efbea9f1267d3a4e5?p2df)
- Navier-Stokes (NS) algorithm: [Navier-Stokes, Fluid Dynamics, and Image and Video Inpainting](https://www.semanticscholar.org/paper/Navier-Stokes%2C-Fluid-Dynamics%2C-and-Image-and-Bertalmio-Bertozzi/0ef7a7e4be421c5982a49b4a6c66f98dfdf9d057)

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
