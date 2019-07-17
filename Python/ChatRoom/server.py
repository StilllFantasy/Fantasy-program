from socket import socket, SOCK_STREAM, AF_INET
from datetime import datetime
from threading import Thread
import time

client_queue = []
name_ID = {}

def senddata(key, data):
    global client_queue
    if key == '00000':
        for each in client_queue:
            each.client.send(data.encode('utf-8'))
    else:
        for each in client_queue:
            name = str(each.name)
            if name == key:
                each.client.send(data.encode('utf-8'))

class ReceiveThread(Thread):
    
    def __init__(self, client_ID, client, name):
        super().__init__()
        self.client_ID = client_ID
        self.client = client
        self.name = name

    def run(self):
        global name_ID, client_queue
        name_data = str(self.client.recv(1024))
        self.name = name_data[name_data.find('[')+1:name_data.rfind(']')]
        self.client.send(self.name.encode('utf-8'))

        while True:
            data = self.client.recv(1024)
            data = str(data)
            # [10001][10002][How are you?]
            textdata = data[data.rfind('[')+1:data.rfind(']')]
            name_from = data[8:13]
            name_to = data[1:6]
            send_data ='[' + str(datetime.now()) + ']' '[' + name_from + ']' + '  ' + '[' + textdata + ']'
            with open('D:/RoomData/chat_data.data','a') as f:
                f.write(send_data+'\n')
            # print(send_data)
            #for each in client_queue:
            #    each.client.send(send_data.encode('utf-8'))
            senddata(name_to, send_data)

    def showid(self):
        return self.client_ID
            #print('['+data[data.rfind(']'):]+']',data)

def main():
    #[]
    global name_ID, client_queue
    server = socket(family=AF_INET, type=SOCK_STREAM)
    server.bind(('0.0.0.0', 8099))
    server.listen(512)
    print('服务器启动成功...')
    while True:
        client, addr = server.accept()
        client_queue.append(ReceiveThread(client_ID=addr, client=client,name='abncn'))
        now_client = client_queue[len(client_queue)-1]
        now_client.start()
        print(str(now_client.name)+'已上线...')
        # 5.发送数据
        #client.send(str(addr).encode('utf-8'), str(datetime.now()).encode('utf-8'))
        #while True:
        
            
        # 6.断开连接
        #client.close() 


if __name__ == '__main__':
    main()
