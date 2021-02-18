from PyQt5 import QtCore, QtGui, QtWidgets, uic
from PyQt5.QtWidgets import QMessageBox

from tests.dialog_tests_ui import Ui_DialogTest

from tests.tests_lcd import TestsLCD

class Tests(QtWidgets.QDialog, Ui_DialogTest):
    win = None

    def __init__(self, win:QtWidgets.QMainWindow, parent=None):
        super().__init__(parent)
        self.setupUi(self)

        self.win = win
        self.buttonStartNext.clicked.connect(self.buttonStartNextClicked)
        self.buttonStop.clicked.connect(self.buttonStopClicked)

    def buttonStartNextClicked(self):
        testName = self.comboBoxTest.currentText()

        if self.buttonStartNext.text() == "Demarrer":
            self.buttonStartNext.setText("Suivant")

            if testName == "Test écran":
                self.runningTest = TestsLCD(self.win.cmp_display)

            self.runningTest.Run()
        else:
            self.runningTest.Next()

    def buttonStopClicked(self):
        self.runningTest.Stop()
        self.buttonStartNext.setText("Demarrer")
