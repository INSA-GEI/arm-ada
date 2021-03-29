from PyQt5 import QtCore, QtGui, QtWidgets, uic
from components.display import Display

from tests.template_tests import TestTemplate
from components.display import Display
from base64 import b64encode

class TestsLCD (TestTemplate):
    lcdWidth = 640
    lcdHeight = 240
    display = None
    testCounter = 0
    startingTest = 7

    def __init__(self, display:Display):
        super().__init__()

        self.display = display

        self.lcdWidth = display.geometry().width()
        self.lcdHeight = display.geometry().height()

    def Run(self):
       self.testCounter = self.startingTest

       self.Next()

    def Stop(self):
        self.display.clearScreen(255,255,255)

    def EnterTest(self, s):
        self.display.clearScreen(255,255,255)
        self.display.setTextColor(0,0,0)
        self.display.drawText(self.lcdWidth/2-(8*len(s))/2,30,s)

    def TestDrawText(self):
        self.EnterTest("Test DrawText")

        self.display.setTextColor(0,0,0)
        self.display.drawText(0,15,"Up")

        self.display.setTextColor(255,0,0)
        self.display.drawText(self.lcdWidth/2-(8*3),self.lcdHeight/2,"Center")

        self.display.setTextColor(0,0,255)
        self.display.drawText(self.lcdWidth-(4*8),self.lcdHeight,"Down")

    def TestPutPixel(self):
        self.EnterTest("Test PutPixel")
        
        self.display.putPixel(10,10,255,0,0)
        self.display.putPixel(self.lcdWidth-10,10,0,255,0)
        self.display.putPixel(self.lcdWidth/2,self.lcdHeight/2,0,255,255)
        self.display.putPixel(10,self.lcdHeight-10,0,0,255)
        self.display.putPixel(self.lcdWidth-10,self.lcdHeight-10,255,0,255)

    def TestPutPixel2(self):
        self.EnterTest("Test PutPixel 2")

        for y in range(128):
            for x in range (255):
                self.display.putPixel((self.lcdWidth-255)/2+x,(self.lcdHeight-128)/2+y,2*y,x/2+y,x)
    
    def TestDrawRect(self):
        self.EnterTest("Test DrawRect")

        self.display.setTextColor(255,0,0)
        self.display.drawRectangle(10,10,self.lcdWidth-10, self.lcdHeight-10)
        self.display.setTextColor(0,255,0)
        self.display.drawRectangle(40,70,self.lcdWidth/2+30, self.lcdHeight-40)
        self.display.setTextColor(0,0,255)
        self.display.drawRectangle(self.lcdWidth/2-30,120,self.lcdWidth-40, self.lcdHeight-70)
            
    def TestDrawFillRect(self):
        self.EnterTest("Test DrawFillRect")   

        self.display.setTextColor(255,0,0)
        self.display.drawFillRectangle(10,70,self.lcdWidth-10, self.lcdHeight-10)
        self.display.setTextColor(0,255,0)
        self.display.drawFillRectangle(40,100,self.lcdWidth/2+30, self.lcdHeight-40)
        self.display.setTextColor(0,0,255)
        self.display.drawFillRectangle(self.lcdWidth/2-30,120,self.lcdWidth-40, self.lcdHeight-70)

    def TestDrawCircle(self):
        self.EnterTest("Test DrawCircle") 
        
        self.display.setTextColor(255,0,0)
        self.display.drawCircle(60,2*self.lcdHeight/3,50)
        self.display.setTextColor(0,255,0)
        self.display.drawCircle(self.lcdWidth/2+30, self.lcdHeight-40, 20)
        self.display.setTextColor(0,0,255)
        self.display.drawCircle(self.lcdWidth/2,self.lcdHeight/2, self.lcdHeight/3)

    def TestDrawFillCircle(self):
        self.EnterTest("Test DrawFillCircle")
        
        self.display.setTextColor(255,0,0)
        self.display.drawFillCircle(60,2*self.lcdHeight/3,50)
        self.display.setTextColor(0,255,0)
        self.display.drawFillCircle(self.lcdWidth/2+30, self.lcdHeight-40, 20)
        self.display.setTextColor(0,0,255)
        self.display.drawFillCircle(self.lcdWidth/2,self.lcdHeight/2, self.lcdHeight/3)

    def TestDrawImage(self):
        self.EnterTest("Test DrawImage")

        # !!!!!!
        # Attention à l'endianess !!!!
        # !!!!!!

        # create list of 64*64 element containing black pixel
        # Pixel are two bytes long (RGB 565)
        #elements=[0x0000]*(64*64)                            
        elements=[0x00, 0x00]*(64*64)   
        img=bytearray(elements)
        self.display.drawImage(30,50,64,64,img)

        # create list of 64*64 element containing red pixel
        # Pixel are two bytes long (RGB 565)
        elements=[0xf8, 0x00]*(64*64)
       
        img=bytearray(elements)

        # correct endianness by flipping byte
        for i in range (64*64):
            temp=img[2*i]
            img[2*i]=img[2*i+1]
            img[2*i+1]=temp

        self.display.drawImage(100,50,64,64,img)

        # create list of 64*64 element containing green pixel
        # Pixel are two bytes long (RGB 565)
        elements=[0x07, 0xE0]*(64*64) 
        img=bytearray(elements)
        
        # correct endianness by flipping byte
        for i in range (64*64):
            temp=img[2*i]
            img[2*i]=img[2*i+1]
            img[2*i+1]=temp

        self.display.drawImage(170,50,64,64,img)

        # create list of 64*64 element containing blue pixel
        # Pixel are two bytes long (RGB 565)
        elements=[0x0, 0x1F]*(64*64) 
        img=bytearray(elements)
        
        # correct endianness by flipping byte
        for i in range (64*64):
            temp=img[2*i]
            img[2*i]=img[2*i+1]
            img[2*i+1]=temp

        self.display.drawImage(240,50,64,64,img)

        # create list of 64*64 element containing white pixel
        # Pixel are two bytes long (RGB 565)
        elements=[0xFF, 0xFF]*(64*64) 
        img=bytearray(elements)
        self.display.drawImage(30,120,64,64,img)
        self.display.setTextColor(0,0,0)
        self.display.drawRectangle(30,120,30+64,120+64)

    def TestDrawImageFromSram(self):
        self.EnterTest("Test DrawImageFromSRAM")

        # !!!!!!
        # Attention à l'endianess !!!!
        # !!!!!!

        # create list of 64*64 element containing red pixel
        # Pixel are two bytes long (RGB 565)
        elements=[0xf8, 0x00]*(64*64)
       
        img=bytearray(elements)
        
        # correct endianness by flipping byte
        for i in range (64*64):
            temp=img[2*i]
            img[2*i]=img[2*i+1]
            img[2*i+1]=temp

        # store it in sram, at index 0
        self.display.writeByteArrayInSRAM(0,img)
        red = 0

        # create list of 64*64 element containing green pixel
        # Pixel are two bytes long (RGB 565)
        elements=[0x07, 0xE0]*(64*64)
       
        img=bytearray(elements)
        
        # correct endianness by flipping byte
        for i in range (64*64):
            temp=img[2*i]
            img[2*i]=img[2*i+1]
            img[2*i+1]=temp

        # store it in sram, at index 64x64x2 (colors are 16bits wide)
        self.display.writeByteArrayInSRAM(64*64*2,img)
        green = 64*64*2

        # create list of 64*64 element containing blue pixel
        # Pixel are two bytes long (RGB 565)
        elements=[0x00, 0x1F]*(64*64)
       
        img=bytearray(elements)
        
        # correct endianness by flipping byte
        for i in range (64*64):
            temp=img[2*i]
            img[2*i]=img[2*i+1]
            img[2*i+1]=temp

        # store it in sram, at index 64*64*4
        self.display.writeByteArrayInSRAM(64*64*4,img)
        blue = 64*64*4

        # Display red square
        self.display.drawImageFromSRAM(100,50,64,64,red)
        # Display green square
        self.display.drawImageFromSRAM(100,120,64,64,green)
        # Display blue square
        self.display.drawImageFromSRAM(170,82,64,64,blue)

    def TestDrawImageFromBase64(self):
        self.EnterTest("Test DrawImageFromSRAM")

        # !!!!!!
        # Attention à l'endianess !!!!
        # !!!!!!

        # create list of 64*64 element containing red pixel
        # Pixel are two bytes long (RGB 565)
        elements=[0xf8, 0x00]*(64*64)
       
        img=bytearray(elements)
        
        # correct endianness by flipping byte
        for i in range (64*64):
            temp=img[2*i]
            img[2*i]=img[2*i+1]
            img[2*i+1]=temp

        red_str = b64encode(img)

        # create list of 64*64 element containing green pixel
        # Pixel are two bytes long (RGB 565)
        elements=[0x07, 0xE0]*(64*64)
       
        img=bytearray(elements)
        
        # correct endianness by flipping byte
        for i in range (64*64):
            temp=img[2*i]
            img[2*i]=img[2*i+1]
            img[2*i+1]=temp

        green_str = b64encode(img)

        # create list of 64*64 element containing blue pixel
        # Pixel are two bytes long (RGB 565)
        elements=[0x00, 0x1F]*(64*64)
       
        img=bytearray(elements)
        
        # correct endianness by flipping byte
        for i in range (64*64):
            temp=img[2*i]
            img[2*i]=img[2*i+1]
            img[2*i+1]=temp

        blue_str= b64encode(img)

        # Display red square
        self.display.drawImageFromBase64(30,50,64,64,red_str)
        # Display green square
        self.display.drawImageFromBase64(120,82,64,64,green_str)
        # Display blue square
        self.display.drawImageFromBase64(200,114,64,64,blue_str)

    def Next(self):
        if self.testCounter == 0:
            # drawtext test
            self.TestDrawText()
            
        elif self.testCounter == 1:
            # drawPixel test
            self.TestPutPixel()
            
        elif self.testCounter == 2:
            # drawPixel test
            self.TestPutPixel2()

        elif self.testCounter == 3:
            # drawRect test
            self.TestDrawRect()
                        
        elif self.testCounter == 4:
            # drawFillRect test
            self.TestDrawFillRect()
            
        elif self.testCounter == 5:
            # drawCircle test
            self.TestDrawCircle()
           
        elif self.testCounter == 6:
            # drawFillCircle test
            self.TestDrawFillCircle()
            
        elif self.testCounter == 7:
            # drawImage test
            self.TestDrawImage()

        elif self.testCounter == 8:
            # drawImagefromsram test
            self.TestDrawImageFromSram()

        elif self.testCounter == 9:
            # drawImagefromsram test
            self.TestDrawImageFromBase64()

        self.testCounter+=1

        if self.testCounter>9:
            self.testCounter=0