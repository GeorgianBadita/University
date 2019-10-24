"""
    @author: Badita Marin-Georgian
    @email:  geo.badita@gmail.com
    @date:   7/25/18 21:26
"""
from domain.book import Book
from repository.repository import RepositoryException

class FileRepository:
    """
    Class for representing our File based Repository
    """
    def __init__(self, val, path):
        self.__val = val
        self.__f_name = path

    def __load_from_file(self):
        """
        Function which loads all the books from the file
        :return: a list containing all the books from the file
        """
        try:
            f = open(self.__f_name, "r")
        except IOError:
            print(self.__f_name)
            #file not exists
            return

        line = f.readline().strip()
        books = []
        while line != "":
            comp = line.split(":")
            book = Book(comp[1], comp[2], comp[3], int(comp[4]))
            book.set_id(int(comp[0]))
            books.append(book)
            line = f.readline().strip()

        f.close()
        return books

    def __write_to_file(self, lst):
        """
        Function which writes a list of books into the file
        :param: lst - a list containing Book type objects
        :return:
        """
        #open file (rewrite file)
        with open(self.__f_name, "w") as f:
            for book in lst:
                book_rf = str(book.get_id()) + ":" + book.get_title() + ":" + book.get_writer() + ":" + book.get_genre() + ":" + str(book.get_year()) + "\n"
                f.write(book_rf)

    def store_book(self, book):
        """
        Function to store a new book into the library
        :param book: Book type object
        :return: None
        :raise: RepositoryException if the book already exists
        """
        lst = self.__load_from_file()
        if book.get_id() in lst:
            raise RepositoryException()
        else:
            id_book = len(lst) + 2
            for num in range(0, len(lst) + 1):
                ids = []
                for b in lst:
                    ids.append(b.get_id())
                if num not in ids:
                    id_book = num
                    break
            if id_book != len(lst) + 2:
                book.set_id(id_book)
                self.__val.validate(book)
                lst.append(book)
                self.__write_to_file(lst)

    def search_book(self, book_id):
        """
        Function to search a book
        :param book_id: id of the book to search
        :return: the book if it exists, None otherwise
        """

        lst = self.__load_from_file()
        for key in lst:
            if key.get_id() == book_id:
                return key

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
            to_del = None
            lst = self.__load_from_file()
            for i in range(0, len(lst)):
                if lst[i].get_id() == book_id:
                    to_del = lst[i]
                    del lst[i]
                    break
            self.__write_to_file(lst)
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
            self.delete_book(book_id)
            self.store_book(book)
            return book

    def get_all(self):
        """
        Function to return a list with all the books
        :return: a list containing all the books stored in repository
        """
        return self.__load_from_file()

    def clear_file(self):
        """
        Function to clear the file
        :return: None
        """
        self.__write_to_file([])