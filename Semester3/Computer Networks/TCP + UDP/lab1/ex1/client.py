import pickle
import socket

HOST = '127.0.0.1'
PORT = 65433
lst = [1, 2, 3, 4]

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.connect((HOST, PORT))
    data = pickle.dumps(lst)
    s.sendall(data)
    data = s.recv(1024)

print('Received: ', data.decode())