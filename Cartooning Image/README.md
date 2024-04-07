## Cartooning an Image using OpenCV – Python

<p>
Computer Vision as you know (or even if you don’t) is a very powerful tool with immense possibilities. So, when I set up to prepare a comic of one of my friend’s college life, I soon realized that I needed something that would reduce my efforts of actually painting it but will retain the quality and I came up with the following solution.
</p>

## Languages  
<code>
<img align="center" src="https://github.com/devicons/devicon/blob/v2.15.1/icons/python/python-original-wordmark.svg" width="50" height="50" /> <img align="center" src="https://github.com/devicons/devicon/blob/v2.15.1/icons/vscode/vscode-original-wordmark.svg" width="50" height="50"/><img align="center" src="https://github.com/devicons/devicon/blob/v2.15.1/icons/numpy/numpy-original.svg" width="50" height="50"/><img align="center" src="https://github.com/devicons/devicon/blob/v2.15.1/icons/opencv/opencv-original-wordmark.svg" width="50" height="50" /> <img align="center" src="https://github.com/devicons/devicon/blob/v2.15.1/icons/pycharm/pycharm-original.svg" width="50" height="50"/>
</code>

## Requirements

To run this program, you will need:
- Python 3.x installed on your machine
- NumPy library for Python
- Matplotlib library for Python

## Installation

1. Install Python 3.x from the official website: [https://www.python.org/downloads/ ↗](https://www.python.org/downloads/)
2. Install NumPy library using pip:
   ```
   pip install numpy
   ```
3. Install Matplotlib library using pip:
   ```
   pip install matplotlib
   ```
4. Install OpenCV library using pip:
   ```
   pip install opencv-python
   ```


## Explanation:

<p>
Basically, we are going to use a series of filters and image conversions.

* First we downscale the image and then apply bilateral filter to get a cartoon flavor. Then again we upscale the image.

* Next step is getting a blurred version of the original image. Now, we don’t want the colours to interfere in this process. We only want the blurring of the boundaries. For this, we first convert the image to gray – scale and then we apply the media blur filter.

* Next step is to identify the edges in the image and then add this to the previously modified images to get a sketch pen effect. For this first we are using adaptive threshold. You can experiment with other types of threshold techniques also. Because Computer Vision is all about experimenting. In step 5, we compile the final images obtained from the previous steps.

</p>

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

