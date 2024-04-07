import numpy as np
import cv2

def rotate_image(image, angle):
    # Convert the angle to radians
    theta = np.radians(angle)

    # Get the image shape
    height, width = image.shape[:2]

    # Calculate the coordinates of the center of the image
    center_x, center_y = width/2, height/2

    # Calculate the rotation matrix
    rotation_matrix = np.array([[np.cos(theta), -np.sin(theta), (1-np.cos(theta))*center_x + np.sin(theta)*center_y],
                                [np.sin(theta), np.cos(theta), (1-np.cos(theta))*center_y - np.sin(theta)*center_x],
                                [0, 0, 1]])

    # Apply the rotation matrix to the image
    rotated_image = cv2.warpPerspective(image, rotation_matrix, (width, height))

    return rotated_image

# Load the input image
image = cv2.imread("C:\\Users\\nilfam\\Desktop\\Coding\\Done\\Image Rotation\\Robot.jpg")

if image is None:
    print("Could not read the image")
    exit()

# Rotate the image
rotated_image = rotate_image(image, 45)

# Display the output image
cv2.imshow("Rotated Image", rotated_image)
cv2.waitKey(0)
cv2.destroyAllWindows()