import cv2
import numpy as np
import os
img_path = 'dataset/FashionMNIST/raw/t10k-images-idx3-ubyte'
label_path = 'dataset/FashionMNIST/raw/t10k-labels-idx1-ubyte'
save_path = 'dataset/FashionMNIST/raw/traindata'
img_path2 = 'dataset/FashionMNIST/raw/train-images-idx3-ubyte'
label_path2 = 'dataset/FashionMNIST/raw/train-labels-idx1-ubyte'
save_path2 = 'dataset/FashionMNIST/raw/testdata'
 
 
classes = { 0: 'T-shirt_or_top',
            1:	'Trouser',
            2:	'Pullover',
            3:	'Dress',
            4:	'Coat',
            5:	'Sandal',
            6:	'Shirt',
            7:	'Sneaker',
            8:	'Bag',
            9:	'Ankle boot'}
 
def save(img_path ,label_path, savepath, num):
    f = open(img_path,'rb')
    la_f = open(label_path,'rb')
    la_f.read(8)
    f.read(16)
    dict = {}
    for n in range(num):
        image = []
        for i in range(28*28):
            image.append(ord(f.read(1)))
        image = np.array(image).reshape(28,28)
        name = classes[ord(la_f.read(1))]
        filepath = os.path.join(savepath, name)
        if not os.path.isdir(filepath):
            os.makedirs(filepath)
        if name not in dict:
            dict[name] = 1
        else:
            dict[name] += 1
        png = str(dict[name])+'.png'
        save_path = os.path.join(filepath, png)
        cv2.imwrite(save_path, image)
    la_f.close()
    f.close()
 
save(img_path,label_path,save_path,num=60000)
save(img_path2,label_path2,save_path2,num=10000)