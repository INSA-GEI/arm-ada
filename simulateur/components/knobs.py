from PyQt5 import QtCore, QtGui, QtWidgets

from dialog_knobs_ui import Ui_DialogPotentiometers

class KnobsDialog(QtWidgets.QDialog, Ui_DialogPotentiometers):

    # knobValuesChanged = pyqtSignal(int,int) # leftKnob: int, rightKnob: int

    def __init__(self,parent=None):
        super().__init__(parent)
        self.setupUi(self)

        self.dialLeft.setRange(1,255)
        self.dialRight.setRange(1,255)

        # signals connection
        self.dialLeft.valueChanged.connect(self.updateLeftLabel)
        self.dialRight.valueChanged.connect(self.updateRightLabel)

        self.reset()

    def reset(self):
        self.dialLeft.setValue(1)
        self.dialRight.setValue(1)

    def getLeftKnobValue(self):
        return self.dialLeft.value()

    def getRightKnobValue(self):
        return self.dialRight.value()

    def updateLeftLabel(self):
        val = self.dialLeft.value()
        self.labelDialLeft.setText("Val = " + str(val) + "[ " + hex(val) + " ]")

    def updateRightLabel(self):
        val = self.dialRight.value()
        self.labelDialRight.setText("Val = " + str(val) + "[ " + hex(val) + " ]")
