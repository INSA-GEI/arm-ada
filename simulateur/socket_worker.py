from PyQt5.QtCore import QObject, QThread, pyqtSignal

import time
import socket
import sys
import os

class SocketWorker(QObject):
    dataReceived = pyqtSignal(str)
    error = pyqtSignal(str)
    server_address = './armada_socket'
    client_address = ""

    def __init__(self, socketName):
        super(SocketWorker, self).__init__()
        # Store constructor arguments (re-used for processing)
        self.server_address = socketName
        #self.signals = WorkerSignals()
        print ("SocketWorker object created with socket file : " + str(self.server_address))

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
        print ('starting up on %s' % self.server_address)
        self.sock.bind(self.server_address)

    def closeSocket(self):
        print ("Closing socket")
        self.sock.close()

    def run(self):
        """network main loop."""
        # Listen for incoming connections
        self.sock.listen(1)

        while True:
        # Wait for a connection
            print ('waiting for a connection')
            self.connection, self.client_address = self.sock.accept()
            try:
                print ('connection from' + str(self.client_address))

                # Receive the data in small chunks and retransmit it
                while True:
                    data = self.connection.recv(640*480*2)
                    print ('received "%s"' % data)
                    if data:
                        #print ('sending data back to the client')
                        #self.connection.send("cmd received: ".encode("utf_8"))
                        #self.connection.sendall(data)
                        self.dataReceived.emit(data.decode("utf_8").rstrip())
                        
                    else:
                        print ('no more data from' % self.client_address)
                        break
            
            finally:
                # Clean up the connection
                self.connection.close()

        self.error.emit("finished")

    def sendData(self,s):
        self.connection.send(s.encode("utf_8"))