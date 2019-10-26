"""
    @author: Badita Marin-Georgian
    @email:  geo.badita@gmail.com
    @date:   1/6/2018 23:33
"""
from domain.entities import Student
from domain.validators import StudentValidator, ValidatorException


class StudentService(object):
    """
    Class for controlling student actions
    """

    def __init__(self, repo):
        self.__repo = repo

    def create_student(self, id_st, name_st):
        """
        Function that creates a student, validates it and save it to memory
        :param id_st: id of the student
        :param name_st: name of the student
        :return: the created student
        :raise: ValidatorException if the student is not given correctly, or ValueError
        if the student is already in the list
        """
        st = Student(id_st, name_st)
        val_st = StudentValidator()
        try:
            val_st.validate(st)
            self.__repo.store_st(st)
            return st
        except ValidatorException as ex:
            print(*ex.get_errors())
        except ValueError as ex:
            print(ex)

    def find_student(self, id_student):
        """
        Function that finds a student if it exists and returns it, else returns None
        :param id_student:
        :return:
        """
        return self.__repo.find_by_id_st(id_student)

    def delete_student(self, id_student):
        """
        Function that deletes a student if it exists and returns it, else returns None
        :param id_student:
        :return:
        """
        return self.__repo.delete_by_id_st(id_student)

    def update_student(self, id_st, name_st):
        """
        Function that updates a student
        :return: the new student if the update was correctly made
        :raise: ValueError if the student doesn't exists
        """
        try:
            new_student = Student(id_st, name_st)
            return self.__repo.update_st(new_student)
        except ValidatorException as ex:
            print(*ex.get_errors())
        except ValueError as ex:
            print(ex)

    def get_all_st(self):
        """
        Function that returns a list with all students in the memory
        :return:
        """
        return self.__repo.get_all_st_rep()
