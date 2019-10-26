from domain.validators import StudentValidator
from domain.validators import StudentCRUDException
from repository.inmemory import StudentRepository
from repository.inmemory import GradeRepository
from repository.inmemory import DuplicatedIDException
from domain.entities import Student
from domain.entities import Address
from domain.entities import Grade
from domain.validators import ValidationException
from domain.validators import GradeValidator


class StudentService:
    """
      Class responsible with the use cases related to Student CRUD
      GRASP Controller
    """
    def __init__(self, val, repo):
        """
          Initialise the controller,
          controller need a validator and a repository to perform the operations
          val - StudentValidator (injected)
          repo - StudentRepository (injected
        """
        self.__val = val
        self.__repo = repo

    def create(self, id, name, street, nr, city):
        """
          Create validate and store a student
          id,name, street,city- strings
          nr - int
          return Student
          raise ValueEror if the data is invalid, on duplicated id
        """
        #create Student instance
        st = Student(id, name, Address(street, nr, city))
        #validate, raise exception if student is invalid
        self.__val.validate(st)
        #store the student, raise exception if duplicated id
        self.__repo.store(st)
        return st

    def getNrStudents(self):
        """
          Return the number of students
          return int
        """
        return self.__repo.size()

    def remove(self, id):
        """
         Remove student with the given id
         id - string, student id
         return Student, the removed Student
         raise ValueError if there is no student with the given id
        """
        return self.__repo.remove(id)
    def search(self, criteria):
        """
          Search students with name containing criteria
          criteria string
          return list of students, where the name contains criteria
        """
        all = self.__repo.getAll()
        if criteria=="":
            return all

        rez = []
        for st in all:
            if criteria in st.getName():
                rez.append(st)
        return rez

    def update(self, id, name, street, nr, city):
        """
          Update student with the given id
          id,name, adr strings
          return the old student
          raise ValueError if the student is invalid, if there is no student with the given id
        """
        newSt = Student(id, name, Address(street, nr, city))

        #validate the student
        self.__val.validate(newSt)

        #get the old student
        oldSt = self.__repo.find(id)

        #update the student
        self.__repo.update(id, newSt)
        return oldSt


def testCreateStudent():
    """
     test function for create student
     Feature 1 - add a student
     Task 4 - Create student - controller
    """
    #create the controller and inject the validator and repository
    ctr =  StudentService(StudentValidator(), StudentRepository())
    st = ctr.create("1", "Ion", "Adr", 1, "Cluj")
    assert st.getId()=="1"
    assert st.getName()=="Ion"
    assert st.getAdr().getStreet()=="Adr"
    assert ctr.getNrStudents()==1
    #test for an invalid student
    try:
        ctr.create("1", "", "", 1, "Cluj")
        assert False
    except ValidationException:
        assert True
    #test for duplicated id
    try:
        ctr.create("1", "Ion2", "Adr2", 1, "Cluj")
        assert False
    except DuplicatedIDException:
        assert True


testCreateStudent()

def testRemoveStudent():
    """
      Test function for remove
      Feature 2 - remove student
      Task 2 - remove student controller
    """
    ctr =  StudentService(StudentValidator(), StudentRepository())
    st = ctr.create("1", "Ion", "Adr", 1, "Cluj")
    #test for an invalid id
    try:
        ctr.remove("2")
        assert False
    except ValueError:
        assert True
    assert ctr.getNrStudents()==1

    st = ctr.remove("1")
    assert ctr.getNrStudents()==0
    assert st.getId()=="1"
    assert st.getName()=="Ion"
    assert st.getAdr().getStreet()=="Adr"



testRemoveStudent()

def testSearchCriteria():
    """
      test first search
      Feature 3 - List students for a criteria
      Task 2 - all students where the name contains a given string
    """
    rep = StudentRepository()
    ctr =  StudentService(StudentValidator(), rep)
    st = ctr.create("1", "Ion", "Adr", 1, "Cluj")
    st2 = ctr.create("2", "Ion2", "Adr", 1, "Cluj")
    st = ctr.create("3", "Ioana1", "Adr", 1, "Cluj")
    st4 = ctr.create("4", "Ioana2", "Adr", 1, "Cluj")
    st = ctr.create("5", "Vlad", "Adr", 1, "Cluj")

    studs = ctr.search("Ion")
    assert len(studs)==2
    assert st2 in studs

    studs = ctr.search("Io")
    assert len(studs)==4
    assert st4 in studs

    studs = ctr.search("Al")
    assert len(studs)==0

    #for empty string
    studs = ctr.search("")
    assert len(studs)==5


testSearchCriteria()

def testUpdate():
    """
     test function for update
     Feature 4 - update a student information
     Task 2 - update student - controller
    """
    ctr =  StudentService(StudentValidator(), StudentRepository())
    st = ctr.create("1", "Ion", "Adr", 1, "Cluj")
    st = ctr.update("1", "Ionel", "Addrr", 1, "Cluj")

    studs = ctr.search("Ionel")
    assert len(studs)==1
    assert studs[0].getAdr().getStreet()=="Addrr"
    #verify if the old student is returned
    assert st.getName()=="Ion"
    assert st.getAdr().getStreet()=="Adr"

    #try to opdate an inexistend student
    try:
        st = ctr.update("2", "Ionel", "Addrr", 1, "Cluj")
        assert False
    except ValueError:
        assert True

    #try to update to invalid data
    try:
        ctr.update("1", "", "", 1, "Cluj")
        assert False
    except ValidationException:
        assert True

testUpdate()

class StudentNotFoundException(StudentCRUDException):
    def __init__(self):
        pass

class GradingService:
    def __init__(self,grRep,grVal,stRep):
        """
          Initialise
          grRep - GradeRepository
          grVal - GradeValidator
          stRep - StudentRepository
        """
        self.__grRep = grRep
        self.__grVal = grVal
        self.__stRep = stRep
    def assign(self,stId,disc,grade):
        """
          Assign a grade for a student at a given discipline
          stID String, id of the student
          disc String, discipline
          grade double, grade
          post: the grade is stored
          return Grade
          raise ValidateException for invalid grade
                StudentNotFound if there is no student for the given id
        """
        #lookup student
        st = self.__stRep.find(stId)
        if st==None:
            raise StudentNotFoundException()
        gr = Grade(st,disc,grade)
        #validate grade
        self.__grVal.validate(gr)
        #store grade
        self.__grRep.store(gr)
        return gr

    def listGrades(self,stId):
        """
         Get all the grades of a student
         stID student id
         return list of Grades
         raise StudentNotFound if there is no student for the given id
        """
        #lookup student
        st = self.__stRep.find(stId)
        if st==None:
            raise StudentNotFoundException()
        return self.__grRep.getAll(st)

    def getTop5(self,disc):
        """
          Get the best 5 students at a given discipline
          disc - string, discipline
          return list of StudentGrade ordered descending on the grade
        """
        sds = self.__grRep.getAllForDisc(disc)
        #order based on the grade
        sortedsds = sorted(sds, key=lambda studentGrade: studentGrade.getGrade(),reverse=True)
        #retain only the first 5
        sortedsds = sortedsds[:5]
        #obtain the student names
        for sd in sortedsds:
            st = self.__stRep.find(sd.getStudentID())
            sd.setStudentName(st.getName())
        return sortedsds


def testAssignGrade():
    stRep = StudentRepository()
    stctr =  StudentService(StudentValidator(), stRep)
    st = stctr.create("1", "Ion", "Adr", 1, "Cluj")
    ctr = GradingService(GradeRepository(), GradeValidator(), stRep)

    gr = ctr.assign("1", "FP", 10)
    assert gr.getDiscipline()=="FP"
    assert gr.getGrade()==10
    assert gr.getStudent().getId()=="1"
    assert gr.getStudent().getName()=="Ion"

testAssignGrade()

def testListGrade():
    stRep = StudentRepository()
    stctr =  StudentService(StudentValidator(), stRep)
    st = stctr.create("1", "Ion", "Adr", 1, "Cluj")

    ctr = GradingService(GradeRepository(), GradeValidator(), stRep)
    gr = ctr.assign("1", "FP", 10)
    grs = ctr.listGrades("1")
    assert len(grs)==1
    gr = ctr.assign("1", "SO", 10)
    grs = ctr.listGrades("1")
    assert len(grs)==2

testListGrade()

def testListFirst5():
    stRep = StudentRepository()
    stctr =  StudentService(StudentValidator(), stRep)
    st = stctr.create("1", "Ion", "Adr", 1, "Cluj")
    st = stctr.create("2", "Ion2", "Adr", 1, "Cluj")
    st = stctr.create("3", "Ion3", "Adr", 1, "Cluj")
    st = stctr.create("4", "Ion4", "Adr", 1, "Cluj")
    st = stctr.create("5", "Ion5", "Adr", 1, "Cluj")
    st = stctr.create("6", "Ion6", "Adr", 1, "Cluj")

    ctr = GradingService(GradeRepository(), GradeValidator(), stRep)
    gr = ctr.assign("1", "FP", 9.5)
    gr = ctr.assign("2", "FP", 7)
    gr = ctr.assign("3", "FP", 8)
    gr = ctr.assign("4", "FP", 10)
    gr = ctr.assign("5", "FP", 6)
    gr = ctr.assign("6", "FP", 9)

    stgrs=ctr.getTop5("FP")
    assert len(stgrs)==5
    assert stgrs[0].getStudentID()=="4"
    assert stgrs[1].getStudentID()=="1"
    assert stgrs[2].getStudentID()=="6"
    assert stgrs[3].getStudentID()=="3"
    assert stgrs[4].getStudentID()=="2"

testListFirst5()


