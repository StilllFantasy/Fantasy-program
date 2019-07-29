import torch
import torchvision
import torchvision.transforms as transforms
from torchvision import datasets
import torch.nn.functional as F
from torch.utils.data import DataLoader
import torch.nn as nn
import torch.optim as optim
import matplotlib.pyplot as plt 
import numpy as np 
from PIL import Image

# DEVICE = torch.device('cuda:0' if torch.cuda.is_available() else 'cpu')


transform = transforms.Compose([transforms.ToTensor()])

train_data = datasets.ImageFolder('D:/DATA/FashionMNIST/raw/traindata/', transform)
# test_data = datasets.ImageFolder('')


train_loader =  DataLoader(train_data, batch_size=50, shuffle=True)



class ConvNet(nn.Module):
    def __init__(self):
        super(ConvNet, self).__init__()
        self.conv1 = nn.Conv2d(3, 16, 5,1,2)
        self.max_pool1 = nn.MaxPool2d(2)
        self.conv2 = nn.Conv2d(16, 32, 5,1,2)
        self.max_pool2 = nn.MaxPool2d(2)
        self.fc1 = nn.Linear(32*7*7, 128)
        self.fc2 = nn.Linear(128, 10)
        
    def forward(self, x):
        in_size = x.size(0)
        x = self.conv1(x)
        x = F.relu(x)
        x = self.max_pool1(x)
        x = self.conv2(x)
        x = F.relu(x)
        x = self.max_pool2(x)
        
        # 展开
        x = x.view(in_size, -1)
        x = self.fc1(x)
        x = F.relu(x)
        x = self.fc2(x)
        x = torch.sigmoid(x)
        return x
 
cnn = ConvNet().cuda(1)
optimizer = torch.optim.Adam(cnn.parameters(), lr=0.0001)
loss_f = nn.CrossEntropyLoss()


for t in range(30):
    for step, (data, target) in enumerate(train_loader):
        # print(data.size())
        data = data.cuda(1)
        target = target.cuda(1)
        output = cnn(data)
        loss = loss_f(output, target)
        optimizer.zero_grad()
        loss.backward()
        optimizer.step()
        print('第',t,'次迭代训练 ',step,'/',len(train_loader))

print('训练结束')
try:
    torch.save(cnn, 'CNN-net-minist.pth')
    print('保存成功')
except:
    print('保存失败')