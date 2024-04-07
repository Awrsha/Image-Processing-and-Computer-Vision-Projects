import cv2
import numpy as np

cap = cv2.VideoCapture("blue-track.mp4")

while True:
    ret, frame = cap.read()
    if not ret:
        break
    hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)
    
    lower_blue = np.array([100,50,50])
    upper_blue = np.array([130,255,255])
    
    mask = cv2.inRange(hsv, lower_blue, upper_blue)
    contours, _ = cv2.findContours(mask, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)
    centers, radius = cv2.minEnclosingCircle(contours[0])
    centers = int(centers[0]), int(centers[1])
    radius = int(radius)
    cv2.circle(frame, centers, radius, (0,0,255), 2)
    cv2.imshow('image',frame)
    
    k = cv2.waitKey(5) & 0xFF
    if k == 27:
        break

cv2.destroyAllWindows()
cap.release()