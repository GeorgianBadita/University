from domain.validators import StudentValidator
from domain.validators import GradeValidator
from repository.inmemory import StudentRepository
from repository.inmemory import GradeRepository
from repository.file import StudentFileRepository
from repository.file import GradeFileRepository
from services.services import StudentService
from services.services import GradingService

from ui.console import ConsoleUI

#Application coordinator
#Use dependency injection pattern to asemble the application

#create a validator
val = StudentValidator()

#create repository
# repo = StudentRepository()

repo = StudentFileRepository("students.txt")

#create controller and inject dependencies
srv = StudentService(val, repo)

#create Grade controller
#gradeRepo = GradeRepository()
gradeRepo = GradeFileRepository("grades.txt")

srvgr =  GradingService(gradeRepo, GradeValidator(), repo)

#create console ui and provide (inject) the controller
ui = ConsoleUI(srv,srvgr)
ui.startUI()