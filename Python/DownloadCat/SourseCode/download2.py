'''
    多线程下载猫猫图片
'''
from threading import Thread
import random
import time
import urllib.request

#全局变量
nob = 0

class DownloadThread(Thread):

    def __init__(self):
        super().__init__()
    
    def run(self):
        start = time.time()
        list1 = self.build()
        file_name = list1[0]
        web_name = list1[1]
        print('[开始下载] '+file_name)
        image = urllib.request.urlopen(web_name).read()
        with open (file_name, 'wb') as file:
            file.write(image)
        print(''+file_name)
        end = time.time()
        print('[下载完成,下载用时:%.2f]' % (end - start))
        return 

    def build(self):
        global nob
        size_x = str(random.randint(333, 999))
        size_y = str(random.randint(333, 999))
        web_name = 'http://placekitten.com/g/' + size_x + '/' + size_y
        nob += 1;
        file_name = 'Python/DownloadCat/Pictures/'+'[第' + str(nob) + '只猫](' + size_x + 'x' + size_y +').jpg'
        return [file_name, web_name]


def main():
    main_start = time.time()
    file = []
    for i in range(100):
        file.append(DownloadThread())
    for i in range(10):
        for j in range(10):
            file[i*10+j].start()
        for j in range(10):
            file[i*10+j].join()
        
    

    main_end = time.time()
    print('总耗时：%.2f' % (main_end - main_start))


if __name__ == '__main__':
    main()