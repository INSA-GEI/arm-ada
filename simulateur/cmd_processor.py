from PyQt5.QtCore import QObject, pyqtSignal
from socket_worker import *

class CmdProcessor(QObject):
    setTextColor = pyqtSignal(int,int,int) # R: int, G: int, B: int
    setBgColor = pyqtSignal(int,int,int) # R: int, G: int, B: int
    drawText = pyqtSignal(int,int,str) # x: int, y: int, text: str
    drawRect = pyqtSignal(int,int,int, int) # x: int, y: int, w: int, h: int
    drawFillRect = pyqtSignal(int,int,int, int) # x: int, y: int, w: int, h: int
    getKeyState = pyqtSignal(str) # key: str ("A", "UP")
    getAllKeys = pyqtSignal()     # get all key status

    def __init__(self, socketWorker: SocketWorker):
        super(CmdProcessor, self).__init__()
        # Store constructor arguments (re-used for processing)
        self.socketWorker = socketWorker
        self.socketWorker.dataReceived.connect(self.dataReceived)

    def dataReceived(self, s):
        if s.find("?KEYSTATE:") != -1:
            self.getKeyState.emit(s[len("?KEYSTATE:"):])
        elif s.find("?ALLKEYS") != -1:
            self.getAllKeys.emit()
        elif s.find("DRAWTEXT=") != -1:
            substr = s[len("DRAWTEXT="):]
            slist = substr.split(',')
            # print ("drawtext params:\nx: "+ slist[0] + "\ny: " + slist[1] + "\ntext: " + slist[2])
            self.drawText.emit(int(slist[0]),int(slist[1]),slist[2])
        elif s.find("SETTEXTCOLOR=") != -1:
            substr = s[len("SETTEXTCOLOR="):]
            slist = substr.split(',')
            print ("setTextColor params:\nR: "+ slist[0] + "\nG: " + slist[1] + "\nB: " + slist[2])
            self.setTextColor.emit(int(slist[0]),int(slist[1]),int(slist[2]))
        elif s.find("SETBGCOLOR=") != -1:
            substr = s[len("SETBGCOLOR="):]
            slist = substr.split(',')
            print ("setBgColor params:\nG: "+ slist[0] + "\nG: " + slist[1] + "\nB: " + slist[2])
            self.setBgColor.emit(int(slist[0]),int(slist[1]),int(slist[2]))
        elif s.find("DRAWRECT=") != -1:
            substr = s[len("DRAWRECT="):]
            slist = substr.split(',')
            print ("drawRect params:\nx: "+ slist[0] + "\ny: " + slist[1] + "\nw: " + slist[2] + "\nh: " + slist[3])
            self.drawRect.emit(int(slist[0]),int(slist[1]),int(slist[2]),int(slist[3]))
        elif s.find("DRAWFILLRECT=") != -1:
            substr = s[len("DRAWFILLRECT="):]
            slist = substr.split(',')
            print ("drawFillRect params:\nx: "+ slist[0] + "\ny: " + slist[1] + "\nw: " + slist[2] + "\nh: " + slist[3])
            self.drawFillRect.emit(int(slist[0]),int(slist[1]),int(slist[2]),int(slist[3]))
        else:
            print ("Unknown command: " + s)

    def sendKeyState(self,key,state):
        if type(key) == str:
            self.socketWorker.sendData("!KEYSTATE:"+key+"="+str(state)+"\n")
        else:
            raise

    def sendAllKeys(self,allkeys):
        if type(allkeys) == int:
            self.socketWorker.sendData("!ALLKEYS="+str(allkeys)+"\n")
        else:
            raise
