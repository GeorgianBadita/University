"""
    @author: Badita Marin-Georgian
    @email:  geo.badita@gmail.com
    @date:   1/28/2018 14:56
"""


class ValidatorException(Exception):

    def __init__(self, errors):
        self.__errors = errors

    def get_errors(self):
        """
        Getter method
        :return:
        """
        return self.__errors


class JucatorValidator(object):

    @staticmethod
    def validate(jucator):
        errs = []
        if jucator.get_nume() == "":
            errs.append("Numele nu poate fi vid!")
        if jucator.get_prenume() == "":
            errs.append("Prenumele nu poate fi vid1")
        if jucator.get_post() not in ["Fundas", "Extrema", "Pivot"]:
            errs.append("Postul trebuie sa fie unl dintre: Fundas, Extrema sau Pivot")
        if jucator.get_inaltime() <= 0:
            errs.append("Inaltimea trebuie sa fie un numar pozitiv!")

        if len(errs) > 0:
            raise ValidatorException(errs)