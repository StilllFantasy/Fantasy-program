import torch
import torch.utils.data as Data

BATCH_SIZE = 5

x = torch.linspace(1, 10, 10) # 生成数据
y = torch.linspace(10, 20, 10) 

print(x)
print(y)

torch_data_set = Data.TensorDataset(x, y)
loader = Data.DataLoader(dataset=torch_data_set, batch_size=BATCH_SIZE, shuffle=True)


for t in range(3):
    for step, (batch_x, batch_y) in enumerate(loader):
        #training...
        print(t, step, batch_x, batch_y)
