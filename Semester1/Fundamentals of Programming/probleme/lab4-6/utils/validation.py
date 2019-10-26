'''
Validation module
'''

from utils.helper import convertFromRoToEng


def readInt(text):
    while True:
        try:
            cmd = int(input(text))
            if cmd < 0: raise ValueError("Valoare invalida, incercati din nou... ")
            return cmd
        except ValueError:
            print("Valoare invalida, incercati din nou... ")


def readStr(text):
    while True:
        try:
            string = str(input(text))
            if string.isalpha() and convertFromRoToEng(string) != 'invalid':
                return convertFromRoToEng(string)
            raise ValueError
        except ValueError:
            print("Valoare invalida, incercati din nou... ")


def typeErr():
    raise ValueError("Comanda introdusa gresit, tastati help pentru a vedea comenzile posibile!!!")