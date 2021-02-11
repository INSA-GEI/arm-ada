# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'ui/main_window.ui'
#
# Created by: PyQt5 UI code generator 5.14.1
#
# WARNING! All changes made in this file will be lost!


from PyQt5 import QtCore, QtGui, QtWidgets


class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        MainWindow.setObjectName("MainWindow")
        MainWindow.resize(640, 420)
        MainWindow.setMinimumSize(QtCore.QSize(640, 420))
        MainWindow.setMaximumSize(QtCore.QSize(640, 420))
        self.centralwidget = QtWidgets.QWidget(MainWindow)
        self.centralwidget.setObjectName("centralwidget")
        self.backgroundImg = QtWidgets.QLabel(self.centralwidget)
        self.backgroundImg.setGeometry(QtCore.QRect(0, 0, 640, 376))
        self.backgroundImg.setObjectName("backgroundImg")
        self.buttonUp = QtWidgets.QPushButton(self.centralwidget)
        self.buttonUp.setGeometry(QtCore.QRect(75, 130, 27, 27))
        self.buttonUp.setText("")
        self.buttonUp.setFlat(True)
        self.buttonUp.setObjectName("buttonUp")
        self.buttonLeft = QtWidgets.QPushButton(self.centralwidget)
        self.buttonLeft.setGeometry(QtCore.QRect(50, 156, 27, 27))
        self.buttonLeft.setText("")
        self.buttonLeft.setFlat(True)
        self.buttonLeft.setObjectName("buttonLeft")
        self.buttonRight = QtWidgets.QPushButton(self.centralwidget)
        self.buttonRight.setGeometry(QtCore.QRect(100, 156, 27, 27))
        self.buttonRight.setText("")
        self.buttonRight.setFlat(True)
        self.buttonRight.setObjectName("buttonRight")
        self.buttonDown = QtWidgets.QPushButton(self.centralwidget)
        self.buttonDown.setGeometry(QtCore.QRect(75, 182, 27, 27))
        self.buttonDown.setText("")
        self.buttonDown.setFlat(True)
        self.buttonDown.setObjectName("buttonDown")
        self.drawingArea = QtWidgets.QLabel(self.centralwidget)
        self.drawingArea.setGeometry(QtCore.QRect(186, 92, 270, 176))
        self.drawingArea.setFrameShape(QtWidgets.QFrame.NoFrame)
        self.drawingArea.setFrameShadow(QtWidgets.QFrame.Plain)
        self.drawingArea.setText("")
        self.drawingArea.setObjectName("drawingArea")
        self.buttonB = QtWidgets.QPushButton(self.centralwidget)
        self.buttonB.setGeometry(QtCore.QRect(500, 156, 45, 45))
        self.buttonB.setText("")
        self.buttonB.setFlat(True)
        self.buttonB.setObjectName("buttonB")
        self.buttonA = QtWidgets.QPushButton(self.centralwidget)
        self.buttonA.setGeometry(QtCore.QRect(558, 137, 45, 45))
        self.buttonA.setText("")
        self.buttonA.setFlat(True)
        self.buttonA.setObjectName("buttonA")
        MainWindow.setCentralWidget(self.centralwidget)
        self.menubar = QtWidgets.QMenuBar(MainWindow)
        self.menubar.setGeometry(QtCore.QRect(0, 0, 640, 22))
        self.menubar.setObjectName("menubar")
        self.menuFichier = QtWidgets.QMenu(self.menubar)
        self.menuFichier.setObjectName("menuFichier")
        self.menuAide = QtWidgets.QMenu(self.menubar)
        self.menuAide.setObjectName("menuAide")
        MainWindow.setMenuBar(self.menubar)
        self.statusbar = QtWidgets.QStatusBar(MainWindow)
        self.statusbar.setObjectName("statusbar")
        MainWindow.setStatusBar(self.statusbar)
        self.actionOuvrir = QtWidgets.QAction(MainWindow)
        self.actionOuvrir.setObjectName("actionOuvrir")
        self.actionQuitter = QtWidgets.QAction(MainWindow)
        self.actionQuitter.setObjectName("actionQuitter")
        self.actionA_propos_de = QtWidgets.QAction(MainWindow)
        self.actionA_propos_de.setObjectName("actionA_propos_de")
        self.menuFichier.addAction(self.actionOuvrir)
        self.menuFichier.addSeparator()
        self.menuFichier.addAction(self.actionQuitter)
        self.menuAide.addAction(self.actionA_propos_de)
        self.menubar.addAction(self.menuFichier.menuAction())
        self.menubar.addAction(self.menuAide.menuAction())

        self.retranslateUi(MainWindow)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)

    def retranslateUi(self, MainWindow):
        _translate = QtCore.QCoreApplication.translate
        MainWindow.setWindowTitle(_translate("MainWindow", "Simulateur Arm-Ada"))
        self.backgroundImg.setText(_translate("MainWindow", "<html><head/><body><p><img src=\":/images/background.png\"/></p></body></html>"))
        self.menuFichier.setTitle(_translate("MainWindow", "&Fichier"))
        self.menuAide.setTitle(_translate("MainWindow", "&Aide"))
        self.actionOuvrir.setText(_translate("MainWindow", "&Ouvrir..."))
        self.actionQuitter.setText(_translate("MainWindow", "&Quitter"))
        self.actionA_propos_de.setText(_translate("MainWindow", "A &propos de ..."))
import ressources_rc
