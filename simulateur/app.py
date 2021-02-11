#!/usr/bin/python3

import sys
from PyQt5 import QtCore, QtGui, QtWidgets, uic

from main_window_ui import Ui_MainWindow

from socket_worker import SocketWorker
from cmd_processor import CmdProcessor
from components.display import Display

class Window(QtWidgets.QMainWindow, Ui_MainWindow):
    def __init__(self, parent=None):
        super().__init__(parent)
        self.setupUi(self)

        canvas = QtGui.QPixmap(self.drawingArea.geometry().width(), self.drawingArea.geometry().height())
        self.drawingArea.setPixmap(canvas)
        self.socketThread = QtCore.QThread()
        self.socketWorker = SocketWorker("/home/dimercur/armada.sock")
        self.socketWorker.moveToThread(self.socketThread)
        self.socketThread.started.connect(self.socketWorker.run)
        self.socketWorker.error.connect(self.socketError)

        self.cmdProcessor = CmdProcessor(self.socketWorker)
        self.cmp_display = Display(self.drawingArea)
        self.socketWorker.openSocket()
        self.socketThread.start()

        self.draw_something()

        self.connectSignalsSlots()

    def __del__(self):
        self.socketError("finished")

    def connectSignalsSlots(self):
        # Connect buttons
        self.buttonUp.clicked.connect(self.buttonUpClicked)
        self.buttonLeft.clicked.connect(self.buttonLeftClicked)
        self.buttonRight.clicked.connect(self.buttonRightClicked)
        self.buttonDown.clicked.connect(self.buttonDownClicked)
        #self.buttonA.clicked.connect(self.buttonAClicked)
        self.buttonA.pressed.connect(self.buttonAPressed)
        self.buttonA.released.connect(self.buttonAReleased)
        #self.buttonB.pressed.connect(self.keyPressEvent,QtCore.Qt.Key_B)
        #self.buttonB.released.connect(self.keyReleaseEvent,QtCore.Qt.Key_B)
        self.buttonB.pressed.connect(lambda key=QtCore.Qt.Key_B: self.buttonPressEvent(key))
        self.buttonB.released.connect(lambda key=QtCore.Qt.Key_B: self.buttonReleaseEvent(key))
        # Connect menus
        self.actionQuitter.triggered.connect(self.close)
        #self.action_Find_Replace.triggered.connect(self.findAndReplace)
        #self.action_About.triggered.connect(self.about)

        # Connect components
        self.cmdProcessor.drawText.connect(self.cmp_display.drawtext)

    def draw_something(self):
        painter = QtGui.QPainter(self.drawingArea.pixmap()) 
        geom = self.drawingArea.geometry()

        painter.fillRect(0,0, geom.width(), geom.height(), QtCore.Qt.white)
        
        painter.drawLine(0, 0, geom.width(), geom.height())
        painter.end()

    def keyPressEvent(self, e):
        self.buttonPressEvent(e.key())
        # if e.key() == QtCore.Qt.Key_A: 
        #     self.cmdProcessor.sendKeyPressed("A")
        # elif e.key() == QtCore.Qt.Key_B:
        #     self.cmdProcessor.sendKeyPressed("B")
        # elif e.key() == QtCore.Qt.Key_C:
        #     self.cmdProcessor.sendKeyPressed("C")
        # elif e.key() == QtCore.Qt.Key_X:
        #     self.cmdProcessor.sendKeyPressed("X")
        # elif e.key() == QtCore.Qt.Key_Y:
        #     self.cmdProcessor.sendKeyPressed("Y")
        # elif e.key() == QtCore.Qt.Key_Up:
        #     self.cmdProcessor.sendKeyPressed("Up")
        # elif e.key() == QtCore.Qt.Key_Down:
        #     self.cmdProcessor.sendKeyPressed("Down")
        # elif e.key() == QtCore.Qt.Key_Left:
        #     self.cmdProcessor.sendKeyPressed("Left")
        # elif e.key() == QtCore.Qt.Key_Right:
        #     self.cmdProcessor.sendKeyPressed("Right")
        # elif e.key() == QtCore.Qt.Key_R:
        #     self.cmdProcessor.sendKeyPressed("Reset")

    def keyReleaseEvent(self, e):
        self.buttonReleaseEvent(e.key())
        # if e.key() == QtCore.Qt.Key_A: 
        #     self.cmdProcessor.sendKeyReleased("A")
        # elif e.key() == QtCore.Qt.Key_B:
        #     self.cmdProcessor.sendKeyReleased("B")
        # elif e.key() == QtCore.Qt.Key_C:
        #     self.cmdProcessor.sendKeyReleased("C")
        # elif e.key() == QtCore.Qt.Key_X:
        #     self.cmdProcessor.sendKeyReleased("X")
        # elif e.key() == QtCore.Qt.Key_Y:
        #     self.cmdProcessor.sendKeyReleased("Y")
        # elif e.key() == QtCore.Qt.Key_Up:
        #     self.cmdProcessor.sendKeyReleased("Up")
        # elif e.key() == QtCore.Qt.Key_Down:
        #     self.cmdProcessor.sendKeyReleased("Down")
        # elif e.key() == QtCore.Qt.Key_Left:
        #     self.cmdProcessor.sendKeyReleased("Left")
        # elif e.key() == QtCore.Qt.Key_Right:
        #     self.cmdProcessor.sendKeyReleased("Right")
        # elif e.key() == QtCore.Qt.Key_R:
        #     self.cmdProcessor.sendKeyReleased("Reset")

    def buttonPressEvent(self,key):
        if key == QtCore.Qt.Key_A: 
            self.cmdProcessor.sendKeyPressed("A")
        elif key == QtCore.Qt.Key_B:
            self.cmdProcessor.sendKeyPressed("B")
        elif key == QtCore.Qt.Key_C:
            self.cmdProcessor.sendKeyPressed("C")
        elif key == QtCore.Qt.Key_X:
            self.cmdProcessor.sendKeyPressed("X")
        elif key == QtCore.Qt.Key_Y:
            self.cmdProcessor.sendKeyPressed("Y")
        elif key == QtCore.Qt.Key_Up:
            self.cmdProcessor.sendKeyPressed("Up")
        elif key == QtCore.Qt.Key_Down:
            self.cmdProcessor.sendKeyPressed("Down")
        elif key == QtCore.Qt.Key_Left:
            self.cmdProcessor.sendKeyPressed("Left")
        elif key == QtCore.Qt.Key_Right:
            self.cmdProcessor.sendKeyPressed("Right")
        elif key == QtCore.Qt.Key_R:
            self.cmdProcessor.sendKeyPressed("Reset")

    def buttonReleaseEvent(self,key):
        if key == QtCore.Qt.Key_A: 
            self.cmdProcessor.sendKeyReleased("A")
        elif key == QtCore.Qt.Key_B:
            self.cmdProcessor.sendKeyReleased("B")
        elif key == QtCore.Qt.Key_C:
            self.cmdProcessor.sendKeyReleased("C")
        elif key == QtCore.Qt.Key_X:
            self.cmdProcessor.sendKeyReleased("X")
        elif key == QtCore.Qt.Key_Y:
            self.cmdProcessor.sendKeyReleased("Y")
        elif key == QtCore.Qt.Key_Up:
            self.cmdProcessor.sendKeyReleased("Up")
        elif key == QtCore.Qt.Key_Down:
            self.cmdProcessor.sendKeyReleased("Down")
        elif key == QtCore.Qt.Key_Left:
            self.cmdProcessor.sendKeyReleased("Left")
        elif key == QtCore.Qt.Key_Right:
            self.cmdProcessor.sendKeyReleased("Right")
        elif key == QtCore.Qt.Key_R:
            self.cmdProcessor.sendKeyReleased("Reset")

    def buttonUpClicked(self):
        print("button up event")

    def buttonLeftClicked(self):
        print("button left event")

    def buttonRightClicked(self):
        print("button right event")

    def buttonDownClicked(self):
        print("button down event")

    def buttonAPressed(self):
        print("button A event")
        self.cmdProcessor.sendKeyPressed("A")

    def buttonAReleased(self):
        print("button A released ")
        self.cmdProcessor.sendKeyReleased("A")

    def buttonBClicked(self):
        print("button B event")

    def socketError(self,err):
        print("Network error received: "+err)
        if err=="finished":
            print ("closing socket and finishing thread")
            self.socketWorker.closeSocket()
    
            self.socketThread.quit()
            self.socketThread.deleteLater() 

    def socketCmd(self,cmd):
        print("Network cmd received: "+cmd) 
        
app = QtWidgets.QApplication(sys.argv)
window = Window()
window.show()
app.exec_()

