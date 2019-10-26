'''
Created on Nov 20, 2017

@author: Geo
'''

class AssignRepository:
    '''
    Class to manage assignment data
    '''
    def __init__(self):
        self.__list = []
        
    def store_assig(self, assig):
        '''
        Store __list
        assig is the element of the class Assignment
        :param: assig
        :return: nothing
        :post: assignment added to the repository
        '''
        if self.search_assign(assig) is None:
            self.__list.append(assig)
            return assig
        else:
            return None
        
    def get_all_assign(self):
        '''
        Function that gets all the assignments from the list
        '''
        return self.__list
    
    

    def search_assign(self, assignment):
        '''
        Function that searches for a given assignment
        '''
        for assig in self.__list:
            if assignment == assig:
                return assig
        
        return None
    
  
            
            