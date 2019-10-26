'''
Created on Nov 20, 2017

@author: Geo
'''

from utils.helper import date_validation, hour_validation

class ValidatorException(Exception):
    '''
    Subclass of Exception
    '''
    def __init__(self, exceptions):
        self.exceptions = exceptions
    
    def get_errors(self):
        '''
        Function to get all exceptions 
        return: a list of strings representing exceptions
        '''
        return self.exceptions
    

class EventValidator():
    '''
    Class which will validate the event entity
    '''
    @staticmethod
    def validate(event):
        '''
        Throws Validator_Excetion if the event fields are incorrect
        '''
        exceptions = date_validation(event.get_date()) + hour_validation(event.get_time())
        
        if event.get_id_event() == "": 
            exceptions.append("The id can't be empty!")
        if event.get_date() == "":
            exceptions.append("The date can't be empty!")
        if event.get_time() == "":
            exceptions.append("The time can't be empty!")
        if event.get_descr() == "":
            exceptions.append("The description can't be empty!")
        
        if len(exceptions) > 0:
            raise ValidatorException(exceptions)

class PersonValidator:
    '''
    Class which will validate the event entity
    '''
    
    @staticmethod
    def validate(person):
        '''
        Throws Validator_Excetion if the person fields are incorrect
        '''
        exceptions = []
        
        if person.get_id_pers() == "":
            exceptions.append("The id can't be empty!")
        if person.get_name() == "":
            exceptions.append("The name can't be empty!")
        if person.get_adr() == "":
            exceptions.append("The address can't be empty!")
            
        if len(exceptions) > 0:
            raise ValidatorException(exceptions)
                           
            
            
    
