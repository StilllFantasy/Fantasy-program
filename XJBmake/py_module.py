import time 
def main():
    print('This is not a real program, This is a Python module.')


def show():
    start = time.time()
    print('show() is running...')
    time.sleep(2.1)
    end = time.time()
    print('show() is end, running time is %.2f' % (end - start))
    return -1

if __name__ == '__main__':
    main()