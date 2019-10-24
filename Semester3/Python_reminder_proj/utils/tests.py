"""
    @author: Badita Marin-Georgian
    @email:  geo.badita@gmail.com
    @date:   7/23/18 19:28
"""
from domain.book import Book
from domain.validator import BookValidator, ValidatorException
from repository.repository import Repository, RepositoryException
from repository.file_repo import FileRepository
from service.service import Service


class Tests:
    """
    Test Class
    """
    @staticmethod
    def __test_book():
        """
        Class for testing the book class
        :return: None
        """
        b = Book("Ion", "Liviu Rebreanu", "Drama", 1912)
        assert b.get_genre() == "Drama"
        assert b.get_id() is None
        assert b.get_year() == 1912
        assert b.get_title() == "Ion"
        assert b.get_writer() == "Liviu Rebreanu"
        b.set_genre("Actiune")
        b.set_id(1)
        b.set_title("Andrei Calin")
        b.set_writer("Alexandru Macovei")
        b.set_year(1962)
        assert b.get_genre() == "Actiune"
        assert b.get_id() == 1
        assert b.get_year() == 1962
        assert b.get_title() == "Andrei Calin"
        assert b.get_writer() == "Alexandru Macovei"

    @staticmethod
    def __test_book_validator():
        """
        Class for testing validator class
        :return: None
        """
        b = Book("Ion", "Liviu Rebreanu", "Drama", 1912)
        b.set_id(1)
        val = BookValidator()
        val.validate(b)
        b1 = Book("", "", "", -1)
        try:
            b1.set_id(-2)
            val.validate(b1)
            assert False
        except ValidatorException as ex:
            errs = ex.get_errs()
            assert len(errs) == 5
        try:
            b1.set_writer(5)
            assert False
        except TypeError:
            assert True
        try:
            b1.set_title(5)
            assert False
        except TypeError:
            assert True
        try:
            b1.set_genre(5)
            assert False
        except TypeError:
            assert True
        try:
            b1.set_year("asda")
            assert False
        except TypeError:
            assert True
        try:
            b1.set_id(":")
            assert False
        except TypeError:
            assert True

    @staticmethod
    def __test_repo():
        """
        Function to test repository
        :return:
        """
        val = BookValidator()
        repo = Repository(val)
        b = Book("Ion", "Liviu Rebreanu", "Drama", 1912)
        b.set_id(0)
        repo.store_book(b)
        assert len(repo.get_all()) == 1
        b.set_id(2)
        repo.store_book(b)

        assert len(repo.get_all()) == 2
        assert repo.search_book(1) is not None
        assert repo.search_book(2) is None
        assert repo.delete_book(1) is not None
        assert repo.delete_book(1) is None

        b.set_id(2)
        repo.store_book(b)
        assert len(repo.get_all()) == 2
        b.set_year(2018)
        assert repo.update_book(1, b) is not None
        assert repo.update_book(2, b) is None
        b1 = repo.search_book(1)
        assert b1.get_year() == 2018

        try:
            repo.store_book(b)
            assert False
        except RepositoryException:
            assert True

    @staticmethod
    def __test_service():
        """
        Function to test service
        :return: None
        """
        val = BookValidator()
        repo = Repository(val)
        srv = Service(repo)
        srv.add_book("Ion", "Liviu Rebreanu", "Drama", 1912)
        assert len(srv.get_all_srv()) == 1
        assert srv.get_all_srv()[0].get_title() == "Ion"
        srv.add_book("Iona", "Marin Sorescu", "Drama", 1971)
        assert len(srv.get_all_srv()) == 2
        assert srv.remove_book(1) is not None
        assert len(srv.get_all_srv()) == 1
        assert srv.remove_book(1) is None
        assert srv.modify_book(0, "Prislea", "Petre Ispirescu", "Fictiune", 1960) is not None
        assert srv.get_all_srv()[0].get_writer() == "Petre Ispirescu"
        srv.add_book("Ion", "Marin Sorescu", "Drama", 1971)
        srv.add_book("Ion", "Liviu Rebreanu", "Drama", 1912)
        rez = srv.filter_by_title("Ion")
        assert len(rez) == 2 and rez[0].get_title() == "Ion"
        rez = srv.filter_by_year(1960)
        assert len(rez) == 1 and rez[0].get_title() == "Prislea"
        sort = srv.sort_by_title(False)
        assert sort[0].get_title() <= sort[1].get_title() <= sort[2].get_title()
        sort = srv.sort_by_title(True)
        assert sort[0].get_title() >= sort[1].get_title() >= sort[2].get_title()

        sort = srv.sort_by_writer(False)
        assert sort[0].get_writer() <= sort[1].get_writer() <= sort[2].get_writer()
        sort = srv.sort_by_writer(True)
        assert sort[0].get_writer() >= sort[1].get_writer() >= sort[2].get_writer()

        sort = srv.sort_by_genre(False)
        assert sort[0].get_genre() <= sort[1].get_genre() <= sort[2].get_genre()
        sort = srv.sort_by_genre(True)
        assert sort[0].get_genre() >= sort[1].get_genre() >= sort[2].get_genre()

        sort = srv.sort_by_year(False)
        assert sort[0].get_year() <= sort[1].get_year() <= sort[2].get_year()
        sort = srv.sort_by_year(True)
        assert sort[0].get_year() >= sort[1].get_year() >= sort[2].get_year()

    @staticmethod
    def __test_file_repo():
        """
        Function to test file based repository
        :return:
        """
        val = BookValidator()
        repo = FileRepository(val, "repository/test_file.txt")
        repo.clear_file()
        b = Book("Ion", "Liviu Rebreanu", "Drama", 1912)
        repo.store_book(b)
        b = Book("Prislea", "Petre Ispirescu", "Basm", 1970)
        repo.store_book(b)
        assert len(repo.get_all()) == 2
        b = Book("Limite de functii", "Catalin Pana", "Stiinta", 2016)
        repo.store_book(b)
        repo.delete_book(1)
        assert len(repo.get_all()) == 2
        mod_b = Book("Integrale", "Catalin Pana", "Stiinta", 2017)
        repo.update_book(2, mod_b)
        assert len(repo.get_all()) == 2
        assert repo.delete_book(5) is None
        assert repo.get_all()[1].get_year() == 2017

    def run_tests(self):
        """
        Function to run all tests
        :return:
        """
        self.__test_book()
        self.__test_book_validator()
        self.__test_repo()
        self.__test_service()
        self.__test_file_repo()
