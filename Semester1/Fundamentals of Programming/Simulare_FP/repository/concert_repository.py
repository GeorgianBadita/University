"""
    @author: Badita Marin-Georgian
    @email:  geo.badita@gmail.com
    @date:   12/12/2017 08:05
"""
from domain.concert import Concert
from domain.concert_dto import ConcertDTO


class ConcertRepository:
    '''
    Class for managing concert data
    '''

    def __init__(self, path):
        '''

        :param path: - string, name of the fi;e
        '''
        self.__path = path

    def load_from_file(self):
        '''
        Function that loads concerts from file
        :return:
        '''
        try:
            f = open(self.__path, "r")
        except IOError:
            #file doesn't exist
            return

        concerts = []
        line = f.readline().strip()
        while line != "":
            params = line.split(",")
            concert = Concert(params[0], params[1], params[2], params[3])
            concerts.append(concert)
            line = f.readline().strip()
        f.close()
        return concerts


    def get_all_concerts(self):
        '''
        Function that gets all concerts as list
        :return:
        '''
        return self.load_from_file()

    def aggregate_location_rep(self, loc):
        '''
        Function that gets all concerts at a location
        :return: concerts at a given location, None if there aren't any concerts at
        that location
        '''
        concerts = []
        all_c = self.load_from_file()
        for concert in all_c:
            if concert.get_con_loc() == loc:
                concerts.append(concert)

        if len(concerts) > 0:
            return concerts
        return None

def test_load_from_file():
    repo = ConcertRepository("testfile.txt")
    all_c = repo.load_from_file()
    for conc in all_c:
        print(conc.get_con_id() + "    " + conc.get_con_loc() + conc.get_con_price())

#test_load_from_file()


class ConcertDTORepository:
    '''
    Repository for the DTO
    '''

    def __init__(self):
        self.__l = {}

    def store_dto(self, concert):
        '''
        Stores the dto into the list
        :return:
        '''

        if concert.get_con_id() not in self.__l:
            new_con_dto = ConcertDTO(concert.get_con_id(), concert.get_con_loc())
            new_con_dto.set_c_total(int(concert.get_con_pers())*int(concert.get_con_price()))
            self.__l[new_con_dto.get_c_id()] = new_con_dto

    def get_all(self):
        '''
        Returns all concertDTO as list
        :return:
        '''
        return list(self.__l.values())

    def sort_by_total_value(self):
        '''
        Sorts descending by total value of each concert
        :return:
        '''
        concert_dto = self.get_all()
        for i in range(0, len(concert_dto) - 1):
            for j in range(i + 1, len(concert_dto)):
                if concert_dto[i].get_c_total() < concert_dto[j].get_c_total():
                    concert_dto[i],concert_dto[j] = concert_dto[j],concert_dto[i]
                    
       #concer_dto = sorted(concer_dto, key=lambda x:x.get_c_total, reverse=True)
        return concert_dto