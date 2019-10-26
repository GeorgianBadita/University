'''
Test module
'''

from domain.apartment import getNumOfApartments, addToCost, modifyApartmentCost, deleteApartmentCost, deleteFromAtoB, \
    deleteCostFromAll, getTotalCost, costsLargerThanSum, costTypeFromAll, totalSumForCost, sortAfterType, \
    addCommandController, deleteCommandController, modifyCommandController, parseCommand
from utils.helper import createNewList, convertToLower, convertFromRoToEng


def testGetNumOfApartments():
    '''
    Function to thest the getNumOfApartments function
    Takes no parameters
    Doesn't return anything
    '''
    testList = createNewList(21)
    assert getNumOfApartments(testList) == 21
    testList = createNewList(0)
    assert getNumOfApartments(testList) == 0
    testList = createNewList(125)
    assert getNumOfApartments(testList) == 125


def testAddtoCost():
    '''
    Function to test the addToCost function
    Takes no arguments
    Doesen't return anything
    '''
    testList = createNewList(1)
    addToCost(testList, 0, 124, 'water', 24)
    assert testList == {0:{'water':124, 'gas':0, 'heating':0, 'sewerage':0, 'others':0, 'day':24}}
    addToCost(testList, 0, 120, 'water', 1)
    addToCost(testList, 0, 90, 'heating', 19)
    assert testList == {0: {'water': 244, 'gas': 0, 'heating': 90, 'sewerage': 0, 'others': 0, 'day': 19}}


def testModifyApartmentCost():
    '''
    Function to test the modifyApartmentCost function
    Takes no argument
    Doesn't return anything
    '''
    emptyDict = {0: {'water': 0, 'gas': 0, 'heating': 0, 'sewerage': 0, 'others': 0, 'day': 0}}
    testList = createNewList(2)
    testList[2] = {'water':0, 'gas': 0, 'heating': 125, 'sewerage': 0, 'others': 0, 'day': 0}
    testList[3] = {'water':0, 'gas': 0, 'heating':  0, 'sewerage': 0, 'others': 0, 'day': 0}
    modifyApartmentCost(testList, 3, 20, 'water', 13)
    #assert testList == {emptyDict, 1:{'water':0, 'gas': 0, 'heating':  0, 'sewerage': 0, 'others': 0, 'day': 0}, 2: {'water':0, 'gas': 0, 'heating':  125, 'sewerage': 0, 'others': 0, 'day': 0},3 : {'water':20, 'gas': 0, 'heating':  0, 'sewerage': 0, 'others': 0, 'day': 13}}
    modifyApartmentCost(testList, 2, 42, 'heating', 15)
    #assert testList == {emptyDict, 1:{'water':0, 'gas': 0, 'heating':  0, 'sewerage': 0, 'others': 0, 'day': 0} , 2: {'water':0, 'gas': 0, 'heating':  42, 'sewerage': 0, 'others': 0, 'day': 15}, 3: {'water':20, 'gas': 0, 'heating':  0, 'sewerage': 0, 'others': 0, 'day': 13}}


def testDeleteApartmentCost():
    '''
    Function to test the deleteApartment function
    Takes no arguments
    Doesn't return anything
    '''
    emptyList = [0, 0, 0, 0, 0, 0]
    testList = [emptyList, emptyList, [0, 0, 125, 0, 0, 0], [20, 0, 0, 0, 0, 0]]
    deleteApartmentCost(testList, 2, 5)
    assert testList == [emptyList, emptyList, [0, 0, 0, 0, 0, 5], [20, 0, 0, 0, 0, 0]]
    deleteApartmentCost(testList, 3, 6)
    assert testList == [emptyList, emptyList,  [0, 0, 0, 0, 0, 5], [0, 0, 0, 0, 0, 6]]


def testDeleteFromAtoB():
    '''
    Function to test the function deleteFromAtoB
    Takes no arguments
    Doesn't return anyhting
    '''
    emptyList = [0, 0, 0, 0, 0, 0]
    testList = createNewList(4)
    deleteFromAtoB(testList, 2, 4)
    assert testList == [emptyList]*4
    modifyApartmentCost(testList, 2, 123, 'water', 1)
    modifyApartmentCost(testList, 3, 123, 'gas', 2)
    modifyApartmentCost(testList, 0, 123, 'heating', 3)
    deleteFromAtoB(testList, 2, 3)
    assert testList == [[0, 0, 123, 0, 0, 3], emptyList, emptyList, [123, 123, 0, 0, 0, 2]]


def testDeleteCostFromAll():
    '''
    Function to test the function deleteCostFromAll
    Takes no arguments
    Doesen't return anything
    '''
    tmpList = [0, 0, 0, 0, 0, 5]
    testList = createNewList(4)
    deleteCostFromAll(testList, 'gas', 5)
    assert testList == [tmpList] * 4
    modifyApartmentCost(testList, 2, 123, 'water', 1)
    modifyApartmentCost(testList, 3, 123, 'gas', 2)
    modifyApartmentCost(testList, 0, 123, 'water', 3)
    deleteCostFromAll(testList, 'water', 7)
    tmpList[5] = 7
    assert testList == [tmpList, tmpList, tmpList, [0, 123, 0, 0, 0, 7]]


def testGetTotalCost():
    '''
    Function that test the function getTotalCost
    Takes no arguments
    Doesn't return anything
    '''
    testList = createNewList(4)
    assert getTotalCost(testList, 2) == 0
    modifyApartmentCost(testList, 2, 123, 'water', 1)
    modifyApartmentCost(testList, 3, 123, 'gas', 2)
    modifyApartmentCost(testList, 2, 120, 'others', 3)
    modifyApartmentCost(testList, 0, 123, 'heating', 4)
    assert getTotalCost(testList, 2) == 243


def testCostsLargerThanSum():
    '''
    Function to test the function costsLargerThanSum
    Takes no arguments
    Doesn't return anything
    '''
    testList = createNewList(4)
    assert costsLargerThanSum(testList, 0) == []
    modifyApartmentCost(testList, 2, 123, 'water', 1)
    modifyApartmentCost(testList, 3, 123, 'gas', 2)
    modifyApartmentCost(testList, 2, 120, 'others', 3)
    modifyApartmentCost(testList, 0, 123, 'heating', 4)
    assert costsLargerThanSum(testList, 119) == [0, 2, 3]


def testCostTypeFromAll():
    '''
    Function to test the function costTypeFromAll
    Takes no arguments
    Doesn't return anything
    '''
    testList = createNewList(4)
    assert costTypeFromAll(testList, 'water') == [0, 0, 0, 0]
    modifyApartmentCost(testList, 2, 123, 'water', 1)
    modifyApartmentCost(testList, 3, 123, 'water', 2)
    modifyApartmentCost(testList, 1, 120, 'water', 3)
    modifyApartmentCost(testList, 0, 123, 'heating', 4)
    assert costTypeFromAll(testList, 'water') == [0, 120, 123, 123]


def testTotalSumForCost():
    testList = createNewList(4)
    assert totalSumForCost(testList, 'water') == ['water', 0]
    modifyApartmentCost(testList, 2, 123, 'water', 1)
    modifyApartmentCost(testList, 3, 123, 'gas', 2)
    modifyApartmentCost(testList, 2, 120, 'water', 3)
    modifyApartmentCost(testList, 0, 123, 'gas', 4)
    assert totalSumForCost(testList, 'water') == ['water', 120]
    assert totalSumForCost(testList, 'gas') == ['gas', 246]


def testSortAfterType():
    testList = createNewList(4)
    #print(sortAfterType(testList, 'water'))
    assert sortAfterType(testList, 'water') == [0, 1, 2, 3]
    modifyApartmentCost(testList, 3, 119, 'water', 1)
    modifyApartmentCost(testList, 2, 156, 'water', 2)
    modifyApartmentCost(testList, 1, 120, 'water', 3)
    modifyApartmentCost(testList, 0, 200, 'water', 4)
    #print(sortAfterType(testList, 'water'))
    assert sortAfterType(testList, 'water') == [3, 1, 2, 0]


def testAddCommandController():
    emptyList = [0, 0, 0, 0, 0, 0]
    someList = [0, 0, 0, 0, 0, 0]
    testList = createNewList(4)
    addCommandController(testList, ['3', '120', 'apa', '15'], someList)
    assert testList == [emptyList, emptyList, [120, 0, 0, 0, 0, 15], emptyList]
    addCommandController(testList, ['2', '99', 'incalzire', '22'], someList)
    assert testList == [emptyList, [0, 0, 99, 0, 0, 22], [120, 0, 0, 0, 0, 15], emptyList]
    addCommandController(testList, ['3', '120', 'apa', '16'], someList)
    assert testList == [emptyList, [0, 0, 99, 0, 0, 22], [240, 0, 0, 0, 0, 16], emptyList]


def testDeleteCommandController():
    emptyList = [0, 0, 0, 0, 0, 0]
    someList = list(emptyList)
    testList = createNewList(4)
    addCommandController(testList, ['3', '120', 'apa', '15'], someList)
    assert testList == [emptyList, emptyList, [120, 0, 0, 0, 0, 15], emptyList]
    deleteCommandController(testList, ['1', ',', '3'], someList)
    assert testList == [emptyList, emptyList, emptyList, emptyList]
    addCommandController(testList, ['3', '120', 'apa', '16'], someList)


def testModifyCommandController():
    emptyList = [0, 0, 0, 0, 0, 0]
    testList = createNewList(4)
    modifyCommandController(testList, ['3', '120', 'apa', '15'])
    assert testList == [emptyList, emptyList, [120, 0, 0, 0, 0, 15], emptyList]
    modifyCommandController(testList, ['2', '99', 'incalzire', '22'])
    assert testList == [emptyList, [0, 0, 99, 0, 0, 22], [120, 0, 0, 0, 0, 15], emptyList]


def testParseCommand():
    assert parseCommand("sterge de la 1 la 10") == ('sterge', ['de', 'la', '1', 'la', '10'])
    assert parseCommand("adauga 10 100 apa 15") == ('adauga', ['10', '100', 'apa', '15'])


def testConvertToLower():
    '''
    Function to test the convertToLower function
    Takes no arguments
    Doesn't return anything
    '''
    assert convertToLower('WaTeR') == 'water'
    assert convertToLower('APA') == 'apa'
    assert convertToLower('') == ''
    assert convertToLower('INCALZIRE') == 'incalzire'


def testConvertFromRoToEn():
    '''
    Function to test the function convertFromRoToEng
    Takes no arguments
    Doesn't return anythinh
    '''
    assert convertFromRoToEng('Apa') == 'water'
    assert convertFromRoToEng('INCALZIRE') == 'heating'
    assert convertFromRoToEng('AlTeLe') == 'others'
    assert convertFromRoToEng('') == 'invalid'
    assert convertFromRoToEng('CANALIZARE') == 'sewerage'


def testCreateNewList():

    '''
    Function to test the createNewList function
    Takes no arguments
    Doesn't return anything
    '''
    emptyDict = {'water':0, 'gas':0, 'heating':0, 'sewerage':0, 'others':0, 'day':0}
    assert createNewList(2) == {0 :emptyDict, 1:emptyDict}
    assert createNewList(0) == {}
    assert createNewList(4) == {0:emptyDict, 1:emptyDict, 2:emptyDict, 3:emptyDict}


testCreateNewList()
testGetNumOfApartments()
testConvertFromRoToEn()
testConvertToLower()
testAddtoCost()
testModifyApartmentCost()
testParseCommand()
















#testDeleteApartmentCost()
#testDeleteFromAtoB()
#testDeleteCostFromAll()
#testGetTotalCost()
#testCostsLargerThanSum()
#testCostTypeFromAll()
#testTotalSumForCost()
#testSortAfterType()
#testAddCommandController()
#testModifyCommandController()
#testDeleteCommandController()

