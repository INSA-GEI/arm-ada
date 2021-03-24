from PyQt5 import QtCore, QtGui, QtWidgets
from base64 import b64decode

class Display(QtWidgets.QLabel):
    fgColor = QtGui.QColor(255,255,255)
    bgColor = QtGui.QColor(0,0,0)
    canvas = None

    Sram = bytearray((2*1024*1024)*2)

    def __init__(self,parentWidget):
        super(Display, self).__init__(parentWidget)

        self.resizeWidget(self.geometry())
        self.reset()

    def reset(self):
        self.setTextColor(0,0,0)
        self.setBgColor(255,255,255)
        self.clearScreen(255,255,255)
        self.update()

    def __openDrawingContext(self):
        self.__currentContext = QtGui.QPainter(self.pixmap())
        return self.__currentContext

    def __closeDrawingContext(self):
        self.__currentContext.end()
        self.__currentContext = None
        self.update()

    def __convertColor(self,r,g,b):
        rCorrected = r*255/7
        gCorrected = g*255/7
        bCorrected = b*255/3

        if rCorrected > 255.0:
            rCorrected = 255.0

        if gCorrected > 255.0: 
            gCorrected = 255.0

        if bCorrected > 255.0: 
            bCorrected = 255.0

        color = QtGui.QColor(int(rCorrected),int(gCorrected),int(bCorrected))
        return color

    def resizeWidget (self, geom: QtCore.QRect):
        self.canvas = QtGui.QPixmap(self.geometry().width(), self.geometry().height())       
        self.setPixmap(self.canvas)

    def setGeometry(self, ax: int, ay: int, aw: int, ah: int) -> None:
        super(Display, self).setGeometry(ax, ay, aw, ah)
        self.resizeWidget(self.geometry())

    def setBgColor(self,r,g,b):
        self.bgColor = self.__convertColor(r,g,b)

    def setTextColor(self,r,g,b):
        self.fgColor = self.__convertColor(r,g,b)

    def clearScreen(self, r,g,b):
        painter=self.__openDrawingContext()
        width = self.geometry().width()
        height = self.geometry().height()
    
        painter.fillRect(0,0,width,height, self.__convertColor(r,g,b))
        self.__closeDrawingContext()

    def putPixel(self, x,y,r,g,b):
        painter=self.__openDrawingContext()
        
        painter.setPen(self.__convertColor(r,g,b))
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
        painter.fillRect((x*8),(y*15),len(s)*8, 15, self.bgColor)
        painter.setPen(self.fgColor)
        
        painter.drawText((x*8),10+(y*15),s)
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
    
    def drawImage (self, x, y, w, h, img:bytes):
        painter=self.__openDrawingContext()
        qimage = QtGui.QImage(img, w,h, QtGui.QImage.Format_RGB16)
        
        painter.drawImage(QtCore.QPoint(x,y),qimage)
        self.__closeDrawingContext()

    def drawImageFromSRAM (self, x, y, w, h, offset):
        painter=self.__openDrawingContext()
        #print (f'drawfromsram: x={x}, y={y}, w={w}, h={h}, offset={offset}')
        #print (f'w*h*2 = {w*h*2}')
        qimage = QtGui.QImage(self.Sram[offset:(offset+(w*h*2)-1)], w, h, QtGui.QImage.Format_RGB16)
        
        painter.drawImage(QtCore.QPoint(x,y),qimage)
        self.__closeDrawingContext()

    def writeByteInSRAM (self, offset, lsb:bytes, msb:bytes):
        self.Sram[offset:offset] = [lsb]
        self.Sram[offset+1:offset+1] = [msb]

    def writeBufferInSRAM (self, offset, s):
        data= b64decode(s)
        #print (f'writeBufferInSRAM: offset={offset}, data length={len(data)}, data type = {type(data)}')
        self.Sram[offset:(offset+len(data)-1)] = data[0:(len(data)-1)]

    def readByteInSRAM (self, offset):
        return self.Sram[(offset*2):(offset*2)+1]

    def drawImageFromBase64 (self, x,y,w,h,s):
        data= b64decode(s)
        self.drawImage(x,y,w,h,data)

    

    
