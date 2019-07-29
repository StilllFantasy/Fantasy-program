import torch
import torchvision
import torchvision.transforms as transforms
from torch.utils.data import DataLoader
import torch.nn as nn
import torch.nn.functional as F
import torch.optim as optim
import matplotlib.pyplot as plt
import numpy as np
from PIL import Image

class ConvNet(nn.Module):
    def __init__(self):
        super(ConvNet, self).__init__()
        self.conv1 = nn.Conv2d(3, 32, 3)
        self.max_pool1 = nn.MaxPool2d(2)
        self.conv2 = nn.Conv2d(32, 64, 3)
        self.max_pool2 = nn.MaxPool2d(2)
        self.conv3 = nn.Conv2d(64, 128, 3)
        self.max_pool3 = nn.MaxPool2d(2)
        self.conv4 = nn.Conv2d(128, 128, 3)
        self.max_pool4 = nn.MaxPool2d(2)
        self.fc1 = nn.Linear(6272, 512)
        self.fc2 = nn.Linear(512, 2)
        
    def forward(self, x):
        in_size = x.size(0)
        x = self.conv1(x)
        x = F.relu(x)
        x = self.max_pool1(x)
        x = self.conv2(x)
        x = F.relu(x)
        x = self.max_pool2(x)
        x = self.conv3(x)
        x = F.relu(x)
        x = self.max_pool3(x)
        x = self.conv4(x)
        x = F.relu(x)
        x = self.max_pool4(x)
        # 展开
        x = x.view(in_size, -1)
        x = self.fc1(x)
        x = F.relu(x)
        x = self.fc2(x)
        x = torch.sigmoid(x)
        return x
 

transform = transforms.Compose([
    transforms.RandomResizedCrop(150),
    transforms.ToTensor(),
    transforms.Normalize([0.5, 0.5, 0.5], [0.5, 0.5, 0.5])
])


names = ['cat', 'dog']

net = torch.load('CNN-net2.pth')
net.cuda()
print('successfully load the net.')




for t in range(1003, 1050):
        imgpath = str('D:/DATA/test_data/dog/') + str(t) + '.jpg'
        image = Image.open(imgpath)
        image_ten = transform(image).cuda()
        image_ten = image_ten.unsqueeze(0)
        # print(image_ten.size())
        with torch.no_grad():
                output = net(image_ten)
        print(output)
        predict_value, predict_idx = torch.max(output, 1)  # 求指定维度的最大值，返回最大值以及索引
        # predict_idx = 1 if predict_value >=0.5 else 0
        plt.figure()
        plt.imshow(np.array(image))
        plt.title(names[predict_idx])
        plt.axis('off')
        plt.show()
