from PyQt5 import QtCore, QtGui, QtWidgets

class Display(QtWidgets.QLabel):

    def __init__(self,parentWidget):
        super(Display, self).__init__(parentWidget)
        # Store constructor arguments (re-used for processing)
        self.fgColor = QtGui.QColor(255,255,255)
        self.bgColor = QtGui.QColor(0,0,0)

        self.resizeWidget(self.geometry())

    def __openDrawingContext(self):
        self.__currentContext = QtGui.QPainter(self.pixmap())
        return self.__currentContext

    def __closeDrawingContext(self):
        self.__currentContext.end()
        self.__currentContext = None
        self.update()

    def resizeWidget (self, geom: QtCore.QRect):
        self.canvas = QtGui.QPixmap(self.geometry().width(), self.geometry().height())       
        self.setPixmap(self.canvas)

    def setGeometry(self, ax: int, ay: int, aw: int, ah: int) -> None:
        super(Display, self).setGeometry(ax, ay, aw, ah)
        self.resizeWidget(self.geometry())

    def setBgColor(self,r,g,b):
        self.bgColor = QtGui.QColor(r,g,b)

    def setTextColor(self,r,g,b):
        self.fgColor = QtGui.QColor(r,g,b)

    def clearScreen(self, r,g,b):
        painter=self.__openDrawingContext()
        width = self.geometry().width()
        height = self.geometry().height()
        painter.fillRect(0,0,width,height, QtGui.QColor(r,g,b))
        self.__closeDrawingContext()

    def putPixel(self, x,y,r,g,b):
        painter=self.__openDrawingContext()
        # pen = QtGui.QPen(QtGui.QBrush(QtGui.QColor(r,g,b)),1.0)
        # painter.setPen(pen)
        painter.setPen(QtGui.QColor(r,g,b))
        painter.drawPoint(x,y)
        self.__closeDrawingContext()

    def drawText(self, x, y, s):
        painter=self.__openDrawingContext()
        #fontdatabase = QtGui.QFontDatabase()
        #for f in fontdatabase.families():
        #    print ("Font familiy: %s" % f)
        
        #cfont = QtGui.QFont('Ubuntu Mono', -1, QtGui.QFont.Monospace)
        cfont = QtGui.QFont('Monospace', -1, QtGui.QFont.Monospace)
        cfont.setPointSizeF(10)
        
        painter.setFont(cfont)
        painter.setPen(self.fgColor)

        # painter.drawText(x*8,10+(y*15),s)
        painter.drawText(x,y,s)
        self.__closeDrawingContext()

    def drawLine(self,x1,y1,x2,y2):
        painter=self.__openDrawingContext()
        painter.setPen(self.fgColor)
        painter.drawLine(x1,y1, x2,y2)
        self.__closeDrawingContext()

    def drawFillRectangle(self,x1,y1,x2,y2):
        painter=self.__openDrawingContext()
        painter.fillRect(x1,y1, x2-x1, y2-y1, self.fgColor)
        self.__closeDrawingContext()

    def drawRectangle(self,x1,y1,x2,y2):
        painter=self.__openDrawingContext()
        painter.setPen(self.fgColor)
        # brush = QtGui.QBrush(QtGui.QColor(self.fgColor.red(),
        #                                  self.fgColor.green(),
        #                                  self.fgColor.blue(),
        #                                  128))
        # painter.setBrush(brush)
        painter.drawRect(QtCore.QRect(x1,y1,x2-x1,y2-y1))
        self.__closeDrawingContext()

    def drawCircle(self, x,y,r):
        painter=self.__openDrawingContext()
        painter.setPen(self.fgColor)
        painter.drawEllipse(QtCore.QPoint(x,y),r,r)
        self.__closeDrawingContext()

    def drawFillCircle(self, x,y,r):
        painter=self.__openDrawingContext()
        painter.setPen(self.fgColor)
        brush = QtGui.QBrush(QtGui.QColor(self.fgColor.red(),
                                          self.fgColor.green(),
                                          self.fgColor.blue(),
                                          255))
        painter.setBrush(brush)
        painter.drawEllipse(QtCore.QPoint(x,y),r,r)
 
        self.__closeDrawingContext()
    

    
