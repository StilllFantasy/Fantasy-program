import torch
import torch.nn as nn
import torch.optim as optim
# from torchvision import datasets, transforms
import torch.nn.functional as F

BATCH_SIZE = 50
EPOCHS = 30
# DEVICE = torch.device('cuda' if torch.cuda.is_available() else 'cpu')

transform = transforms.Compose([transforms.RandomResizedCrop(150),transforms.ToTensor(), transforms.Normalize([0.5, 0.5, 0.5], [0.5, 0.5, 0.5])])

data_train = datasets.ImageFolder('Python/ML/Day6/CatDog_Data/train', transform)
data_test = datasets.ImageFolder('Python/ML/Day6/CatDog_Data/test', transform)

train_load = torch.utils.data.DataLoader(data_train, batch_size = BATCH_SIZE, shuffle=True)
test_load = torch.utils.data.DataLoader(data_test, batch_size=BATCH_SIZE, shuffle=True)

class Net(nn.Module):
    def __init__(self):
        super(Net, self).__init__()
        self.conv1 = nn.Conv2d(3, 32, 3)
        self.max_pool1 = nn.MaxPool2d(2)
        self.conv2 = nn.Conv2d(32, 64, 3)
        self.max_pool2 = nn.MaxPool2d(2)
        self.conv3 = nn.Conv2d(64, 128, 3)
        self.max_pool3 = nn.MaxPool2d(2)
        self.conv4 = nn.Conv2d(128, 128, 3)
        self.max_pool4 = nn.MaxPool2d(2)
        self.fc1 = nn.Linear(6272, 512)
        self.fc2 = nn.Linear(512, 1)

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


net = Net().cuda()

optimizer = optim.Adam(net.parameters(), lr=0.004)


def Train(net,  train_load, optimizer, epoch):
    net.train()
    for batch_idx, (data, target) in enumerate(train_load):
        data, target = data.to(device), target.cuda().float().reshape(50, 1)
        optimizer.zero_grad()
        output = net(data)

        loss = F.binary_cross_entropy(output, target)
        loss.backward()
        optimizer.step()
        if(batch_idx + 1) % 10 == 0:
               print('Train Epoch: {} [{}/{} ({:.0f}%)]\tLoss: {:.6f}'.format(
                epoch, (batch_idx+1) * len(data), len(train_loader.dataset),
                100. * (batch_idx+1) / len(train_loader), loss.item()))

def Test(net, test_load):
    net.eval()
    test_loss = 0
    correct = 0
    with torch.no_grad():
        for data, target in test_load:
            data, target = data.to(device), target.cuda().float().reshape(50, 1)
            output = net(data)
            test_loss += F.binary_cross_entropy(output, target, reduction='sum').item() # 将一批的损失相加
            pred = torch.tensor([[1] if num[0] >= 0.5 else [0] for num in output]).to(device)
            correct += pred.eq(target.long()).sum().item()
        print('\nTest set: Average loss: {:.4f}, Accuracy: {}/{} ({:.0f}%)\n'.format(
        test_loss, correct, len(test_loader.dataset),
        100. * correct / len(test_loader.dataset)))


for t in range(1, EPOCHS+1):
    Train(net, train_load, optimizer, t)
    Test(net, test_load)
