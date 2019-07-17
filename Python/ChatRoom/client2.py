from socket import socket
import wx
from threading import Thread
from datetime import datetime
import time

class Frame(wx.Frame):
    def __init__(self, title, x_size, y_size, x_pos, y_pos):
        super().__init__()
        
    

client = socket()
client.connect(('127.0.0.1', 8099))
client.send(str('[10001]').encode('utf-8'))
data = str(client.recv(1024))
data = data[data.find('\'')+1:data.rfind('\'')]
print(data)

