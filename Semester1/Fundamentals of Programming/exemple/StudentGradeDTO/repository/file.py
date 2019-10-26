from repository.inmemory import  DuplicatedIDException
from repository.inmemory import RepositorException
from repository.inmemory import GradeAlreadyAssigned
from domain.entities import Student
from domain.entities import Address
from domain.entities import Grade
from domain.entities import StudentGrade


class StudentFileRepository:
    """
      Store/retrieve students from file
    """
    def __init__(self, fileN):
        """
          initialise repository
          fileName - string, file path where the students are stored
          post: students are loaded from the file
        """        
        self.__fName = fileN        

    def __loadFromFile(self):
        """
          Load students from file
          raise CorruptedFileException if there is an error when reading from the file
        """
        try:
            f = open(self.__fName, "r")
        except IOError:
            #file not exist
            return
        line = f.readline().strip()
        rez = []
        while line!="":
            attrs = line.split(";")
            st = Student(attrs[0], attrs[1], Address(attrs[2], attrs[3], attrs[4]))
            rez.append(st)
            line = f.readline().strip()
        f.close()
        return rez

    def store(self, st):
        """
          Store the student to the file.Overwrite store
          st - student
          Post: student is stored to the file
          raise DuplicatedIdException for duplicated id
        """
        allS = self.__loadFromFile()
        if st in allS:
            raise DuplicatedIDException()
        allS.append(st)
        self.__storeToFile(allS)

    def update(self, id, st):
        """
          Update student in the repository
          id - string, the id of the student to be updated
          st - Student, the updated student
          raise ValueError if there is no student with the given id
        """
        allS = self.__loadFromFile()
        allS.remove(st)
        allS.append(st)
        self.__storeToFile(allS)


    def remove(self, id):
        """
          remove a student from the repository
          id - string, the id of the student to be removed
          return student
          post: the repository not contains student with the given id
          raise ValueError if there is no student with the given id
        """        
        allS = self.__loadFromFile()
        poz = -1
        for i in range(len(allS)):
            if allS[i].getId()==id:
                poz = i
        if poz == -1:
            raise ValueError("No student for the id:"+id)
        st = allS[poz]
        del allS[poz]     
        self.__storeToFile(allS)
        return st


    def __storeToFile(self,sts):
        """
         Store all the students  in to the file
         raise CorruptedFileException if we can not store to the file
        """
        #open file (rewrite file)
        with open(self.__fName, "w") as f:
            for st in sts:
                strf = st.getId()+";"+st.getName()+";"
                strf = strf + st.getAdr().getStreet()+";"+str(st.getAdr().getNr())+";"+st.getAdr().getCity()
                strf = strf+"\n"
                f.write(strf)        

    def find(self,id):
        """
          Find the student for a given id
          id - string
          return student with the given id or None if there is no student with the given id
        """
        studs = self.__loadFromFile()
        for st in studs:
            if st.getId()==id:
                return st
        return None
    
    def removeAll(self):
        """
          Remove all the students from the repository
          post: the repository is empty
        """        
        self.__storeToFile([])
        
    def getAll(self):
        return self.__loadFromFile()
     
    def size(self):
        return len(self.__loadFromFile())

def testStore():
    fileName = "teststudent.txt"
    repo = StudentFileRepository(fileName)
    repo.removeAll()

    st = Student("1", "Ion", Address("str", 3, "Cluj"))
    repo.store(st)
    assert repo.size()==1
    assert repo.find("1") == st
    #verify if the student is stored in the file
    repo2 = StudentFileRepository(fileName)
    assert repo2.size()==1
    assert repo2.find("1") == st

testStore()

class GradeFileRepository:
    """
      Repository of grades
      Store grades in a file
    """
    def __init__(self, fname):
        self.__fname = fname

    def store(self, gr):
        """
          Store a grade
          post: grade is in the repository
          raise GradeAlreadyAssigned exception if we already have a grade for the student at the given discipline
          raise RepositoryException if there is an IO error when writing to the file
        """
        if self.find(gr.getStudent(), gr.getDiscipline())!=None:
            raise GradeAlreadyAssigned()

        #open the file for append
        try:
            f = open(self.__fname, "a")
            grStr = gr.getStudent().getId()+","+gr.getDiscipline()+","+str(gr.getGrade())+"\n"
            f.write(grStr)
            f.close()
        except IOError:
            raise RepositorException("Unable to write a grade to the file")

    def size(self):
        """
          Return the number of elements in the repository
        """
        #open the file for read and count the number of lines
        try:
            f = open(self.__fname, "r")
            line = f.readline().strip()
            rez = 0
            while line!="":
                rez = rez+1
                line = f.readline().strip()
            f.close()
            return rez
        except IOError:
            return 0


    def find(self, st, disc):
        """
          Lookup a grade for a given student and discipline
          st - student
          disc - discipline
          return Grade or None if there is no grade in the repository
        """
        #open the file for read and count the number of lines
        try:
            f = open(self.__fname, "r")
        except IOError:
            #the file is not created yet
            return None
        try:
            line = f.readline().strip()
            while line!="":
                attrs = line.split(",")
                #if this line refers to the requested student and discipline
                isSameStudent = attrs[0]==st.getId() and attrs[1] == disc
                if isSameStudent:
                    rez = Grade(st, disc, float(attrs[2]))
                    f.close()
                    return rez
                line = f.readline().strip()
            f.close()
            return None
        except IOError:
            raise RepositorException("Unable to read grades from the file")
        return None

    def getAll(self,st):
        """
         Return the grades for a given student
         st student
         return a list of grades
        """
        try:
            f = open(self.__fname, "r")
        except IOError:
            #the file is not created yet
            return None
        try:
            rez = []
            line = f.readline().strip()
            while line!="":
                attrs = line.split(",")
                #if this line refers to the requested student
                if attrs[0]==st.getId():
                    gr = Grade(st, attrs[1], float(attrs[2]))
                    rez.append(gr)
                line = f.readline().strip()
            f.close()
            return rez
        except IOError:
            raise RepositorException("Unable to read grades from the file")

    def getAllForDisc(self,disc):
        """
         Return all the grades for all the students from all disciplines
         disc - string, the discipline
         return list of StudentGrade's
        """
        try:
            f = open(self.__fname, "r")
        except IOError:
            #the file is not created yet
            return None
        try:
            rez = [] #StudentGrade instances
            line = f.readline().strip()
            while line!="":
                attrs = line.split(",")
                #if this line refers to the requested student
                if attrs[1]==disc:
                    gr = StudentGrade(attrs[0], attrs[1], float(attrs[2]))
                    rez.append(gr)
                line = f.readline().strip()
            f.close()
            return rez
        except IOError:
            raise RepositorException("Unable to read grades from the file")


    def removeAll(self):
        """
          Remove all grades
          post: the repository is empty
        """
        f = open(self.__fname, "w")
        f.close()

def testStoreGradeFile():
    st = Student("1", "Ion", Address("Adr", 1, "Cluj"))
    gr = Grade(st, "FP", 9.5)
    rep = GradeFileRepository("testgrade.txt")
    rep.removeAll()
    assert rep.size()==0
    rep.store(gr)
    assert rep.size()==1
    gr2 = rep.find(st, "FP")
    assert gr2==gr

    gr = Grade(st, "FP", 9)
    try:
        rep.store(gr)
        assert False
    except GradeAlreadyAssigned:
        assert True

testStoreGradeFile()

def testGetGradesFile():
    st = Student("1", "Ion", Address("Adr", 1, "Cluj"))
    gr = Grade(st, "FP", 10)
    rep = GradeFileRepository("testgrade.txt")
    rep.removeAll()
    rep.store(gr)
    gr = Grade(st, "SO", 9.5)
    rep.store(gr)
    grades = rep.getAll(st)
    assert grades[0].getStudent()==st
    assert grades[0].getGrade()==10
    assert grades[0].getDiscipline()=="FP"

testGetGradesFile()

def testGetStudentGrades():
    """
     Test function for getForDisc
    """
    rep = GradeFileRepository("testgrade.txt")
    rep.removeAll()

    st = Student("1", "Ion", Address("Adr", 1, "Cluj"))
    gr = Grade(st, "FP", 10)
    rep.store(gr)
    gr = Grade(st, "SO", 9.5)
    rep.store(gr)

    studentGrades = rep.getAllForDisc("FP")
    assert len(studentGrades)==1
    assert studentGrades[0].getStudentID()=="1"
    assert studentGrades[0].getGrade()==10
    assert studentGrades[0].getDiscipline()=="FP"

    st = Student("2", "Ionel", Address("Adr2", 22, "Cluj"))
    gr = Grade(st, "SO", 9.5)
    rep.store(gr)
    studentGrades = rep.getAllForDisc("SO")
    assert len(studentGrades)==2
    assert studentGrades[0].getStudentID()=="1"
    assert studentGrades[1].getStudentID()=="2"

testGetStudentGrades()