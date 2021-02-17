from PyQt5 import QtCore, QtGui, QtWidgets

class Display(QtWidgets.QLabel):

    def __init__(self,parentWidget):
        super(Display, self).__init__(parentWidget)
        # Store constructor arguments (re-used for processing)
        self.textColor = QtGui.QColor(0,0,0)
        self.fgColor = QtGui.QColor(255,255,255)
        self.bgColor = QtGui.QColor(0,0,0)
        self.resizeWidget(self.geometry())

    def resizeWidget (self, geom: QtCore.QRect):
        self.canvas = QtGui.QPixmap(self.geometry().width(), self.geometry().height())       
        self.setPixmap(self.canvas)

    def setGeometry(self, ax: int, ay: int, aw: int, ah: int) -> None:
        super(Display, self).setGeometry(ax, ay, aw, ah)
        self.resizeWidget(self.geometry())

    def setFgColor(self,r,g,b):
        self.fgColor = QtGui.QColor(r,g,b)

    def setBgColor(self,r,g,b):
        self.bgColor = QtGui.QColor(r,g,b)

    def setTextColor(self,r,g,b):
        self.textColor = QtGui.QColor(r,g,b)

    def drawFillRectangle(self,x,y,w,h):
        painter = QtGui.QPainter(self.pixmap())
        painter.fillRect(x,y, w, h, self.fgColor)
        painter.end()
        self.update()

    def drawRectangle(self,x,y,w,h):
        painter = QtGui.QPainter(self.pixmap())
        painter.setPen(self.fgColor)
        painter.drawRect(x,y, w, h)
        painter.end()
        self.update()

    def drawText(self, x, y, s):
        painter = QtGui.QPainter(self.pixmap()) 
        #fontdatabase = QtGui.QFontDatabase()
        #for f in fontdatabase.families():
        #    print ("Font familiy: %s" % f)
        
        #cfont = QtGui.QFont('Ubuntu Mono', -1, QtGui.QFont.Monospace)
        cfont = QtGui.QFont('Monospace', -1, QtGui.QFont.Monospace)
        cfont.setPointSizeF(10)
        
        painter.setFont(cfont)
        painter.setPen(self.textColor)

        painter.drawText(x*8,10+(y*15),s)
        painter.end()
        self.update()
