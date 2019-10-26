'''
Created on Nov 20, 2017

@author: Geo
'''
class EventRepositoryException(Exception):
    pass


class EventRepository:
    '''
    Class to manage person data 
    '''
    def __init__(self, event_validator):
        self.__list = {}
        self.__validator = event_validator
        
    def store_event(self, event):
        '''
        Store __list
        event is the element of the class Event
        raise Repository_Exception if we have an element with the same ID in list
        :param: event
        :return: nothing
        :post: event added to the repository
        '''
        if event.get_id_event() in self.__list:
            raise EventRepositoryException()
        self.__validator.validate(event)
        self.__list[event.get_id_event()] = event
        
    def delete_event(self, id_event):
        '''
        Deletes an event from the list if the event exists
        :return: returns the deleted event if it exists, otherwise
        returns None
        '''
        for event in self.__list:
            if id_event == event:
                event_to_return = self.__list[event]
                del self.__list[event]
                return event_to_return
        return None
        
    def size(self):
        '''
        :return: an integer value, representing the number of events
        on the list
        '''    
        return len(self.__list)
    
    
    def get_all_events(self):
        '''
        :return: a list with all events
        '''
        return list(self.__list.values())
    
    
    def update_event(self, new_event):
        '''
        updates an event in the list
        :post: the event with the id of the new event will be changed
        '''
        for event in self.__list:
            if new_event.get_id_event() == event:
                self.__validator.validate(new_event)
                self.__list[event] = new_event
                return new_event
            
        return None
    
    
    def search_event(self, lst, id_event):
        '''
        Function that searches for an event after a given id
        :return: returns the event if it exists, otherwise it returns None
        '''
        try:
            if lst[0].get_id_event() == id_event:
                return lst[0]
            return self.search_event(lst[1:], id_event)
        except IndexError:
            return None
    
    
    
    