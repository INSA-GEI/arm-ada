from PyQt5.QtCore import QObject, QThread, pyqtSignal

import time
import socket
import sys
import os

class SocketWorker(QObject):
    dataReceived = pyqtSignal(str)
    stateChanged = pyqtSignal(str)

    server_address = './armada_socket'
    client_address = ""
    connected = False

    def __init__(self, socketName):
        super(SocketWorker, self).__init__()
        # Store constructor arguments (re-used for processing)
        self.server_address = socketName
        # print ("SocketWorker object created with socket file : " + str(self.server_address))

    def openSocket(self):
        # Make sure the socket does not already exist
        try:
            os.unlink(self.server_address)
        except OSError:
            if os.path.exists(self.server_address):
                raise
        
        # Create a UDS socket
        self.sock = socket.socket(socket.AF_UNIX, socket.SOCK_STREAM)
        
        # Bind the socket to the port
        # print ('starting up on %s' % self.server_address)
        self.sock.bind(self.server_address)

    def closeSocket(self):
        # print ("Closing socket")
        self.sock.close()
        self.connected = False
        self.stateChanged.emit("disconnected")

    def run(self):
        """network main loop."""
        # print ("SocketThread running")
        # Listen for incoming connections
        self.sock.listen(1)
        # print ('Listening on sock')

        while True:
        # Wait for a connection
            print ('waiting for a connection (on socket %s)' % self.server_address)
            self.connection, self.client_address = self.sock.accept()
            try:
                # print ('connection from' + str(self.client_address))
                self.connected = True
                self.stateChanged.emit("connected")

                # Receive the data in small chunks and retransmit it
                while self.connected:
                    data = self.connection.recv(640*480*2)
                    #print ('length = %i' % len(data))
                    
                    if data:
                        #print ('received "%s"' % data)
                        self.dataReceived.emit(data.decode("utf_8").rstrip())
                    else:
                        self.connected = False
                        self.stateChanged.emit("disconnected")
                        # print("socket closed by client")
            
            finally:
                # Clean up the connection
                self.connection.close()
                self.connected = False
                self.stateChanged.emit("disconnected")

        self.stateChanged.emit("finished")

    def sendData(self,s):
        if self.connected == True:
            self.connection.send(s.encode("utf_8"))