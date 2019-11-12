import pickle
import socket
import sys
from threading import Thread

HOST = '127.0.0.1'
PORT = 65433


def listenToClient(client, address):
    size = 1024
    while True:
        try:
            data = client.recv(size)
            data = pickle.loads(data)
            if data:
                # Set the response to echo back the recieved data
                response = data
                client.send(response.encode())
            else:
                raise socket.error('Client disconnected')
        except:
            client.close()
            return False


threads = []
while True:
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        s.bind((HOST, PORT))
        print('Waiting for clients..\n')
        s.listen()
        conn, addr = s.accept()
        t = Thread(target=listenToClient, args=(conn, addr))
        threads.append(t)
        t.start()

for t in threads:
    t.join()
