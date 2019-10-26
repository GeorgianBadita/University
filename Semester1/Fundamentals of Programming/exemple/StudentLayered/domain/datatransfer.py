'''
Created on Nov 10, 2017

@author: istvan
'''
class AddressReportItem:
    """
      Helper class for creating reports
    """
    def __init__(self,address,count):
        self.__address = address
        self.__count = count
        
    def getAddress(self):
        return self.__address
    
    def getCount(self):
        return self.__count
    
    def incCount(self):
        self.__count+=1


