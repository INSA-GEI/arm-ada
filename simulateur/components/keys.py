from PyQt5 import QtCore

class Keys():

    Key_A = 1<<0
    Key_B = 1<<1
    Key_C = 1<<2
    Key_X = 1<<3
    Key_Y = 1<<4
    Key_Up = 1<<5
    Key_Down = 1<<6
    Key_Left = 1<<7
    Key_Right = 1<<8
    Key_Reset = 1<<9

    keyList = [ Key_A, Key_B, Key_C, Key_X, Key_Y,
                Key_Up, Key_Down, Key_Left, Key_Right, Key_Reset ]

    keyTextList = ['A', 'B', 'C', 'X', 'Y', 'UP', 'DOWN', 'LEFT', 'RIGHT', 'RESET']

    keyState = 0

    def __init__(self):
        self.keyState=0

    def getState(self):
        return self.keyState

    def isKeyPressed(self, key):
        state = False

        if (key in self.keyList): 
            if (self.keyState & key) == key:
                state = True    
        else:
            raise

        return state

    def isKeyReleased(self, key):
        state = False

        if (key in self.keyList): 
            if (self.keyState & key) == 0:
                state = True    
        else:
            raise

        return state

    def sendKeyPressed(self, key):
        if (key in self.keyList): 
            self.keyState |= key
        else:
            raise

    def sendKeyReleased(self, key):
        if (key in self.keyList): 
            self.keyState &= ~key
        else:
            raise

    
