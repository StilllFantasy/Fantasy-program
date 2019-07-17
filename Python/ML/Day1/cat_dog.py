import numpy as np
import matplotlib.pyplot as plt
import os
import torch
import torch.nn as nn
import torchvision
from torchvision import models,transforms,datasets
import time
import sys

print(torch.__version__)
print(sys.version)
device = torch.device("cuda:0" if torch.cuda.is_available() else "cpu")
print("Using gpu:%s" % torch.cuda.is_available())
