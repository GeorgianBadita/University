"""
    @author: Badita Marin-Georgian
    @email:  geo.badita@gmail.com
    @date:   7/23/18 20:26
"""


class RepositoryException(Exception):
    """
    Class for Repository Exception
    """
    pass


class Repository:
    """
    Class for representing Repository
    """
    def __init__(self, val):
        self.__val = val
        self.__lst = {}

    def store_book(self, book):
        """
        Function to store a new book into the library
        :param book: Book type object
        :return: None
        :raise: RepositoryException if the book already exists
        """
        lst = self.__lst.keys()
        if book.get_id() in lst:
            raise RepositoryException()
        else:
            id_book = len(self.__lst.keys()) + 2
            for num in range(0, len(self.__lst.keys()) + 1):
                if num not in self.__lst.keys():
                    id_book = num
                    break
            if id_book != len(self.__lst.keys()) + 2:
                book.set_id(id_book)
                self.__val.validate(book)
                self.__lst[id_book] = book

    def search_book(self, book_id):
        """
        Function to search a book
        :param book_id: id of the book to search
        :return: the book if it exists, None otherwise
        """
        for key in self.__lst.keys():
            if key == book_id:
                return self.__lst[key]

        return None

    def delete_book(self, book_id):
        """
        Function to delete a book
        :param book_id: id of the book to delete
        :return: the book if it exists, false otherwise
        """
        searched = self.search_book(book_id)
        if searched is None:
            return None
        else:
            to_del = self.__lst[book_id]
            del self.__lst[book_id]
            return to_del

    def update_book(self, book_id, book):
        """
        Function to update a book
        :param book: the new book
        :param book_id: id of the old book
        :return: the new book if it exists, false otherwise
        """
        searched = self.search_book(book_id)
        if searched is None:
            return None
        else:
            for b in self.__lst.values():
                if b.get_id() == book_id:
                    del self.__lst[book_id]
                    break
            self.store_book(book)
            return book

    def get_all(self):
        """
        Function to return a list with all the books
        :return: a list containing all the books stored in repository
        """
        return list(self.__lst.values())

    def get_keys(self):
        """
        Function to return a list with all the keys
        :return: a list containing all the keys stored in repository
        """
        return self.__lst.keys()