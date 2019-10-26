'''
Created on Nov 20, 2017

@author: Geo
'''

from domain.event import Event


class EventService:
    '''
    Class which defines the operations that can be performed
    with events
    '''
    def __init__(self, event_repo):
        '''
        Initialise service
        :param: rep - event_repository - object to store events
        '''
        self.__rep = event_repo
        
    def create_event(self, id_event, date, time, descr):
        '''
        store an event
        :param: id_event - string
        :param: date - string
        :param: time - string
        :param: descr - string
        :post: the event will be added to the list
        :raise: Event_Repository_Exception if the event already exists
        :raise: Validator_Exception if the event fields are completed wrong
        '''
        #create new_event
        new_event = Event(id_event, date, time, descr)
        #add the event into using repository
        self.__rep.store_event(new_event)
        #return the added event
        return new_event
    
    def get_all_events_service(self):
        '''
        Function that gets all events in the list
        :return: returns a list with all events
        '''

        return self.__rep.get_all_events()
    
    def delete_event_service(self, id_event):
        '''
        Function that deletes an event by a given id
        :return: the deleted event if it exists, None otherwise
        :post: the event will be deleted from the list
        '''
        return self.__rep.delete_event(id_event)
    
    def update_event_service(self, id_event, date, time, descr):
        '''
        Function that updates an event
        :return: the new event if it exists, None otherwise
        '''
        new_event = Event(id_event, date, time, descr)
        return self.__rep.update_event(new_event)  
    
    
    def search_event_service(self, id_event):
        '''
        Function that searches for an event by the given id
        :return: the event if it exists, None otherwise
        '''
        lst = self.get_all_events_service()
        return self.__rep.search_event(lst, id_event)
    
        