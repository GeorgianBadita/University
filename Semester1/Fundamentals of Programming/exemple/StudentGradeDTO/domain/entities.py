class Address:
    """
      Represent an address
    """
    def __init__(self, street, nr, city):
        self.__street = street
        self.__nr = nr
        self.__city = city

    def getStreet(self):
        return self.__street

    def getNr(self):
        return self.__nr

    def getCity(self):
        return self.__city

    def __str__(self):
        """
          Give a string representation for the address
          return string
        """
        return self.__street+" nr."+self.__nr+" "+self.__city

class Student:
    """
      Represent a student
    """
    def __init__(self, id, name, adr):
        """
         Create a new student
         id, name String
         address - Address
        """
        self.__id = id
        self.__name = name
        self.__adr = adr

    def getId(self):
        """
          Getter method for id
        """
        return self.__id

    def getName(self):
        """
          Getter for name
        """
        return self.__name

    def getAdr(self):
        """
         Getter for address
        """
        return self.__adr
    def __str__(self):
        """
          Give a string representation for the student
          return string
        """
        return self.__id+" "+self.__name+" "+str(self.__adr)

    def __eq__(self, ot):
        """
          Define equal for students
          ot - student
          return True if ot and the current instance represent the same student
        """
        if ot == None:
            return False
        return self.__id==ot.__id

def testIdentity():
    #attributes may change
    st = Student("1", "Ion", Address("Adr", 1, "Cluj"))
    st2 = Student("1", "Ion", Address("Adr2", 1, "Cluj"))
    assert st==st2

    #is defined by its identity
    st = Student("1", "Popescu", Address("Adr", 1, "Cluj"))
    st2 = Student("2", "Popescu", Address("Adr2", 1, "Cluj"))
    assert st!=st2

    st = Student("1", "Ion", Address("Ade", 1, "Cluj"))
    st1 = Student("2", "Alexandru", Address("Adr", 2, "Valcea"))
    print(st.getId())
    print(st1.getId())
    st, st1 = st1, st
    print(st.getId())
    print(st1.getId())

testIdentity()


def testCreateStudent():
    """
      Testing student creation
      Feature 1 - add a student
      Task 1 - Create student
    """
    st = Student("1", "Ion", Address("Adr", 1, "Cluj"))
    assert st.getId() == "1"
    assert st.getName() == "Ion"
    assert st.getAdr().getStreet() == "Adr"

    st = Student("2", "Ion2", Address("Adr2", 1, "Cluj"))
    assert st.getId() == "2"
    assert st.getName() == "Ion2"
    assert st.getAdr().getStreet() == "Adr2"
    assert st.getAdr().getCity() == "Cluj"

testCreateStudent()

class Grade:
    """
     Represent a grade
    """
    def __init__(self, st, disc, gr):
        """
          Initialise grade
          st - student
          disc - string, the discipline
          gr - double, grade
        """
        self.__st = st
        self.__discipline = disc
        self.__grade = gr

    def getStudent(self):
         return self.__st

    def getDiscipline(self):
        return self.__discipline

    def getGrade(self):
        return self.__grade

    def __eq__(self,ot):
        """
          A student and a discipline is unique
        """
        if ot==None: return False
        return self.__st==ot.__st and self.__discipline == ot.__discipline

def testCreateGrade():
    """
     Test function for grade creation
    """
    st = Student("1", "Ion", Address("Adr", 1, "Cluj"))
    gr = Grade(st, "FP", 9.5)
    assert gr.getStudent()==st
    assert gr.getDiscipline()=="FP"
    assert gr.getGrade()==9.5

testCreateGrade()

def testIdentityGrade():
    """
     Testing identity
    """
    st = Student("1", "Ion", Address("Adr", 1, "Cluj"))
    gr = Grade(st, "FP", 9.5)
    gr2 = Grade(st, "FP", 8.5)
    assert gr==gr2

testIdentityGrade()

class StudentGrade:
    """
      Data transfer object
    """
    def __init__(self,stId, discipline, grade):
        self.__stID = stId
        self.__discipline = discipline
        self.__grade = grade
        self.__name = None

    def getStudentID(self):
        """
         Getter method
        """
        return self.__stID
    def getGrade(self):
        """
         Getter method
        """
        return self.__grade
    def getDiscipline(self):
        """
         Getter method
        """
        return self.__discipline

    def getStudentName(self):
        """
         Getter method
        """
        return self.__name

    def setStudentName(self,n):
        self.__name = n

def testStudentGrade():
    sg = StudentGrade("1","FP",9)
    assert sg.getStudentID()=="1"
    assert sg.getDiscipline()=="FP"
    assert sg.getGrade()==9

testStudentGrade()