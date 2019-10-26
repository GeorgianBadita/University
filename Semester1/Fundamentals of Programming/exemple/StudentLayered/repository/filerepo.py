from repository.inmemory import InMemoryRepository
from domain.entities import Student
from utils.fileutils import clearFileContent
class StudentRepositoryFile(InMemoryRepository):
    """
      Responsible with the load/store of students from/into a text file
      Include different version of:
           reading from the file
           accessing base class attributes (fields/methods)
      
    """
    def __init__(self,fileName):
        #invoke base class __init__ method
        InMemoryRepository.__init__(self)
        self.__fileName = fileName
        #load __students from the file
        self.__loadFromFile2()

    def __createStudentFromLine(self, line):
        """
        Process the a line from the file and create a student
        return student
        """
        fields = line.split(" ")
        st = Student(fields[0], fields[1], fields[2])
        return st


    def __loadFromFile(self):
        """
         Load student from file
         Load file at once
        """
        fh = open(self.__fileName)
        #read in the entire file
        content = fh.read()
        fh.close()
        lines = content.split('\n')
        for line in lines:
            if line.strip()=="":
                continue#we have an empty line, just skip
            st = self.__createStudentFromLine(line)
            #we have access to the fields from the base class
            self.__students[st.getId()] = st

    def __loadFromFile2(self):
        """
          Load __students from file
          process file line by line
        """
        fh = open(self.__fileName)
        for line in fh:
            if line.strip()=="":
                continue#we have an empty line, just skip
            st = self.__createStudentFromLine(line)
            #invoke the store method from the base class
            InMemoryRepository.store(self, st)
        fh.close()
        
    def store(self,st):
        #invoke store method from the base class
        InMemoryRepository.store(self, st)
        self.__appendToFile(st)

    def __appendToFile(self,st):
        """
          Append a new line in the file representing the student st
        """
        fh = open(self.__fileName,"a")
        line = st.getId()+" "+st.getName()+" "+st.getAdr()
        fh.write("\n")
        fh.write(line)
        fh.close()




def testRepo():
    fileName = "test.txt"
    #make sure wi start with an empty file
    clearFileContent(fileName)
    repo = StudentRepositoryFile(fileName)
    assert repo.size()==0
    repo.store(Student("9","Ion2","Adr2"))
    assert repo.size()==1


def testRead():
    fileName = "c:/temp/test.txt"
    #make sure wi start with an empty file
    clearFileContent(fileName)
    
    repo = StudentRepositoryFile(fileName)
    repo.store(Student("8","Ion1","Adr1"))
    repo.store(Student("9","Ion2","Adr2"))
    
    repo2 = StudentRepositoryFile(fileName)
    assert repo2.size()==2

testRepo()
testRead()