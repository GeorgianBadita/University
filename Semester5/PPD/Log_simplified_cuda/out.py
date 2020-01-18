import cv2
import sys
import numpy as np

imgPath = sys.argv[1]

file = open("pixels.txt", "r")

line = list(map(int,file.readline().split()))

img = np.zeros(shape=line)

for lin in range(line[0]):
    for col in range(line[1]):
        bgr = list(map(int,file.readline().split()))
        img[lin][col] = bgr

file.close()

cv2.imwrite(imgPath, img)
