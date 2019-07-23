import numpy as np
import cv2
import torch
from PIL import Image

x = np.ones(10)
y = np.zeros(10)

z = np.hstack((x, y))

print(torch.cuda.is_available())