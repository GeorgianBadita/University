"""
    @author: Badita Marin-Georgian
    @email:  geo.badita@gmail.com
    @date:   1/28/2018 14:49
"""

class Jucator(object):
    """
    Clasa pentru entitatea jucator
    """

    def __init__(self, nume, prenume, inaltime, post):
        self.__nume = nume
        self.__prenume = prenume
        self.__inaltime = inaltime
        self.__post = post

    def get_nume(self):
        """
        Getter method
        :return:
        """
        return self.__nume

    def get_prenume(self):
        """
        Getter method
        :return:
        """
        return self.__prenume

    def get_inaltime(self):
        """
        Getter method
        :return:
        """
        return self.__inaltime

    def get_post(self):
        """
        Getter method
        :return:
        """
        return self.__post

    def set_inaltime(self, new_h):
        """
        Setter method
        :param new_h:
        :return:
        """
        self.__inaltime = new_h


    def __eq__(self, other):
        return self.__prenume == other.__prenume and self.__nume == other.__nume

    def __str__(self):
        return "Nume: " + self.get_nume() + "   " + "Prenume: " + self.get_prenume() + "    " + "Inaltime: " + str(self.get_inaltime()) + "  " + "Post: " + self.get_post()

