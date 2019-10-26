from domain.commandBased import commandBasedUI
from domain.menuBased import menuBasedUI
from utils.validation import readInt
from utils.tests import *

# USER INTERFACE PART
def startUI():
    '''
    Function that starts the user interface menu
    Takes no argument
    Doesn't return anything
    '''
    while True:
        try:
            specfiyMenu = readInt("Apasati 1 pentru Menu Based UI sau 2 pentru Command Based UI: ")
            if specfiyMenu == 1:
                menuBasedUI()
            elif specfiyMenu == 2:
                commandBasedUI()
            else:
                raise TypeError("NUMARUL INTRODUS POATE FI DOAR 1 SAU 2")
        except TypeError as msg:
            print(msg)

startUI()

