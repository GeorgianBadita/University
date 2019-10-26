"""
    @author: Badita Marin-Georgian
    @email:  geo.badita@gmail.com
    @date:   1/6/2018 22:56
"""


class DisciplineRepository(object):
    """
    Class for mantaining the Discipline Data
    """

    def __init__(self):
        self.__list = {}

    def store_disc(self, discipline):
        """
        Function that stores a discipline in the memory
        :param discipline: -Student object
        :return:
        :raise: ValueError exception if the discipline is already in the list
        :post: The student will be added to the repository
        """
        if discipline.get_dis_id() in self.__list.keys():
            raise ValueError("The discipline is already in the list!")
        else:
            self.__list[discipline.get_dis_id()] = discipline

    def find_by_id_disc(self, id_disc):
        """
        Function that finds a student by a given id
        :param id_disc:
        :return:
        """
        if id_disc not in self.__list.keys():
            return None
        return self.__list[id_disc]

    def delete_by_id_disc(self, id_disc):
        """
        Function that deletes a student by a given id
        :param id_disc:
        :return:
        """
        if id_disc not in self.__list.keys():
            return None

        list = self.get_all_disc_rep()
        for disc in list:
            if disc.get_dis_id() == id_disc:
                to_ret = disc
                del self.__list[id_disc]
                return to_ret

    def get_all_disc_rep(self):
        """
        Function that returns a list with all disciplines
        :return: list with all disciplines
        """
        return list(self.__list.values())
