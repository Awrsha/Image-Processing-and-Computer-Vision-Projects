import cv2
import mediapipe as mp
import time
import math

class PoseDetector:
    def __init__(self, static_image_mode=False, model_complexity=1, smooth_landmarks=True, detection_confidence=0.5, tracking_confidence=0.5):
        self.mpDraw = mp.solutions.drawing_utils
        self.mpPose = mp.solutions.pose
        self.pose = self.mpPose.Pose(static_image_mode=static_image_mode, model_complexity=model_complexity, smooth_landmarks=smooth_landmarks, min_detection_confidence=detection_confidence, min_tracking_confidence=tracking_confidence)

    def find_pose(self, img, draw=True):
        img_rgb = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)
        results = self.pose.process(img_rgb)
        if draw:
            self.mpDraw.draw_landmarks(img, results.pose_landmarks, self.mpPose.POSE_CONNECTIONS)
        return img, results.pose_landmarks

    def find_angle(self, img, p1, p2, p3, draw=True):
        # Get the landmarks
        x1, y1 = p1.x * img.shape[1], p1.y * img.shape[0]
        x2, y2 = p2.x * img.shape[1], p2.y * img.shape[0]
        x3, y3 = p3.x * img.shape[1], p3.y * img.shape[0]

        # Calculate the angle
        angle = math.degrees(math.atan2(y3 - y2, x3 - x2) - math.atan2(y1 - y2, x1 - x2))
        if angle < 0:
            angle += 360

        # Draw the angle on the image
        if draw:
            cv2.putText(img, str(int(angle)), (int(x2) - 70, int(y2)), cv2.FONT_HERSHEY_PLAIN, 2, (255, 0, 0), 2)

        return angle

def main():
    # Load the video file
    cap = cv2.VideoCapture('PoseVideos/test.mp4')

    # Create an instance of PoseDetector
    detector = PoseDetector(detection_confidence=0.7, tracking_confidence=0.7)  # Adjust confidence thresholds for better accuracy

    # Initialize variables for FPS calculation
    p_time = 0

    # Main loop for processing frames
    while True:
        # Read a frame from the video
        success, img = cap.read()

        # Check if the frame was read successfully
        if not success:
            break

        # Detect poses in the frame
        img, landmarks = detector.find_pose(img)

        # Calculate angles if landmarks are detected
        if landmarks:
            # Ensure enough landmarks are detected before accessing specific ones
            if len(landmarks.landmark) >= 16:
                angle = detector.find_angle(img, landmarks.landmark[11], landmarks.landmark[13], landmarks.landmark[15])

        # Calculate and display FPS
        c_time = time.time()
        fps = 1 / (c_time - p_time)
        p_time = c_time
        cv2.putText(img, f'FPS: {int(fps)}', (70, 50), cv2.FONT_HERSHEY_PLAIN, 3, (255, 0, 0), 3)

        # Display the processed frame
        cv2.imshow("Image", img)

        # Check for user input to quit the application
        if cv2.waitKey(1) & 0xFF == ord('q'):
            break

    # Release the video capture object and close all OpenCV windows
    cap.release()
    cv2.destroyAllWindows()

if __name__ == "__main__":
    main()