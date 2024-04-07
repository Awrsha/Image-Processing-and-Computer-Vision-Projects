import numpy as np
import cv2
from matplotlib import pyplot as plt

draw_rectangle = False
drawing = False
rect_or_mask = -1
rect_is_drawed = False

def onmouse(event, x, y, flags, param):
    # Draw Rectangle
    global draw_rectangle, start_point, rect, drawing, rect_or_mask, draw_image, rect_is_drawed
    if event == cv2.EVENT_RBUTTONDOWN:
        draw_rectangle = True
        start_point = (x, y)

    elif event == cv2.EVENT_MOUSEMOVE:
        if draw_rectangle:
            draw_image = image.copy()
            cv2.rectangle(draw_image, start_point, (x, y), (255,0,0), 2)

    elif event == cv2.EVENT_RBUTTONUP:
        draw_rectangle = False
        cv2.rectangle(draw_image, start_point, (x, y), (255,0,0), 2)
        rect = (min(start_point[0], x), min(start_point[1], y), abs(start_point[0] - x), abs(start_point[1] - y))
        rect_is_drawed = True
        rect_or_mask = 0
    # draw touchup curves
    if event == cv2.EVENT_LBUTTONDOWN:
        if not rect_is_drawed:
            print("first draw rectangle \n")
        else:
            drawing = True
            cv2.circle(draw_image, (x,y), 3, value['color'], -1)
            cv2.circle(mask, (x,y), 3, value['val'], -1)

    elif event == cv2.EVENT_MOUSEMOVE:
        if drawing == True:
            cv2.circle(draw_image, (x, y), 3, value['color'], -1)
            cv2.circle(mask, (x, y), 3, value['val'], -1)

    elif event == cv2.EVENT_LBUTTONUP:
        if drawing == True:
            drawing = False

image = cv2.imread('test.jpg')
draw_image = image.copy()                               # a copy of original image
mask = np.zeros(image.shape[:2], dtype = np.uint8)      # mask initialized to PR_BG
output = np.zeros(image.shape, np.uint8)                # output image to be shown

# input and output windows
cv2.namedWindow('output')
cv2.namedWindow('input')
cv2.setMouseCallback('input', onmouse)

DRAW_BG = {'color' : (0,0,0), 'val' : 0}
DRAW_FG = {'color' : (255,255,255), 'val' : 1}

while True:

    cv2.imshow('output', output)
    cv2.imshow('input', draw_image)
    k = cv2.waitKey(1)
    # key bindings
    if k == 27:         # esc to exit
        break
    elif k == ord('0'): # BG drawing
        value = DRAW_BG
    elif k == ord('1'): # FG drawing
        value = DRAW_FG
    elif k == ord('n'): # segment the image
        bgdmodel = np.zeros((1, 65), np.float64)
        fgdmodel = np.zeros((1, 65), np.float64)
        if rect_or_mask == 0:         # grabcut with rect
            cv2.grabCut(image, mask, rect, bgdmodel, fgdmodel, 1, cv2.GC_INIT_WITH_RECT)
            rect_or_mask = 1
        elif rect_or_mask == 1:       # grabcut with mask
            cv2.grabCut(image, mask, rect, bgdmodel, fgdmodel, 1, cv2.GC_INIT_WITH_MASK)


    mask2 = np.where((mask==1) + (mask==3), 255, 0).astype('uint8')
    output = cv2.bitwise_and(image, image, mask=mask2)

cv2.destroyAllWindows()
cv2.imwrite('grabcut_output.png', output)

plt.figure(figsize=[15,5])
plt.subplot(121);plt.imshow(mask2, cmap='gray');plt.title("mask");
plt.subplot(122);plt.imshow(output[...,::-1]);plt.title("Output");