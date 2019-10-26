"""
    @author: Badita Marin-Georgian
    @email:  geo.badita@gmail.com
    @date:   12/12/2017 08:05
"""
class Concert:
    '''
    Class for concert
    '''

    def __init__(self, con_id, con_loc, con_pri, con_pers):
        '''
        Initialise the concert
        :param con_id: -string
        :param con_loc: -string
        :param con_pri: -string
        :param con_pers: -string
        '''
        self.__con_id = con_id
        self.__con_loc = con_loc
        self.__con_price = con_pri
        self.__con_pers = con_pers

    def get_con_id(self):
        '''
        Getter method
        :return:
        '''
        return self.__con_id

    def get_con_loc(self):
        '''
        Getter method
        :return:
        '''
        return self.__con_loc

    def get_con_price(self):
        '''
        Getter method
        :return:
        '''
        return self.__con_price

    def get_con_pers(self):
        '''
        Getter method
        :return:
        '''
        return self.__con_pers

    def __str__(self):
        '''
        Function for printing a concert
        :return: the string representation of a concert
        '''
        return "ID: " + self.__con_id + "   " + "Loc: " + self.__con_loc + "    " + "Price: " + self.__con_price + "    " + "Pers: " + self.get_con_pers()

def test_concert():
    con = Concert('111', "Cluj Arena", "20", "11")
    assert con.get_con_id() == "111"
    assert con.get_con_loc() == "Cluj Arena"
    assert con.get_con_pers() == "11"
    assert con.get_con_price() == "20"

test_concert()