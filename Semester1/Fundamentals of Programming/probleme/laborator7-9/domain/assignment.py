'''
Created on Nov 20, 2017

@author: Geo
'''
class Assignment:
    '''
    Class which controls the enrollment functionality of the application 
    '''
    def __init__(self, id_person, id_event):
        self.__id_pers = id_person
        self.__id_event = id_event
        
    def get_person_id(self):
        '''
        Function that gets the person from the assignment
        '''
        return self.__id_pers
    
    def get_event_id(self):
        '''
        Function that gets the event from the assignment
        '''
        return self.__id_event
    
    def __str__(self):
        '''
        Defint the str function for assignment
        '''
        print(self.__id_pers, self.__id_event)
    
        
    def __eq__(self, ot):
        '''
        Function which defines when 2 assignments are equal
        '''
        if self.get_person_id() == ot.get_person_id() and self.get_event_id() == ot.get_event_id():
            return True
        return False
        
    
    