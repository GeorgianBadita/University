'''
Created on Dec 1, 2017

@author: Geo
'''
from domain.person import Person 
from domain.event import Event
from domain.assignment import Assignment
from repository.person_repository import PersonRepositoryException
from repository.event_repository import EventRepositoryException


class PersonFileRepository:
    '''
        Store people from file
    '''
    
    def __init__(self, path):
        '''
        init the repository
        path - string, file path where the people are stored
        post: people are loaded from the file
        '''
        self.__path = path
    
    def __loadFromFile(self):
        '''
        Loads students from file
        raise CorruptedFIleException if there's an eror when reading from the file 
        '''
        try:
            f = open(self.__path, "r")
        except IOError:
            #file not exists
            return 
        line = f.readline().strip()
        people = []
        
        while line != "":
            comp = line.split(",")
            pers = Person(comp[0], comp[1], comp[2])
            people.append(pers)
            line = f.readline().strip()
        f.close()
        return people
    

    def __storeToFile(self, allP):
        '''
        Store all the people in to the file
        raise CorruptedFileException if we can't save to the file 
        '''
        #open file (rewrite file)
        with open(self.__path, "w") as f:
            for pers in allP:
                pers_rf = pers.get_id_pers() + ',' + pers.get_name() + ',' + pers.get_adr()
                pers_rf += "\n"
                f.write(pers_rf)
    
    
    def store_person(self, pers):
        '''
        Store the person to the file. Overwrite store
        pers - Person
        Post: person is stored to the file
        raise DuplicatedIdException for duplicated id 
        '''

        allP = self.__loadFromFile()
        if pers in allP:
            raise PersonRepositoryException()
        allP.append(pers)
        self.__storeToFile(allP)
            
    
    def delete_person(self, id):
        '''
        remove a person from the repository
        id - string, the id of the person to be deleted
        :return: person
        :post: the repository won't contain the student with the give id
        :raise: ValueError if there is no student with the given id
        '''
        allP = self.__loadFromFile()
        pos = -1
        for i in range(len(allP)):
            if allP[i].get_pers_id() == id:
                poz = i
        if poz == -1:
            return None
        pers = allP[poz]
        del allP[poz]
        self.__storeToFile(allP)
        return pers
            
    def search_person(self, list, id):
        '''
        Find the person for a given id
        id - string
        return person with the given id or None if the person doesn't exist
        '''
        try:
            if list[0].get_id_pers() == id:
                return list[0]
            return self.search_person(list[1:], id)
        except IndexError:
            return None
        
    
    def update_person(self, new_person):
        '''
        Update person in the repo
        new_person = Person object which contains the new 
        name and address for the person and the id where should 
        modify 
        '''
        allP = self.__loadFromFile()
        pers = self.__search_person(new_person.get_id_pers())
        if pers == None:
            return None
        allP.remove(pers)
        allP.append(new_person)
        self.__storeToFile(allP)
        return new_person 
    

    def removeAll(self):
        '''
        Remove all the students from the repository
        :post: the repository is empty
        '''
        self.__storeToFile([])

    def get_all_people(self):
        return self.__loadFromFile()
    
    def size(self):
        return len(self.__loadFromFile())
    


class EventFileRepository:
    '''
        Store events from file
    '''
    
    def __init__(self, path):
        '''
        init the repository
        path - string, file path where the events are stored
        post: events are loaded from the file
        '''
        self.__path = path
    
    def __loadFromFile(self):
        '''
        Loads students from file
        raise CorruptedFIleException if there's an error when reading from the file 
        '''
        try:
            f = open(self.__path, "r")
        except IOError:
            #file not exists
            return 
        line = f.readline().strip()
        events = []
        
        while line != "":
            comp = line.split(",")
            event = Event(comp[0], comp[1], comp[2], comp[3])
            events.append(event)
            line = f.readline().strip()
        f.close()
        return events
    

    def __storeToFile(self, allE):
        '''
        Store all the events in to the file
        raise CorruptedFileException if we can't save to the file 
        '''
        #open file (rewrite file)
        with open(self.__path, "w") as f:
            for event in allE:
                event_rf = event.get_id_event() + ',' + event.get_date() + ',' + event.get_time() + ',' + event.get_descr()         
                event_rf += "\n"
                f.write(event_rf)
    
    
    def store_event(self, event):
        '''
        Store the event to the file. Overwrite store
        pers - Event
        Post: event is stored to the file
        raise DuplicatedIdException for duplicated id 
        '''
        allE = self.__loadFromFile()
        if event in allE:
            raise EventRepositoryException()
        allE.append(event)
        self.__storeToFile(allE)
            
    
    def delete_event(self, id):
        '''
        remove an event from the repository
        id - string, the id of the event to be deleted
        :return: event
        :post: the repository won't contain the event with the give id
        :raise: ValueError if there is no event with the given id
        '''
        allE = self.__loadFromFile()
        pos = -1
        for i in range(len(allE)):
            if allE[i].get_pers_id() == id:
                poz = i
        if poz == -1:
            return None
        event = allE[poz]
        del allE[poz]
        self.__storeToFile(allE)
        return event
            
    def search_event(self, lst,  id):
        '''
        Find the event for a given id
        id - string
        return event with the given id or None if the event doesn't exist
        '''
        try:
            if lst[0].get_id_event() == id:
                return lst[0]
            return self.search_event(lst[1:], id)
        except IndexError:
            return None
        
    
    def update_event(self, new_event):
        '''
        Update event in the repo
        new_event = Event object which contains the new 
        data for the event and the id where should 
        modify 
        '''
        allE = self.__loadFromFile()
        ev = self.__search_person(new_event.get_id_event())
        if ev == None:
            return None
        allE.remove(ev)
        allE.append(new_event)
        self.__storeToFile(allE)
        return new_event 
    

    def removeAll(self):
        '''
        Remove all the students from the repository
        :post: the repository is empty
        '''
        self.__storeToFile([])

    def get_all_events(self):
        return self.__loadFromFile()
    
    def size(self):
        return len(self.__loadFromFile())
     

        
    
    
class AssignmentFileRepository:
    '''
        Store people from file
    '''
    
    def __init__(self, path):
        '''
        init the repository
        path - string, file path where the assignments are stored
        post: assignments are loaded from the file
        '''
        self.__path = path
    
    def __loadFromFile(self):
        '''
        Loads assignments from file
        raise CorruptedFIleException if there's an error when reading from the file 
        '''
        try:
            f = open(self.__path, "r")
        except IOError:
            #file not exists
            return 
        line = f.readline().strip()
        assig = []
        
        while line != "":
            comp = line.split(",")
            ass = Assignment(comp[0], comp[1])
            assig.append(ass)
            line = f.readline().strip()
        f.close()
        return assig
    

    def __storeToFile(self, allA):
        '''
        Store all the assignments in to the file
        raise CorruptedFileException if we can't save to the file 
        '''
        #open file (rewrite file)
        with open(self.__path, "w") as f:
            for assig in allA:
                assig_rf = assig.get_person_id() + ',' + assig.get_event_id()
                assig_rf += "\n"
                f.write(assig_rf)
    
    
    def store_assig(self, assig):
        '''
        Store the assignemnt to the file. Overwrite store
        assig - Assignment
        Post: assig is stored to the file
        '''
        allA = self.__loadFromFile()
        if assig in allA:
            return None
        allA.append(assig)
        self.__storeToFile(allA)
 
            
    def search_assig(self, assignment):
        '''
        Find the assignment for a given id
        id - string
        return the assignment with the given id or None if the assignment doesn't exist
        '''
        assignments = self.__loadFromFile()
        for assig in assignments:
            if assig == assignment:
                return assig
        return None
    

    def removeAll(self):
        '''
        Remove all the assignemnts from the repository
        :post: the repository is empty
        '''
        self.__storeToFile([])

    def get_all_assign(self):
        return self.__loadFromFile()
  
    def size(self):
        return len(self.__loadFromFile())
  
