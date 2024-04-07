import numpy as np
import cv2
import matplotlib.pyplot as plt

def rgb_to_gray(image):
    return np.dot(image[...,:3], [0.2989, 0.5870, 0.1140])

def detect_and_compute_sift(image):
    sift = cv2.SIFT_create()
    keypoints, descriptors = sift.detectAndCompute(image, None)
    return keypoints, descriptors

def match_keypoints(descriptors1, descriptors2):
    FLANN_INDEX_KDTREE = 1
    index_params = dict(algorithm=FLANN_INDEX_KDTREE, trees=5)
    search_params = dict(checks=50)
    flann = cv2.FlannBasedMatcher(index_params, search_params)
    matches = flann.knnMatch(descriptors1, descriptors2, k=2)
    good_matches = []
    for m, n in matches:
        if m.distance < 0.7 * n.distance:
            good_matches.append(m)
    return good_matches

def find_homography(src_pts, dst_pts):
    A = []
    for i in range(len(src_pts)):
        x, y = src_pts[i][0]
        u, v = dst_pts[i][0]
        A.append([-x, -y, -1, 0, 0, 0, u * x, u * y, u])
        A.append([0, 0, 0, -x, -y, -1, v * x, v * y, v])
    A = np.asarray(A)
    _, _, V = np.linalg.svd(A)
    H = V[-1, :].reshape((3, 3))
    return H / H[2, 2]

def perspective_transform(pts, H):
    transformed_pts = []
    for pt in pts:
        x, y = pt[0]
        denominator = H[2, 0] * x + H[2, 1] * y + H[2, 2]
        u = (H[0, 0] * x + H[0, 1] * y + H[0, 2]) / denominator
        v = (H[1, 0] * x + H[1, 1] * y + H[1, 2]) / denominator
        transformed_pts.append([u, v])
    return np.float32(transformed_pts)

def draw_polyline(image, pts):
    pts = pts.reshape(-1, 2).astype(int)  # Convert to int and reshape
    for i in range(len(pts)):
        cv2.line(image, tuple(pts[i]), tuple(pts[(i + 1) % len(pts)]), (0, 255, 0), 3, cv2.LINE_AA)

# Load the images
original_img1 = cv2.imread('pahlavi.jpg')
original_img2 = cv2.imread('coins.jpg')

# Convert images to grayscale
img1 = cv2.cvtColor(original_img1, cv2.COLOR_BGR2GRAY)
img2 = cv2.cvtColor(original_img2, cv2.COLOR_BGR2GRAY)

# Detect and compute SIFT keypoints and descriptors
kp1, des1 = detect_and_compute_sift(img1)
kp2, des2 = detect_and_compute_sift(img2)

# Match keypoints using FLANN
matches = match_keypoints(des1, des2)

MIN_MATCH_COUNT = 10

if len(matches) > MIN_MATCH_COUNT:
    src_pts = np.float32([kp1[m.queryIdx].pt for m in matches]).reshape(-1, 1, 2)
    dst_pts = np.float32([kp2[m.trainIdx].pt for m in matches]).reshape(-1, 1, 2)
    
    # Find homography matrix using RANSAC
    M = find_homography(src_pts, dst_pts)
    
    h, w = img1.shape
    pts = np.float32([[0, 0], [0, h - 1], [w - 1, h - 1], [w - 1, 0]]).reshape(-1, 1, 2)
    
    # Transform points based on homography matrix
    transformed_pts = perspective_transform(pts, M)
    
    # Draw polygon on the second image
    draw_polyline(original_img2, transformed_pts)
    
    result = original_img2
else:
    print("Not enough matches are found - {}/{}".format(len(matches), MIN_MATCH_COUNT))
    result = original_img2

# Display the images
plt.figure(figsize=[15, 4])
plt.subplot(131), plt.imshow(original_img1[..., ::-1]), plt.title('Image1')
plt.subplot(132), plt.imshow(original_img2[..., ::-1]), plt.title('Image2')
plt.subplot(133), plt.imshow(result[..., ::-1]), plt.title('Result')
plt.show()