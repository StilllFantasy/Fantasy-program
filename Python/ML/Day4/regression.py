import torch
from torch.autograd import Variable
import torch.nn.functional as F
import matplotlib.pyplot as plt

def show_data_graph():

    plt .scatter(x.data.numpy(), y.data.numpy())
    plt.show()

class Net(torch.nn.Module):
    def __init__(self):
        super(Net, self).__init__()
        self.hidden = torch.nn.Linear(1, 10)
        self.predict = torch.nn.Linear(10, 1)
    
    def forward(self, x):
        x = F.relu(self.hidden(x))
        x = self.predict(x)
        return x
        

x = torch.unsqueeze(torch.linspace(-1, 1, 300), dim=1)
y = x.pow(2) + 0.2 * torch.rand(x.size())
x = Variable(x)
y = Variable(y)

net = Net()
optimizer = torch.optim.SGD(net.parameters(), lr=0.2)
loss_f = torch.nn.MSELoss()

# show_data_graph()

show_data_graph()

print('开始训练....')

plt.ion()
plt.show()

for t in range(1000):
    prediction = net(x)
    loss = loss_f(prediction, y)
    optimizer.zero_grad()
    loss.backward()
    optimizer.step()
    print("t = ", t)
    if t % 5 == 0:
        plt.cla()
        plt.scatter(x.data.numpy(), y.data.numpy())
        plt.plot(x.data.numpy(), prediction.data.numpy(), 'r-', lw=5)
        plt.text(0.5, 0, 'Loss = %.4f' % loss.item())
        plt.pause(0.1)
print('训练结束！')
plt.ioff()
plt.show()