
from domain.entities import Student
from domain.entities import Address
from domain.entities import Grade

class StudentCRUDException(Exception):
    pass

class ValidationException(StudentCRUDException):
    def __init__(self,msgs):
        """
         Initialise
         msg is a list of strings (errors)
        """
        self.__msgs = msgs
    def getMsgs(self):
        return self.__msgs

    def __str__(self):
        return str(self.__msgs)

class StudentValidator:
    """
      Class responsible with the validation for students
      GRASP - Protect Variation

    """
    def __init__(self):
        pass

    def validate(self,st):
        """
          Validate student
          raise ValidationException if id, name, or addres is empty
        """
        errorMsg = []
        if st.getId()=="":
            errorMsg.append("Id can not be empty")
        if st.getName()=="":
            errorMsg.append("Name can not be empty")
        if st.getAdr()==None or st.getAdr().getStreet()=="":
            errorMsg.append("Address can not be empty")
        #if there is a validation error throw exception
        if errorMsg!=[]:
            raise ValidationException(errorMsg)

def testValidateStudent():
    """
      Testing method for validate
      Feature 1 - add a student
      Task2 - Validate Student
    """
    val = StudentValidator()
    #student invalid if id is empty
    st = Student("", "Ion", Address("Adr",1,"Cluj"))
    try:
        val.validate(st)
        assert False
    except ValidationException:
        assert True

    #student invalid if name is empty
    st = Student("3", "", Address("Adr",1,"Cluj"))
    try:
        val.validate(st)
        assert False
    except ValidationException:
        assert True

    #student invalid if adr is empty
    st = Student("3", "Ion", Address("",1,"Cluj"))
    try:
        val.validate(st)
        assert False
    except ValidationException:
        assert True

testValidateStudent()

class GradeValidator:
    """
     Validator for grades
    """
    def validate(self,gr):
        """
         Validate grade
         gr Grade
         raise ValidateException if the grade is not between 0 and 10
        """
        if gr.getGrade()<=0 or gr.getGrade()>10:
            raise ValidationException("Grade need to be between 0 and 10")


def testValidateGrade():
    st = Student("1", "Ion", Address("Adr", 1, "Cluj"))
    gr = Grade(st, "FP", 11)
    val = GradeValidator()
    try:
        val.validate(gr)
        assert False
    except ValidationException:
        assert True

testValidateGrade()