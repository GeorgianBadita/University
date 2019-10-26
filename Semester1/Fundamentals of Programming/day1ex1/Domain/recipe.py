"""
    @author: Badita Marin-Georgian
    @email:  geo.badita@gmail.com
    @date:   12/11/2017 19:40
"""
class Recipe:
    '''
    Class that controsl the Recipe functionality
    '''

    def __init__(self, medicines):
        self.medicines = medicines

    def get_total_price(self):
        '''
        Function that gets the total price of a list of medicines
        :return:
        '''
        sum = 0
        for med in self.medicines:
            sum += med.get_price()
        return sum