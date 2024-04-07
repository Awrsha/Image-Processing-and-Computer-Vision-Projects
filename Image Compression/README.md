# Image Compression using DCT, SVD and Wavelet Transform

## Overview

This project implements various image compression techniques like Discrete Cosine Transform (DCT), Singular Value Decomposition (SVD) and Wavelet Transform in Python using OpenCV and other libraries. 

The goal is to compare different compression algorithms and achieve high compression ratios with minimal loss of quality.

## Algorithms

### Discrete Cosine Transform (DCT)

- Applies 2D DCT on the image divided into 8x8 blocks
- Quantizes the DCT coefficients to reduce precision
- Inverse DCT reconstructs compressed image

### Singular Value Decomposition (SVD)

- Performs SVD on the image matrix
- Sets smaller singular values to 0 to reduce dimensions
- Obtains compressed image by multiplying remaining singular vectors

### Wavelet Transform 

- Applies 2D Wavelet Transform to decompose image into frequency sub-bands
- Keeps high energy coefficients, sets others to 0 
- Inverse transform reconstructs compressed image

## Usage

The project contains Python scripts implementing each algorithm.

To compress an image:

```
python DCT.py test.jpg compressed_output.jpg quality
```

This applies DCT on the input image and saves compressed image to output path. 'quality' parameter controls compression level.

Similarly for SVD:

```
python SVD.py test.jpg compressed_output.jpg num_values
``` 

'num_values' controls how many singular values to retain.

And for wavelet compression:

```
python WT.py test.jpg compressed_output.jpg num_coeffs 
```

'num_coeffs' sets the number of wavelet coefficients to keep.

Lower quality/num_values/num_coeffs gives higher compression but loses more details.

## Results

The techniques can achieve upto 90% compression on typical images with reasonable quality. DCT performs better on smooth regions while wavelets preserve edges better.

![Results](https://github.com/Awrsha/Image-Compression/blob/master/Image%20Compression%20using%20Discrete%20Cosine%20Transform%20(DCT)/compressed.jpg)

## References

- DCT algorithm adopted from OpenCV docs
- SVD implementation based on scikit-image 
- Wavelet compression uses PyWavelets library

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
