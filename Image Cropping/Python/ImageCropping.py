import cv2

img = cv2.imread("Robot.jpg")
selectObject = False
objectCropped = False
selection = None
origin = None
imgClone = None

def onMouse(event, x, y, flags, param):
	global selectObject, selection, origin, img, imgClone, objectCropped

	if selectObject:
		selection = (min(x, origin[0]), min(y, origin[1]), abs(x - origin[0]), abs(y - origin[1]))
		selection = (max(0, selection[0]), max(0, selection[1]), min(img.shape[1], selection[2]), min(img.shape[0], selection[3]))

	if event == cv2.EVENT_LBUTTONDOWN:
		origin = (x, y)
		selection = (x, y, 0, 0)
		selectObject = True
	elif event == cv2.EVENT_LBUTTONUP:
		selectObject = False
		if selection[2] > 0 and selection[3] > 0:
			objectCropped = True

	imgClone = img.copy()
	cv2.rectangle(imgClone, (selection[0], selection[1]), (selection[0] + selection[2], selection[1] + selection[3]), (0, 0, 255), 1, 8, 0)
	cv2.imshow("image", imgClone)

cv2.namedWindow("image", cv2.WINDOW_AUTOSIZE)
cv2.setMouseCallback("image", onMouse)
cv2.imshow("image", img)

d = 1
while d == 1:
	if objectCropped:
		crop = img[selection[1]:selection[1]+selection[3], selection[0]:selection[0]+selection[2]]
		cv2.namedWindow("crop", cv2.WINDOW_AUTOSIZE)
		cv2.imshow("crop", crop)
		d = 0
	cv2.waitKey(10)

cv2.waitKey(0)
cv2.destroyAllWindows()