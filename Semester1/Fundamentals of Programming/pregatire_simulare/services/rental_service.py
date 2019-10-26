"""
    @author: Badita Marin-Georgian
    @email:  geo.badita@gmail.com
    @date:   12/10/2017 19:51
"""
from domain.entities import Rental, CarClientDto
from domain.validators import ValidatorException
from repository.client_repository import RepositoryException


class RentalService:
    '''
    Class to controls the action performed with rentals
    '''

    def __init__(self, rental_repo, client_rep, car_rep):
        '''
        :param rental_repo: RentalRepository
        '''
        self.__rep = rental_repo
        self.__cl_rep = client_rep
        self.__car_rep = car_rep

    def add_rent_srv(self, id_car, id_client):
        '''
        Function that adds a new rental to the repository
        :param id_car:
        :param id_client:
        :return:
        '''
        try:
            new_rental = Rental(id_car, id_client)
            self.__rep.store_rental(new_rental)
        except ValidatorException as ex:
            print(ex.args)
        except RepositoryException as ex:
            print(ex)

    def del_rent_srv(self, id_rental):
        '''
        Function that deletes a rental by a given id
        :param id_rental:
        :return:
        '''
        del_rental = self.__rep.delete_rental(id_rental)
        if del_rental is None:
            print("There is no rental with this id! ")
        else:
            return del_rental

    def find_rent_srv(self, id_rental):
        '''
        Function that finds a rental by a given id
        :param id_rental:
        :return:
        '''
        find_rent = self.__rep.find_rental(id_rental)
        if find_rent is None:
            print("There is no rental with this id!")
        else:
            return find_rent

    def list_rental_srv(self):
        '''
        Function that returns all cars and the client who rent them
        :return:
        '''
        list_to_print = []
        all_r = self.__rep.get_all_rents()
        for rent in all_r:
            item = CarClientDto(self.__car_rep.find_car(rent.get_id_car()),
                                self.__cl_rep.find_client(rent.get_id_client()))
            list_to_print.append(item)
        if len(list_to_print) == 0:
            return None
        return list_to_print

    def list_sorted_srv(self):
        '''
        Function that sorts a list of rentals by client_id
        :return:
        '''
        list_to_print = []
        all_r = self.__rep.get_all_rents()
        for rent in all_r:
            item = CarClientDto(self.__car_rep.find_car(rent.get_id_car()),
                                self.__cl_rep.find_client(rent.get_id_client()))
            list_to_print.append(item)
        if len(list_to_print) == 0:
            return None

        return sorted(list_to_print,  key = lambda x : x[1].get_cl_id())
