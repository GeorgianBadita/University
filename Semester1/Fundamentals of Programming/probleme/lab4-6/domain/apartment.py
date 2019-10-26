from copy import deepcopy

from utils.helper import clearScreen, printCostLargerThanSum, printCostTypeFromAll, \
    convertFromEnToRo, convertFromRoToEng, printCommands
from utils.validation import readInt, readStr

'''
The apartments List will be defined as a bi-dimensional list with n rows and 6 columns
Every column from an 'apartment' which is a list of numbers will have the following meaning:
COLUMN 1: WATER COSTS
COLUMN 2: GAS COSTS
COLUMN 3: HEATING COSTS
COLUMN 4: SEWERAGE COSTS
COLUMN 5: OTHERS
COLUMN 6: THE DATE IN WHICH THE COST WAS ADDED/DELETED/MODIFIED
'''

typeOfCosts = {
    "water": 0,
    "gas": 1,
    "heating": 2,
    "sewerage": 3,
    "others": 4
}

date = {
    "day": 5
}


def printCost(listOfApartments, index):
    '''
    Function that prints the cost from an apartment
    '''
    print("Apartamentul ", index + 1)
    for key in typeOfCosts:
        print(convertFromEnToRo(key), " ", listOfApartments[index][key])
    print("zi ", listOfApartments[index]['day'])
    print("\n" * 3)


def getNumOfApartments(listOfApartments):
    '''
    Function to calculate the number of apartments
    Takes one argument, the listOfApartments
    Returns the number of apartments
    '''
    return len(listOfApartments)


# CREATING AND ADDING COSTS PART

def addToCost(listOfApartments, index, sum, type, day):
    '''
    Function to add a new cost to an existing one
    Takes 4 arguments: the list of apartments, the index of the apartment, the sum of the cost and it's type
    Doesn't return anything
    '''
    listOfApartments[index][type] += sum
    listOfApartments[index]['day'] = day


def modifyApartmentCost(listOfApartments, index, sum, type, day):
    '''
    Function to modify an apartment cost from the list
    Takes 4 arguments: the list of apartments, the index of apartment, the sum and its cost
    Doesn't return anything
    '''
    listOfApartments[index][type] = sum
    listOfApartments[index]['day'] = day


# DELETE PART

def deleteApartmentCost(listOfApartments, index, day):
    '''
    Function to delete all the costs of an apartment
    Takes two arguments the list of apartments and the index
    Doesn't return anything
    '''
    emptyDict = {'water': 0, 'gas': 0, 'heating': 0, 'sewerage': 0, 'others': 0, 'day': day}
    listOfApartments[index] = emptyDict


def deleteFromAtoB(listOfApartments, A, B):
    '''
    Function to delete apartments costs between index A and index B
    Takes 3 parameters, the list of apartments, the starting index and the ending index
    Doesn't return anything
    '''

    emptyDict = {'water': 0, 'gas': 0, 'heating': 0, 'sewerage': 0, 'others': 0, 'day': 0}
    for i in range(A, B):
        listOfApartments[i] = emptyDict


def deleteCostFromAll(listofApartments, type, day):
    '''
    Delet the cost of some type from all apartments
    Takse the list of apartments and a type of cost as arguemts
    Doesen't return anything
    '''
    for i in range(0, len(listofApartments)):
        listofApartments[i][type] = 0
        listofApartments[i]['day'] = day


# SEARCHING PART

def getTotalCost(listofApartments, index):
    '''
    Function that calculates the total cost of an apartment
    Takes the list of apartments and the the index of the apartment as input
    Return the total cost of an apartment
    '''
    totalCost = 0
    for i in typeOfCosts:
        totalCost += listofApartments[index][i]
    return totalCost


def costsLargerThanSum(listOfApartments, sum):
    '''
    Function that returns all apartments with totalCost > sum
    Takes 2 arguments the list of apartments and the sum
    Returns a list of apartments with totalCost > sum
    '''
    newApartments = []
    for i in range(len(listOfApartments)):
        if getTotalCost(listOfApartments, i) > sum:
            newApartments.append(i)
    return newApartments


def costTypeFromAll(listOfApartments, type):
    '''
    Function that returns a type of cost from all apartments
    Takes two arguments, the list of apartments and the type of cost
    Returns a list, representing the value of a cost from every apartment
    '''
    newApartments = []
    for i in range(len(listOfApartments)):
        newApartments.append(listOfApartments[i][type])
    return newApartments


def costBeforDay(listOfApartments, day, sum):
    '''
    Function that prints all the costs before a day and larger than a sum
    Takes the list of costs, the day and the sum as arguments
    Returns the costs made before the day and larger than sum
    '''
    for cost in range(0, len(listOfApartments)):
        if listOfApartments[cost]['day'] and getTotalCost(listOfApartments, cost) > sum:
            printCost(listOfApartments, cost)


# VIEW PART
def totalSumForCost(listOfApartments, type):
    '''
    Function that calculates the total sum of some cost
    Takes the list of costs and the type of cost as arguments
    Returns a list with 2 elements, the sum and the type of cost
    '''
    totalCost = 0
    for i in range(len(listOfApartments)):
        totalCost += listOfApartments[i][type]

    return [type, totalCost]


def sortAfterType(listOfApartments, type):
    '''
    Function to print the list of apartments sorted after some type of cost
    :param listOfApartments: list of costs
    :param type: type of cost
    :return: listOfApartments sorted by index
    '''
    sortedList = sorted(range(len(listOfApartments)), key=lambda k: listOfApartments[k][type])
    return sortedList


def printSortedAfterType(listOfApartments, type):
    listToPrint = sortAfterType(listOfApartments, type)
    for apartment in listToPrint:
        printCost(listOfApartments, apartment)


# COMMANDS CONTROL

def makeBackUp(listOfAapartments, backUpList):
    backUpList[str(len(backUpList))] = (deepcopy(listOfAapartments))


def addCostControl(listOfApartments, backUpList):
    '''
    Function that controls the subcommand1 (adding a new cost to an apartment)
    Takes no arguments
    Doesn't return anything
    '''
    makeBackUp(listOfApartments, backUpList)
    print("\n")
    subCommand = readInt("Selectati comanda dorita: ")
    print("\n" * 2)
    if subCommand == 1:
        try:
            index = readInt("Dati numarul apartamentului: ")
            sumCost = readInt("Dati suma cheltuielii: ")
            type = readStr("Specificati tipul cheltuielii: ")
            day = readInt("Dati ziua in care se adauga cheltuiala: ")
            addToCost(listOfApartments, index - 1, sumCost, type, day)
            clearScreen()
        except IndexError:
            print("\nIndexul este prea mare sau negativ !!\n")
    elif subCommand == 2:
        try:
            index = readInt("Dati numarul apartamentului ")
            sumCost = readInt("Dati suma cheltuielii: ")
            type = readStr("Specificati tipul cheltuielii: ")
            day = readInt("Dati ziua in care se modifica cheltuiala: ")
            modifyApartmentCost(listOfApartments, index - 1, sumCost, type, day)
            clearScreen()
        except IndexError:
            print("\nIndexul este prea mare sau negativ!!\n")


def deleteCostControl(listOfApartments, backUpList):
    '''
    Function that controls the subcommand2 (deleting cost of an apartment)
    Takes no arguments
    Doesn't return anything
    '''
    makeBackUp(listOfApartments, backUpList)
    print("\n" * 2)
    subCommand = readInt("Selectati comanda dorita :")
    print("\n" * 2)
    if subCommand == 1:
        try:
            index = readInt("Dati numarul apartamentului: ")
            day = readInt("Dati ziua in care se face stergerea: ")
            deleteApartmentCost(listOfApartments, index - 1, day)
            clearScreen()
        except IndexError:
            print("Indexul este prea mare sau prea mic!!")
    elif subCommand == 2:
        try:
            startIndex = readInt("Dati primul apartamentul de la care se incepe stergerea: ")
            endIndex = readInt("Dati ultimul apartament la care se face stergere")
            if startIndex > endIndex:
                startIndex, endIndex = endIndex, startIndex
            deleteFromAtoB(listOfApartments, startIndex - 1, endIndex)
            clearScreen()
        except IndexError:
            print("Indecsii sunt prea mari sau prea mici!!")
    elif subCommand == 3:
        type = readStr("Dati tipul de cheltuiala care se vrea a fi stearsa: ")
        date = readInt("Dati ziua in care se face stergerea: ")
        deleteCostFromAll(listOfApartments, type, date)
        clearScreen()


def searchingCostControl(listOfApartments):
    '''
    Function that controls the searching part of the aplication
    Takes the list of costs as parameter
    Doesn't return anything
    '''
    print("\n")
    subCommand = readInt("Selectati comanda dorita :")
    print("\n" * 2)
    if subCommand == 1:
        sum = readInt("Dati suma de comparare: ")
        print("\n" * 2)
        printCostLargerThanSum(costsLargerThanSum(listOfApartments, sum), sum)
        print("\n" * 2)
    elif subCommand == 2:
        type = readStr("Dati tipul de cheltuiala ce se vrea afisat de la toate apartamentele: ")
        printCostTypeFromAll(costTypeFromAll(listOfApartments, type), type)
    elif subCommand == 3:
        day = readInt("Dati ziua: ")
        sum = readInt("Dati suma de comparare: ")
        costBeforDay(listOfApartments, day, sum)


def viewCostControl(listOfApartments):
    '''
    Function that controls the view part of the aplication
    :param listOfApartments:
    :return: None
    '''

    print("\n")
    subCommand = readInt("Selectati comanda dorita: ")
    print("\n" * 2)
    if subCommand == 1:
        type = readStr("Dati tipul de cheltuiala: ")
        totalSum = totalSumForCost(listOfApartments, type)
        print("Suma totala pentru ", convertFromEnToRo(totalSum[0]), " este ", totalSum[1])
        print("\n" * 2)
        print("\n" * 2)
    elif subCommand == 2:
        type = readStr("Dati tipul de cheltuiala dupa care se vrea a fi sortata lista: ")
        printSortedAfterType(listOfApartments, type)
    elif subCommand == 3:
        try:
            index = readInt("Dati numarul apartamentului pentru tiparirea costului: ")
            print("Costul total pentru apartamentul ", index, " este ", getTotalCost(listOfApartments, index - 1))
        except IndexError:
            print("Indxul este prea mare sau prea mic!!")


def filterAp(listOfApartments, type):
    '''
    Function that filters the apartments with some type
    :param listOfApartments:
    :param type:
    :return:
    '''
    for index in range(len(listOfApartments)):
        print("Apartamentul ", index + 1)
        for key in typeOfCosts:
            if key != type:
                print(convertFromEnToRo(key), " ", listOfApartments[index][key])
        print("zi ", listOfApartments[index]['day'])
        print("\n" * 3)


def filterApSum(listOfApartments, sum):
    '''
    Function that filters the costs < sum
    :param listOfApartments:
    :param sum:
    :return:
    '''
    for index in range(len(listOfApartments)):
        print("Apartamentul ", index + 1)
        for key in typeOfCosts:
            if listOfApartments[index][key] >= sum:
                print(convertFromEnToRo(key), " ", listOfApartments[index][key])
        print("zi ", listOfApartments[index]['day'])
        print("\n" * 3)


def filterCostControl(listOfApartments):
    '''
    Function that controls the filter feature of the application
    :param listOfApartments:
    :return: none
    '''
    print('\n')
    subCommand = readInt("Selectati comanda dorita: ")
    print("\n" * 2)

    if subCommand == 1:
        type = readStr("Dati tipul dorit: ")
        filterAp(listOfApartments, type)
    elif subCommand == 2:
        sum = readInt("Dati suma dorita: ")
        filterApSum(listOfApartments, sum)


def undo(listOfApartments, backUpList):
    '''
    Function for the undo functionality
    :param lisfOfApartments:
    :return:
    '''
    try:
        return backUpList.pop(str(len(backUpList) - 1))
    except KeyError:
        print("Nu se mai poate face undo!")


# COMMAND BASED CONTROLS

# adauga nrApartament sumaCost tipCost ziua
def addCommandController(listOfApartments, command, newBackUpList):
    '''
    Function that controls adding cost part
    :param listOfApartments:
    :param command:
    :return:
    '''
    makeBackUp(listOfApartments, newBackUpList)
    try:
        if len(command) != 4: raise ValueError("Indexul trebuie sa fie un numar intreg pozitiv!!!")
        index = int(command[0])
        sumCost = int(command[1])
        costType = convertFromRoToEng(command[2])
        if costType not in typeOfCosts:
            raise KeyError("Tipul costului trebuie sa fie valid!!")
        day = int(command[3])
        addToCost(listOfApartments, index - 1, sumCost, costType, day)
    except ValueError as msg:
        print(msg)
    except IndexError:
        print("Indexul trebuie sa fie un numar intreg pozitiv!!")
    except KeyError as ex:
        print(ex)


def deleteCommandController(listOfApartments, command, newBackUpList):
    '''
    Function that controls the delete part of the aplication
    :param listOfApartments:
    :param command:
    :return:
    '''
    makeBackUp(listOfApartments, newBackUpList)
    if len(command) > 1 and command[1] == ',':
        try:
            if len(command) != 3:
                raise ValueError("Comanda trebuie sa fie valida!")
            startIndex = int(command[0])
            endIndex = int(command[2])
            if startIndex > endIndex:
                startIndex, endIndex = endIndex, startIndex
            deleteFromAtoB(listOfApartments, startIndex - 1, endIndex)
        except IndexError:
            print("startIndex si stopIndex trebuie sa fie numere intregi pozitive!!")
        except ValueError:
            print("startIndex si stopIndex trebuie sa fie numere intregi pozitive!!")

    elif len(command) > 1 and command[0] == 'de' and command[1] == 'la':
        try:
            if len(command) != 4:
                raise ValueError("Comanda trebuie sa fie Valida!")
            index = int(command[2])
            day = int(command[3])
            deleteApartmentCost(listOfApartments, index - 1, day)
        except ValueError:
            print("Indexul trebuie sa fie un numar intreg pozitiv")
        except IndexError:
            print("Indexul este prea mare sau negativ!")
    elif len(command) != 0 and convertFromRoToEng(command[0]) in typeOfCosts:
        try:
            if not convertFromRoToEng(command[0]) in typeOfCosts:
                raise KeyError("Tip de cost invalid")
            type = convertFromRoToEng(command[0])
            day = int(command[1])
            deleteCostFromAll(listOfApartments, type, day)
        except KeyError as msg:
            print(msg)
    else:
        print("Comanda invalida!!!")


def modifyCommandController(listOfApartments, command):
    '''
    Function that modifies costs
    :param listOfApartments:
    :param command:
    :return:
    '''
    try:
        if len(command) != 4:
            raise ValueError("Comanda gresita!!!")
        index = int(command[0])
        sumCost = int(command[1])
        costType = convertFromRoToEng(command[2])
        if not costType in typeOfCosts:
            raise KeyError("Tipul costului trebuie sa fie valid!")
        day = int(command[3])
        modifyApartmentCost(listOfApartments, index - 1, sumCost, costType, day)
    except ValueError as msg:
        print(msg)
    except IndexError:
        print("Indexul trebuie sa fie numar intreg pozitiv")
    except KeyError as ex:
        print(ex)


def printsCommandController(listOfApartments, command):
    '''
    Function that controls the user prints
    :param listOfApartments:
    :param command:
    :return:
    '''

    if command[0] == '>':
        try:
            if len(command) != 2:
                raise ValueError("Comanda trebuie sa fie valida!")
            sum = int(command[1])
            printCostLargerThanSum(costsLargerThanSum(listOfApartments, sum), sum)
        except ValueError as msg:
            print(msg)
    elif command[0] == 'toate':
        try:
            if len(command) != 2:
                raise ValueError("Comanda trebuie sa fie valida!!")
            type = convertFromRoToEng(command[1])
            if not type in typeOfCosts:
                raise KeyError("Tipul costului trebuie sa fie valid!")
            printCostTypeFromAll(costTypeFromAll(listOfApartments, type), type)
        except KeyError as msg:
            print(msg)
        except ValueError as ex:
            print(ex)
    elif len(command) > 2 and command[0] == '<' and command[2] == '>':
        try:
            if len(command) != 4:
                raise ValueError("Comanda trebuie sa fie valida!")
            day = int(command[1])
            sum = int(command[3])
            costBeforDay(listOfApartments, day, sum)
        except ValueError as msg:
            print(msg)
    else:
        print("Comanda invalida!!!")


def listCommandController(listOfApartments, command):
    '''
    Function that prints the sorted list of apartments
    :param listOfApartments:
    :param command:
    :return:
    '''
    try:
        if len(command) != 2:
            raise IndexError("Comanda nu este valida!!")
        costType = convertFromRoToEng(command[1])
        if not costType in typeOfCosts: raise KeyError("Tipul Costului trebuie sa fie valid")
        printSortedAfterType(listOfApartments, costType)
    except KeyError as msg:
        print(msg)
    except IndexError as ex:
        print(ex)


def viewCommandController(listOfApartments, command):
    '''
    Function for views
    :param listOfApartments:
    :param command:
    :return:
    '''
    if len(command) == 1 and convertFromRoToEng(command[0]) in typeOfCosts:
        type = convertFromRoToEng(command[0])
        totalSum = totalSumForCost(listOfApartments, type)
        print("Suma totala pentru ", convertFromEnToRo(totalSum[0]), " este ", totalSum[1])
    elif len(command) == 1:
        try:
            index = int(command[0])
            printCost(listOfApartments, index - 1)
        except ValueError:
            print("Indexul trebuie sa fie un numar intreg pozitiv!!")
        except IndexError:
            print("Indexul trebuie sa fie un numar intreg pozitiv!!")

    else:
        print("Comanda invalida!!!")


def filterCommandController(listOfApartments, command):
    '''
    Function that controls the command based fileter part
    :return: none
    '''
    if len(command) == 1 and convertFromRoToEng(command[0]) in typeOfCosts:
        filterAp(listOfApartments, convertFromRoToEng(command[0]))
    elif len(command) == 1 and int(command[0]):
        filterApSum(listOfApartments, int(command[0]))


def readCommand():
    '''
    Reads Command
    '''
    cmd = input("Dati comanda dorita/Scrieti help pentru comenzi: ")
    return cmd.lower()


def parseCommand(command):
    '''

    :param command:
    :return:
    '''
    command = command.lstrip(" ")
    pos = command.find(" ")

    if pos == -1:
        return command, []

    cmds = command[: pos]
    args = command[pos + 1:].split()

    return cmds, args


def undoCommandController(listOfApartments, command, newBackUpList):
    '''
    controls the command based undo
    :param listOfApartments:
    :param param:
    :return:
    '''
    if len(command) == 0:
       listOfApartments =  undo(listOfApartments, newBackUpList)
