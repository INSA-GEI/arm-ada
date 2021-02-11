from PyQt5 import QtCore, QtGui, QtWidgets

#from ... import cmd_processor

class Display():

    #def __init__(self, cmdProcessor: cmd_processor.CmdProcessor, drawingArea: QtWidgets.QLabel):
    def __init__(self, drawingArea: QtWidgets.QLabel):
        super(Display, self).__init__()
        # Store constructor arguments (re-used for processing)
        #self.cmdProcessor = cmdProcessor
        self.drawingArea = drawingArea
        self.pixmap = self.drawingArea.pixmap()
        self.drawingGeom = self.drawingArea.geometry()
        
        #self.cmdProcessor.drawText.connect(self.drawtext)

    def drawtext(self, x, y, s):
        print ("drawText received: " +str((x, y, s)))
        
        painter = QtGui.QPainter(self.pixmap) 
        painter.drawText(10,10,s)
        painter.end()
        self.drawingArea.update()
