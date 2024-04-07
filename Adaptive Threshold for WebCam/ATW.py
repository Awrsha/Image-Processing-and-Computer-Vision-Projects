import cv2
import numpy as np
import matplotlib.pyplot as plt

# Initialize the webcam
cap = cv2.VideoCapture(0)

while True:
    # Read a frame from the webcam
    ret, original_image = cap.read()
    if not ret:
        break
    
    # Convert the image to grayscale
    original_image = cv2.cvtColor(original_image, cv2.COLOR_BGR2GRAY)
    
    # Noise removal
    noise_removed_image = cv2.medianBlur(original_image, 5)  # or cv2.GaussianBlur(original_image, (5, 5), 0)

    # Thresholding
    _, output1 = cv2.threshold(original_image, 127, 255, cv2.THRESH_BINARY)
    output2 = cv2.adaptiveThreshold(original_image, 255, cv2.ADAPTIVE_THRESH_MEAN_C, cv2.THRESH_BINARY, 11, 2)
    output3 = cv2.adaptiveThreshold(original_image, 255, cv2.ADAPTIVE_THRESH_GAUSSIAN_C, cv2.THRESH_BINARY, 11, 2)

    # Thresholding with noise removal
    _, output4 = cv2.threshold(noise_removed_image, 127, 255, cv2.THRESH_BINARY)
    output5 = cv2.adaptiveThreshold(noise_removed_image, 255, cv2.ADAPTIVE_THRESH_MEAN_C, cv2.THRESH_BINARY, 11, 2)
    output6 = cv2.adaptiveThreshold(noise_removed_image, 255, cv2.ADAPTIVE_THRESH_GAUSSIAN_C, cv2.THRESH_BINARY, 11, 2)

    # Display the results in separate windows
    cv2.imshow('Original', original_image)
    cv2.imshow('Noise removed', noise_removed_image)
    cv2.imshow('Global Thresholding (v = 127)', output1)
    cv2.imshow('Adaptive Mean Thresholding', output2)
    cv2.imshow('Adaptive Gaussian Thresholding', output3)
    cv2.imshow('Global Thresholding + noise removal', output4)
    cv2.imshow('Adaptive Mean + noise removal', output5)
    cv2.imshow('Adaptive Gaussian + noise removal', output6)

    # Exit if the 'q' key is pressed
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

# Release the webcam and close all windows
cap.release()
cv2.destroyAllWindows()