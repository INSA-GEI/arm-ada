from PyQt5 import QtCore, QtGui, QtWidgets, uic
from components.display import Display

from tests.template_tests import TestTemplate
from components.display import Display

class TestsLCD (TestTemplate):
    lcdWidth = 320
    lcdHeight = 240
    display = None
    testCounter = 0

    def __init__(self, display:Display):
        super().__init__()

        self.display = display

        self.lcdWidth = display.geometry().width()
        self.lcdHeight = display.geometry().height()

    def Run(self):
       self.testCounter = 0

       self.Next()

    def Stop(self):
        self.display.clearScreen(255,255,255)
        
    def Next(self):
        if self.testCounter == 0:
            # drawtext test
            self.display.clearScreen(255,255,255)

            self.display.setTextColor(255,0,0)
            self.display.drawText(self.lcdWidth/2-(8*7),30,"Test drawText")

            self.display.setTextColor(0,0,0)
            self.display.drawText(0,15,"Up")

            self.display.setTextColor(255,0,0)
            self.display.drawText(self.lcdWidth/2-(8*3),self.lcdHeight/2,"Center")

            self.display.setTextColor(0,0,255)
            self.display.drawText(self.lcdWidth-(4*8),self.lcdHeight,"Down")
            
        elif self.testCounter == 1:
            # drawPixel test
            self.display.clearScreen(255,255,255)
            self.display.setTextColor(255,0,0)
            self.display.drawText(self.lcdWidth/2-(8*7),30,"Test PutPixel")

            self.display.putPixel(10,10,255,0,0)
            self.display.putPixel(self.lcdWidth-10,10,0,255,0)
            self.display.putPixel(self.lcdWidth/2,self.lcdHeight/2,0,255,255)
            self.display.putPixel(10,self.lcdHeight-10,0,0,255)
            self.display.putPixel(self.lcdWidth-10,self.lcdHeight-10,255,0,255)

        elif self.testCounter == 2:
            # drawPixel test
            self.display.clearScreen(255,255,255)
            self.display.setTextColor(255,0,0)
            self.display.drawText(self.lcdWidth/2-(8*8),30,"Test PutPixel 2")

            for y in range(128):
                for x in range (255):
                    self.display.putPixel((self.lcdWidth-255)/2+x,(self.lcdHeight-128)/2+y,2*y,x/2+y,x)

        elif self.testCounter == 3:
            # drawRect test
            self.display.clearScreen(255,255,255)
            self.display.setTextColor(255,0,0)
            self.display.drawText(self.lcdWidth/2-(8*7),30,"Test DrawRect")

            self.display.setTextColor(255,0,0)
            self.display.drawRectangle(10,10,self.lcdWidth-10, self.lcdHeight-10)
            self.display.setTextColor(0,255,0)
            self.display.drawRectangle(40,70,self.lcdWidth/2+30, self.lcdHeight-40)
            self.display.setTextColor(0,0,255)
            self.display.drawRectangle(self.lcdWidth/2-30,120,self.lcdWidth-40, self.lcdHeight-70)
            
        elif self.testCounter == 4:
            # drawFillRect test
            self.display.clearScreen(255,255,255)
            self.display.setTextColor(255,0,0)
            self.display.drawText(self.lcdWidth/2-(8*9),30,"Test DrawFillRect")

            self.display.setTextColor(255,0,0)
            self.display.drawFillRectangle(10,70,self.lcdWidth-10, self.lcdHeight-10)
            self.display.setTextColor(0,255,0)
            self.display.drawFillRectangle(40,100,self.lcdWidth/2+30, self.lcdHeight-40)
            self.display.setTextColor(0,0,255)
            self.display.drawFillRectangle(self.lcdWidth/2-30,120,self.lcdWidth-40, self.lcdHeight-70)

        elif self.testCounter == 5:
            # drawCircle test
            self.display.clearScreen(255,255,255)
            self.display.setTextColor(255,0,0)
            self.display.drawText(self.lcdWidth/2-(8*9),30,"Test DrawFillRect")

            self.display.setTextColor(255,0,0)
            self.display.drawCircle(60,2*self.lcdHeight/3,50)
            self.display.setTextColor(0,255,0)
            self.display.drawCircle(self.lcdWidth/2+30, self.lcdHeight-40, 20)
            self.display.setTextColor(0,0,255)
            self.display.drawCircle(self.lcdWidth/2,self.lcdHeight/2, self.lcdHeight/3)

        elif self.testCounter == 6:
            # drawFillCircle test
            self.display.clearScreen(255,255,255)
            self.display.setTextColor(255,0,0)
            self.display.drawText(self.lcdWidth/2-(8*9),30,"Test DrawFillRect")

            self.display.setTextColor(255,0,0)
            self.display.drawFillCircle(60,2*self.lcdHeight/3,50)
            self.display.setTextColor(0,255,0)
            self.display.drawFillCircle(self.lcdWidth/2+30, self.lcdHeight-40, 20)
            self.display.setTextColor(0,0,255)
            self.display.drawFillCircle(self.lcdWidth/2,self.lcdHeight/2, self.lcdHeight/3)

        self.testCounter+=1

        if self.testCounter>6:
            self.testCounter=0