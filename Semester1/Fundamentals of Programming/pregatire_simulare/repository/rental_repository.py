"""
    @author: Badita Marin-Georgian
    @email:  geo.badita@gmail.com
    @date:   12/10/2017 19:28
"""

from repository.client_repository import RepositoryException

class RentalRepository:
    '''
    Class controlling the rental data
    '''

    def __init__(self, rent_validator):
        '''
        Function that inits the RentalRepository
        :param rent_validator: validator for Rental class
        '''
        self.__list = {}
        self.__validator = rent_validator

    def get_all_rents(self):
        '''
        Function that gets all rents as a list
        :return:
        '''
        return list(self.__list.values())

    def store_rental(self, rental):
        '''
        Function that stores a rental into the list
        :post: if the rental doesn't exists in the list, the rental will be added
        :param rental: Rental type object
        :return:
        '''
        new_id = len(self.get_all_rents()) + 1
        rental.set_rental_id(new_id)
        if rental.get_rental_id() not in self.get_all_rents():
            self.__list[new_id] = rental
        else:
            raise RepositoryException("Duplicated ID!")

    def find_rental(self, rental_id):
        '''
        Function that finds a rental by a given id
        :param rental_id:
        :return:
        '''
        all_r = self.get_all_rents()
        for rental in all_r:
            if rental.get_rental_id() == rental_id:
                return rental
        return None

    def delete_rental(self, rental_id):
        '''
        Functon that deletes a rental, by rental_id
        :param rental_id:
        :return:
        '''
        rent_del = self.find_rental(rental_id)
        if rental_id is None:
            return None

        del self.__list[rental_id]
        return rent_del
