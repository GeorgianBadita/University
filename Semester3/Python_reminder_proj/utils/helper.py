"""
    @author: Badita Marin-Georgian
    @email:  geo.badita@gmail.com
    @date:   7/25/18 21:08
"""


def concatenate(strings):
    """
    Function which concatenates a list of strings
    :param strings: -list of strings
    :return: a string containing all the strings from strings
    """
    string = ""
    for s in strings:
        string = string + s + "\n"

    return string
