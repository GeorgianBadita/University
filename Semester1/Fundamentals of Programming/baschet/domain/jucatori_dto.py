"""
    @author: Badita Marin-Georgian
    @email:  geo.badita@gmail.com
    @date:   1/28/2018 17:09
"""

class JucatoriDTO(object):
    """
    Classa pentru raport
    """

    def __init__(self, fundasi, extreme, pivoti):
        self.__fundasi = fundasi
        self.__extreme = extreme
        self.__pivoti = pivoti

    def get_fundasi(self):
        return self.__fundasi

    def get_pivoti(self):
        return self.__pivoti

    def get_extreme(self):
        return self.__extreme