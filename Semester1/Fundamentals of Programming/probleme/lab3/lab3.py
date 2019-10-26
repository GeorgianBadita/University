import math

def readInt(text):
    '''
    Tell if the user input is valid
    text - user input
    return the number the user introduces if it's an integer, else an
    exception is thrown
    '''
    while True:
        try:
            number = int(input(text))
            return number
        except ValueError:
            print("Valoare invalida")

def gcd(a, b):
    '''
    Compute the greatest common divisor of a and b
    a, b positive integers
    return a number, the greatest common divisor of a and b
    '''
    if a < 0 or b < 0:
        return "Eroare"
    if b == 0:
        return a
    else:
        return gcd(b, a % b)

def testGcd():
    '''
    Function to check if the gcd function works properly
    no parameters
    Stops the program if one of the assert statements is False,
    otherwise nothing happens
    '''
    assert gcd(2, 3) == 1
    assert gcd(2, 4) == 2
    assert gcd(4, 20) == 4
    assert gcd(256, 16) == 16
    assert gcd(-2, 9) == "Eroare"


def readList():
    l = []
    n = readInt("Dati numarul de elemente al listei: ")
    for i in range(0, n):
        a = readInt(("Introduceti elementul "+str(i+1)+":"))
        l.append(a)
    return l


def findLongestCoprime(myList):
    '''
    Find the longest sequence of coprime numbers
    myList - list of integers
    return a list representing the longest sequence of coprime numbers
    '''
    for i in range(0, len(myList)):
        if myList[i] < 0:
            return "Nu se poate calcula cel mai mare divizor comun a doua numere negative"
    maxLength = 0
    position = 0
    for i in range(0, len(myList)):
        length = 0
        while i + 1 < len(myList) and gcd(myList[i], myList[i + 1]) == 1:
            length += 1
            i += 1
        if length > maxLength:
            maxLength = length
            position = i

    if maxLength <= 0:
        return []
    return myList[position - maxLength:position + 1]


def testFindLongestCoprime():
    '''
    Function to check if the findLongestCoprime function works properly
    no parameters
    Stops the program if one of the assert statements is False,
    otherwise nothing happens
    '''
    assert findLongestCoprime([1, 2, 3, 4, 5]) == [1, 2, 3, 4, 5]
    assert findLongestCoprime([1, 2, 5, 10, 9, 11, 4, 5]) == [10, 9, 11, 4, 5]
    assert findLongestCoprime([9, 8, 7, 5, 2, 4, 1]) == [9, 8, 7, 5, 2]
    assert findLongestCoprime([]) == []

def commonDigits(a, b):
    '''
    Check if numbers a and b have at least 2 distinct common digits
    a, b - numbers, integers
    return True if a and b have at least 2 distinct common digits otherwise
    False
    '''
    if a < 0:
        a *= -1
    if b < 0:
        b *= -1
    newA = 0
    while a:
        newA |= (1 << a % 10)
        a //= 10
    newB = 0
    while b:
        newB |= (1 << b % 10)
        b //= 10

    checkNumber = newA & newB
    bitCount = 0
    while checkNumber:
        bitCount += 1
        checkNumber = checkNumber & (checkNumber - 1)

    return bitCount >= 2

def testCommonDigits():
    '''
    Function to check if the commonDigits function works properly
    no parameters
    Stops the program if one of the assert statements is False,
    otherwise nothing happens
    '''
    assert commonDigits(211, 112) == True
    assert commonDigits(9571, 19) == True
    assert commonDigits(257, 87) == False
    assert commonDigits(9715, 11) == False
    assert commonDigits(0 , 0) == False

def longestCommonDigits(myList):
    '''
    Find the longest sequence of numbers which have at least 2 common distinct digits
    myList - list of integers
    return a list representing the longest sequence of number
    with at least 2 common distinct digits
    '''
    maxLength = 0
    position = 0
    for i in range(0, len(myList)):
        length = 0
        while i + 1 < len(myList) and commonDigits(myList[i], myList[i + 1]) == True:
            length += 1
            i += 1
        if length > maxLength:
            position = i
            maxLength = length

    if maxLength <= 0:
        return []

    return myList[position - maxLength:position + 1]


def testLongestCommonDigits():
    '''
    Function to check if the longestCommonDigits function works properly
    no parameters
    Stops the program if one of the assert statements is False,
    otherwise nothing happens
    '''
    assert longestCommonDigits([122, 12, 213, 32]) == [122, 12, 213, 32]
    assert longestCommonDigits([567, 76, 678, 87, 25, 26]) == [567, 76, 678, 87]
    assert longestCommonDigits([]) == []
    assert longestCommonDigits([121, 55, 556, 65, 665, 211]) == [556, 65, 665]

def isPrime(x):
    '''
    Verify if a number is prime
    x - positive integer
    returns True if x is prime, False otherwise
    '''
    if x < 2:
        return  False
    if x == 2:
        return  True
    if x % 2 == 0:
        return  False
    for i in range(3, int(math.sqrt(x)), 2):
        if x % i == 0:
            return False
    return  True

def testIsPrime():
    '''
    Function to check if the isPrime function works properly
    no parameters
    Stops the program if one of the assert statements is False,
    otherwise nothing happens
    '''
    assert isPrime(2) == True
    assert isPrime(4) == False
    assert isPrime(-2) == False
    assert isPrime(5) == True
    assert isPrime(11) == True
    assert isPrime(0) == False


def longestPrime(myList):
    '''
    Find the longest sequence of prime numbers
    myList - list of integers
    return a list representing the longest sequence of prime numbers
    '''
    maxLength = 0
    position = 0
    for i in range(0, len(myList)):
        length = 0
        while i + 1 < len(myList) and isPrime(myList[i]) and isPrime(myList[i + 1]) == True:
            length += 1
            i += 1
        if length > maxLength:
            position = i
            maxLength = length

    if maxLength <= 0:
        return []

    return myList[position - maxLength:position + 1]

def testLongestPrime():
    '''
    Function to check if longestPrime function works properly
    no parameters
    Doesen't return  anything
    '''
    assert longestPrime([1, 2, 3, 5, 7, 12]) == [2, 3, 5, 7]
    assert longestPrime([]) == []
    assert longestPrime([1, 1, 2, 2, 3, 5, 7]) == [2, 2, 3, 5, 7]
    assert longestPrime([13, 13, 13, 13, 13]) == [13, 13, 13, 13, 13]

def generalTest():
    '''
    Function to check if all the functions works properly
    no parameters
    Doesen't return  anything
    '''
    testLongestPrime()
    testIsPrime()
    testCommonDigits()
    testFindLongestCoprime()
    testGcd()
    testLongestCommonDigits()

def printMenu():
    '''
    Function to print the menu console
    no parameters
    Doesen't return anything
    '''
    print("Apasati tasta 1 pentru a introduce un sir de numere... ")
    print("Apasati tasta 2 pentru a printa cea mai lunga secventa de numere prime intre ele... ")
    print("Apasati tasta 3 pentru a printa cea mai lunga secventa de numere care au cel putin doua cifre distincte... ")
    print("Apasati tasta 4 pentru a printa cea mai lunga secventa de numere prime")
    print("Apasati tasta 5 pentru a inchide aplicatia... ")


def menuController():
    '''
    Function to control the menu functions
    no parameters
    Controls the operations user can perform
    '''
    userList = []
    while True:
        printMenu()
        command = readInt("")
        if command == 1:
            userList = readList()
        elif command == 2:
            if len(userList) == 0:
                print("Trebuie mai intai sa introduceti o lista de numere... ")
                continue
            print(findLongestCoprime(userList))
        elif command == 3:
            if len(userList) == 0:
                print("Trebuie mai intai sa introduceti o lista de numere... ")
                continue
            print(longestCommonDigits(userList))
        elif command == 4:
            if len(userList) == 0:
                print("Trebuie mai intai sa introduceti o lista de numere... ")
                continue
            print(longestPrime(userList))
        elif command == 5:
            exit()
        else:
            print("Valoarea introdusa nu este corecta, va rugam incercati din nou... ")

def mainFunction():
    '''
    Function to manage and control the program more efficiently
    no parameters
    Doesen't return anything, it just controls the entire program
    '''
    generalTest() #Test all functions to be sure they work properly
    menuController() #The function which controls the user console





'''
THE CALL OF THE MAIN FUNCTION
'''

mainFunction()


