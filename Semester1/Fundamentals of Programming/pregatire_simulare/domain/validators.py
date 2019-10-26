"""
    @author: Badita Marin-Georgian
    @email:  geo.badita@gmail.com
    @date:   12/9/2017 21:54
"""
class ValidatorException(Exception):
    '''
    Class for validator
    '''

    def __init__(self, errors):
        '''
        inits the errors to be thrown
        :param errors:
        '''
        self.__errors = errors

    def get_errs(self):
        return self.__errors

class CarValidator:

    @staticmethod
    def validate(car):
        '''
        Function to validate a car object
        Raise ValidatorException if the car object isn't well defined
        :param car: Car object
        :return: None
        '''
        errs = []
        if car.get_car_year() is int and car.get_car_year() < 1880:
            errs.append("Year can't be lower than 1880")
        if car.get_car_year() == '':
            errs.append("The year can't be empty")
        if car.get_car_model() == '':
            errs.append("The model can't be empty")
        if car.get_car_id() == '':
            errs.append("The id can't be empty")
        if car.get_car_engine() == '':
            errs.append("The car engine can't be empty")

        if len(errs) > 0:
            raise ValidatorException(errs)


class ClientValidator:

    @staticmethod
    def validate(client):
        '''
        Function to validate a client object
        :Raises ValidatorException if the client object isn't well defined
        :param client: Client object
        :return: None
        '''
        errs = []
        if client.get_cl_id() == '':
            errs.append("Client id can't be empty!")
        if client.get_cl_name() == '':
            errs.append("Client name can't be empty!")
        if client.get_cl_address() == '':
            errs.append("Client address can't be empty!")
        if len(errs) > 0:
            raise ValidatorException(errs)

class RentalValidator:
    '''
    Function that checks if a rental is well-defined
    '''

    @staticmethod
    def validate(rental):
        '''
        Function that validates a Rental object
        :Raises: ValidatorException if the Rental object isn't well defined
        :param rental: Rental Object
        :return: None if the rental is well-defined
        '''
        errs = []
        if rental.get_id_car() == '':
            errs.append("The rental car id can't be empty!")
        if rental.get_id_client() == '':
            errs.append("The rental id clinet can't be empty!")

        if len(errs) > 0:
            raise ValidatorException(errs)