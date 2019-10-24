"""
    @author: Badita Marin-Georgian
    @email:  geo.badita@gmail.com
    @date:   7/23/18 19:07
"""


class Book:
    """
    Book constructor function
    :param: title - string - title of the book
    :param: writer - writer of the book
    :param: genre - genre of the book
    :param: year - year of release
    """
    def __init__(self, title, writer, genre, year):
        self.__title = title
        self.__writer = writer
        self.__genre = genre
        self.__year = year
        self.__id = None

    """
    Getter methods
    """
    def get_title(self):
        return self.__title

    def get_writer(self):
        return self.__writer

    def get_genre(self):
        return self.__genre

    def get_year(self):
        return self.__year

    def get_id(self):
        return self.__id

    """
    Setters methods
    """
    def set_title(self, new_title):
        if type(new_title) is str:
            self.__title = new_title
        else:
            raise TypeError("Title must be a string")

    def set_writer(self, new_writer):
        if type(new_writer) is str:
            self.__writer = new_writer
        else:
            raise TypeError("Writer must be a string")

    def set_genre(self, new_genre):
        if type(new_genre) is str:
            self.__genre = new_genre
        else:
            raise TypeError("Genre must be a string")

    def set_year(self, new_year):
        if type(new_year) is int:
            self.__year = new_year
        else:
            raise TypeError("Year must be integer")

    def set_id(self, new_id):
        if type(new_id) is int:
            self.__id = new_id
        else:
            raise TypeError("ID must be integer")

    def __str__(self):
        """
        Overloading string operator
        :return: string form of a Book object
        """
        return "ID: " + str(self.__id) + "   " + "Titlu: " + self.__title + "   " + "Autor: " +\
               self.__writer + "   " + "Gen: " + self.__genre + "  " + "An: " + str(self.__year)

    def __eq__(self, other):
        """
        Overloading == operator
        :param other: Other Book object
        :return: True if the books are equal, false otherwise
        """
        if other is None:
            return False
        if self.__id is None or other.get_id() is None:
            return self.__title == other.get_title() and self.__writer == other.get_writer() and self.__genre == other.get_genre() and self.__year == other.get_year()
        else:
            return self.__id == other.get_id()
