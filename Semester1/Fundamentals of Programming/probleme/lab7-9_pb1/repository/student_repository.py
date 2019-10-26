"""
    @author: Badita Marin-Georgian
    @email:  geo.badita@gmail.com
    @date:   1/6/2018 22:56
"""


class StudentRepository(object):
    """
    Class for mantaining the Student Data
    """

    def __init__(self):
        self.__list = {}

    def store_st(self, student):
        """
        Function that stores a student in the memory
        :param student: -Student object
        :return:
        :raise: ValueError exception if the student is already in the list
        :post: The student will be added to the repository
        """
        if student.get_st_id() in self.__list.keys():
            raise ValueError("The student is already in the list!")
        else:
            self.__list[student.get_st_id()] = student

    def find_by_id_st(self, id_st):
        """
        Function that finds a student by a given id
        :param student:
        :return:
        """
        if id_st not in self.__list.keys():
            return None
        return self.__list[id_st]

    def delete_by_id_st(self, id_st):
        """
        Function that deletes a student by a given id
        :param id_st:
        :return:
        """
        if id_st not in self.__list.keys():
            return None

        list = self.get_all_st_rep()
        for st in list:
            if st.get_st_id() == id_st:
                to_ret = st
                del self.__list[id_st]
                return to_ret

    def update_st(self, new_student):
        """
        Function that updates a student
        :param new_student:
        :return: the new student
        :raise: ValueError if the student doesn't exists
        """
        id_st = new_student.get_st_id()
        if self.find_by_id_st(id_st) is None:
            raise ValueError("The student doesn't exists")
        else:
            self.__list[id_st] = new_student
            return new_student


    def get_all_st_rep(self):
        """
        Function that returns a list with all students
        :return: list with all students
        """
        return list(self.__list.values())
