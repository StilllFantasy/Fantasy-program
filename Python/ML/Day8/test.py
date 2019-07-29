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
import cv2

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
 

try:
    print('正在载入神经网络...')
    net = torch.load('CNN-net-minist.pth').cuda()
    print('载入神经网络成功.')
except:
    print('载入神经网络失败.')

transform = transforms.Compose([transforms.ToTensor()])

train_data = datasets.ImageFolder('D:/DATA/FashionMNIST/raw/traindata/', transform)
# test_data = datasets.ImageFolder('')
train_loader =  DataLoader(train_data, batch_size=1, shuffle=True)

print(train_data.class_to_idx)

names = ['Ankle boot', 'Bag', 'Coat', 'Dress', 'Pullover', 'Sandal', 'Shirt', 'Sneaker', 'Trouser', 'T-shirt_or_top']
labels = ['靴子','包包','外套','裙子','套头衫','凉鞋','汗衫','运动鞋','裤子','T-shirt']

for image, label in train_loader:
    print('数据类型：',type(image))
    print('数据规模：',image.size())
    new = image.squeeze(0)
    print('转换后：', type(new), new.size())
    new = torchvision.transforms.ToPILImage()(new)
    
    image = image.cuda(1)
    with torch.no_grad():
        out = net(image)
    predict_value, predict_idx = torch.max(out, 1)
    print('识别结果：',labels[predict_idx])
    print(out)
    plt.imshow(new)
    
    plt.title(names[predict_idx])
    plt.show()




'''
for t in  range(100):
    t += 1
    impath = 'D:/DATA/FashionMNIST/raw/testdata/Ankle boot/' + str(t) + '.png' 
    img = cv2.imread(impath)
    img_ten = transform(img).cuda()
    img_ten = img_ten.unsqueeze(0)
    print('图片规格:',img_ten.size())
    with torch.no_grad():
        out = net(img_ten)
    print(out)
    predict_value, predict_idx = torch.max(out, 1)
    plt.figure()
    plt.imshow(np.array(img))
    plt.title(names[predict_idx])
    plt.axis('off')
    plt.show()


impath = 'D:/DATA/FashionMNIST/raw/testdata/Ankle boot/' + str(1) + '.png' 
image = Image.open(impath)
plt.imshow(image)
plt.show()
'''
