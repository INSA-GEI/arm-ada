from PyQt5.QtCore import QObject, pyqtSignal
from socket_worker import *

class CmdProcessor(QObject):
    drawText = pyqtSignal(int,int,str) # x: int, y: int, text: str
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
            print ("drawtext params:\nx: "+ slist[0] + "\ny: " + slist[1] + "\ntext: " + slist[2])
            self.drawText.emit(int(slist[0]),int(slist[1]),slist[2])
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
