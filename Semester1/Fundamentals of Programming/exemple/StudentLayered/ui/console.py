from services.studentservice import StudentService
from domain.entities import Student
from repository.inmemory import RepositoryException
from domain.validators import ValidatorException
class Console:
    def __init__(self, srv):
        self.__srv = srv

    def __showAllStudents(self):
        """
        View (print) all student from the catalog 
        """
        sts = self.__srv.getAllStudents()
        if len(sts) == 0:
            print("No student in the catalog")
        else:
            print("Id    Name   Adr")
        for st in sts:
            print(st.getId(), st.getName(), st.getAdr())


    def __addStudent(self):
        """
        Add student read from the console
        """
        idSt = input("Give student idSt:")
        name = input("Give student name:")
        adr = input("Give student adr:")
        try:
            st = self.__srv.createStudent(idSt, name, adr)
            print("Student " + st.getName() + " saved..")
        except RepositoryException:
            print("Duplicated student idSt")
        except ValidatorException as ex:
            print(ex.getErrors())
            
    def __showNrStudentsPerAddress(self):
        """
          Show table with address and the number of students from the same address
          For more formatting options see: https://docs.python.org/3/library/string.html#string-formatting
        """
        reportItems = self.__srv.getAggregateOnAddress()
        print("| {:^10} | {:^10} |".format("Address","Count"))
        for item in reportItems:
            print("| {:^10} | {:^10} |".format(item.getAddress(),item.getCount()))
        

    def showUI(self):
        while True:
            cmd = input("Give command (Add,View,Report):")
            if cmd == "Add":
                self.__addStudent()
            if cmd == "View":
                self.__showAllStudents()
            if cmd == "Report":
                self.__showNrStudentsPerAddress()    
