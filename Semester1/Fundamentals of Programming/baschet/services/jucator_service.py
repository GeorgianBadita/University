"""
    @author: Badita Marin-Georgian
    @email:  geo.badita@gmail.com
    @date:   1/28/2018 16:22
"""
from domain.entities import Jucator
from domain.validators import ValidatorException
from repository.repository_validator import RepositoryException


class JucatorService(object):
    """
    Clasa pentru operatiile cu jucatori
    """

    def __init__(self, repo, val):
        self.__repo = repo
        self.__val = val

    def adauga_jucator_serv(self, nume, prenume, inaltime, post):
        jc = Jucator(nume, prenume, inaltime, post)
        try:
            self.__val.validate(jc)
            self.__repo.adauga_jucator(jc)
        except ValidatorException as ex:
            print(ex.get_errors())
        except RepositoryException as ex:
            print(ex)

    def modifica_h_serv(self, nume, prenume, new_h):
        jc = Jucator(nume, prenume, new_h, "Fundas")
        try:
            self.__val.validate(jc)
            jucator_mod = self.__repo.modificare_h(nume, prenume, new_h)
            return jucator_mod
        except ValidatorException as ex:
            print(ex.get_errors())

    def get_all_serv(self):
        return self.__repo.load_from_file()

    def formeaza_echipa(self):
        """
        Functie care formeaza echipa cu media de inaltime cea mai mare
        :return:
        """
        dto_separat = self.__repo.separare()
        fundasi = dto_separat.get_fundasi()
        extreme = dto_separat.get_extreme()
        pivoti = dto_separat.get_pivoti()
        fundasi = sorted(fundasi, key = lambda x:x.get_inaltime(), reverse=True)
        extreme = sorted(extreme, key = lambda x:x.get_inaltime(), reverse=True)
        pivoti = sorted(pivoti, key = lambda x:x.get_inaltime(), reverse=True)
        if len(extreme) < 2 or len(pivoti) < 1 or len(fundasi) < 2:
            return None
        return extreme[:2] + [pivoti[0]] + fundasi[:2]


    def import_serv(self):
        return self.__repo.import_juc_repo()

    def set_path_service(self, new_path):
        """
        Functie care seteaza fisierul din repository
        :return:
        """
        self.__repo.set_path_repo(new_path)

    def get_path_serv(self):
        return self.__repo.get_path_repo()