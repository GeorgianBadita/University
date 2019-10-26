class Student:
    def __init__(self, idst, name, adr):
        """
         Create a new student withn the given idst, name and adress
         idst, name, address are Strings
        """
        self.__id = idst
        self.__name = name
        self.__adr = adr

    def getId(self):
        return self.__id

    def getName(self):
        return self.__name

    def getAdr(self):
        return self.__adr

    def __eq__(self,st):
        """
        Verify equality
        st - student
        return True if the curent student equals with st (have the same id)
        """
        return self.getId()==st.getId()
    
def testCreateStudent():
    """
      Testing student creation
    """
    st = Student("1", "Ion", "Adr")
    assert st.getId() == "1"
    assert st.getName() == "Ion"
    assert st.getAdr() == "Adr"

def testEqual():
    st1 = Student("1", "Ion", "Adr")
    st2 = Student("1", "Ion", "Adr")
    assert st1==st2
    
testCreateStudent()
testEqual()