from repository.inmemory import InMemoryRepository
from services.studentservice import StudentService
from ui.console import Console
from domain.validators import StudentValidator
#from repository.filerepo import StudentRepositoryFile
# from repository.filerepo import StudentRepositoryFile

rep = InMemoryRepository()
#rep = StudentRepositoryFile("test.txt")
val = StudentValidator()
ctr = StudentService(rep,val)
ui = Console(ctr)

ui.showUI()
