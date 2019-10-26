"""
    @author: Badita Marin-Georgian
    @email:  geo.badita@gmail.com
    @date:   1/6/2018 23:46
"""
from UI.ui import UI
from repository.discipline_repository import DisciplineRepository
from repository.student_repository import StudentRepository
from services.discipline_service import DisciplineService
from services.student_service import StudentService

st_repo = StudentRepository()
disc_repo = DisciplineRepository()

st_service = StudentService(st_repo)
disc_service = DisciplineService(disc_repo)

ui = UI(st_service, disc_service)

ui.show_ui()