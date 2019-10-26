"""
    @author: Badita Marin-Georgian
    @email:  geo.badita@gmail.com
    @date:   12/9/2017 22:33
"""

from repository.client_repository import RepositoryException


class CarRepository:
    '''
    Class to control data about cars (data manager)
    '''

    def __init__(self, car_Validator):
        '''

        :param entity_validator: the validator for the Car class
        '''
        self.__list = {}
        self.__validator = car_Validator

    def store_car(self, car):
        '''
        Class to store the client into the list
        Raises RepositoryException if the car already in list
        :post - Car added to the repository
        :param car:
        :return:
        '''
        if not car.get_car_id() in self.__list:
            self.__list[car.get_car_id()] = car
            self.__validator.validate(car)
        else:
            raise RepositoryException("Duplicated ID!")

    def get_all_cars(self):
        '''
        Function that gets all cars
        :return:
        '''

        return list(self.__list.values())

    def find_car(self, car_id):
        '''
        Function that finds a car by id
        :return: returns the car if it's in list, None otherwise
        '''
        cars_list = self.get_all_cars()
        for car in cars_list:
            if car_id == car.get_car_id():
                return car
        return None

    def delete_car(self, car_id):
        '''
        Function that deletes a car by id
        First searches the car by id, deletes the car and returns it if it exists
        None otherwise
        :param car_id:
        :return:
        '''
        car_ret = self.find_car(car_id)
        if car_ret is not None:
            del self.__list[car_id]
            return car_ret
        return None
