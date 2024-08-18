from ultralytics import YOLO
import cv2
import os
import numpy as np
from mtcnn import MTCNN

yolo_model = YOLO('yolov8n.pt')
mtcnn_detector = MTCNN()

def get_face_encoding(image_path):
    image = cv2.imread(image_path)
    rgb_image = cv2.cvtColor(image, cv2.COLOR_BGR2RGB)
    
    faces = mtcnn_detector.detect_faces(rgb_image)
    if not faces:
        return None, None, None
    
    face = faces[0]
    x, y, width, height = face['box']
    face_location = [y, x + width, y + height, x]
    
    face_image = rgb_image[y:y+height, x:x+width]
    face_image = cv2.resize(face_image, (128, 128))
    
    face_encoding = cv2.dnn.blobFromImage(face_image)
    face_encoding = face_encoding.flatten()
    
    return face_encoding, face_location, image

test_image_path = 'test.jpg'
reference_folder = 'C://Users//pc//Desktop//New folder//images'

test_encoding, face_location, test_image = get_face_encoding(test_image_path)

if test_encoding is None:
    print("No face.")
else:
    best_match = None
    best_distance = float('inf')

    for filename in os.listdir(reference_folder):
        if filename.lower().endswith(('.png', '.jpg', '.jpeg')):
            ref_image_path = os.path.join(reference_folder, filename)
            ref_encoding, _, _ = get_face_encoding(ref_image_path)
            
            if ref_encoding is not None:
                distance = np.linalg.norm(test_encoding - ref_encoding)
                if distance < best_distance:
                    best_distance = distance
                    best_match = os.path.splitext(filename)[0]

    if best_match:
        print(f"Nearest Result: {best_match}")
        
        cv2.rectangle(test_image, (face_location[3], face_location[0]), (face_location[1], face_location[2]), (0, 255, 0), 2)
        cv2.putText(test_image, best_match, (face_location[3], face_location[0] - 10), cv2.FONT_HERSHEY_SIMPLEX, 0.9, (0, 255, 0), 2)
        
        cv2.imshow("Test Image", test_image)
        cv2.waitKey(0)
        cv2.destroyAllWindows()
    else:
        print("Not Found.")