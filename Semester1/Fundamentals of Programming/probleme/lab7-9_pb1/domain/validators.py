"""
    @author: Badita Marin-Georgian
    @email:  geo.badita@gmail.com
    @date:   1/6/2018 22:21
"""

class ValidatorException(Exception):
    """
    Class for handling Exceptions
    """
    def __init__(self, exceptions):
        self.errors = exceptions

    def get_errors(self):
        """
        Getter method
        :return: all the exceptions
        """
        return self.errors


class StudentValidator(object):
    """
    Class to validate a student
    """

    @staticmethod
    def validate(student):
        """
        Validation Function
        :return: None if there are no exceptions, throws exceptions otherwise
        """
        errors = []
        id_st = student.get_st_id()
        name = student.get_st_name()
        if id_st == "": errors.append("The id can't be empty!")
        if name == "": errors.append("The name can't be empty")
        if len(id_st) != 5: errors.append("There must be 5 characters in id!")
        if id_st[0:2].isalpha() is not True: errors.append("The first 2 characters from the id must be digits!")
        if id_st[2:5].isdecimal() is not True: errors.append("The last 3 characters from the id must be letters!")


        if len(errors) > 0:
            raise ValidatorException(errors)


class DisciplineValidator(object):
    """
    Class to validate a discipline
    """

    @staticmethod
    def validate(discipline):
        """
        Validation Function
        :return: None if there are no exceptions, throws exceptions otherwise
        """
        errors = []
        id_disc = discipline.get_dis_id()
        name = discipline.get_dis_name()
        if id_disc == "": errors.append("The id can't be empty!")
        if name == "": errors.append("The name can't be empty!")
        if id_disc.isdecimal() is False: errors.append("The id must contain only digits!")
        if len(errors) > 0:
            raise ValidatorException(errors)