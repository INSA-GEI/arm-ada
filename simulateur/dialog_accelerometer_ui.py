# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'ui/dialog_accelerometer.ui'
#
# Created by: PyQt5 UI code generator 5.14.1
#
# WARNING! All changes made in this file will be lost!


from PyQt5 import QtCore, QtGui, QtWidgets


class Ui_DialogAccelerometer(object):
    def setupUi(self, DialogAccelerometer):
        DialogAccelerometer.setObjectName("DialogAccelerometer")
        DialogAccelerometer.resize(381, 234)
        self.horizontalLayout = QtWidgets.QHBoxLayout(DialogAccelerometer)
        self.horizontalLayout.setObjectName("horizontalLayout")
        self.verticalLayout = QtWidgets.QVBoxLayout()
        self.verticalLayout.setObjectName("verticalLayout")
        self.labelX = QtWidgets.QLabel(DialogAccelerometer)
        self.labelX.setAlignment(QtCore.Qt.AlignCenter)
        self.labelX.setObjectName("labelX")
        self.verticalLayout.addWidget(self.labelX)
        self.sliderX = QtWidgets.QSlider(DialogAccelerometer)
        self.sliderX.setMinimum(-32768)
        self.sliderX.setMaximum(32767)
        self.sliderX.setSingleStep(100)
        self.sliderX.setPageStep(1000)
        self.sliderX.setOrientation(QtCore.Qt.Horizontal)
        self.sliderX.setTickPosition(QtWidgets.QSlider.TicksBelow)
        self.sliderX.setTickInterval(2500)
        self.sliderX.setObjectName("sliderX")
        self.verticalLayout.addWidget(self.sliderX)
        self.line = QtWidgets.QFrame(DialogAccelerometer)
        self.line.setFrameShape(QtWidgets.QFrame.HLine)
        self.line.setFrameShadow(QtWidgets.QFrame.Sunken)
        self.line.setObjectName("line")
        self.verticalLayout.addWidget(self.line)
        self.labelZ = QtWidgets.QLabel(DialogAccelerometer)
        self.labelZ.setAlignment(QtCore.Qt.AlignCenter)
        self.labelZ.setObjectName("labelZ")
        self.verticalLayout.addWidget(self.labelZ)
        self.sliderZ = QtWidgets.QSlider(DialogAccelerometer)
        self.sliderZ.setMinimum(-32768)
        self.sliderZ.setMaximum(32767)
        self.sliderZ.setSingleStep(100)
        self.sliderZ.setPageStep(1000)
        self.sliderZ.setOrientation(QtCore.Qt.Horizontal)
        self.sliderZ.setTickPosition(QtWidgets.QSlider.TicksBelow)
        self.sliderZ.setTickInterval(2500)
        self.sliderZ.setObjectName("sliderZ")
        self.verticalLayout.addWidget(self.sliderZ)
        self.horizontalLayout.addLayout(self.verticalLayout)
        self.line_2 = QtWidgets.QFrame(DialogAccelerometer)
        self.line_2.setFrameShape(QtWidgets.QFrame.VLine)
        self.line_2.setFrameShadow(QtWidgets.QFrame.Sunken)
        self.line_2.setObjectName("line_2")
        self.horizontalLayout.addWidget(self.line_2)
        self.verticalLayout_2 = QtWidgets.QVBoxLayout()
        self.verticalLayout_2.setObjectName("verticalLayout_2")
        self.labelY = QtWidgets.QLabel(DialogAccelerometer)
        self.labelY.setAlignment(QtCore.Qt.AlignCenter)
        self.labelY.setObjectName("labelY")
        self.verticalLayout_2.addWidget(self.labelY)
        self.horizontalLayout_2 = QtWidgets.QHBoxLayout()
        self.horizontalLayout_2.setObjectName("horizontalLayout_2")
        spacerItem = QtWidgets.QSpacerItem(40, 20, QtWidgets.QSizePolicy.Expanding, QtWidgets.QSizePolicy.Minimum)
        self.horizontalLayout_2.addItem(spacerItem)
        self.sliderY = QtWidgets.QSlider(DialogAccelerometer)
        self.sliderY.setMinimum(-32768)
        self.sliderY.setMaximum(32767)
        self.sliderY.setSingleStep(100)
        self.sliderY.setPageStep(1000)
        self.sliderY.setOrientation(QtCore.Qt.Vertical)
        self.sliderY.setTickPosition(QtWidgets.QSlider.TicksBelow)
        self.sliderY.setTickInterval(2500)
        self.sliderY.setObjectName("sliderY")
        self.horizontalLayout_2.addWidget(self.sliderY)
        spacerItem1 = QtWidgets.QSpacerItem(40, 20, QtWidgets.QSizePolicy.Expanding, QtWidgets.QSizePolicy.Minimum)
        self.horizontalLayout_2.addItem(spacerItem1)
        self.verticalLayout_2.addLayout(self.horizontalLayout_2)
        self.horizontalLayout.addLayout(self.verticalLayout_2)

        self.retranslateUi(DialogAccelerometer)
        QtCore.QMetaObject.connectSlotsByName(DialogAccelerometer)

    def retranslateUi(self, DialogAccelerometer):
        _translate = QtCore.QCoreApplication.translate
        DialogAccelerometer.setWindowTitle(_translate("DialogAccelerometer", "Accelerometre"))
        self.labelX.setText(_translate("DialogAccelerometer", "Axe X = 0 g [0x00]"))
        self.labelZ.setText(_translate("DialogAccelerometer", "Axe Z = 0 g [0x00]"))
        self.labelY.setText(_translate("DialogAccelerometer", "Axe Y = 0 g [0x00]"))
