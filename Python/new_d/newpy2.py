import wx


def button1_enter(event):
    wx.MessageBox('你好')
def main():
    app = wx.App()
    frame = wx.Frame(None, title='ABC', pos=(500, 200), size=(500, 300))
    button1 = wx.Button(frame, pos=(100, 100), size=(50, 30), label='确定')
    button2 = wx.Button(frame, pos=(100, 150), size=(50, 30), label='取消')
    button1.Bind(wx.EVT_BUTTON, button1_enter)
    frame.Show()
    app.MainLoop()


if __name__ == '__main__':
    main()


