'''
Created on Nov 20, 2017

@author: Geo
'''
from domain.validator import ValidatorException
from repository.event_repository import EventRepositoryException
from repository.person_repository import PersonRepositoryException
from utils.helper import read_int
class ConsoleUI:
    '''
    Class which controls the UI
    '''
    
    def __init__(self, event_service, person_service, assig_service):
        self.__event_service = event_service
        self.__person_service = person_service
        self.__assig_service = assig_service
        
        
    def __print_ui(self):
        '''
        Function that prints the user interface
        '''
        print("\t1. Add Person\n\t2. Add Event\n\t3. Delete Person\n\t4. Delete Event\n\t5. Update Person\n\t6. Update Event\n\t7. Print people\n\t8. Print events\n\t9. Search person\n\t10. Search event\n\t11. Enroll person to event\n\t12. Print person enrolled\n\t13. Add n random people\n\t14. Print most people to events\n\t15. Print top 20% events with most participants\n\t x Exit")
        

    def __add_person(self):
        '''
        Function that adds a person to the list
        :pre: reads the arguments for creating a new person
        '''
        id_pers = input("Give the id of the person: ")
        name = input("Give the name of the person: ")
        address = input("Give the address of the person: ")
        try:
            self.__person_service.create_person(id_pers, name, address)
            print("Person " + name + " was added!")
        except ValidatorException as ex:
            print(ex.args)
        except PersonRepositoryException:
            print("There's already a person with this id!")
        
    
    
    def __add_event(self):
        '''
        Function that adds an event to the list
        :pre: reads the arguments for creating a new event
        '''
        id_event = input("Give the id of the event: ")
        date = input("Give the date of the event in format dd/mm/yyyy: ")
        time = input("Give the time of the event in format hh:mm: ")
        descr = input("Give the description of the event: ")
        try:
            self.__event_service.create_event(id_event, date, time, descr)
            print("Event " + id_event + " was added!")
        except ValidatorException as ex:
            print(ex.args)
        except EventRepositoryException:
            print("There's already an event with this id!")
        
        
    def __view_events(self):
        '''
        Function that prints all the events
        '''
        all_events = self.__event_service.get_all_events_service()
        if len(all_events) == 0:
            print("There are no events in the list")
        else:
            print("    Id_event        Date         Time    Description")
            for event in all_events:
                print("\t" + event.get_id_event() + "\t" + event.get_date() + "\t" + event.get_time() + "\t" + event.get_descr())
            print("\n\n")
            
        
    
    def __view_people(self):
        '''
        Function that prints all people 
        '''
        all_people = self.__person_service.get_all_people_service()
        if len(all_people) == 0:
            print("There are no people in the list")
        else:
            print("    Id_person   Name    Address")
            for person in all_people:
                print("\t" + person.get_id_pers() + "\t" +  person.get_name() + "\t" + person.get_adr())
            print("\n\n")
                
            
    
    def __delete_event(self):
        '''
        Function that deletes an event by the given id
        '''
        id_event = input("Give the event id: ")
        deleted = self.__event_service.delete_event_service(id_event)
        if deleted == None:
            print("There's no event with this id!")
        else:
            print("Event ", deleted.get_id_event() + " was deleted!")
    
    def __delete_person(self):
        '''
        Function that deletes a person by the given id
        '''
        id_person = input("Give the person id: ")
        deleted = self.__person_service.delete_person_service(id_person)
        if deleted == None:
            print("There's no event with this id!")
            
        else:
            print("Person ", deleted.get_name() + " was deleted!")
        
    
    
    def __update_person(self):
        '''
        Function that updates the a person
        '''
        id_person = input("Give the person id: ")
        name = input("Give the name of the person: ")
        address = input("Give the address of the person: ")
        try:
            updated = self.__person_service.update_person_service(id_person, name, address)
            if updated == None:
                print("There's no person with this id!")
            else:
                print("Person ", updated.get_name() + " was updated!")
        except ValidatorException as ex:
            print(ex.args)
        
    def __update_event(self):
        
        '''
        Function that updates the an event
        '''
        
        id_event = input("Give the event id: ")
        date = input("Give the date of the event in format mm/dd/yyyy: ")
        time = input("Give the time of the event in format hh:mm: ")
        descr = input("Give the event description: ")
        try:
            updated = self.__event_service.update_event_service(id_event, date, time, descr)
            if updated == None:
                print("There's no event with this id!")
            else:
                print("Event ", updated.get_id_event() + " was updated!")
        except ValidatorException as ex:
            print(ex.args)
        
    
    def __search_person(self):
        '''
        Function that searches for a person by the given id
        :return: nothing
        '''
        id_person = input("Give the person id: ")
        searched = self.__person_service.search_person_service(id_person)
        if searched is None:
            print("There's no person with this id!")
        else:
            print("    Id_person   Name    Address")
            print("\t" + searched.get_id_pers() + "\t" +  searched.get_name() + "\t" + searched.get_adr())
            print("\n\n")
    
    
    def __search_event(self):
        '''
        Function that searches for an event by the given id
        :return: nothing
        '''
        id_event = input("Give the event id: ")
        searched = self.__event_service.search_event_service(id_event)
        if searched is None:
            print("There's no event with this id!")
        else:
            print("    Id_event        Date         Time    Description")
            print("\t" + searched.get_id_event() + "\t" + searched.get_date() + "\t" + searched.get_time() + "\t" + searched.get_descr())
            print("\n\n")
    
    
    
    def __enroll_person(self):
        '''
        Function that enrolls a person to an event
        :return: None
        '''
        
        id_pers = input("Give the person id: ")
        id_event = input("Give the event id: ")
        person = self.__person_service.search_person_service(id_pers)
        event = self.__event_service.search_event_service(id_event)
        if person is None or event is None:
            print("The event or the person doesn't exist!")
        else:
            id_pers = person.get_id_pers()
            id_event = event.get_id_event()
            assignment = self.__assig_service.create_assig(id_pers, id_event)
            if assignment is None:
                print("A person can't be enrolled to the same event twice!")
            else:
                print(person.get_name() + " was enrolled in the event with id " + event.get_id_event())
    
    def __sorted_enrolled(self):
        '''
        Function that sorts the events of a person by description and date
        '''
        id_pers = input("Give the person id: ")
        person = self.__person_service.search_person_service(id_pers)
        if person is None:
            print("There is no person with this id!")
        else:
            person_events = self.__assig_service.get_pers_enrolled_serv(person.get_id_pers())
            sorted_person_events = self.__assig_service.sort_pers_enrolled_serv(person_events)
            if sorted_person_events is not None:
                print("Person ", person.get_name(), " is enrolled in: ")
                print("    Id_event        Date         Time    Description")
                for event in sorted_person_events:
                    event_ref = self.__event_service.search_event_service(event)
                    print("\t" + event_ref.get_id_event() + "\t" + event_ref.get_date() + "\t" + event_ref.get_time() + "\t" + event_ref.get_descr())
                print("\n\n")
            else: print("Person is not enrolled in any event!")
    
    
    def __gen_random_people(self):
        '''
        Function that generates n random people
        '''
        number = read_int("Give the number of random perople: ") 
        self.__person_service.gen_random_people_service(number)
    
    
    def __print_most_participants(self):
        '''
        Function that prints people who participate to most events
        '''
        list_pers = self.__assig_service.print_most_participants()
        print("    Id_person   Name    Address")
        for person in list_pers:
            person_ref = self.__person_service.search_person_service(person)
            print("\t" + person_ref.get_id_pers() + "\t" +  person_ref.get_name() + "\t" + person_ref.get_adr())
            
        print("\n\n")
    

    def __first_20_percent(self):
        '''
        Function that prints the first 20% events with most people
        '''
        list_events = self.__assig_service.first_20_percent()
        print("    Id_event    Descripton    Num_pers")
        for event in list_events:
            event_ref = self.__event_service.search_event_service(event[0])
            print("     " + event_ref.get_id_event() + "          " + event_ref.get_descr() + "\t" + "\t" +  event[1])
        print("\n\n") 
    
    def show_ui(self):
        '''
        Function that controls the user interface actions
        '''
        
        self.__auto_add_pers_events_enroll_mem_repo()
        while True:
            self.__print_ui()
            cmd = input("Give a command: ")
            
            if cmd == '1':
                self.__add_person()
            if cmd == '2':
                self.__add_event()
            if cmd == '3':
                self.__delete_person()
            if cmd == '4':
                self.__delete_event()
            if cmd == '5':
                self.__update_person()
            if cmd == '6':
                self.__update_event()
            if cmd == '7':
                self.__view_people()
            if cmd == '8':
                self.__view_events()
            if cmd == '9':
                self.__search_person()
            if cmd == '10':
                self.__search_event()
            if cmd == '11':
                self.__enroll_person()
            if cmd == '12':
                self.__sorted_enrolled()
            if cmd == '13':
                self.__gen_random_people()
            if cmd == '14':
                self.__print_most_participants()
            if cmd == '15':
                self.__first_20_percent()
            if cmd == 'x':
                exit()
            
    def __auto_add_pers_events_enroll_mem_repo(self):
        '''
        Function that gives data to the program
        '''
        
        pers1 = self.__person_service.create_person("1", "Badita", "Valcea")
        pers2 = self.__person_service.create_person("2", "Cristina", "Sibiu")
        pers3 = self.__person_service.create_person("3", "Adina", "Cluj-Napoca")
        pers4 = self.__person_service.create_person("4", "Mirabela", "Timisoara")
        
        
        ev1 = self.__event_service.create_event("1", "20/05/2012", "10:50", "Xuneral")
        ev2 = self.__event_service.create_event("2", "21/06/2013", "11:00", "Wedding")
        ev3 = self.__event_service.create_event("3", "17/06/2020", "12:40", "Birthday Party!")
        ev4 = self.__event_service.create_event("4", "21/03/2019", "09:30", "Wedding")
        ev5 = self.__event_service.create_event("5", "19/07/2020", "11:40", "Funeral")
        
        self.__assig_service.create_assig('1', '1')
        self.__assig_service.create_assig('1', '2')
        self.__assig_service.create_assig('2', '3')
        self.__assig_service.create_assig('3', '4')
        self.__assig_service.create_assig('4', '1')
        self.__assig_service.create_assig('2', '2')  
        self.__assig_service.create_assig('1', '5')
        self.__assig_service.create_assig('3', '1')
    