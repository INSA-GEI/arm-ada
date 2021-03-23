from PyQt5.QtCore import QObject, pyqtSignal
from socket_worker import *

class CmdProcessor(QObject):
    setTextColor = pyqtSignal(int,int,int) # R: int, G: int, B: int
    setBgColor = pyqtSignal(int,int,int) # R: int, G: int, B: int
    clearScreen = pyqtSignal(int,int,int) # R: int, G: int, B: int
    drawText = pyqtSignal(int,int,str) # x: int, y: int, text: str
    drawLine = pyqtSignal(int,int,int, int) # x1: int, y1: int, x2: int, y2: int
    drawRect = pyqtSignal(int,int,int, int) # x: int, y: int, w: int, h: int
    drawFillRect = pyqtSignal(int,int,int, int) # x: int, y: int, w: int, h: int
    drawImage = pyqtSignal(int,int,int,int,str) # x: int, y: int, w: int, h: int, img(base64): str
    drawImageFromSram = pyqtSignal(int,int,int,int,int) # x: int, y: int, w: int, h: int, offset: int
    writeByte = pyqtSignal(int,int,int) # offset: int, LSB: int, MSB: int
    writeBuffer = pyqtSignal(int,str) # offset: int, LSB: int, MSB: int
    
    def __init__(self, socketWorker: SocketWorker):
        super(CmdProcessor, self).__init__()
        # Store constructor arguments (re-used for processing)
        self.socketWorker = socketWorker
        self.socketWorker.dataReceived.connect(self.dataReceived)

    def dataReceived(self, s):
        # decoupe le message en bloc separé par les line feed
        
        commandList = s.split('\n')
        # print ("Cmd in pipe = " + str(len(commandList)))

        for cmdstr in commandList:
            if cmdstr.find("DRAWTEXT=") != -1:
                substr = cmdstr[len("DRAWTEXT="):]
                slist = substr.split(',')
                #print ("drawtext params:\nx: "+ slist[0] + "\ny: " + slist[1] + "\ntext: " + slist[2])
                self.drawText.emit(int(slist[0]),int(slist[1]),slist[2])
            elif cmdstr.find("SETTEXTCOLOR=") != -1:
                substr = cmdstr[len("SETTEXTCOLOR="):]
                slist = substr.split(',')
                #print ("setTextColor params:\nR: "+ slist[0] + "\nG: " + slist[1] + "\nB: " + slist[2])
                self.setTextColor.emit(int(slist[0]),int(slist[1]),int(slist[2]))
            elif cmdstr.find("SETBGCOLOR=") != -1:
                substr = cmdstr[len("SETBGCOLOR="):]
                slist = substr.split(',')
                #print ("setBgColor params:\nG: "+ slist[0] + "\nG: " + slist[1] + "\nB: " + slist[2])
                self.setBgColor.emit(int(slist[0]),int(slist[1]),int(slist[2]))
            elif cmdstr.find("CLEARSCREEN=") != -1:
                substr = cmdstr[len("CLEARSCREEN="):]
                slist = substr.split(',')
                #print ("setBgColor params:\nG: "+ slist[0] + "\nG: " + slist[1] + "\nB: " + slist[2])
                self.clearScreen.emit(int(slist[0]),int(slist[1]),int(slist[2]))
            elif cmdstr.find("DRAWLINE=") != -1:
                substr = cmdstr[len("DRAWLINE="):]
                slist = substr.split(',')
                #print ("drawRect params:\nx1: "+ slist[0] + "\ny1: " + slist[1] + "\nx2: " + slist[2] + "\ny2: " + slist[3])
                self.drawLine.emit(int(slist[0]),int(slist[1]),int(slist[2]),int(slist[3]))
            elif cmdstr.find("DRAWRECT=") != -1:
                substr = cmdstr[len("DRAWRECT="):]
                slist = substr.split(',')
                #print ("drawRect params:\nx: "+ slist[0] + "\ny: " + slist[1] + "\nw: " + slist[2] + "\nh: " + slist[3])
                self.drawRect.emit(int(slist[0]),int(slist[1]),int(slist[2]),int(slist[3]))
            elif cmdstr.find("DRAWFILLRECT=") != -1:
                substr = cmdstr[len("DRAWFILLRECT="):]
                slist = substr.split(',')
                #print ("drawFillRect params:\nx: "+ slist[0] + "\ny: " + slist[1] + "\nw: " + slist[2] + "\nh: " + slist[3])
                self.drawFillRect.emit(int(slist[0]),int(slist[1]),int(slist[2]),int(slist[3]))
            elif cmdstr.find("DRAWIMAGE=") != -1:
                substr = cmdstr[len("DRAWIMAGE="):]
                slist = substr.split(',')
                #print ("DRAWIMAGE params:\nx: "+ slist[0] + "\ny: " + slist[1] + "\nw: " + slist[2] + "\nh: " + slist[3])
                #print ("Base 64 => " + slist[4])
                self.drawImage.emit(int(slist[0]),int(slist[1]),int(slist[2]),int(slist[3]), str(slist[4]))
            elif cmdstr.find("DRAWIMAGEFROMSRAM=") != -1:
                print (cmdstr)
                substr = cmdstr[len("DRAWIMAGEFROMSRAM="):]
                slist = substr.split(',')
                #print ("DRAWIMAGEFROMSRAM params:\nx: "+ slist[0] + "\ny: " + slist[1] + "\nw: " + slist[2] + "\nh: " + slist[3])
                #print ("Base 64 => " + slist[4])
                self.drawImageFromSram.emit(int(slist[0]),int(slist[1]),int(slist[2]),int(slist[3]),int(slist[4]))
            elif cmdstr.find("WRITEBYTE=") != -1:
                # print (cmdstr)
                substr = cmdstr[len("WRITEBYTE="):]
                slist = substr.split(',')
                #print ("setBgColor params:\nG: "+ slist[0] + "\nG: " + slist[1] + "\nB: " + slist[2])
                self.writeByte.emit(int(slist[0]),int(slist[1]),int(slist[2]))
            elif cmdstr.find("WRITEBUFFER=") != -1:
                # print (cmdstr)
                substr = cmdstr[len("WRITEBUFFER="):]
                slist = substr.split(',')
                #print ("setBgColor params:\nAddr: "+ slist[0])
                #print ("Base 64 => " + slist[1])
                self.writeBuffer.emit(int(slist[0]),slist[1])
            else:
                print ("Unimplemented command: " + cmdstr)

    def sendKeyPressed(self,key):
        if type(key)==str:
            self.socketWorker.sendData("KEYPRESSED="+key+"\n")
        else:
            raise

    def sendKeyReleased(self,key):
        if type(key)==str:
            self.socketWorker.sendData("KEYRELEASED="+key+"\n")
        else:
            raise

    def sendKnobsValues(self,leftKnob, rightKnob):
        if type(leftKnob)==int and type(rightKnob)==int:
            self.socketWorker.sendData("KNOBSCHANGED="+str(leftKnob)+','+str(rightKnob)+"\n")
        else:
            raise

    def sendAccelerometerValues(self,X, Y, Z):
        if type(X)==int and type(Y)==int and type(Z)==int:
            self.socketWorker.sendData("ACCCHANGED="+str(X)+','+str(Y)+','+str(Z)+"\n")
        else:
            raise
    
    def sendGyroscopeValues(self,X, Y, Z):
        if type(X)==int and type(Y)==int and type(Z)==int:
            self.socketWorker.sendData("GYRCHANGED="+str(X)+','+str(Y)+','+str(Z)+"\n")
        else:
            raise

    def sendMagnetometerValues(self,X, Y, Z):
        if type(X)==int and type(Y)==int and type(Z)==int:
            self.socketWorker.sendData("MAGCHANGED="+str(X)+','+str(Y)+','+str(Z)+"\n")
        else:
            raise

    
