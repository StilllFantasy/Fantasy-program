import cv2
import matplotlib.pyplot as plt 
import matplotlib
import torch
import numpy as np
from PIL import Image

image = cv2.imread('D:/imagetest/image1.jpg',0)

image = cv2.resize(image, (500, 500))

image = torch.from_numpy(image)
image = image.view(1, 500*500)
print(image)



  
