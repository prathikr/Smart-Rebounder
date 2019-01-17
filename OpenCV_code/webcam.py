import cv2
import sys

import time

currentx = 0
def largestArea(faces):
    largestx = 0
    largesty = 0
    largestw = 0
    largesth = 0
    largestArea = 0

    for (x, y, w, h) in faces:
        if(w * h > largestArea):
            largestArea = w * h
            largestx = x
            largesty = y
            largestw = w
            largesth = h

    cv2.rectangle(frame, (largestx, largesty), (largestx+largestw, largesty+largesth), (0, 255, 0), 2)
    return largestx

cascPath = "haarcascade_frontalface_default.xml"
#cascPath = "haarcascade_upperbody.xml"
faceCascade = cv2.CascadeClassifier(cascPath)

video_capture = cv2.VideoCapture(0)

while True:
    # Capture frame-by-frame
    ret, frame = video_capture.read()

    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

    faces = faceCascade.detectMultiScale(
        gray,
        scaleFactor=1.1,
        minNeighbors=5,
        minSize=(30, 30),
        flags=cv2.CASCADE_SCALE_IMAGE
    )

    # Draw a rectangle around the faces
    # for (x, y, w, h) in faces:
    #     cv2.rectangle(frame, (x, y), (x+w, y+h), (0, 255, 0), 2)

    newx = largestArea(faces)
    change = newx - currentx
    cv2.putText(frame, "Delta : " + str(int(change)), (100,50), cv2.FONT_HERSHEY_SIMPLEX, 0.75, (50,170,50), 2)

    currentx = newx



    # Display the resulting frame
    cv2.imshow('Video', frame)

    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

    time.sleep(0.1)

# When everything is done, release the capture
video_capture.release()
cv2.destroyAllWindows()
