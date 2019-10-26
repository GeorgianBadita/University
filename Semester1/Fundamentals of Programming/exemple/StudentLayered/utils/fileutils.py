'''
Created on Nov 9, 2014

@author: istvan
'''

def clearFileContent(fileName):
    """
      Clear the content of the file
      Post: the given file exist and is empty
    """
    f = open(fileName, "w")
    f.close()