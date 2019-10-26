from sutdent import Student


class StudentRepo:
    def __init__(self):
        self.__l = {}

    def store(self, st):
        self.__l[st.getNrMatricol()] = st

    def getAll(self):
        return list(self.__l.values())


class StudentRepoFile:
    def __init__(self, fileName):
        self.__l = {}
        self.__fileName = fileName
        self.__loadFromFile()

    def __loadFromFile(self):
        file = open(self.__fileName, "r")
        for linie in file:
            sir = linie.split(",")
            st = Student(sir[0], sir[1], int(sir[2]))
            self.__l[st.getNrMatricol()] = st
        file.close()


    def store(self, st):
        self.__l[st.getNrMatricol()] = st

    def getAll(self):
        return list(self.__l.values())


def testRepoFile():
    file = open("studtest.txt", "w")
    file.write("1,Ion,20\n")
    file.write("2,Alexandru,18\n")
    file.write("3,Andrei,26\n")
    file.close()
    newRepo = StudentRepoFile("studtest.txt")
    assert len(newRepo.getAll()) == 3


testRepoFile()