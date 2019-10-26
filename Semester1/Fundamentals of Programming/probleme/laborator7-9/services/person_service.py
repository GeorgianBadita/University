'''
Created on Nov 20, 2017

@author: Geo
'''

from domain.person import Person
from utils.helper import rand_int, rand_string


class PersonService:
    '''
    Class which defines the operations that can be performed
    with people
    '''
    def __init__(self, event_repo):
        '''
        Initialise service
        :param: rep - event_repository - object to store people
        '''
        self.__rep = event_repo
        
    def create_person(self, id_person, name, address):
        '''
        store an event
        :param: id_person - string
        :param: name - string
        :param: address - string
        :post: the person will be added to the list
        :raise: Person_Repository_Exception if the person already exists
        :raise: Validator_Exception if the person fields are completed wrong
        '''
        #create new_person
        new_person = Person(id_person, name, address)
        #add the event into using repository
        self.__rep.store_person(new_person)
        #return the added event
        return new_person
    
    def get_all_people_service(self):
        '''
        Function that gets all people in the list
        :return: returns a list with all people
        '''
        return self.__rep.get_all_people()
    
    def delete_person_service(self, id_person):
        '''
        Function that deletes a person by a given id
        :return: the deleted person if it exists, None otherwise
        :post: the person will be deleted from the list
        '''
        return self.__rep.delete_person(id_person)
    
    def update_person_service(self, id_person, name, address):
        '''
        Function that updates a person
        :return: the new person if it exists, None otherwise
        '''
        new_person = Person(id_person, name, address)
        return self.__rep.update_person(new_person) 
    
    def search_person_service(self, id_pers):
        '''
        Function that searches for a person by the given id
        :return: the person if it exists, None otherwise
        '''  
        lst = self.get_all_people_service()
        return self.__rep.search_person(lst, id_pers)
    
    def gen_random_people_service(self, number):
        '''
        Function that generates random people
        :post: adds random people to the list
        '''
        for new_person in range(number):
            
            rand_id = str(rand_int())
            rand_name = rand_string(7)
            rand_address = rand_string(10)
            self.create_person(rand_id, rand_name, rand_address)
        
             
    
        
        