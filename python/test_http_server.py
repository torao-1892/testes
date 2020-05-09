import socket
import time

class Server(object):
    '''
    classdocs
    '''
    sock = None

    def __init__(self, host_ip, host_port):
        '''
        Constructor
        '''
        # Create a TCP/IP socket
        self.sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        # Bind the socket to the port
        server_address = (host_ip, host_port)
        self.sock.bind(server_address)
        
        
    def waiting_data(self):
        try:
            data, address = self.sock.recvfrom(64, socket.MSG_DONTWAIT)
        except socket.error as e:
            data, address = "--", "--"
        return data, address

if __name__ == '__main__':
    server = Server("0.0.0.0", 6020)
    while (True):
        print server.waiting_data()
        time.sleep(1)
