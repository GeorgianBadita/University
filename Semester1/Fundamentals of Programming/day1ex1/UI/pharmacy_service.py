"""
    @author: Badita Marin-Georgian
    @email:  geo.badita@gmail.com
    @date:   12/11/2017 20:25
"""

from Domain.medicine import Medicine
from Domain.recipe import Recipe
class PharmacyService:
    '''
    Class that controls the operations performed
    '''

    def __init__(self, repo):
        self.__repo = repo

    def look_up(self, med_name):
        '''
        Function that finds all medicines after a string
        :param med_name: -string name of the medicine
        :return: the found medicine, None otherwise
        '''
        return self.__repo.find_by_name(med_name)

    def create_recipe(self, meds):
        '''
        Function that creates a recipe
        :return: a Recipe
        '''
        recipe = Recipe(meds)
        return recipe.get_total_price()
