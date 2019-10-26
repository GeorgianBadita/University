"""
    @author: Badita Marin-Georgian
    @email:  geo.badita@gmail.com
    @date:   1/28/2018 15:07
"""
import random

from domain.entities import Jucator
from domain.jucatori_dto import JucatoriDTO
from repository.repository_validator import RepositoryException


class FileRepository(object):
    """
    Clasa pentru file repository
    """

    def __init__(self, file_path):
        self.__file_path = file_path

    def set_path_repo(self, new_file_pat):
        self.__file_path = new_file_pat

    def get_path_repo(self):
        return self.__file_path

    def adauga_jucator(self, jc):
        """
        Functie care adauga un jucator in fisier
        :param jc: jucatorul nou ce se vrea a fi introdus
        :return: jucatorul adaugat
        """
        all_j = self.load_from_file()
        if jc in all_j:
            raise RepositoryException("Jucatorul deja exista!")
        else:
            all_j.append(jc)
            self.store_to_file(all_j)
            return jc

    def store_to_file(self, all_j):
        """
        Functie care tipareste o lista de inregistrari in fisier
        :return: None
        """

        with open(self.__file_path, "w") as f:
            for juc in all_j:
                string = juc.get_nume() + "," + juc.get_prenume() + "," + str(juc.get_inaltime()) + "," + str(juc.get_post())
                string += "\n"
                f.write(string)

    def load_from_file(self):
        """
        Functie care citeste toate inregisrarile dintr-un fisier
        :return:
        """

        try:
            f = open(self.__file_path, "r")
        except IOError:
            return

        line = f.readline().strip()
        jucatori = []
        while line != "":
            params = line.split(",")
            juc = Jucator(params[0], params[1], int(params[2]), params[3])
            jucatori.append(juc)
            line = f.readline().strip()

        return jucatori

    def cauta_jucator(self, jc):
        """
        Functie care cauta un jucator in fisier
        :param jc: jucatorul ce se vrea a fi cautat
        :return: jucatorul daca jucatorul exoista, None altfel
        """

        all_j = self.load_from_file()
        if jc in all_j:
            return jc
        return None

    def modificare_h(self, nume, prenume, new_h):
        """
        Functie care modifica inaltimea unui jucator
        :param nume: nume dat de la tastatura
        :param prenume: prenume dat de la tastaura
        :param new_h: nua inaltime a jucatorului
        :return: jucatorul modificat daca exista, None altfel
        """

        all_j = self.load_from_file()
        to_change = None
        for jucator in all_j:
            if jucator.get_prenume() == prenume and jucator.get_nume() == nume:
                to_change = jucator
                break
        if to_change is None:
            return None
        all_j.remove(to_change)
        to_change.set_inaltime(new_h)
        all_j.append(to_change)
        self.store_to_file(all_j)
        return to_change

    def sterge_fisier(self):
        """
        Functie care sterge toate inregisrarile din fisier
        :return: None
        """
        self.store_to_file([])

    def separare(self):
        """
        Functie care separa pozitiille pentru DTO
        :return:
        """
        all_j = self.load_from_file()
        fundasi = []
        pivoti = []
        extreme =[]
        for jucator in all_j:
            if jucator.get_post() == "Fundas":
                fundasi.append(jucator)
            elif jucator.get_post() == "Pivot":
                pivoti.append(jucator)
            elif jucator.get_post() == "Extrema":
                extreme.append(jucator)
        dto = JucatoriDTO(fundasi, extreme, pivoti)
        return dto


    def import_juc_repo(self):
        """
        Functie care importa pe rand jucatorii dintr-un fisier dat si
        genereaza random din intervalul (a,b) inaltimile acestora
        :return:
        """
        try:
            f = open(self.__file_path, "r")
        except IOError:
            return

        line = f.readline().strip()
        jucatori = []
        while line != "":
            params = line.split(",")
            juc = Jucator(params[0], params[1], int(params[2]), params[3])
            if juc not in jucatori:
                rand_number = random.randint(180, 230)
                juc.set_inaltime(rand_number)
                jucatori.append(juc)
            line = f.readline().strip()

        return jucatori