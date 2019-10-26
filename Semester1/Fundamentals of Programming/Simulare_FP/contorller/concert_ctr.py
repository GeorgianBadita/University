"""
    @author: Badita Marin-Georgian
    @email:  geo.badita@gmail.com
    @date:   12/12/2017 08:18
"""

'''
------------------------
|Application controller|
------------------------
'''

class ConcertController:
    '''
    Class controlling the Concert operations
    '''
    def __init__(self, con_rep, dto_rep):
        self.__rep = con_rep
        self.__dto_rep = dto_rep

    def aggregate_location(self, location):
        '''
        Function that gets all concerts at a given location
        :param location: -string input given by the user
        :return: all concerts at the given location if there are any, None otherwise
        '''
        return self.__rep.aggregate_location_rep(location)

    def get_all_concerts_ctr(self):
        '''
        Functoon that returns a list with all concers
        :return:
        '''
        return self.__rep.get_all_concerts()

    def store_concerts_dto(self, concerts):
        '''
        Function that stores a lsit of concerts to DTORepo
        :return:
        '''
        for concert in concerts:
            self.__dto_rep.store_dto(concert)

    def sort_by_value_ctr(self):
        '''
        Function that sorts all concertsDTO by total value (concert_price*concert_people)
        :return: all concerts sorted by the total value
        '''
        all_concerts = self.__rep.get_all_concerts()
        self.store_concerts_dto(all_concerts)
        return self.__dto_rep.sort_by_total_value()