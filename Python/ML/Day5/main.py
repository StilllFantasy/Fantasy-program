import torch.nn
import torch.utils.data as Data
import numpy as np
import cv2
import torch.nn.functional as F
from torch.autograd import Variable
import matplotlib.pyplot as plt
from PIL import Image

class Net(torch.nn.Module):
    def __init__(self, n_f, n_h, n_o):
        super(Net, self).__init__()
        self.hidden = torch.nn.Linear(n_f, n_h)
        self.predict = torch.nn.Linear(n_h, n_o)
    
    def forward(self, x):
        x = F.relu(self.hidden(x))
        x = self.predict(x)
        return x


net = Net(500*500, 10, 1)

optimizer = torch.optim.SGD(net.parameters(), lr=0.02)
loss_f = torch.nn.CrossEntropyLoss()

filepath = 'D:/imagetest/image' + str(1) + '.jpg'
image = cv2.imread(filepath, cv2.IMREAD_GRAYSCALE)
image = np.array(image)
data = np.array([image.flatten()])

print('Data is loadding...')
for t in range(92):
    t += 1
    filepath = 'D:/imagetest/image' + str(t) + '.jpg'
    image = cv2.imread(filepath, cv2.IMREAD_GRAYSCALE)
    image = np.array(image)
    data = np.concatenate((data,[image.flatten()]))
x = np.zeros(54)
y = np.ones(39)
label = np.hstack((x, y))

data = torch.Tensor(data)
label = torch.Tensor(label)



data_set = Data.TensorDataset(data, label)

loader = Data.DataLoader(dataset=data_set,batch_size=1,shuffle=False)


print('Loading completed.')    
    

#data = Variable(data)
#label = Variable(data)
print('Start training...')
for t_x, t_y in loader:
    a = torch.unsqueeze(torch.Tensor(t_x),dim=1)
    out = net(a)
    loss = loss_f(out, torch.Tensor(t_y))
    optimizer.zero_grad()
    loss.backward()
    optimizer.step()
    print(loss)
    ch = input()
    


