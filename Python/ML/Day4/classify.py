import torch.nn.functional as F
import torch
from torch.autograd import Variable
import matplotlib.pyplot as plt


class Net(torch.nn.Module):
    
    def __init__(self, n_in, n_mid, n_out):
        super(Net, self).__init__()
        self.f1 = torch.nn.Linear(n_in, n_mid)
        self.f2 = torch.nn.Linear(n_mid, n_out)

    def forward(self, x):
        
        x = F.relu(self.f1(x))
        x = self.f2(x)
        return x

train_data_x = torch.unsqueeze(torch.linspace(-1, 1, 200), dim=1)
train_data_y = train_data_x.pow(2) + 0.2 * torch.rand(train_data_x.size())

test_data_x = torch.unsqueeze(torch.linspace(-1, 1, 200), dim=1)
dataloader = torch.utils.data.DataLoader(test_data_x, batch_size=3, shuffle=True)

net = Net(1, 10, 1)
optimizer = torch.optim.SGD(net.parameters(), lr=0.2)
loss_f = torch.nn.MSELoss()

print('Start trainning...')

for t in range(200):
    print('t = ',t)
    prediction = net(train_data_x)
    loss = loss_f(prediction, train_data_y)
    optimizer.zero_grad()
    loss.backword()
    optimizer.step()

print('End of trainning.')


