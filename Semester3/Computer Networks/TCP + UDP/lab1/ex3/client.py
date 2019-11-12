import pickle
import socket
import struct

HOST = '172.20.10.2'
PORT = 65437
string = 'sda'

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.connect((HOST, PORT))
    s.sendall(bytes(string, encoding='utf-8'))
    # data = s.recv(1024)

# print('Received: ', struct.unpack('!h', data)[0])
