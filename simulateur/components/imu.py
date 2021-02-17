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

    def getXValue(self):
        return self.dialLeft.value()

    def getYValue(self):
        return self.dialRight.value()

    def getZValue(self):
        return self.dialRight.value()

    def setXRange(self,minVal, maxVal):
        self.sliderX.setRange(minVal,maxVal)

    def setYRange(self,minVal, maxVal):
        self.sliderY.setRange(minVal,maxVal) 

    def setZRange(self,minVal, maxVal):
        self.sliderZ.setRange(minVal,maxVal)

    def updateXLabel(self):
        val = self.sliderX.value()
        print ("X= " + str(val))
        self.labelX.setText("Axe X = " + str(val) + " g [ " + hex(val) + " ]")

    def updateYLabel(self):
        val = self.sliderY.value()
        print ("Y= " + str(val))
        self.labelY.setText("Axe Y = " + str(val) + " g [ " + hex(val) + " ]")

    def updateZLabel(self):
        val = self.sliderZ.value()
        print ("Z= " + str(val))
        self.labelZ.setText("Axe Z = " + str(val) + " g [ " + hex(val) + " ]")

class Accelerometer(MetaIMUDialog, Ui_DialogAccelerometer):
    pass

class Gyroscope(MetaIMUDialog, Ui_DialogGyroscope):
    pass

class Magnetometer(MetaIMUDialog, Ui_DialogMagnetometer):
    pass
