from domain.apartment import readCommand, parseCommand, addCommandController, deleteCommandController, \
    modifyCommandController, printsCommandController, listCommandController, viewCommandController, \
    filterCommandController, undo
from domain.menuBased import initApartments
from utils.helper import printCommands
from utils.validation import typeErr


def commandBasedUI():
    '''
    Controls the commandBased menu
    :return:
    '''
    listOfApartments = initApartments()
    newBackUpList = {}
    while True:
        command = readCommand()
        try:
            command = parseCommand(command)
            if command[0] == 'help':
                printCommands()
            elif command[0] == 'adauga':
                addCommandController(listOfApartments, command[1], newBackUpList)
            elif command[0] == 'sterge':
                deleteCommandController(listOfApartments, command[1], newBackUpList)
            elif command[0] == 'modifica':
                modifyCommandController(listOfApartments, command[1])
            elif command[0] == 'afiseaza':
                printsCommandController(listOfApartments, command[1])
            elif command[0] == 'lista':
                listCommandController(listOfApartments, command[1])
            elif command[0] == 'tipareste':
                viewCommandController(listOfApartments, command[1])
            elif command[0] == 'filtrare':
                filterCommandController(listOfApartments, command[1])
            elif command[0] == 'undo':
                listOfApartments = undo(listOfApartments, newBackUpList)
            elif command[0] == 'iesire':
                exit()
            else:
                typeErr()

        except ValueError as msg:
            print(msg)