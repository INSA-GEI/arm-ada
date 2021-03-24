from PyQt5 import QtCore, QtGui, QtWidgets

from dialog_accelerometer_ui import Ui_DialogAccelerometer
from dialog_gyroscope_ui import Ui_DialogGyroscope
from dialog_magnetometer_ui import Ui_DialogMagnetometer

class MetaIMUDialog(QtWidgets.QDialog):

    def __init__(self,parent=None):
        super().__init__(parent)
        self.setupUi(self)

        # signals connection
        self.sliderX.valueChanged.connect(self.updateXLabel)
        self.sliderY.valueChanged.connect(self.updateYLabel)
        self.sliderZ.valueChanged.connect(self.updateZLabel)

        self.sliderX.sliderReleased.connect(self.resetX)
        self.sliderY.sliderReleased.connect(self.resetY)
        self.sliderZ.sliderReleased.connect(self.resetZ)

        self.reset()
    
    def reset(self):
        self.resetX()
        self.resetY()
        self.resetZ()

    def getXValue(self):
        return self.sliderX.value()

    def getYValue(self):
        return self.sliderY.value()

    def getZValue(self):
        return self.sliderZ.value()

    def setXRange(self,minVal, maxVal):
        self.sliderX.setRange(minVal,maxVal)

    def setYRange(self,minVal, maxVal):
        self.sliderY.setRange(minVal,maxVal) 

    def setZRange(self,minVal, maxVal):
        self.sliderZ.setRange(minVal,maxVal)

    def resetX(self):
        #print("sliderX released")
        self.sliderX.setValue(0)
    
    def resetY(self):
        #print("sliderY released")
        self.sliderY.setValue(0)
    
    def resetZ(self):
        #print("sliderZ released")
        self.sliderZ.setValue(0)

    def updateXLabel(self):
        val = self.getXValue()
        #print ("X= " + str(val))
        self.labelX.setText("Axe X = " + str(val) + " g [ " + hex(val) + " ]")

    def updateYLabel(self):
        val = self.getYValue()
        #print ("Y= " + str(val))
        self.labelY.setText("Axe Y = " + str(val) + " g [ " + hex(val) + " ]")

    def updateZLabel(self):
        val = self.getZValue()
        #print ("Z= " + str(val))
        self.labelZ.setText("Axe Z = " + str(val) + " g [ " + hex(val) + " ]")

class Accelerometer(MetaIMUDialog, Ui_DialogAccelerometer):
    def __init__(self,parent=None):
        super().__init__(parent)

        self.setXRange(-32768, +32767)
        self.setYRange(-32768, +32767)
        self.setZRange(-32768, +32767)

class Gyroscope(MetaIMUDialog, Ui_DialogGyroscope):
    def __init__(self,parent=None):
        super().__init__(parent)

        self.setXRange(-32768, +32767)
        self.setYRange(-32768, +32767)
        self.setZRange(-32768, +32767)

class Magnetometer(MetaIMUDialog, Ui_DialogMagnetometer):
    def __init__(self,parent=None):
        super().__init__(parent)

        self.setXRange(-32768, +32767)
        self.setYRange(-32768, +32767)
        self.setZRange(-32768, +32767)
