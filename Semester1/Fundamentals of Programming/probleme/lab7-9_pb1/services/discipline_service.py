"""
    @author: Badita Marin-Georgian
    @email:  geo.badita@gmail.com
    @date:   1/6/2018 23:33
"""
from domain.entities import Discipline
from domain.validators import DisciplineValidator, ValidatorException


class DisciplineService(object):
    """
    Class for controlling discipline actions
    """

    def __init__(self, repo):
        self.__repo = repo

    def create_discipline(self, id_disc, name_disc, prof):
        """
        Function that creates a discipline, validates it and save it to memory
        :param id_disc: id of the discipline
        :param name_disc: name of the discipline
        :param prof: professor of the discipline
        :return: the created discipline
        :raise: ValidatorException if the discipline is not given correctly, or ValueError
        if the discipline is already in the list
        """
        disc = Discipline(id_disc, name_disc, prof)
        val_disc = DisciplineValidator()
        try:
            val_disc.validate(disc)
            self.__repo.store_disc(disc)
            return disc
        except ValidatorException as ex:
            print(*ex.get_errors())
        except ValueError as ex:
            print(ex)

    def find_discipline(self, id_discipline):
        """
        Function that finds a discipline if it exists and returns it, else returns None
        :param id_discipline:
        :return:
        """
        return self.__repo.find_by_id_disc(id_discipline)

    def delete_discipline(self, id_discipline):
        """
        Function that deletes a discipline if it exists and returns it, else returns None
        :param id_discipline:
        :return:
        """
        return self.__repo.delete_by_id_disc(id_discipline)

    def get_all_disc(self):
        """
        Function that returns a list with all disciplines in the memory
        :return:
        """
        return self.__repo.get_all_disc_rep()
