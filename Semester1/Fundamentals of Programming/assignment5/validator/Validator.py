class ValidatorException(Exception):
    '''
    class for all exceptions regarding validation of input data
    '''
    def __init__(self, message):
        self.__message = message

    def get_message(self):
        return self.__message

    def __str__(self):
        result = ""
        for msg in self.get_message(): result = result + msg + "\n"
        return result


class StudentValidator:
    '''
    class for validating input data of a new student
    '''
    @staticmethod
    def validate_student(student):
        exceptions = []
        if student.student_id() == "":
            exceptions.append("A student must have an ID! ")
        if student.student_name() == "":
            exceptions.append("A student must have a name! ")
        if not student.student_id() == "" and not isinstance(student.student_id(), int):
            exceptions.append("An ID must be an integer! ")
        if len(exceptions) > 0:
            raise ValidatorException(exceptions)
        else:
            return True


class DisciplineValidator:
    '''
    class for validating input data of a new discipline
    '''

    @staticmethod
    def validate_discipline(discipline):
        exceptions = []
        if discipline.discipline_id() == "":
            exceptions.append("A discipline must have an ID! ")
        if discipline.discipline_name() == "":
            exceptions.append("A discipline must have a name! ")
        if not discipline.discipline_id() == "" and not isinstance(discipline.discipline_id(), int):
            exceptions.append("An ID must be an integer! ")
        if len(exceptions) > 0:
            raise ValidatorException(exceptions)
        else:
            return True


class GradeValidator:
    '''
    class for validating input data of a new grade
    '''

    @staticmethod
    def validate_grade(grade):
        exceptions = []
        if str.isalpha(str(grade.grade_value())):
            exceptions.append("A grade must be a number. ")
        elif float(grade.grade_value()) < 0.0 or float(grade.grade_value()) > 10.0:
            exceptions.append("Invalid grade. ")
        if len(exceptions) > 0:
            raise ValidatorException(exceptions)
        else:
            return True
