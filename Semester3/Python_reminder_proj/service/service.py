"""
    @author: Badita Marin-Georgian
    @email:  geo.badita@gmail.com
    @date:   7/23/18 21:25
"""

from repository.repository import Repository
from domain.book import Book
from domain.undo import *

class Service:
    """
    Class for representing our Service
    """
    def __init__(self, repo):
        self.__repo = repo
        self.__undo = []

    def get_all_srv(self):
        """
        Function to return all the books stored in repository
        :return: a list containing all the books stored in repository
        """
        return self.__repo.get_all()

    def add_book(self, title, writer, genre, year):
        """
        Function to add a book into the repository
        :param title: title of the book
        :param writer: writer of the book
        :param genre: genre of the book
        :param year: year of release
        :return: the newly added book
        """
        book = Book(title, writer, genre, year)
        self.__undo.append(UndoAdd(self.__repo, book))
        self.__repo.store_book(book)
        return book

    def remove_book(self, book_id):
        """
        Function to remove a book by giving its id
        :param book_id: the id of the book to be removed
        :return: the removed book if it exists, None otherwise
        """
        to_ret = self.__repo.delete_book(book_id)
        if to_ret is not None:
            self.__undo.append(UndoDel(self.__repo, to_ret))
        return to_ret

    def modify_book(self, book_id, title, writer, genre, year):
        """
        Function to modify a book by giving the old book's id and the new book
        :param book_id: id of the old book
        :param title: title of the book
        :param writer: writer of the book
        :param genre: genre of the book
        :param year: year of release
        :return: the new book if the old book exists, None otherwise
        """
        book = Book(title, writer, genre, year)
        to_ret = self.__repo.update_book(book_id, book)
        if to_ret is not None:
            self.__undo.append(UndoUpd(self.__repo, book_id, to_ret))
        return to_ret

    def filter_by_title(self, title):
        """
        Function to filter all the books by a given title
        :param: title - title to filter by
        :return: a list containing all the books with the given title
        """
        to_return = []
        for book in self.__repo.get_all():
            if book.get_title() == title:
                to_return.append(book)

        return to_return

    def filter_by_year(self, year):
        """
        Function to filter all the books by a given year of release
        :param: year - year to filter by
        :return: a list containing all the books with the given year
        """
        to_return = []
        for book in self.__repo.get_all():
            if book.get_year() == year:
                to_return.append(book)

        return to_return

    def sort_by_title(self, reverse):
        """
        Function to sort all books by title
        :param: reverse - boolean tells to sort ascending or descending
        True for descending, False for ascending
        :return: a list containing books sorted by title
        """

        to_sort = self.__repo.get_all()
        to_sort = sorted(to_sort, key=lambda x: x.get_title(), reverse=reverse)

        return to_sort

    def sort_by_year(self, reverse):
        """
        Function to sort all books by year
        :param: reverse - boolean tells to sort ascending or descending
        True for descending, False for ascending
        :return: a list containing books sorted by year
        """

        to_sort = self.__repo.get_all()
        to_sort = sorted(to_sort, key=lambda x: x.get_year(), reverse=reverse)

        return to_sort

    def sort_by_writer(self, reverse):
        """
        Function to sort all books by writer
        :param: reverse - boolean tells to sort ascending or descending
        True for descending, False for ascending
        :return: a list containing books sorted by year
        """

        to_sort = self.__repo.get_all()
        to_sort = sorted(to_sort, key=lambda x: x.get_writer(), reverse=reverse)

        return to_sort

    def sort_by_genre(self, reverse):
        """
        Function to sort all books by genre
        :param: reverse - boolean tells to sort ascending or descending
        True for descending, False for ascending
        :return: a list containing books sorted by genre
        """

        to_sort = self.__repo.get_all()
        to_sort = sorted(to_sort, key=lambda x: x.get_genre(), reverse=reverse)

        return to_sort

    def undo_srv(self):
        """
        Function to execute an undo
        :return: None
        """

        if len(self.__undo) > 0:
            to_undo = self.__undo.pop()
            to_undo.do_undo()
