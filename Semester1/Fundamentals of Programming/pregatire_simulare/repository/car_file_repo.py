"""
    @author: Badita Marin-Georgian
    @email:  geo.badita@gmail.com
    @date:   12/10/2017 20:59
"""
from domain.entities import Car
from repository.client_repository import RepositoryException


class CarFileRepository:
    '''
    Class for Car repository using files
    '''

    def __init__(self, path):
        '''
        Init the repository
        :param path: -string the path were the file will be located
        '''
        self.__path = path

    def __load_from_file(self):
        '''
        Function that loads all cars from the file
        :return:
        '''
        try:
            f = open(self.__path, "r")
        except IOError:
            #file not exists
            return
        line = f.readline().strip()
        cars = []

        while line != "":
            params = line.split(",")
            car = Car(int(params[0]), params[1], int(params[2]), params[3])
            cars.append(car)
            line = f.readline().strip()
        f.close()
        return cars

    def __store_to_file(self, allC):
        '''
        Function that stores to file
        :return:
        '''
        with open(self.__path, "w") as f:
            for car in allC:
                to_write = str(car.get_car_id()) + ',' + car.get_car_model() + ',' + str(car.get_car_year()) + ',' + car.get_car_engine()
                to_write += '\n'
                f.write(to_write)

    def store_car(self, car):
        '''
        Class to store the client into the list
        Raises RepositoryException if the car already in list
        :post - Car added to the repository
        :param car:
        :return:
        '''
        car_id = car.get_car_id()
        allC = self.__load_from_file()
        if self.find_car(car_id) is not None:
            raise RepositoryException("Duplicated ID!")
        else:
            allC.append(car)
            self.__store_to_file(allC)

    def get_all_cars(self):
        '''
        Function that gets all cars
        :return:
        '''

        return self.__load_from_file()

    def find_car(self, car_id):
        '''
        Function that finds a car by id
        :return: returns the car if it's in list, None otherwise
        '''
        cars_list = self.__load_from_file()
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
        allC = self.__load_from_file()
        pos = -1
        for i in range(len(allC)):
            if allC[i].get_car_id() == car_id:
                pos = i
        if pos == -1:
            return None
        car = allC[pos]
        del allC[pos]
        self.__store_to_file()
        return car

    def remove_all(self):
        '''
        Function to clear the file
        :return:
        '''
        self.__store_to_file([])