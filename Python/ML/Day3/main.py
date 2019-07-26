import torch
from torch.autograd import Variable

print(torch.version.cuda)
try:
    gpu_data = Variable(torch.randn(3, 3)).cuda()
    cpu_data = gpu_data.cpu()
    print('Successful')
except:
    print('Faild')

