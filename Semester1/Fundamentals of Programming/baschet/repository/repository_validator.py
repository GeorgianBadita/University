"""
    @author: Badita Marin-Georgian
    @email:  geo.badita@gmail.com
    @date:   1/28/2018 16:25
"""


class RepositoryException(Exception):

    def __init__(self, err):
        self.__err = err

    def __str__(self):
        return self.__err