# Pose Detection Project

This project utilizes OpenCV and MediaPipe to detect human poses in videos. It includes a Python script that processes a video file frame by frame, detecting key points of the human body and drawing pose landmarks.

## Installation

1. Clone the repository to your local machine:

```bash
git clone https://github.com/Awrsha/Pose-Estimation.git
```


2. Install the required dependencies:

```bash
pip install opencv-python mediapipe
```

## Usage

1. Navigate to the project directory:

```bash
cd pose-estimation
```

2. Run the main Python script:

```bash
python testProject.py
```

3. The script will prompt you to provide the path to the video file you want to analyze. Once provided, it will start processing the video, displaying the frames with pose landmarks drawn on them. Press 'q' to quit the application.

## Configuration

You can customize the behavior of the pose detection by modifying the parameters in the `PoseDetector` class constructor in `main.py`. These parameters include:

- `mode`: Whether to detect the full-body pose or only the upper body.
- `up_body`: Whether to focus on upper body poses.
- `smooth`: Whether to apply smoothing to the detected pose.
- `detection_con`: Detection confidence threshold.
- `track_con`: Tracking confidence threshold.

## Contributing

Contributions are welcome! If you'd like to contribute to this project, please fork the repository and submit a pull request with your changes.
