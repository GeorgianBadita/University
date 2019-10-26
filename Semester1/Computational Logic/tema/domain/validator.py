"""
Clasa pentru valodarea unui numar
"""
from utils.helper import atrib_huge


class ValidatorException(Exception):
    """
    Clasa ce mosteneste atributiile clasei Exception
    """

    def __init__(self, errs):
        self.__errs = errs

    def get_errs(self):
        """
        Functie ce returneaza erorile, in cazul in care numarul este intrdus gresit
        :return: erorile
        """
        return self.__errs

class NumarValidator(object):
    """
    Clasa pentru validarea unui Numar
    """

    @staticmethod
    def validate(cls):
        """
        Functie ce verifica si returneaza eroriile
        :return:
        """
        allowed = "0123456789ABCDEF"
        errs = []
        if cls.get_val() == "":
            errs.append("Valoarea introdusa nu poate fi vida!")
        if cls.get_baza() == "":
            errs.append("Baza numarului nu poate fi vida!")
        values = cls.get_val()
        for char in values:
            if char not in allowed:
                errs.append("Exista caractere incorecte in numarul introdus!")
                break

        if len(errs) > 0:
            raise ValidatorException(errs)

        if cls.get_val() != "" and max(atrib_huge(cls)[1:]) >= cls.get_baza():
            errs.append("Numarul contine cifre mai mari sau egale cu baza!")
        if cls.get_baza() <= 1 or cls.get_baza() > 16:
            errs.append("Baza trebuie sa fie un numar natural intre 2 si 16")


        if len(errs) > 0:
            raise ValidatorException(errs)