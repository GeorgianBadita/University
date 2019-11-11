import pickle
import socket
import sys

HOST = '127.0.0.1'
PORT = 65433


def merge(a, b):
    c = ""
    i = 0
    j = 0
    while i < len(a) and j < len(b):
        if a[i] < b[j]:
            c += a[i]
            i += 1
        else:
            c += b[j]
            j += 1

    if i < len(a):
        c += a[i:]
    if j < len(b):
        c += b[j:]
    return c


while True:
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        s.bind((HOST, PORT))
        print('Waiting for clients..\n')
        s.listen()
        conn, addr = s.accept()
        with conn:
            print('Connected by ', addr)
            data1 = conn.recv(1024)
            data1 = pickle.loads(data1)
            data2 = conn.recv(1024)
            data2 = pickle.loads(data2)
            res = merge(data1, data2)
            conn.sendall(res.encode())
