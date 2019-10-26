
#HELPER FUNCTIONS AND STRUCTURES


def convertToLower(string):
    '''
    Function that converts every uppercase letters in a string into lowercase letters
    Takes in argument a string
    Return a string with lowercase letters
    '''
    string = string.lower()
    return string


def convertFromRoToEng(string):
    '''
    Function to convert the names of costs from Ro to En
    Takes one argument a string
    Return the corespondent in En for the Ro word
    '''
    string = convertToLower(string)
    if string == 'apa':
        return 'water'
    elif string == 'gaz':
        return 'gas'
    elif string == 'incalzire':
        return 'heating'
    elif string == 'altele':
        return 'others'
    elif string == 'canalizare':
        return 'sewerage'

    return 'invalid'


def convertFromEnToRo(type):
    '''
    Function that convert the type from En to Ro
    Takes one argument the type which is a string
    Returns the correspondend in Ro
    '''
    if type == 'heating':
        type = 'incalzrie'
    elif type == 'water':
        type = 'apa'
    elif type == 'gaz':
        type = 'gas'
    elif type == 'others':
        type = 'altele'
    elif type == 'sewerage':
        type = 'canalizare'
    return  type


def createNewList(n):
    '''
    Function to create a new empty list of apartments
    Takes one argument number of apartments
    Returns a bi-dimensional list, representing the attributes of an apartment
    '''
    l = {}
    for i in range(n):
        l[i] = {'water':0, 'gas':0, 'heating':0, 'sewerage':0, 'others':0, 'day':0}
    return l


def clearScreen():
    print("\n"*80)


#UI PRINT MENU PART

def printMenu():

    ''''
    Function to print the menu
    Takes no arguments
    Doesn't return anything
    '''
    print("Apasati 1 pentru optiunile de adaugare ale unei cheltuieli")
    print("Apasati 2 pentru optiunile de stergere ale unei cheltuieli")
    print("Apasati 3 pentru optiunile de cautare ale unei cheltuieli")
    print("Apasati 4 pentru a putea vizualiza rapoarte")
    print("Apasati 5 pentru optiunile de filtrare")
    print("Apasati 6 pentru a face undo")
    print("Apasati 7 pentru a inchide aplicatia")
    print("O cheltuiala poate fi doar de tipul: apa, incalzire, canalizare, gaz sau altele")


def printAddSubmenu():

    '''
    Function to print the submenu for Cost adding features
    Takes no arguments
    Doesn't return anything
    '''
    print("Apasati 1 pentru a introduce o cheltuiala unui apartament la o cheltuiala curenta")
    print("Apasati 2 pentru a modifica cheltuiala unui apartament")


def printDeleteSubmenu():

    '''
    Function to print the submenu for Cost deleting feature
    Takes no arguments
    Doesn't return anything
    '''
    print("Apasati 1 pentru a sterge toate cheltuielile de la un apartament")
    print("Apasati 2 pentru a sterge cheltuielile de la apartamente consecutive")
    print("Apasati 3 pentru a sterge cheltuielile de un anumit tip de la toate apartamentele")


def printSearchSubmenu():
    '''
    Function to print the submenu for Cost searching feature
    Takse no arguments
    Doesn't return anything
    '''
    print("Apasati 1 pentru a tipari toate apartamentele cu cheltuieli mai mari decat o suma data")
    print("Apasati 2 pentru a tipari toate cheltuielile de un anumit tip de la toate apartamentele")
    print("Apasati 3 pentru a tipari toate cheltuielile efectuate inainte de o zi si mai mari decat o suma data")

def printViewSubmenu():
    '''
    Function to print the submenu for cost-view feature
    :return: none
    '''
    print("Apasati 1 pentru a tipari suma totala pentru un tip de cheltuiala")
    print("Apasati 2 pentru a tipari toate apartamentele sortate dupa un tip de cheltuiala")
    print("Apasati 3 pentru a topari totalul de cheltuieli pentru un apartament dat")

def printFilterSubmenu():
    '''
    Functon to print the submenu for filter feature
    :return: none
    '''
    print("Apasati 1 pentru a elimina toate cheltuielile de un anumit tip")
    print("Apasati 2 pentru a elimina toate cheltuielile mai mici decat o suma data")

def printCostLargerThanSum(listOfApartments, sum):
    '''
    Function that prints the list of apartments with cost larger than a sum
    Takes 2 argument the list of apartments and the sum
    Doesn't return anythinh
    '''
   #print('\n')
    print("Sunt " + str(len(listOfApartments)) + " apartamente cu suma mai mare decat " + str(sum) )
    for i in range(len(listOfApartments)):
        print("Apartamentul " + str(listOfApartments[i] + 1))


def printCostTypeFromAll(listOfApartments, type):
    '''
    Function that prints a type of cost from all apartments
    Takes 2 arguments, the list of Apartments and the type of cost
    Doesn't return anything
    '''
    type = convertFromEnToRo(type)
    print("Costul pentru " + type + " pentru toate apartamentele este:")
    print("\n"*2)
    for i in range(len(listOfApartments)):
        print("Apartamentul " + str(i + 1) + " este: " + str(listOfApartments[i]))
    print("\n"*2)





'''
Conventions to command based line
To add cost for a new apartment the user will type: adauga nrApartament sumaCost tipCost ziua
To modify cost for a new apartment the user will type: modifica nrApartament sumaCost tipCost ziua

To delete all costs from an apartment the user will type: sterge de la nrApartament ziua
To delete from consecutive apartments the user will type: sterge startIndex, finalIndex 
To delete a cost from all apartments the user will type: sterge tipCost ziua

To print all the apartments with cost > than a sum, the user will type: afiseaza > suma
To print all the costs from a single type the user will type: afiseaza toate type
To print all the costs before a specific day and > than a sum the user will type: afiseaza < ziua > suma

To print the total sum for a specific type the user will type: tipareste tip
To print all the apartments sorted by a specific type of cost the user will type:  lista sortata tipCheltuiala
To print the total cost from an apartment the user will type: tipareste nrAP
'''

def printCommands():
    print("Pentru a adauga cost unui apartament la costul curent, tastati: adauga <nrAp> <sumaCost> <tipCost> <ziua>")
    print("Pentru a modifica costul unui apartament, tastati: modifica <nrAp> <sumaCost> tipCost> <ziua>")
    print("\nPentru a sterge costul unui apartament, tastati: sterge de la <nrAp> <ziua>")
    print("Pentru a sterge costul de la apartamentele dintr-un interval, tastati: sterge <start> , <stop>")
    print("Pentru a sterge un tip de cost de la toate apartamentele, tastati: sterge <tipCost> <ziua>")
    print("\nPentru a afisa toate apartamentele cu un cost mai mare decat unul dat, tastati: afiseaza > <suma>")
    print("Pentru a afisa un tip de cost de la toate apartamentele, tastati: afiseaza toate <tipCost>")
    print("Pentru a afisa costurile inainte de o zi si mai mari decat o suma, tastati: afiseaza < <ziua> > <suma>")
    print("\nPentru a afisa suma totala pentru un anumit tip, tastati: tipareste <tipCost>")
    print("Pentru a printa toate apartamentele sortat in functie de un cost, tastati: lista sortata <tipCost>")
    print("Pentru a printa costul total de la un apartament, tipariti: tipareste <nrAp>")
    print("\nPentru a filtra apartamentele dupa un anumit tip de cost, tipariti: filtrare <tipCost>")
    print("Pentru a filtra apartamentele mai mici decat o suma, tipariti: filtrare <suma>" )
    print("\nPentru a reveni la ultima comanda, tipariti undo")
    print("Pentru a inchide aplicatia tipariti: iesire")