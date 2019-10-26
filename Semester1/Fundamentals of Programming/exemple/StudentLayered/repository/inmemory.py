from domain.entities import Student

class RepositoryException(Exception):
    pass


class InMemoryRepository:
    def __init__(self):
        self.__students = {}
        

    def store(self,st):
        """
          Store __students
          st is a student
          raise RepositoryException if we have a student with the same id
        """
        if st.getId() in self.__students:
            raise RepositoryException()
        self.__students[st.getId()] = st

    def size(self):
        """
          The number of __students in the repository
          return an integer number
        """
        return len(self.__students)
    
    def getAllStudents(self):
        """
        return a list, list of all __students in the repository
        """
        return list(self.__students.values())

def testStoreStudent():
    st = Student("1","Ion","Adr")
    rep = InMemoryRepository()
    assert rep.size()==0
    rep.store(st)
    assert rep.size()==1
    st2 = Student("2","Vasile","Adr2")
    rep.store(st2)
    assert rep.size()==2
    st3 = Student("2","Ana","Adr3")
    try:
        rep.store(st3)
        assert False
    except RepositoryException:
        pass




testStoreStudent()