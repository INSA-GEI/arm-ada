# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'ui/dialog_tests.ui'
#
# Created by: PyQt5 UI code generator 5.14.1
#
# WARNING! All changes made in this file will be lost!


from PyQt5 import QtCore, QtGui, QtWidgets


class Ui_DialogTest(object):
    def setupUi(self, DialogTest):
        DialogTest.setObjectName("DialogTest")
        DialogTest.resize(318, 168)
        self.gridLayout = QtWidgets.QGridLayout(DialogTest)
        self.gridLayout.setObjectName("gridLayout")
        self.label = QtWidgets.QLabel(DialogTest)
        self.label.setObjectName("label")
        self.gridLayout.addWidget(self.label, 0, 0, 1, 1)
        self.comboBoxTest = QtWidgets.QComboBox(DialogTest)
        self.comboBoxTest.setObjectName("comboBoxTest")
        self.comboBoxTest.addItem("")
        self.gridLayout.addWidget(self.comboBoxTest, 0, 1, 1, 2)
        self.buttonStartNext = QtWidgets.QPushButton(DialogTest)
        self.buttonStartNext.setObjectName("buttonStartNext")
        self.gridLayout.addWidget(self.buttonStartNext, 1, 1, 1, 1)
        self.buttonStop = QtWidgets.QPushButton(DialogTest)
        self.buttonStop.setObjectName("buttonStop")
        self.gridLayout.addWidget(self.buttonStop, 1, 2, 1, 1)

        self.retranslateUi(DialogTest)
        QtCore.QMetaObject.connectSlotsByName(DialogTest)

    def retranslateUi(self, DialogTest):
        _translate = QtCore.QCoreApplication.translate
        DialogTest.setWindowTitle(_translate("DialogTest", "Tests"))
        self.label.setText(_translate("DialogTest", "Selection du test:"))
        self.comboBoxTest.setItemText(0, _translate("DialogTest", "Test écran"))
        self.buttonStartNext.setText(_translate("DialogTest", "Demarrer"))
        self.buttonStop.setText(_translate("DialogTest", "Stop"))
