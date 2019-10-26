'''
Created on Nov 20, 2017

@author: Geo
'''
class Person:
    '''
    Class which define the person object defined by
    id, name and address - all strings
    '''
    def __init__(self, id_pers, name, address):
        self.__id = id_pers
        self.__name = name
        self.__address = address
        
    def get_id_pers(self):
        '''
        Function which gets the id of the current person
        return: string representing the id of the person
        '''
        return self.__id
    
    def get_name(self):
        '''
        Function which gets the name of the current person
        return: string representing the name of the person
        '''
        return self.__name
    
    def get_adr(self):
        '''
        Function which gets the address of the current person
        return: string representing the address of the person
        '''
        return self.__address
    
    def __eq__(self, ot):
        '''
        Function that tells when 2 people are equal
        '''
        return self.__id == ot.__id
        return self.__id == ot.__id and self.__name == ot.__name and self.__address == ot.__address
    

    