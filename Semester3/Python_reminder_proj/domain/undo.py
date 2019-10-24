"""
    @author: Badita Marin-Georgian
    @email:  geo.badita@gmail.com
    @date:   7/26/2018 23:45
"""


class UndoAdd:
    """
    Class for representing undo add Operation
    """

    def __init__(self, repo, book):
        self.__repo = repo
        self.__book = book

    def do_undo(self):
        """
        Function to undo a add operation
        :return:
        """
        self.__repo.delete_book(self.__book.get_id())


class UndoDel:
    """
    Class for representing undo delete Operation
    """

    def __init__(self, repo, book):
        self.__repo = repo
        self.__book = book

    def do_undo(self):
        """
        Function to undo a add operation
        :return:
        """
        self.__repo.store_book(self.__book)


class UndoUpd:
    """
    Class for representing undo update Operation
    """

    def __init__(self, repo, book_id, book):
        self.__repo = repo
        self.__book_id = book_id
        self.__book = book

    def do_undo(self):
        """
        Function to undo a add operation
        :return:
        """
        self.__repo.update_book(self.__book_id, self.__book)