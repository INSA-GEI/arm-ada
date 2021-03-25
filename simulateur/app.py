#!/usr/bin/python3

import sys, threading,subprocess
from PyQt5 import QtCore, QtGui, QtWidgets, uic
from PyQt5.QtWidgets import QMessageBox, QFileDialog

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

        # Gestion de l'appli externe ADA
        self.isRunning=False
        self.execThread=None

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
        # Reset signal
        self.cmdProcessor.resetEvent.connect(self.cmp_display.reset)
        self.cmdProcessor.resetEvent.connect(self.cmp_knobs.reset)
        self.cmdProcessor.resetEvent.connect(self.cmp_accelerometer.reset)
        self.cmdProcessor.resetEvent.connect(self.cmp_gyroscope.reset)
        self.cmdProcessor.resetEvent.connect(self.cmp_magnetometer.reset)
        self.cmdProcessor.resetEvent.connect(self.reset)

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

        # Connect dialog events
        self.cmp_knobs.dialLeft.valueChanged.connect(self.knobsChanged)
        self.cmp_knobs.dialRight.valueChanged.connect(self.knobsChanged)
        self.cmp_accelerometer.sliderX.valueChanged.connect(self.accelerometerChanged)
        self.cmp_accelerometer.sliderY.valueChanged.connect(self.accelerometerChanged)
        self.cmp_accelerometer.sliderZ.valueChanged.connect(self.accelerometerChanged)
        self.cmp_gyroscope.sliderX.valueChanged.connect(self.gyroscopeChanged)
        self.cmp_gyroscope.sliderY.valueChanged.connect(self.gyroscopeChanged)
        self.cmp_gyroscope.sliderZ.valueChanged.connect(self.gyroscopeChanged)
        self.cmp_magnetometer.sliderX.valueChanged.connect(self.magnetometerChanged)
        self.cmp_magnetometer.sliderY.valueChanged.connect(self.magnetometerChanged)
        self.cmp_magnetometer.sliderZ.valueChanged.connect(self.magnetometerChanged)

        # Connect command processor events
        self.cmdProcessor.drawText.connect(self.cmp_display.drawText)
        self.cmdProcessor.setTextColor.connect(self.cmp_display.setTextColor)
        self.cmdProcessor.setBgColor.connect(self.cmp_display.setBgColor)
        self.cmdProcessor.clearScreen.connect(self.cmp_display.clearScreen)
        self.cmdProcessor.drawLine.connect(self.cmp_display.drawLine)
        self.cmdProcessor.drawRect.connect(self.cmp_display.drawRectangle)
        self.cmdProcessor.drawFillRect.connect(self.cmp_display.drawFillRectangle)
        self.cmdProcessor.drawCircle.connect(self.cmp_display.drawCircle)
        self.cmdProcessor.drawFillCircle.connect(self.cmp_display.drawFillCircle)
        self.cmdProcessor.drawImage.connect(self.cmp_display.drawImageFromBase64)
        self.cmdProcessor.drawImageFromSram.connect(self.cmp_display.drawImageFromSRAM)
        self.cmdProcessor.writeByte.connect(self.cmp_display.writeByteInSRAM)
        self.cmdProcessor.writeBuffer.connect(self.cmp_display.writeBufferInSRAM)

        # Connect socket events
        self.socketWorker.stateChanged.connect(self.socketEvent)
        self.socketThread.started.connect(self.socketWorker.run)
    
    def reset(self):
        pass

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

    def knobsChanged(self):
        leftKnob = self.cmp_knobs.getLeftKnobValue()
        rightKnob = self.cmp_knobs.getRightKnobValue()
        self.cmdProcessor.sendKnobsValues(leftKnob, rightKnob)

    def accelerometerChanged(self):
        X = self.cmp_accelerometer.getXValue()
        Y = self.cmp_accelerometer.getYValue()
        Z = self.cmp_accelerometer.getZValue()
        self.cmdProcessor.sendAccelerometerValues(X, Y, Z)

    def gyroscopeChanged(self):
        X = self.cmp_gyroscope.getXValue()
        Y = self.cmp_gyroscope.getYValue()
        Z = self.cmp_gyroscope.getZValue()
        self.cmdProcessor.sendGyroscopeValues(X, Y, Z)

    def magnetometerChanged(self):
        X = self.cmp_magnetometer.getXValue()
        Y = self.cmp_magnetometer.getYValue()
        Z = self.cmp_magnetometer.getZValue()
        self.cmdProcessor.sendMagnetometerValues(X, Y, Z)

    def close(self):
        self.socketWorker.closeSocket()
    
        self.socketThread.quit()
        self.socketThread.deleteLater() 

        app.exit()

    def about(self):
        QMessageBox.information(self,"A propos de","Arm-Ada simulator\nVersion 1.0\n\nCopyright INSA-GEI 2021", QMessageBox.Ok)
    
    def open(self):
        if self.isRunning==True:
            print ("Previous execWorker running: killing instance ")
            del self.execThread
            print ("Previous execWorker killed")

        options = QFileDialog.Options()
        options |= QFileDialog.DontUseNativeDialog
        adaExec, _ = QFileDialog.getOpenFileName(self,"Select an ADA executable", "","Python Files (*.adx);;All Files (*)", options=options)

        if adaExec:
            self.execThread = threading.Thread(target=self.fun, args=(adaExec,))
            self.execThread.daemon=True
            # print ("Starting execWorker thread")
            self.execThread.start()
            # print ("Starting execWorker thread done")
        else:
            QMessageBox.critical(self,"Error","No ADA executable selected", QMessageBox.Ok)
    
    def fun(self, filename):
        # print ("Start execWorker")

        if filename and filename != "":
            # print ("Start %1 executable",filename)
            self.isRunning=True

            return_code = subprocess.call(filename, shell=True)
        else:
            print ("No ada executable to run")

        self.isRunning=False
        # print ("execWorker done")

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
        # print("Socket event received: "+ evt)

        if evt=="connected":
            # print ("socket connected")
            pass

        elif evt=="disconnected":
            # print ("socket disconnected")
            pass

        elif evt=="finished":
            # print ("closing socket and finishing thread")
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
