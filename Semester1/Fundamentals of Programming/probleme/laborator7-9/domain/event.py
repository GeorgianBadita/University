'''
Created on Nov 20, 2017

@author: Geo
'''
class Event:
    '''
    Class which represents the event object defined by
    id, date, time and description - all strings
    '''
    
    def __init__(self, id_event, date, time, descr):
        self.__id = id_event
        self.__date = date
        self.__time = time
        self.__descr = descr
        
    def get_id_event(self):
        '''
        Function that gets the id of the current event
        return: a string representing the current event id
        '''
        return self.__id
    
    def get_date(self):
        '''
        Function that gets the date of the current event
        return: a string representing the current event date
        '''
        return self.__date
    
    def get_time(self):
        '''
        Function that gets the time of the current event
        return: a string representing the current event time
        '''
        return self.__time
    
    def get_descr(self):
        '''
        Function that gets the description of the current event
        return: a string representing the current event description
        '''
        return self.__descr
    
    def __lt__(self, ot):
        '''
        Tells how to compare 2 events objects
        '''
        if self.__descr < ot.__descr:
            return True
        if self.__descr == ot.__descr:
            if self.__date <= ot.__date:
                return True
        return False
        
    def __eq__(self, ot):
        '''
        Tells when 2 Events are equal
        '''
        return self.__id == ot.__id
        if self.__date == ot.__date and self.__time == ot.__time and self.__id == ot.__id and self.__descr == ot.__descr:
            return True
        return  False
    
    
    