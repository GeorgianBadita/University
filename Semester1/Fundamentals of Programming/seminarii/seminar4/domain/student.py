'''

'''


def createStudent(nrMat, nume, varsta):
    '''
    Creaza un student
    '''
    return [nrMat, nume, varsta]


def getNrMatricol(st):
    '''

    :param st:
    :return: numarul matricol al studentului
    '''
    return st[0]


def getNume(st):
    '''

    :param st:
    :return: numele studentului
    '''
    return st[1]

def getVarsta(st):
    '''

    :param st:
    :return: returneaza numele studentului
    '''
    return st[2]


def testCreateSt():
    st = createStudent("bl2314", "Ion Ionescu", 18)
    assert getNrMatricol(st) == "bl2314"
    assert getNume(st) == "Ion Ionescu"
    assert getVarsta(st) == 18

testCreateSt()