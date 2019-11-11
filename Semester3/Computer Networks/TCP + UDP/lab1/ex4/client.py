import pickle
import socket

HOST = '127.0.0.1'
PORT = 65433
string1 = "abc"
string2 = "def"

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.connect((HOST, PORT))
    data1 = pickle.dumps(string1)
    s.sendall(data1)
    data2 = pickle.dumps(string2)
    s.sendall(data2)
    data = s.recv(1024)

print('Received: ', data.decode())
