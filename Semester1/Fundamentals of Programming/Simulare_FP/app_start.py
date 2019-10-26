"""
    @author: Badita Marin-Georgian
    @email:  geo.badita@gmail.com
    @date:   12/12/2017 08:18
"""
from UI.concert_ui import ConcertUI
from contorller.concert_ctr import ConcertController
from repository.concert_repository import ConcertRepository, ConcertDTORepository

'''
-------------------
|Assembling the app|
-------------------
'''

def assemble():
    dto_repo = ConcertDTORepository()
    file_repo = ConcertRepository("concerts.txt")
    conc_ctr = ConcertController(file_repo, dto_repo)
    conc_ui = ConcertUI(conc_ctr)
    conc_ui.show_ui()

assemble()