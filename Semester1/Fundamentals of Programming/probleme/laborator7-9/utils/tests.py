'''
Created on Nov 20, 2017

@author: Geo
'''
from domain.person import Person
from domain.event import Event
from domain.assignment import Assignment
from domain.validator import PersonValidator, EventValidator, ValidatorException
from repository.person_repository import PersonRepository, PersonRepositoryException
from repository.event_repository import EventRepository, EventRepositoryException
from services.person_service import PersonService
from services.event_service import EventService
from utils.helper import hour_validation, date_validation
from pygments.lexers.textfmts import TodotxtLexer
from unittest.case import TestCase
from repository.file_repo import PersonFileRepository, EventFileRepository,\
    AssignmentFileRepository
from setuptools.py31compat import unittest_main
#from _ast import Assign



class test_person_entity(TestCase):
    
    def test_person_entity(self):
        '''
        Function for testing the person class
        '''
        person = Person('1', 'Geo', 'Olanu')
        self.assertEqual(person.get_id_pers(), '1')
        self.assertEqual(person.get_name(), 'Geo')
        self.assertEqual(person.get_adr(), 'Olanu')

class test_event_entity(TestCase):
    
    def test_event_entity(self):
        '''
        Function for testing the event class
        '''
        event = Event('1', '20/12/2012', '10:59', 'Wedding')

        self.assertEqual(event.get_id_event(), '1')
        self.assertEqual(event.get_date(), '20/12/2012')
        self.assertEqual(event.get_time(), '10:59')
        self.assertEqual(event.get_descr(), 'Wedding')


class test_hour_validation(TestCase):

    def test_hour_validation(self):
        '''
        Function for testing the hour validation function
        '''
        errors = hour_validation("25:60")
        self.assertEqual(len(errors), 2)
        errors = hour_validation("10:60")
        self.assertEqual(len(errors),1)
        errors = hour_validation("9:59")
        self.assertEqual(len(errors),1)
        errors = hour_validation("09:59")
        self.assertEqual(len(errors),0)
        errors = hour_validation("akfla")
        self.assertEqual(errors, ['The hour format is incorrect!'])



class test_date_validator(TestCase):
    
    def test_date_validation(self):
        '''
        Function for testing the date validation function
        '''
        errors = date_validation('33/15/2020')
        self.assertEqual(len(errors), 2)
        errors = date_validation('13/13/20100')
        self.assertEqual(len(errors), 2)
        errors = date_validation('12/12/2012')
        self.assertEqual(len(errors), 0)
        errors = date_validation('12/13/2012')
        self.assertEqual(len(errors), 1)


class test_person_validaotr(TestCase):
    

    def test_person_validator(self):
        '''
        Function to test the person validation
        '''
        person = Person("", "", "")
        validator = PersonValidator()
        with self.assertRaises(Exception):
            validator.validate(person)
            
        person = Person("1", "", "")
        
        with self.assertRaises(Exception):
            validator.validate(person)
        
        person = Person("1", "Gabi", "")
        
        with self.assertRaises(Exception):
            validator.validate(person)
            
class test_event_validator(TestCase):
    
    def test_event_validator(self):
        '''
        Function to test the event validation
        '''
        event = Event("", "", "", "")
        validator = EventValidator()
        with self.assertRaises(Exception):
            validator.validate(event)
        
        
        event = Event("1", "", "", "")
        
        with self.assertRaises(Exception):
            validator.validate(event)
            
        event = Event("1", "32/12/2051", "", "Funeral")
        
        with self.assertRaises(Exception):
            validator.validate(event)
        

class test_person_repo(TestCase):

    def test_person_repo(self):
        '''
        Function to test the person repository store
        '''
        person = Person('1', "Ion", "Arad")
        repo = PersonRepository(PersonValidator)
        self.assertEqual(repo.size(), 0)
        repo.store_person(person)
        self.assertEqual(repo.size(), 1)
        person = Person('2', "Andrei", "Valcea")
        repo.store_person(person)
        self.assertEqual(repo.size(), 2)
        repo.delete_person(person.get_id_pers())
        self.assertEqual(repo.size(), 1)
        
        
class test_event_repi(TestCase):
    
    def test_event_repo(self):
        '''
        Function to test the event repository store
        '''
        event = Event('1', "20/06/2010", "10:56", "Funeral")
        repo = EventRepository(EventValidator)
        self.assertEqual(repo.size(), 0)
        repo.store_event(event)
        self.assertEqual(repo.size(), 1)
        event = Event('2', "15/06/2011", "12:03", "Wedding")
        repo.store_event(event)
        self.assertEqual(repo.size(), 2)
        repo.delete_event(event.get_id_event())
        self.assertEqual(repo.size(), 1)
        event = Event("1", "12/12/2012", "11:07", "Birthday Party")
    


class test_create_person_service(TestCase):
    
    def test_create_person_service(self):
        '''
        Function to test the person service create method
        '''
        val = PersonValidator()
        repo = PersonRepository(val)
        person_service = PersonService(repo)
        person = person_service.create_person("1", "Badita", "Valcea")
        self.assertEqual(person.get_id_pers(), "1")
        self.assertEqual(person.get_adr(), "Valcea")
        self.assertEqual(person.get_name(), "Badita")
        allPeople = person_service.get_all_people_service()
        self.assertEqual(len(allPeople), 1)
        
        with self.assertRaises(Exception):
            person = person_service.create_person("1", "Adi", "Baia Mare")
        
        
        with self.assertRaises(Exception):
            person = person_service.create_person("", "", "")
        
class test_create_event_service(TestCase):
    

    def test_create_event_service(self):
        '''
        Function to test the event service create method
        '''
        val = EventValidator()
        repo = EventRepository(val)
        event_service = EventService(repo)
        event = event_service.create_event("1", "20/12/2013", "10:59", "Wedding")
        self.assertEqual(event.get_id_event(), "1")
        self.assertEqual(event.get_date(), "20/12/2013")
        self.assertEqual(event.get_time(),"10:59")
        self.assertEqual(event.get_descr(), "Wedding")
       
        allEvents = event_service.get_all_events_service()
        
        self.assertEqual(len(allEvents), 1)
        
        with self.assertRaises(Exception):
            event = event_service.create_event("1", "20/11/2014", "20:59", "Funeral")
        
        with self.assertRaises(Exception):
            event = event_service.create_event("", "", "25:67", "")
        
class test_create_assignment(TestCase):

    def test_create_assignment(self):
        '''
        Functon that tests the create assignment feature
        '''
        
        person = Person('1', 'Geo', 'Olanu')
        event = Event('1', "20/07/2019", "10:58", "Wedding")
        assignment = Assignment(person.get_id_pers(), event.get_id_event())
        self.assertEqual(assignment.get_person_id(), '1')
        self.assertEqual(assignment.get_event_id(),'1')



class test_store(TestCase):
    
    def setUp(self):
        self.fileName = "testpeople.txt"
        self.repo = PersonFileRepository(self.fileName)
        self.repo.removeAll()
        self.person3 = Person("5", "Andrei", "Roman")
        self.person1 = Person("2", "Alex", "Caracal")
        self.person2 = Person("3", "Andrada", "Valcea")
        self.repo.store_person(self.person3)
        self.repo.store_person(self.person1)
        self.repo.store_person(self.person2)  
        self.repo2 = PersonFileRepository(self.fileName)
        
    def tearDown(self):
        self.repo.removeAll()
        
    def test_store(self):
        
        self.assertEqual(self.repo.size(), 3)
        self.assertEqual(self.repo.search_person(self.repo.get_all_people(),"2"), self.person1)
        #verify if the person is stored in the file
        self.assertEqual(self.repo2.size(), 3)
        self.assertEqual(self.repo2.search_person(self.repo.get_all_people(),"3"),self. person2)
        
class test_store_ev(TestCase):
    
    def setUp(self):
        self.fileName = "testevents.txt"
        self.repo = EventFileRepository(self.fileName)
        self.repo.removeAll() 
        self.event1 = Event("1", "20/11/2012", "10:58", "Funeral")
        self.event2 = Event("2", "20/09/2013", "11:21", "Party")
        self.event3 = Event("3", "19/06/2017", "12:31", "Wedding")
        self.repo.store_event(self.event1)
        self.repo.store_event(self.event2)
        self.repo.store_event(self.event3)
    
    def tearDown(self):
        self.repo.removeAll()
        
    def test_store_ev(self):
        self.assertEqual(self.repo.size(), 3)
        self.assertEqual(self.repo.search_event(self.repo.get_all_events(),"2"), self.event2)    
        #verify if the person is stored in the file
        self.repo2 = EventFileRepository(self.fileName)
        self.assertEqual(self.repo2.size(), 3)
        self.assertEqual(self.repo2.search_event(self.repo.get_all_events(),"2"), self.event2)
        


class test_store_assig(TestCase):

    
    def setUp(self):
        
        self.fileName = "testassig.txt"
        self.repo = AssignmentFileRepository(self.fileName)
        self.repo.removeAll()
        self.person3 = Person("5", "Andrei", "Roman")
        self.person1 = Person("2", "Alex", "Caracal")
        self.person2 = Person("3", "Andrada", "Valcea")
        self.event1 = Event("1", "20/11/2012", "10:58", "Funeral")
        self.event2 = Event("2", "20/09/2013", "11:21", "Party")
        self.event3 = Event("3", "19/06/2017", "12:31", "Wedding")
        
        self.assignment1 = Assignment(self.person1.get_id_pers(), self.event1.get_id_event())
        self.assignment2 = Assignment(self.person2.get_id_pers(), self.event2.get_id_event())
        self.assignment3 = Assignment(self.person3.get_id_pers(), self.event3.get_id_event())
        
        self.repo.store_assig(self.assignment1)
        self.repo.store_assig(self.assignment2)
        self.repo.store_assig(self.assignment3)
        self.assertEqual(self.repo.size(), 3)
        
        
        self.repo2 = AssignmentFileRepository(self.fileName)
        self.assignemnt4 = Assignment(self.person1.get_id_pers(), self.event2.get_id_event())
        self.repo2.store_assig(self.assignemnt4)
    


    def tearDown(self):
        self.repo.removeAll()

    def test_store_assig(self):
                
        self.assertEqual(self.repo.search_assig(self.assignment1), self.assignment1)
        self.assertEqual(self.repo2.size(), 4)
        
      

    
    if __name__ == "__main__":
        unittest_main()

