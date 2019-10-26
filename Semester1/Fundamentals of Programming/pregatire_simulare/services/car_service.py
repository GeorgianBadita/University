"""
    @author: Badita Marin-Georgian
    @email:  geo.badita@gmail.com
    @date:   12/9/2017 22:49
"""
from domain.entities import Car
from repository.client_repository import RepositoryException

from domain.validators import ValidatorException

class CarService:
    '''
    Class which controlls the Car class performed actions
    '''

    def __init__(self, car_rep):
        '''

        :param car_rep: CarRepository
        '''
        self.__rep = car_rep

    def add_car_srv(self, id, model, year, engine):
        '''
        Function that stores a car into the repository, using CartRepository
        Creates a new Car object and adds it into repository
        post: car will be added to the repository
        :param: id - int
        :param: model - string
        :param: year - int
        :param: engine - string
        :return:
        '''
        car = Car(id, model, year, engine)
        try:
            self.__rep.store_car(car)
        except RepositoryException as ex:
            print(ex)
        except ValidatorException as ex:
            print(ex.args)

    def get_all_cars(self):
        '''
        Function that returs a list with all cars
        :return:
        '''
        return self.__rep.get_all_cars()

    def del_car_srv(self, car_id):
        '''
        Function that deletes a car by a given id, using
        the delete function from repository
        :param car_id:
        :return:

        '''
        del_car  = self.__rep.delete_car(car_id)
        if del_car is None:
            print("There is no car with this id!")
        else:
            return del_car

    def find_car_srv(self, car_id):
        '''
        Function that finds a car by a given id, using the find function
        from the repository
        :return:
        '''
        find_car = self.__rep.find_car(car_id)
        if find_car is None:
            print("There is no car with this id!")
        else:
            return find_car