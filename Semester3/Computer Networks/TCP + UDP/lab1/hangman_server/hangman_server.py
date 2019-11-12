import pickle
import socket
import sys

WORD = "mac"
mistakes = 0
MAX_MISTAKES = 5
curr_word = '_' * len(WORD)

HOST = '192.168.43.149'
PORT = 65433

def reveal(curr_word, word, char):
    string = ""
    i = 0
    for c in word:
        if char == c:
            string += c
        elif curr_word[i] != '_':
            string += curr_word[i]
        else:
            string += "_"
        i += 1
    return string


while True:
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        s.bind((HOST, PORT))
        print('Waiting for clients..\n')
        s.listen()
        conn, addr = s.accept()
        with conn:
            print('Connected by ', addr)
            while mistakes < MAX_MISTAKES and curr_word != WORD:
                data = conn.recv(1024)
                '''
                if not data:
                    break
                '''
                data = pickle.loads(data)
                char = data[0]
                new_curr = reveal(curr_word, WORD, char)
                if new_curr == curr_word:
                    mistakes += 1
                curr_word = new_curr
                if mistakes == MAX_MISTAKES:
                    conn.sendall(new_curr.encode())
                    conn.sendall(("Game Over too many mistakes, " + str(mistakes)).encode())
                    break
                elif mistakes < MAX_MISTAKES and curr_word != WORD:
                    conn.sendall(new_curr.encode())
                    conn.sendall(("Good guess ;). No of mistakes: " + str(mistakes)).encode())
                elif curr_word == WORD:
                    conn.sendall(new_curr.encode())
                    conn.sendall("Game Over You won ;)!".encode())
                    break
