"""
    @author: Badita Marin-Georgian
    @email:  geo.badita@gmail.com
    @date:   12/11/2017 19:40
"""

class Medicine:
    '''
    The medicine class
    '''

    def __init__(self, name, price):
        self.__name = name
        self.__price = price

    def get_name(self):
        '''
        Function that gets the name of the medicine
        :return:
        '''
        return self.__name

    def get_price(self):
        '''
        Function that get the price of the medicine
        :return: 
        '''
        return self.__price

    def __str__(self):
        return "Name: " + self.get_name() + "   " + "price: " + str(self.get_price())