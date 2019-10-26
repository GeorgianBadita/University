'''

'''
from domain.catalog import addStudent, createCatalog
from domain.student import getNume


def startMenu():
    cat = createCatalog()
    while True:
        cmd = input("1 Add\nx Exit")
        if cmd == 'x': break
        if cmd == '1':
            try:
                addStudUI(cat)
            except ValueError as ex:
                print(ex)


def addStudUI(cat):
    nrMat = input("Dati nr matricol: ")
    nume = input("Dati numele studentului: ")
    varsta = input("Dati varsta studentului: ")
    st = addStudent(cat, nrMat, nume, varsta)
    print(getNume(st), " a fost adaugat")


startMenu()