"""
    @author: Badita Marin-Georgian
    @email:  geo.badita@gmail.com
    @date:   12/10/2017 21:00
"""
from domain.entities import Rental
from repository.client_repository import RepositoryException


class RentalFileRepository:

    def __init__(self, path):
        '''

        :param path: - string, file name
        '''
        self.__path = path

    def __load_from_file(self):
        '''
        Function that loads rentals from file
        :return:
        '''
        try:
            f = open(self.__path, "r")
        except IOError:
            #file doesn't exist
            return

        rentals = []

        line = f.readline().strip()
        while line != "":
            params = line.split(",")
            rental = Rental(int(params[1]), int(params[2]))
            rental.set_rental_id(int(params[0]))
            rentals.append(rental)
            line = f.readline().strip()
        f.close()
        return rentals

    def __store_to_file(self, allR):
        '''
        Function that stores a list of rentals into the file
        :return:
        '''
        with open(self.__path, "w") as f:
            for rental in allR:
                to_write = str(rental.get_rental_id()) + "," + str(rental.get_id_car()) + "," + str(rental.get_id_client())
                to_write = to_write + "\n"
                f.write(to_write)

    def get_all_rents(self):
        '''
        Function that gets all rents as a list
        :return:
        '''
        return self.__load_from_file()

    def remove_all(self):
        '''
        Function that removes all rentals
        :return:
        '''
        self.__store_to_file([])

    def store_rental(self, rental):
        '''
        Function that stores a rental into the list
        :post: if the rental doesn't exists in the list, the rental will be added
        :param rental: Rental type object
        :return:
        '''
        all_r = self.__load_from_file()
        new_id = len(all_r) + 1
        rental.set_rental_id(new_id)
        if rental not in all_r:
            all_r.append(rental)
            self.__store_to_file(all_r)
        else:
            raise RepositoryException("Duplicated ID!")

    def find_rental(self, rental_id):
        '''
        Function that finds a rental by a given id
        :param rental_id:
        :return:
        '''
        all_r = self.__load_from_file()
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
        pos = - 1
        all_r = self.__load_from_file()
        for i in range(len(all_r)):
            if all_r[i].get_rental_id() == rental_id:
                pos = i
                break
        if pos == -1:
            return None

        to_ret = all_r[pos]
        del all_r[pos]
        self.__store_to_file(all_r)
        return to_ret
