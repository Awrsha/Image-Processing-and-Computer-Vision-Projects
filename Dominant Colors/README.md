# Dominant Colors with Clustering (K-Mean) and Histogram

This repository provides an advanced implementation of the Dominant Colors algorithm using clustering and histogram techniques in a Jupyter Notebook without the use of external libraries. The Dominant Colors algorithm is commonly used in image processing and computer vision to extract the most prominent colors from an image.

## Contents

- [Introduction](#introduction)
- [Getting Started](#getting-started)
- [Usage](#usage)
- [Algorithm](#algorithm)
- [Example](#example)
- [Contributing](#contributing)
- [License](#license)

## Introduction

The Dominant Colors algorithm aims to identify the most prominent colors in an image. This implementation utilizes clustering algorithms and histogram analysis to extract these dominant colors without relying on external libraries. The algorithm provides flexibility in selecting the number of dominant colors to extract and offers customizable parameters for fine-tuning the results.

## Languages  
<code>
<img align="center" src="https://github.com/devicons/devicon/blob/v2.15.1/icons/python/python-original-wordmark.svg" width="50" height="50" /> <img align="center" src="https://github.com/devicons/devicon/blob/v2.15.1/icons/vscode/vscode-original-wordmark.svg" width="50" height="50"/><img align="center" src="https://github.com/devicons/devicon/blob/v2.15.1/icons/numpy/numpy-original.svg" width="50" height="50"/><img align="center" src="https://github.com/devicons/devicon/blob/v2.15.1/icons/opencv/opencv-original-wordmark.svg" width="50" height="50" /> <img align="center" src="https://github.com/devicons/devicon/blob/v2.15.1/icons/pycharm/pycharm-original.svg" width="50" height="50"/>
  
## Getting Started

To use this Dominant Colors implementation in your Jupyter Notebook, follow these steps:

1. Clone this repository to your local machine or download the Jupyter Notebook file.
2. Open the Jupyter Notebook file using Jupyter Notebook or JupyterLab.
3. Execute the notebook cells to run the Dominant Colors algorithm and view the results.

## Usage

To use the Dominant Colors algorithm in your Jupyter Notebook, follow these steps:

1. Load an image using the provided utility function or by specifying the image path.
2. Configure the algorithm parameters such as the number of dominant colors to extract and the clustering algorithm to use.
3. Run the algorithm by calling the `extract_dominant_colors()` function, passing the loaded image and the desired parameters.
4. The algorithm will return the dominant colors as a list of RGB tuples.
5. You can visualize the dominant colors using the provided utility function or by customizing the visualization based on your needs.

Refer to the example section for a more detailed demonstration of the usage.

## Algorithm

The Dominant Colors algorithm implemented in this notebook utilizes the following steps:

1. Load the image and convert it to the RGB color space.
2. Flatten the image into a 2D array of pixels, where each row represents a pixel with RGB values.
3. Apply a clustering algorithm, such as K-means or DBSCAN, to cluster the pixels based on their RGB values.
4. Extract the centroids or representative colors of the clusters as the dominant colors.
5. Sort the dominant colors based on their frequency of occurrence or importance.
6. Return the dominant colors as a list of RGB tuples.

## Example

Here's an example demonstrating the usage of the Dominant Colors algorithm:

```python
# Import the required functions from the DominantColors.ipynb notebook
from DominantColors import load_image, extract_dominant_colors, visualize_dominant_colors

# Load the image
image_path = 'path_to_image.jpg'
image = load_image(image_path)

# Configure the algorithm parameters
num_colors = 5
clustering_algorithm = 'kmeans'

# Extract the dominant colors
dominant_colors = extract_dominant_colors(image, num_colors, clustering_algorithm)

# Visualize the dominant colors
visualize_dominant_colors(dominant_colors)
```

Make sure to replace `'path_to_image.jpg'` with the actual path to your image file. Adjust the `num_colors` parameter to specify the desired number of dominant colors to extract. You can choose between different clustering algorithms, such as `'kmeans'` or `'dbscan'`, based on your requirements.

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
