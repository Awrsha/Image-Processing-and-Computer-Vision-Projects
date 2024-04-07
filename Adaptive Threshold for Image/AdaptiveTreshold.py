import cv2
import numpy as np
import matplotlib.pyplot as plt

# Load our new image
original_image = cv2.imread('C:\\Users\\nilfam\\Desktop\\Coding\\Futures\\Adaptive Treshold for Image\\Robot.jpg', 0)
#Noise removal
noise_removed_image = cv2.medianBlur(original_image,5)# or cv2.GaussianBlur(original_image,(5,5),0)

_,output1 = cv2.threshold(original_image,127,255,cv2.THRESH_BINARY)
output2 = cv2.adaptiveThreshold(original_image,255,cv2.ADAPTIVE_THRESH_MEAN_C, cv2.THRESH_BINARY,11,2)
output3 = cv2.adaptiveThreshold(original_image,255,cv2.ADAPTIVE_THRESH_GAUSSIAN_C, cv2.THRESH_BINARY,11,2)

_,output4 = cv2.threshold(noise_removed_image,127,255,cv2.THRESH_BINARY)
output5 = cv2.adaptiveThreshold(noise_removed_image,255,cv2.ADAPTIVE_THRESH_MEAN_C, cv2.THRESH_BINARY,11,2)
output6 = cv2.adaptiveThreshold(noise_removed_image,255,cv2.ADAPTIVE_THRESH_GAUSSIAN_C, cv2.THRESH_BINARY,11,2)


plt.figure(figsize=[15,15])
plt.subplot(331);plt.imshow(original_image, cmap='gray');plt.title("Original");
plt.subplot(332);plt.imshow(noise_removed_image, cmap='gray');plt.title("Noise removed");

plt.subplot(334);plt.imshow(output1, cmap='gray');plt.title("Global Thresholding (v = 127)");
plt.subplot(335);plt.imshow(output2, cmap='gray');plt.title("Adaptive Mean Thresholding");
plt.subplot(336);plt.imshow(output3, cmap='gray');plt.title("Adaptive Gaussian Thresholding");

plt.subplot(337);plt.imshow(output4, cmap='gray');plt.title("Global Thresholding + noise removal");
plt.subplot(338);plt.imshow(output5, cmap='gray');plt.title("Adaptive Mean + noise removal");
plt.subplot(339);plt.imshow(output6, cmap='gray');plt.title("Adaptive Gaussian + noise removal");