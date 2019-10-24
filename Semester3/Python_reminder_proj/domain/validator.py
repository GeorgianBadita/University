"""
    @author: Badita Marin-Georgian
    @email:  geo.badita@gmail.com
    @date:   7/23/18 19:35
"""


class ValidatorException(Exception):
    """
    Class for Raising Exceptions
    """
    def __init__(self, excs):
        self.__errs = excs

    def get_errs(self):
        """
        Returns the errors contained in __errs
        :return: a string containing errors
        """
        return self.__errs


class BookValidator:
    """
    Class to verify a book
    """

    @staticmethod
    def validate(book):
        """
        Function to validate a book
        :param book: Book type object
        :return: None
        :raise: Raise ValidatorException if the book fields are incorrect
        """
        errs = []
        if type(book.get_id()) is not int:
            errs.append("ID-ul trebuie sa fie un numar intreg!")
        if book.get_id() < 0:
            errs.append("ID-ul trebuie sa fie un numar pozitiv!")
        if book.get_writer() == "":
            errs.append("Campul autor nu poate fi gol!")
        if book.get_title() == "":
            errs.append("Campul titlu nu poate fi gol!")
        if book.get_genre() == "":
            errs.append("Campul gen nu poate fi gol!")
        if book.get_year() == "":
            errs.append("Campul an nu poate fi gol!")
        if type(book.get_year()) is not int:
            errs.append("Camoul an trebuie sa fie un numar intreg!")
        if book.get_year() < 0:
            errs.append("The year of release must be a positive integer")

        if len(errs) > 0:
            raise ValidatorException(errs)
