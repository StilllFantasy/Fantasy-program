import numpy as np
import cv2
from matplotlib import pyplot as plt

img=cv2.imread('Python/DownloadCat/Pictures/[第7只猫](572x483).jpg',cv2.IMREAD_COLOR)

#method1
b,g,r=cv2.split(img)
img2=cv2.merge([r,g,b])
plt.imshow(img2)
plt.show()