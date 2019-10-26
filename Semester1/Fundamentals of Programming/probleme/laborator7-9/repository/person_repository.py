'''
Created on Nov 20, 2017

@author: Geo
'''
class PersonRepositoryException(Exception):
    pass

class PersonRepository:
    '''
    Class to manage person data 
    '''
    def __init__(self, person_validator):
        self.__list = {}
        self.__validator = person_validator
        
    def store_person(self, person):
        '''
        Store __list
        person is the element of the class Person
        raise Repository_Exception if we have an element with the same ID in list
        :param: person
        :return: nothing
        :post: person added to the repository
        '''
            
        if person.get_id_pers() in self.__list:
            raise PersonRepositoryException()
        self.__validator.validate(person)
        self.__list[person.get_id_pers()] = person
            
            
    def delete_person(self, id_person):
        '''
        Deletes a person from the list if the person exists
        :return: returns the deleted person if it exists, otherwise
        returns None
        '''
        for person in self.__list:
            if id_person == person:
                person_to_return = self.__list[person]
                del self.__list[person]
                return person_to_return
        return None
        
    def size(self):
        '''
        :return: an integer value, representing the number of people
        on the list
        '''    
        return len(self.__list)
    
    
    def get_all_people(self):
        '''
        :return: a list with all people
        '''
        return list(self.__list.values())
    
    
    def update_person(self, new_person):
        '''
        updates a person in the list
        :post: the person with the id of the new person will be changed
        '''
        for person in self.__list:
            if new_person.get_id_pers() == person:
                self.__validator.validate(new_person)
                self.__list[person] = new_person
                return new_person
            
        return None
    
    def search_person(self, lst, id_person):
        '''
        Function that searches for a person after a given id
        :return: returns the person if it exists, otherwise it returns None
        '''
        try:
            if lst[0].get_id_pers() == id_person:
                return lst[0]
            return self.search_person(lst[1:], id_person)
        except IndexError:
            return None
    
    
        
    