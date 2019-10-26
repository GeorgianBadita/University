from studentRepo import StudentRepo, StudentRepoFile
from studentValidator import StudentValidator
from sutdent import Student, VarstaCati


class Catalog:

    def __init__(self, val, rep):
        self.__listOfStudents = rep
        self.__val = val

    def addStudent(self, nrMatricol, nume, varsta):
        st = Student(nrMatricol, nume, varsta)
        self.__listOfStudents.store(st)
        self.__val.validate(st)
        return st

    def getAllStud(self):
        return self.__listOfStudents.getAll()

    def filterByAge(self):
        dictionar = {}
        for st in self.__listOfStudents:
            if st.getVarsta() in dictionar:
                dictionar[st.getVarsta()].incrementCati()
            else:
                dictionar[st.getVarsta()] = VarstaCati(st.getVarsta(), 1)
        return dictionar


def testAddStudent():
    rep = StudentRepo()
    val = StudentValidator()
    cat = Catalog(val, rep)
    st = cat.addStudent("we12324", "Ion", 18)
    assert st.getNume() == 'Ion'
    assert st.getVarsta() == 18
    studenti = cat.getAllStud()
    print(studenti)
    assert len(studenti) == 1
    st = cat.addStudent("rr15324", "Vasile", 18)
    studenti = cat.getAllStud()
    assert len(studenti) == 2

testAddStudent()