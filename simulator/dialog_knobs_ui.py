# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'ui/dialog_knobs.ui'
#
# Created by: PyQt5 UI code generator 5.14.1
#
# WARNING! All changes made in this file will be lost!


from PyQt5 import QtCore, QtGui, QtWidgets


class Ui_DialogPotentiometers(object):
    def setupUi(self, DialogPotentiometers):
        DialogPotentiometers.setObjectName("DialogPotentiometers")
        DialogPotentiometers.resize(380, 217)
        self.horizontalLayout = QtWidgets.QHBoxLayout(DialogPotentiometers)
        self.horizontalLayout.setObjectName("horizontalLayout")
        self.verticalLayout = QtWidgets.QVBoxLayout()
        self.verticalLayout.setObjectName("verticalLayout")
        self.dialLeft = QtWidgets.QDial(DialogPotentiometers)
        self.dialLeft.setMaximum(4095)
        self.dialLeft.setNotchTarget(36.0)
        self.dialLeft.setNotchesVisible(True)
        self.dialLeft.setObjectName("dialLeft")
        self.verticalLayout.addWidget(self.dialLeft)
        self.label = QtWidgets.QLabel(DialogPotentiometers)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Preferred, QtWidgets.QSizePolicy.Fixed)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.label.sizePolicy().hasHeightForWidth())
        self.label.setSizePolicy(sizePolicy)
        self.label.setAlignment(QtCore.Qt.AlignCenter)
        self.label.setObjectName("label")
        self.verticalLayout.addWidget(self.label)
        self.labelDialLeft = QtWidgets.QLabel(DialogPotentiometers)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Preferred, QtWidgets.QSizePolicy.Fixed)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.labelDialLeft.sizePolicy().hasHeightForWidth())
        self.labelDialLeft.setSizePolicy(sizePolicy)
        self.labelDialLeft.setAlignment(QtCore.Qt.AlignCenter)
        self.labelDialLeft.setObjectName("labelDialLeft")
        self.verticalLayout.addWidget(self.labelDialLeft)
        self.horizontalLayout.addLayout(self.verticalLayout)
        self.verticalLayout_2 = QtWidgets.QVBoxLayout()
        self.verticalLayout_2.setObjectName("verticalLayout_2")
        self.dialRight = QtWidgets.QDial(DialogPotentiometers)
        self.dialRight.setMaximum(4095)
        self.dialRight.setNotchTarget(36.0)
        self.dialRight.setNotchesVisible(True)
        self.dialRight.setObjectName("dialRight")
        self.verticalLayout_2.addWidget(self.dialRight)
        self.label_2 = QtWidgets.QLabel(DialogPotentiometers)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Preferred, QtWidgets.QSizePolicy.Fixed)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.label_2.sizePolicy().hasHeightForWidth())
        self.label_2.setSizePolicy(sizePolicy)
        self.label_2.setAlignment(QtCore.Qt.AlignCenter)
        self.label_2.setObjectName("label_2")
        self.verticalLayout_2.addWidget(self.label_2)
        self.labelDialRight = QtWidgets.QLabel(DialogPotentiometers)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Preferred, QtWidgets.QSizePolicy.Fixed)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.labelDialRight.sizePolicy().hasHeightForWidth())
        self.labelDialRight.setSizePolicy(sizePolicy)
        self.labelDialRight.setAlignment(QtCore.Qt.AlignCenter)
        self.labelDialRight.setObjectName("labelDialRight")
        self.verticalLayout_2.addWidget(self.labelDialRight)
        self.horizontalLayout.addLayout(self.verticalLayout_2)

        self.retranslateUi(DialogPotentiometers)
        QtCore.QMetaObject.connectSlotsByName(DialogPotentiometers)

    def retranslateUi(self, DialogPotentiometers):
        _translate = QtCore.QCoreApplication.translate
        DialogPotentiometers.setWindowTitle(_translate("DialogPotentiometers", "Potentiometres"))
        self.label.setText(_translate("DialogPotentiometers", "Potentiometre gauche"))
        self.labelDialLeft.setText(_translate("DialogPotentiometers", "Val = 0 [0x00]"))
        self.label_2.setText(_translate("DialogPotentiometers", "Potentiometre Droit"))
        self.labelDialRight.setText(_translate("DialogPotentiometers", "Val = 0 [0x00]"))
