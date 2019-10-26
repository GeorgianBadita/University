'''
Created on Nov 20, 2017

@author: Geo
'''

from domain.validator import PersonValidator, EventValidator
from repository.file_repo import PersonFileRepository, EventFileRepository, AssignmentFileRepository
from repository.event_repository import EventRepository
from repository.person_repository import PersonRepository
from services.person_service import PersonService
from services.event_service import EventService
from ui.console_ui import ConsoleUI
from repository.assignment_repository import AssignRepository
from services.assignment_service import AssignmentService


person_val = PersonValidator()
event_val = EventValidator()
person_rep = PersonRepository(person_val)
event_rep = EventRepository(event_val)
assig_rep = AssignRepository()
'''
person_rep = PersonFileRepository("testpeople.txt")
person_rep.removeAll()
event_rep = EventFileRepository("testevents.txt")
event_rep.removeAll()
assig_rep = AssignmentFileRepository("testassig.txt")
assig_rep.removeAll()
'''
ctr_person = PersonService(person_rep)
ctr_event = EventService(event_rep)
ctr_assign = AssignmentService(assig_rep)

user_interface = ConsoleUI(ctr_event, ctr_person, ctr_assign)
user_interface.show_ui()




