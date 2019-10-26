"""
    @author: Badita Marin-Georgian
    @email:  geo.badita@gmail.com
    @date:   1/28/2018 16:45
"""
from UI.user_interface import UserInterface
from domain.validators import JucatorValidator
from repository.file_repository import FileRepository
from services.jucator_service import JucatorService

repo = FileRepository("jucatori.txt")
val = JucatorValidator()
service = JucatorService(repo, val)
ui = UserInterface(service)
ui.show_ui()