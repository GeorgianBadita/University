from domain.student import getNume, getVarsta, createStudent, getNrMatricol


def createCatalog():
    '''

    :return: creaza un catalog vid
    '''
    return []

def addStudent(cat, nrMat, nume, varsta):
    '''

    :param nrMat:
    :param nume:
    :param varsta:
    :return: returneaza studentul adaugat
    '''
    st = createStudent(nrMat, nume, varsta)
    validareStudent(nrMat, nume, varsta)
    for student in cat:
        if nrMat == getNrMatricol(student):
           raise ValueError("Numar matricol deja existent!!")
    cat.append(st)
    return st


def validareStudent(nrMat, nume, varsta):
    if nrMat == '' : raise ValueError("Numar matricol vid!!")
    if nume == '' : raise ValueError("Nume vid!!")
    if int(varsta) <= 0 : raise ValueError("Varsta prea mica")


def getAll(cat):
    '''

    :param cat:
    :return: lista de studenti
    '''
    return cat


def testAddStudent():
    cat = createCatalog()
    st = addStudent(cat, "we1234", "Ion", 18)
    assert getNume(st) == "Ion"
    assert getVarsta(st) == 18
    studenti = getAll(cat)
    assert len(studenti) == 1


    st = addStudent(cat, "rr15324", "Vasile", 18)
    studenti = getAll(cat)
    assert len(studenti) == 2
    try:
        st = addStudent(cat, "rr15324", "Vasile", 18)
        assert False
    except ValueError:
        assert True

    try:
        st = addStudent(cat, "", "Vasile", 18) #numar matricol vid
        assert False
    except ValueError:
        assert True

    try:
        st = addStudent(cat, "asfg", "Vasile", -18)  # numar matricol vid
        assert False
    except ValueError:
        assert True


testAddStudent()