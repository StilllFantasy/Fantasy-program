from socket import socket
import wx
from threading import Thread
from datetime import datetime
import time

app = wx.App()
# image = wx.Image('D:/RoomData/main.jpg', wx.BITMAP_TYPE_JPEG).Scale(100, 100)
client = socket()
frame1 = wx.Frame(None, title="登录", pos=(500, 300), size=(500, 400))
frame2 = wx.Frame(None, title="聊天室", pos=(500, 200), size=(300, 500))
frame3 = wx.Frame(None, title="注册", pos=(500, 300), size=(500, 300))
pass_txt1 = wx.TextCtrl(frame3, pos=(100, 70), size=(300, 30))
pass_txt2 = wx.TextCtrl(frame3, pos=(100, 120), size=(300, 30))
pass_name = wx.TextCtrl(frame3, pos=(100, 170), size=(300, 30))
user_txt = wx.TextCtrl(frame1, pos=(100, 150), size=(300, 30))
pass_txt = wx.TextCtrl(frame1, pos=(100, 200), size=(300, 30), style=wx.TE_PASSWORD)
log_search = wx.TextCtrl(frame2, pos=(40, 70), size=(210, 25))
butten_add = wx.Button(frame2, label='添加好友', pos=(40, 100), size=(70, 30))
butten_chat = wx.Button(frame2, label='私聊好友', pos=(110, 100), size=(70, 30))
butten_group = wx.Button(frame2, label='进群聊天', pos=(180, 100), size=(70, 30))
friend_list_txt = wx.StaticText(frame2, label='好友列表', pos=(110, 150))
group_chat_frm = wx.Frame(None, title="群组聊天室", pos=(200, 200), size=(500, 550))
input_txt = wx.TextCtrl()
chat_data_list = ['正在进行群组聊天...']
chat_list = wx.ListBox(group_chat_frm, -1, (20, 20), (450, 300), chat_data_list, wx.LB_SINGLE)
user_id_text = ''
user_id_name = ''


def register_return(event):
    global frame3
    frame3.Hide()
    return


class ReceiveThread(Thread):

    def __init__(self, cclient):
        super().__init__()
        self.cclient = cclient

    def run(self):
        global chat_data_list, chat_list
        while True:
            data = str(self.cclient.recv(2048))
            # print(data)
            # chat_data_list.append(data)
            # print(chat_data_list)
            # chat_list = wx.ListBox(group_chat_frm, -1, (20, 20), (450, 300), chat_data_list, wx.LB_SINGLE)
            text1 = data[data.find('b')+2:data.rfind('[')]
            chat_list.Append(text1)
            user_name_list = []
            with open('D:/RoomData/server.data', 'r') as f:
                user_name_list = f.readlines()
            f.close()
            text1 = text1[text1.rfind('[')+1:text1.rfind(']')]
            for each in user_name_list:
                text2 = each[:each.rfind('[')]
                text2 = text2[text2.find('[')+1:text2.find(']')]
                if text1 == text2:
                    chat_list.Append(str(each[each.rfind('['):])+' : '+data[data.rfind('[')+1:len(data)-2])
                    break
            group_chat_frm.Update()


def register_enter(event):
    global frame3, pass_txt1, pass_txt2, pass_name

    if str(pass_txt1.GetValue()) == str(pass_txt2.GetValue()):
        with open('D:/RoomData/server.data', 'r') as f:
            data = f.readlines()
        f.close()
        user_data = data[len(data)-1]
        user_data = user_data[user_data.find('[')+1:user_data.find(']')]
        user_data_id = int(user_data)
        user_data_id += 1
        wx.MessageBox('你的账号是：'+str(user_data_id)+'\n'+'你的密码是：'+str(pass_txt2.GetValue()), '注册成功')
        with open('D:/RoomData/server.data', 'a') as f:
            f.write('['+str(user_data_id)+']['+str(pass_txt2.GetValue())+']['+pass_name.GetValue()+']'+'\n')
        f.close()
        filename = 'D:/RoomData/' + str(user_data_id)+'.data'
        with open(filename, 'a') as f:
            f.write(str(user_data_id)+'\n')
            '''
                创建数据文件 
            '''
        f.close()
        frame3.Close()
        return
    else:
        wx.MessageBox('输入密码不一致', '注册失败')


def register(event):
    global frame3
    text1 = wx.StaticText(frame3, -1, '输入密码系统自动分配账号', (120, 35))
    text2 = wx.StaticText(frame3, -1, '输入密码', (50, 70))
    text3 = wx.StaticText(frame3, -1, '确认密码', (50, 120))
    text4 = wx.StaticText(frame3, -1, '输入昵称', (50, 170))
    button1 = wx.Button(frame3, label="注册", pos=(150, 215), size=(66, 33))
    button2 = wx.Button(frame3, label="返回", pos=(250, 215), size=(66, 33))
    frame3.Show()
    button2.Bind(wx.EVT_BUTTON, register_return)
    button1.Bind(wx.EVT_BUTTON, register_enter)


def group_chat_return(event):

    '''

        sfa
    '''
    global group_chat_frm
    group_chat_frm.Hide()


def group_chat_send(event):

    global client, input_txt, chat_data_list, chat_list
    input_data = str(input_txt.GetValue())
    input_txt.Clear()
    client.send(str('['+user_id_text+']'+input_data).encode('utf-8'))
    # chat_data_list.append(str('时间 [' + str(datetime.now()) + ']'))
    # chat_data_list.append(str('['+user_id_text+']: '+input_data))
    # chat_list = wx.ListBox(group_chat_frm, -1, (20, 20), (450, 300), chat_data_list, wx.LB_SINGLE)
    # group_chat_frm.Update()


def group_chat():

    global group_chat_frm, input_txt, chat_data_list, chat_list, client

    ReceiveThread(client).start()

    btn1 = wx.Button(group_chat_frm, label='退出', pos=(410, 450))
    btn2 = wx.Button(group_chat_frm, label='发送', pos=(30, 450))
    btn2.SetSize((50, 30))
    btn1.SetSize((50, 30))
    input_txt = wx.TextCtrl(group_chat_frm, pos=(20, 330), size=(450, 100))

    btn1.Bind(wx.EVT_BUTTON, group_chat_return)
    btn2.Bind(wx.EVT_BUTTON, group_chat_send)

    group_chat_frm.Hide()

    # frm.Update()
    # time.sleep(2)
def room_show(event):
    global group_chat_frm, input_txt, chat_data_list, chat_list, client
    group_chat_frm.Show()


def log_init(txt1):

    global client, user_id_name
    client.connect(('127.0.0.1', 8099))
    # client.send(str('[' + txt1 + ']' + 'i am ok').encode('utf-8'))
    group_chat()
    def friend_add(event):
        add_name = str(log_search.GetValue())
        filename = 'D:/RoomData/' + str(user_id_name)+'.data'
        with open(filename, 'a') as f:
            f.write(add_name+'\n')
            friend_data_list.append('好友账号：   '+add_name)
            wx.MessageBox('添加成功', '恭喜')
            friend_data_list.Update()

    butten_group.Bind(wx.EVT_BUTTON, room_show)
    butten_add.Bind(wx.EVT_BUTTON, friend_add)
    user_id = wx.StaticText(frame2, size=(50, 30), pos=(30, 10), label=str('账号：' + '[' + txt1 + ']'))
    user_nm = wx.StaticText(frame2, size=(50, 30), pos=(30, 30), label=str('昵称：' + '[' + user_id_name + ']'))
    font = wx.Font(16, wx.DECORATIVE, wx.ITALIC, wx.NORMAL)
    user_id.SetFont(font)
    user_nm.SetFont(font)
    filename = 'D:/RoomData/' + txt1 + '.data'
    with open(filename, 'r') as f:
        friend_data = f.readlines()
    f.close()
    friend_data_list = ['好友账号            好友昵称']

    with open('D:/RoomData/server.data', 'r') as f:
        data = f.readlines()
    f.close()
    data_text1 = ''
    data_text2 = ''

    for each in friend_data:
        id_name = ''
        data_text2 = str(each)
        for name in data:
            data_text1 = str(name[1:6])
            print(data_text1, data_text2)
            if data_text1 == data_text2:
                # id_name = name[name.rfind('[')+1:name.rfind(']')]
                print('相同了')
                # break
        friend_data_list.append('好友账号：   '+each)
    listBox = wx.ListBox(frame2, -1, (53, 180), (170, 200), friend_data_list, wx.LB_SINGLE)
    frame2.Show()


def main_log(event):

    global user_txt, pass_txt, user_id_text, user_id_name
    txt1 = str(user_txt.GetValue())
    txt2 = str(pass_txt.GetValue())
    user_data = '[' + txt1 + '][' + txt2 + ']'

    with open('D:/RoomData/server.data', 'r') as f:
        data = f.readlines()
    f.close()

    k = 0
    for each in data:
        text = each[:each.rfind('[')]
        if user_data == text:
            k = 1
            user_id_name = each[each.rfind('[')+1:each.rfind(']')]
    if k == 0:
        wx.MessageBox('密码错误或账号不存在', '登录失败')
    else:
        wx.MessageBox('欢迎' + user_id_name + '同学, 开始愉快聊天吧！', '登录成功')
        log_init(txt1)
        user_id_text = txt1
        frame1.Close()


def main():

    text1 = wx.StaticText(frame1, -1, '账号', (50, 150))
    text2 = wx.StaticText(frame1, -1, '密码', (50, 200))
    button1 = wx.Button(frame1, label="登录", pos=(160, 260), size=(66, 33))
    button2 = wx.Button(frame1, label="注册", pos=(270, 260), size=(66, 33))
    image = wx.Image('D:/RoomData/true.jpg', wx.BITMAP_TYPE_JPEG).Scale(120, 120)
    # frame1.PicShow.SetBitmap(wx.BitmapFromImage(image))
    showimage = wx.StaticBitmap(frame1, -1, wx.BitmapFromImage(image), pos=(180, 20))
    frame1.Show()
    button1.Bind(wx.EVT_BUTTON, main_log)
    button2.Bind(wx.EVT_BUTTON, register)
    app.MainLoop()

    '''
        print('请输入账号：')
    clientID = input()

    client = socket()
    client.connect(('127.0.0.1', 8099))
    print('连接服务器成功...')
    while True:
        print('请输入要发送的内容:')
        data = input()
        client.send(str('['+clientID+']'+data).encode('utf-8'))
    '''


if __name__ == '__main__':
    main()
