#!/usr/bin/python3

import sys
from PyQt5 import QtCore, QtGui, QtWidgets, uic
from PyQt5.QtWidgets import QMessageBox

from main_window_ui import Ui_MainWindow

from socket_worker import SocketWorker
from cmd_processor import CmdProcessor
from components.display import Display
from components.keys import Keys

keyDict = { QtCore.Qt.Key_A: Keys.Key_A, 
            QtCore.Qt.Key_B: Keys.Key_B,
            QtCore.Qt.Key_C: Keys.Key_C,
            QtCore.Qt.Key_X: Keys.Key_X,
            QtCore.Qt.Key_Y: Keys.Key_Y,
            QtCore.Qt.Key_Up: Keys.Key_Up,
            QtCore.Qt.Key_Down: Keys.Key_Down,
            QtCore.Qt.Key_Left: Keys.Key_Left,
            QtCore.Qt.Key_Right: Keys.Key_Right,
            QtCore.Qt.Key_R: Keys.Key_Reset }

textKeyDict = { 'A': Keys.Key_A, 
                'B': Keys.Key_B,
                'C': Keys.Key_C,
                'X': Keys.Key_X,
                'Y': Keys.Key_Y,
                'UP': Keys.Key_Up,
                'DOWN': Keys.Key_Down,
                'LEFT': Keys.Key_Left,
                'RIGHT': Keys.Key_Right,
                'RESET': Keys.Key_Reset }

class Window(QtWidgets.QMainWindow, Ui_MainWindow):
    def __init__(self, parent=None):
        super().__init__(parent)
        self.setupUi(self)

        self.socketThread = QtCore.QThread()
        self.socketWorker = SocketWorker("/home/dimercur/armada.sock")
        self.socketWorker.moveToThread(self.socketThread)
        
        self.cmp_display = Display(self.centralwidget)
        self.cmp_display.setGeometry(271,92,480,272)
        self.cmp_display.setObjectName("cmp_display")
        self.cmp_display.drawFillRectangle(0,0,480,272)

        self.cmp_keys = Keys()

        self.cmdProcessor = CmdProcessor(self.socketWorker)
        self.socketWorker.openSocket()
        self.socketThread.start()

        self.connectSignalsSlots()

    def __del__(self):
        self.socketError("finished")

    def connectSignalsSlots(self):
        # Connect buttons
        self.buttonUp.pressed.connect(lambda key=QtCore.Qt.Key_Up: self.buttonPressEvent(key))
        self.buttonLeft.pressed.connect(lambda key=QtCore.Qt.Key_Left: self.buttonPressEvent(key))
        self.buttonRight.pressed.connect(lambda key=QtCore.Qt.Key_Right: self.buttonPressEvent(key))
        self.buttonDown.pressed.connect(lambda key=QtCore.Qt.Key_Down: self.buttonPressEvent(key))
        self.buttonA.pressed.connect(lambda key=QtCore.Qt.Key_A: self.buttonPressEvent(key))
        self.buttonB.pressed.connect(lambda key=QtCore.Qt.Key_B: self.buttonPressEvent(key))
        self.buttonX.pressed.connect(lambda key=QtCore.Qt.Key_X: self.buttonPressEvent(key))
        self.buttonY.pressed.connect(lambda key=QtCore.Qt.Key_Y: self.buttonPressEvent(key))
        self.buttonReset.pressed.connect(lambda key=QtCore.Qt.Key_R: self.buttonPressEvent(key))

        self.buttonUp.released.connect(lambda key=QtCore.Qt.Key_Up: self.buttonReleaseEvent(key))
        self.buttonLeft.released.connect(lambda key=QtCore.Qt.Key_Left: self.buttonReleaseEvent(key))
        self.buttonRight.released.connect(lambda key=QtCore.Qt.Key_Right: self.buttonReleaseEvent(key))
        self.buttonDown.released.connect(lambda key=QtCore.Qt.Key_Down: self.buttonReleaseEvent(key))
        self.buttonA.released.connect(lambda key=QtCore.Qt.Key_A: self.buttonReleaseEvent(key))
        self.buttonB.released.connect(lambda key=QtCore.Qt.Key_B: self.buttonReleaseEvent(key))
        self.buttonX.released.connect(lambda key=QtCore.Qt.Key_X: self.buttonReleaseEvent(key))
        self.buttonY.released.connect(lambda key=QtCore.Qt.Key_Y: self.buttonReleaseEvent(key))
        self.buttonReset.released.connect(lambda key=QtCore.Qt.Key_R: self.buttonReleaseEvent(key))

        # Connect menus
        self.actionQuitter.triggered.connect(self.close)
        self.actionA_propos_de.triggered.connect(self.about)
        self.actionOuvrir.triggered.connect(self.open)

        # Connect command processor events
        self.cmdProcessor.drawText.connect(self.cmp_display.drawText)
        self.cmdProcessor.getKeyState.connect(self.cp_GetKeyState)
        self.cmdProcessor.getAllKeys.connect(self.cp_GetAllKeys)

        # Connect socket events
        self.socketWorker.stateChanged.connect(self.socketEvent)
        self.socketThread.started.connect(self.socketWorker.run)
        self.socketWorker.stateChanged.connect(self.socketEvent)
        
    def keyPressEvent(self, e):
        self.buttonPressEvent(e.key())

    def keyReleaseEvent(self, e):
        self.buttonReleaseEvent(e.key())

    def buttonPressEvent(self,key):
        if key in keyDict:
            self.cmp_keys.setKeyPressed(keyDict[key])

    def buttonReleaseEvent(self,key):
        if key in keyDict:
            self.cmp_keys.setKeyReleased(keyDict[key])

    def cp_GetKeyState(self, key):
        if key in textKeyDict:
            if self.cmp_keys.isKeyPressed(textKeyDict[key]):
                self.cmdProcessor.sendKeyState(key, 1)
            else:
                self.cmdProcessor.sendKeyState(key, 0)
        else:
            raise

    def cp_GetAllKeys(self):
        allkeys = self.cmp_keys.getState()
        self.cmdProcessor.sendAllKeys(allkeys)

    def close(self):
        self.socketWorker.closeSocket()
    
        self.socketThread.quit()
        self.socketThread.deleteLater() 
        app.exit()

    def about(self):
        QMessageBox.information(self,"A propos de","Arm-Ada simulator\nVersion 1.0\n\nCopyright INSA-GEI 2021", QMessageBox.Ok)
    
    def open(self):
        QMessageBox.critical(self,"Error","Function not implemented", QMessageBox.Ok)

    def socketEvent(self,evt):
        print("Socket event received: "+ evt)

        if evt=="connected":
            print ("socket connected")
            
        elif evt=="disconnected":
            print ("socket disconnected")
        elif evt=="finished":
            print ("closing socket and finishing thread")
            self.socketWorker.closeSocket()
    
            self.socketThread.quit()
            self.socketThread.deleteLater() 
        
app = QtWidgets.QApplication(sys.argv)
window = Window()
window.show()
app.exec_()

