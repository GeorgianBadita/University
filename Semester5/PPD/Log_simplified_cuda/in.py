import cv2
import sys

imgPath = sys.argv[1]

img = cv2.imread(imgPath)

file = open("pixels.txt","w")
file.write(str(img.shape[0]) + " " + str(img.shape[1]) + " " + str(img.shape[2]) + "\n")

for row in img:
    for col in row:
        for pixel in col:
            file.write(str(pixel) + " ")
        file.write("\n")
file.close()