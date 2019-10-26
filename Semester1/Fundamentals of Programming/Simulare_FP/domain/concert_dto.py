"""
    @author: Badita Marin-Georgian
    @email:  geo.badita@gmail.com
    @date:   12/12/2017 08:05
"""
class ConcertDTO:
    '''
    Class for making a view about concerts
    '''
    def __init__(self, c_id, location):
        self.__c_id = c_id
        self.__location = location
        self.__total = None

    def get_c_id(self):
        '''
        Getter method
        :return:
        '''
        return self.__c_id

    def get_c_location(self):
        '''
        Getter method
        :return:
        '''
        return self.__location

    def get_c_total(self):
        '''
        Getter method
        :return:
        '''
        return self.__total

    def set_c_total(self, new_total):
        '''
        Setter method
        :param new_total:
        :return:
        '''
        self.__total = new_total

    def __str__(self):
        return "ID: " + self.get_c_id() + "   " + "Loc:" + str(self.__location) + "  " + "Total: " + str(self.get_c_total())