import pickle
import socket

HOST = '127.0.0.1'
PORT = 65433
string = "Teiu"

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.connect((HOST, PORT))
    data = pickle.dumps(string)
    s.sendall(data)
    data = s.recv(1024)

print('Received: ', data.decode())