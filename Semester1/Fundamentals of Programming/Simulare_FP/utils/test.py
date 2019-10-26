"""
    @author: Badita Marin-Georgian
    @email:  geo.badita@gmail.com
    @date:   12/12/2017 08:55
"""
from contorller.concert_ctr import ConcertController
from repository.concert_repository import ConcertRepository, ConcertDTORepository


'''
-----------------
|Testing the app|
-----------------
'''

def test_aggregate():
    file_repo = ConcertRepository("test.txt")
    dto_repo = ConcertDTORepository()
    conc_ctr = ConcertController(file_repo, dto_repo)
    concerts = conc_ctr.aggregate_location("Sala palatului")
    if concerts is not None:
        assert False
    else:
        assert True
    concerts = conc_ctr.aggregate_location("Cluj Arena")
    assert len(concerts) == 3


def test_view_concerts():
    file_repo = ConcertRepository("test.txt")
    dto_repo = ConcertDTORepository()
    conc_ctr = ConcertController(file_repo, dto_repo)
    concerts = conc_ctr.sort_by_value_ctr()
    assert len(concerts) == 10
    assert concerts[0].get_c_total() == 13720
    assert concerts[len(concerts) -1].get_c_total() == 220
    assert concerts[0].get_c_location() == "Cluj Arena"

test_aggregate()
test_view_concerts()