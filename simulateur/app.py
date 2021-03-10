#!/usr/bin/python3

import sys
from PyQt5 import QtCore, QtGui, QtWidgets, uic
from PyQt5.QtWidgets import QMessageBox

from main_window_ui import Ui_MainWindow

from socket_worker import SocketWorker
from cmd_processor import CmdProcessor
from components.display import Display
from components.keys import Keys
from components.knobs import KnobsDialog
from components.imu import Accelerometer, Gyroscope, Magnetometer

from tests.tests import Tests

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

legacyMode = False

class Window(QtWidgets.QMainWindow, Ui_MainWindow):
    def __init__(self, parent=None):
        super().__init__(parent)
        self.setupUi(self)
        self.setChildrenFocusPolicy(QtCore.Qt.NoFocus)

        self.socketThread = QtCore.QThread()
        self.socketWorker = SocketWorker("/home/dimercur/armada.sock")
        self.socketWorker.moveToThread(self.socketThread)

        self.cmp_display = Display(self.centralwidget)
        self.cmp_display.setObjectName("cmp_display")

        if legacyMode == True: 
            # Legacy mode enabled: screen size is 320x240
            self.cmp_display.setGeometry(351,108,320,240)
            self.cmp_display.drawFillRectangle(0,0,319,239)
        else: 
            # Normal mode enabled: screen size is 480x272
            self.cmp_display.setGeometry(271,92,480,272)
            self.cmp_display.drawFillRectangle(0,0,479,271)

        self.cmp_keys = Keys()
        self.cmp_knobs = KnobsDialog(self)
        self.cmp_accelerometer = Accelerometer(self)
        self.cmp_gyroscope = Gyroscope(self)
        self.cmp_magnetometer = Magnetometer(self)

        self.cmdProcessor = CmdProcessor(self.socketWorker)

        if legacyMode == True:
            # Legacy mode enabled
            # Calibrate sensors for legacy system
            self.cmp_accelerometer.setXRange(-1000,1000)
            self.cmp_accelerometer.setXRange(-1000,1000)
            self.cmp_accelerometer.setXRange(-1000,1000)
        else:
            # Normal mode enabled
            # Disable knobs
            self.actionPotentiometres.setDisabled(True)

        self.connectSignalsSlots()

        self.socketWorker.openSocket()
        self.socketThread.start()

    def setChildrenFocusPolicy (self, policy):
        self.centralwidget.setFocusPolicy(policy)
        self.backgroundImg.setFocusPolicy(policy)
        self.buttonUp.setFocusPolicy(policy)
        self.buttonLeft.setFocusPolicy(policy)
        self.buttonRight.setFocusPolicy(policy)
        self.buttonDown.setFocusPolicy(policy)
        self.buttonB.setFocusPolicy(policy)
        self.buttonA.setFocusPolicy(policy)
        self.buttonX.setFocusPolicy(policy)
        self.buttonY.setFocusPolicy(policy)
        self.buttonReset.setFocusPolicy(policy)

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
        self.actionPotentiometres.triggered.connect(self.showPotentiometres)
        self.actionAccelerometre.triggered.connect(self.showAccelerometer)
        self.actionGyroscope.triggered.connect(self.showGyroscope)
        self.actionMagnetometre.triggered.connect(self.showMagnetometer)
        self.actionTests.triggered.connect(self.showTests)

        # Connect command processor events
        self.cmdProcessor.drawText.connect(self.cmp_display.drawText)
        #self.cmdProcessor.getKeyState.connect(self.cp_GetKeyState)
        #self.cmdProcessor.getAllKeys.connect(self.cp_GetAllKeys)
        self.cmdProcessor.setTextColor.connect(self.cmp_display.setTextColor)
        self.cmdProcessor.setBgColor.connect(self.cmp_display.setBgColor)
        self.cmdProcessor.clearScreen.connect(self.cmp_display.clearScreen)
        self.cmdProcessor.drawLine.connect(self.cmp_display.drawLine)
        self.cmdProcessor.drawRect.connect(self.cmp_display.drawRectangle)
        self.cmdProcessor.drawFillRect.connect(self.cmp_display.drawFillRectangle)
        self.cmdProcessor.drawImage.connect(self.cmp_display.drawImageFromBase64)
        self.cmdProcessor.drawImageFromSram.connect(self.cmp_display.drawImageFromSRAM)
        self.cmdProcessor.writeByte.connect(self.cmp_display.writeByteInSRAM)
        self.cmdProcessor.writeBuffer.connect(self.cmp_display.writeBufferInSRAM)

        # Connect socket events
        self.socketWorker.stateChanged.connect(self.socketEvent)
        self.socketThread.started.connect(self.socketWorker.run)
        
    def keyPressEvent(self, e):
        #print ("Key Pressed event: " + str(e.key()))
        self.buttonPressEvent(e.key())

    def keyReleaseEvent(self, e):
        #print ("Key Released event: " + str(e.key()))
        self.buttonReleaseEvent(e.key())

    def buttonPressEvent(self,key):
        keystr=""

        if key in keyDict:
            if key == QtCore.Qt.Key_Up:
                keystr="UP"
            elif key == QtCore.Qt.Key_Left:
                keystr="LEFT"  
            elif key == QtCore.Qt.Key_Right: 
                keystr="RIGHT"
            elif key == QtCore.Qt.Key_Down: 
                keystr="DOWN"
            elif key == QtCore.Qt.Key_A:
                keystr="A"
            elif key == QtCore.Qt.Key_B: 
                keystr="B"
            elif key == QtCore.Qt.Key_X:
                keystr="X"
            elif key == QtCore.Qt.Key_Y: 
                keystr="Y"
            elif key == QtCore.Qt.Key_R:
                keystr="R"
            else:
                raise

            self.cmdProcessor.sendKeyPressed(keystr)

    def buttonReleaseEvent(self,key):
        keystr=""

        if key in keyDict:
            if key == QtCore.Qt.Key_Up:
                keystr="UP"
            elif key == QtCore.Qt.Key_Left:
                keystr="LEFT"  
            elif key == QtCore.Qt.Key_Right: 
                keystr="RIGHT"
            elif key == QtCore.Qt.Key_Down: 
                keystr="DOWN"
            elif key == QtCore.Qt.Key_A:
                keystr="A"
            elif key == QtCore.Qt.Key_B: 
                keystr="B"
            elif key == QtCore.Qt.Key_X:
                keystr="X"
            elif key == QtCore.Qt.Key_Y: 
                keystr="Y"
            elif key == QtCore.Qt.Key_R:
                keystr="R"
            else:
                raise

            self.cmdProcessor.sendKeyReleased(keystr)

    # def buttonPressEvent(self,key):
    #     if key in keyDict:
    #         self.cmp_keys.setKeyPressed(keyDict[key])

    # def buttonReleaseEvent(self,key):
    #     if key in keyDict:
    #         self.cmp_keys.setKeyReleased(keyDict[key])

    # def cp_GetKeyState(self, key):
    #     if key in textKeyDict:
    #         if self.cmp_keys.isKeyPressed(textKeyDict[key]):
    #             self.cmdProcessor.sendKeyState(key, 1)
    #         else:
    #             self.cmdProcessor.sendKeyState(key, 0)
    #     else:
    #         raise

    # def cp_GetAllKeys(self):
    #     allkeys = self.cmp_keys.getState()
    #     self.cmdProcessor.sendAllKeys(allkeys)

    def close(self):
        self.socketWorker.closeSocket()
    
        self.socketThread.quit()
        self.socketThread.deleteLater() 
        app.exit()

    def about(self):
        QMessageBox.information(self,"A propos de","Arm-Ada simulator\nVersion 1.0\n\nCopyright INSA-GEI 2021", QMessageBox.Ok)
    
    def open(self):
        QMessageBox.critical(self,"Error","Function not implemented", QMessageBox.Ok)

    def showPotentiometres(self):
        self.cmp_knobs.show()

    def showAccelerometer(self):
        self.cmp_accelerometer.show()

    def showGyroscope(self):
        self.cmp_gyroscope.show()

    def showMagnetometer(self):
        self.cmp_magnetometer.show()

    def showTests(self):
        self.tests = Tests(self)
        self.tests.show()

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

if len(sys.argv) > 1:
    if sys.argv[1] == "legacy":
        print ("enabling legacy mode")
        legacyMode = True

app = QtWidgets.QApplication(sys.argv)
window = Window()
window.show()
app.exec_()
