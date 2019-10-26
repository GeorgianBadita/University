from domain.entities import Student
from repository.inmemory import InMemoryRepository
from repository.inmemory import RepositoryException
from domain.validators import StudentValidator
from itertools import count
from domain.datatransfer import AddressReportItem


class StudentService:
    def __init__(self,rep,val):
        """
          Initialise service
          rep - reposirory - object to store students
          val - validator - object to validate students
        """
        self.__rep = rep
        self.__val = val

    def createStudent(self,idst,name,adr):
        """
          store a student
          idst, name, address of the student as strings
          return the Student
          Post: student added to the repository
          raise RepositoryExeption - if student already exist
          raise ValidationException - if student fields are invalid
        """
        #create student object
        st = Student(idst,name,adr)
        #validate student using a validator object
        self.__val.validate(st)
        #store student into using repository
        self.__rep.store(st)
        
        return st

    
    def getAllStudents(self):
        """
        return list of all students in the system
        """
        return self.__rep.getAllStudents()
    
    def getAggregateOnAddress(self):
        """
          Count the number of students for each address
          return list of ReportItem s
        """
        countDic = {}
        for st in self.__rep.getAllStudents():
            addr = st.getAdr()
            if addr in countDic:
                countDic[addr].incCount()
            else:
                countDic[addr] = AddressReportItem(addr,1)
        return list(countDic.values())

def tesCreateStudent():
    rep = InMemoryRepository()
    val = StudentValidator()
    srv = StudentService(rep,val)
    st = srv.createStudent("1","Ion","Adr")
    assert st.getId()=="1"
    assert st.getName()=="Ion"
    allSts = srv.getAllStudents()
    assert len(allSts)==1
    assert allSts[0]==st
    
    try:
        st = srv.createStudent("1","Vasile","Adr")
        assert False
    except RepositoryException:
        assert True

tesCreateStudent()

def testReportAddress():
    rep = InMemoryRepository()
    val = StudentValidator()
    srv = StudentService(rep,val)
    srv.createStudent("1","Ion","Cluj")
    srv.createStudent("2","Ion2","Cluj")
    srv.createStudent("3","Ion3","Oradea")
    srv.createStudent("4","Ion4","Carei")
    reportItems = srv.getAggregateOnAddress()
    assert len(reportItems)==3
    
testReportAddress()