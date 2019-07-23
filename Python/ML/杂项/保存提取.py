import torch
import matplotlib

def save():
    #建立神经网络
    net1 = torch.nn.Sequential(torch.nn.Linear(1, 10), torch.nn.ReLU(), torch.nn.Linear(10, 1))
    
    #1. 保存整个神经网络
    torch.save(net1, 'net1.pkl')


    #2. 保存神经网络的参数
    torch.save(net1.state_dict(), 'net2.pkl')

def restore_net():
    #提取整个神经网络
    net2 = torch.load('net1.pkl')


def restore_params():
    #提取神经网络的参数，所以再提取之前要建立一个一模一样的神经网络
    net3 = torch.nn.Sequential(torch.nn.Linear(1, 10), torch.nn.ReLU(), torch.nn.Linear(10, 1))
    net3.load_state_dict(torch.load('net2.pkl'))