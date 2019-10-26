from domain.entities import Student

class ValidatorException(Exception):
    def __init__(self, errors):
        self.errors = errors

    def getErrors(self):
        return self.errors


class StudentValidator:

    def validate(self, st):
        """
        throw ValidatorException if fields are empty
        """
        errors = []
        if (st.getId()==""): errors.append("Id can not be empty!")
        if (st.getName()==""): errors.append("Name can not be empty!")
        if (st.getAdr()==""): errors.append("Address can not be empty!")
        if len(errors)>0:
            raise ValidatorException(errors)


def testStudentValidator():
    validator = StudentValidator()

    st = Student("", "", "")
    try:
        validator.validate(st)
        assert False
    except ValidatorException as ex:
        assert len(ex.getErrors())==3
    
    st = Student("IO231", "", "")
    try:
        validator.validate(st)
        assert False
    except ValidatorException as ex:
        assert len(ex.getErrors())==2
    
    st = Student("IO23", "Ion", "Cj")
    try:
        validator.validate(st)
        assert True
    except ValidatorException as ex:
        assert False

testStudentValidator()