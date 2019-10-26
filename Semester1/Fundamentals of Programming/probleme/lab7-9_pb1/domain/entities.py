"""
    @author: Badita Marin-Georgian
    @email:  geo.badita@gmail.com
    @date:   1/6/2018 22:21
"""
class Student(object):
    """
    Class for Student object
    """

    def __init__(self, id_student, name_student):
        """
        Function that initialize a student
        :param id_student: string 2-letters, 3 digits
        :param name_student: string
        """
        self.__id_student = id_student
        self.__name_student = name_student

    def get_st_id(self):
        """
        Getter method
        :return: the id of the student
        """
        return self.__id_student

    def get_st_name(self):
        """
        Getter method
        :return: the name of the student
        """

        return self.__name_student
    def __str__(self):
        return "Stud id: " + self.__id_student + "   Name:" + self.__name_student + "\n"


class Discipline(object):
    """
    Class for the Discipline object
    """

    def __init__(self, id_discipline, name_discipline, professor):
        """
        Function that initialize a Discipline
        :param id_discipline:
        :param name_discipline:
        :param professor:
        """
        self.__id_discipline = id_discipline
        self.__name_discipline = name_discipline
        self.__professor = professor

    def get_dis_id(self):
        """
        Getter method
        :return: the id of the discipline
        """
        return self.__id_discipline

    def get_dis_name(self):
        """
        Getter method
        :return: the name of the discipline
        """
        return self.__name_discipline

    def get_dis_prof(self):
        """
        Getter method
        :return: the professor of the discipline
        """
        return self.__professor

    def __str__(self):
        return "Disc id: " + self.__id_discipline + "   Name:" + self.__name_discipline + "    Professor: " + self.__professor + "\n"
