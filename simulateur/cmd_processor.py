from PyQt5.QtCore import QObject, pyqtSignal
from socket_worker import *

class CmdProcessor(QObject):
    drawText = pyqtSignal(int,int,str)
    #error = pyqtSignal(str)

    def __init__(self, socketWorker: SocketWorker):
        super(CmdProcessor, self).__init__()
        # Store constructor arguments (re-used for processing)
        self.socketWorker = socketWorker
        self.socketWorker.dataReceived.connect(self.dataReceived)

    def dataReceived(self, s):
        print ("data received: " + s)

        if s == "TOTO":
            self.drawText.emit(1,1,"TOTO")

    def sendKeyPressed(self,key):
        if key == "A":
            self.socketWorker.sendData("KEY=A\n")
        elif key == "B":
            self.socketWorker.sendData("KEY=B\n")

    def sendKeyReleased(self,key):
        if key == "A":
            self.socketWorker.sendData("KEY!=A\n")
        if key == "B":
            self.socketWorker.sendData("KEY!=B\n")
