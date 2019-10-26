class VarstaCati:
    def __init__(self, varsta, cati):
        self.__varsta = varsta
        self.__cati = cati

    def getVarsta(self):
        return  self.__varsta

    def getCati(self):
        return self.__cati

    def incrementCati(self):
        self.__cati += 1


class Student:

    def __init__(self, nrMatricol, nume, varsta):
        self.__nrMatricol = nrMatricol
        self.__nume = nume
        self.__varsta = varsta

    def getNrMatricol(self):
        return self.__nrMatricol

    def getNume(self):
        return self.__nume

    def getVarsta(self):
        return self.__varsta

    def printStud(self):
        print(self.__nrMatricol + " " + self.__nume + " " + str(self.__varsta))


def testCreateSt():
    st = Student("bl2314", "Ion Ionescu", 18)
    assert st.getNrMatricol() == "bl2314"
    assert st.getNume() == "Ion Ionescu"
    assert st.getVarsta() == 18
    self.assertRaises(KeyError, self.rep.save, v)