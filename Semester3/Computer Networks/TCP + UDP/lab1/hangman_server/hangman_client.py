import pickle
import socket

HOST = '192.168.43.149'
PORT = 65433

checked = set()
with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.connect((HOST, PORT))
    while True:
        char = input("Give a character: ")[0]
        if char in checked:
            continue
        checked.add(char)
        data = pickle.dumps(char)
        s.sendall(data)
        word = s.recv(1024)
        info = s.recv(1024)
        print(word.decode())
        print(info.decode())
        if 'Game Over' in info.decode():
            break
