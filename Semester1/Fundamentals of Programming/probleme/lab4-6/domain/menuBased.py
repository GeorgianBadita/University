import domain.apartment
from utils.helper import printMenu, printAddSubmenu, printDeleteSubmenu, printSearchSubmenu, printViewSubmenu, \
    printFilterSubmenu, createNewList
from utils.validation import readInt


def menuBasedUI():
    '''
    control the menuBased UI
    :return:
    '''
    listOfApartments = initApartments()
    backUpList = {}
    while True:
        printMenu()
        command = readInt("Selectati comanda dorita: ")
        if command == 1:
            printAddSubmenu()
            domain.apartment.addCostControl(listOfApartments, backUpList)
        elif command == 2:
            printDeleteSubmenu()
            domain.apartment.deleteCostControl(listOfApartments, backUpList)
        elif command == 3:
            printSearchSubmenu()
            domain.apartment.searchingCostControl(listOfApartments)
        elif command == 4:
            printViewSubmenu()
            domain.apartment.viewCostControl(listOfApartments)
        elif command == 5:
            printFilterSubmenu()
            domain.apartment.filterCostControl(listOfApartments)
        elif command == 6:
            listOfApartments = domain.apartment.undo(listOfApartments, backUpList)
        elif command == 7:
            exit()


def initApartments():
    numofApartments = readInt("Dati numarul de apartamente: ")
    listOfApartments = createNewList(numofApartments)
    return listOfApartments