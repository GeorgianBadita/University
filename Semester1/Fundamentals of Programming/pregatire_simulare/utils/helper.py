"""
    @author: Badita Marin-Georgian
    @email:  geo.badita@gmail.com
    @date:   12/9/2017 23:10
"""

def readInt(text):
    '''
    Function that reads and validates an int
    Function won't stop until the read input is a string
    :return: text - string - prompt to the user
    '''
    while True:
        try:
            cmd = int(input(text))
            return cmd
        except ValueError:
            print("The value must be an integer!")