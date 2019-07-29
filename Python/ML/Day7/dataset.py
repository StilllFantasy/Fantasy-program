import cv2
from PIL import Image

print('cat:')
for t in range(12499+1):
    filepath = 'D:/DataDownload/kaggle/train/cat.' + str(t) + '.jpg'
    image = cv2.imread(filepath)
    savepath = 'D:/DATA/train_data/cat/' + str(t) + '.jpg'
    cv2.imwrite(savepath, image)
    print(t)

print('dog:')
for t in range(12499+1):
    filepath = 'D:/DataDownload/kaggle/train/dog.' + str(t) + '.jpg'
    image = cv2.imread(filepath)
    savepath = 'D:/DATA/train_data/dog/' + str(t) + '.jpg'
    cv2.imwrite(savepath, image)
    print(t)


