"""
    @author: Badita Marin-Georgian
    @email:  geo.badita@gmail.com
    @date:   7/23/18 19:19
"""


from PyQt5.QtWidgets import QApplication

from utils.tests import Tests
from domain.validator import BookValidator
from repository.repository import Repository
from repository.file_repo import FileRepository
from service.service import Service
from gui.gui import GUI
import sys

t = Tests()
t.run_tests()

val = BookValidator()
#repo = Repository(val)
repo = FileRepository(val, "book_file.txt")
repo.clear_file()
srv = Service(repo)



if __name__ == '__main__':
    app = QApplication(sys.argv)
    w = GUI(srv)
    w.show()
    sys.exit(app.exec())