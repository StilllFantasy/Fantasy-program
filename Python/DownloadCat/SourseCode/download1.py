import urllib.request
import random
import time
def main():
    while True:
        nob = 0
        while True:
            # print('请输入一只猫的尺寸(X*Y)')
            x = random.randint(100,999)
            y = random.randint(100,999)
            web_name = 'http://placekitten.com/g/' + str(x) + '/' + str(y)
            image = urllib.request.urlopen(web_name).read()
            nob += 1
            file_name = 'Python/new_d/Pictures/'+'[第' + str(nob) + '只猫](' + str(x) + 'x' + str(y) +').jpg'
            with open (file_name, 'wb') as file:
                file.write(image)
            print(file_name+' is ok!')
            # time.sleep(0.5)


if __name__ == '__main__':
    main()