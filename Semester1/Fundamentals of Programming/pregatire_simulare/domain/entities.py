"""
    @author: Badita Marin-Georgian
    @email:  geo.badita@gmail.com
    @date:   12/9/2017 21:54
"""

class Car:
    '''
    Class for the car entitiy
    '''
    def __init__(self, id, model, year, engine):
        '''

        :param id: -integer
        :param model: -string
        :param year: integer
        :param engine: -string
        '''
        self.__id = id
        self.__model = model
        self.__year = year
        self.__engine = engine

    def get_car_id(self):
        return self.__id

    def get_car_model(self):
        return self.__model

    def get_car_year(self):
        return self.__year

    def get_car_engine(self):
        return self.__engine

    def __str__(self):
        return "ID: " + str(self.__id) + "   " + self.__model + "   " + str(self.__year) + "  " + self.get_car_engine()


class Client:
    '''
    Class for the client entity
    '''

    def __init__(self, id, name, address):
        '''

        :param id: -integer
        :param name: -string
        :param address: -string
        '''
        self.__id = id
        self.__name = name
        self.__address = address

    def get_cl_id(self):
        return self.__id

    def get_cl_name(self):
        return self.__name

    def get_cl_address(self):
        return  self.__address

    def __str__(self):
        return "ID:  " + str(self.__id) + "   " + self.__name + "   " + self.__address


class Rental:
    '''
    Class for controlling rentals
    '''
    def __init__(self, id_car, id_client):
        '''
        Initialising a rental
        :param id_car: id of the car to be rented
        :param id_client: client to rent the car
        '''
        self.__rental_id = None
        self.__id_car = id_car
        self.__id_client = id_client

    def get_rental_id(self):
        return self.__rental_id

    def get_id_car(self):
        return self.__id_car

    def get_id_client(self):
        return self.__id_client

    def set_rental_id(self, new_id):
        self.__rental_id = new_id

class CarClientDto:

    def __init__(self, car, client):
        self.__car = car
        self.__client = client

    def get_car(self):
        return  self.__car

    def get_cl(self):
        return self.__client