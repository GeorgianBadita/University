"""
    @author: Badita Marin-Georgian
    @email:  geo.badita@gmail.com
    @date:   1/26/2018 23:34
"""


def succ_search(my_list, elem):
    """
    Function that checks if an element is in a list
    :param my_list: list of integers
    :param elem: the element to be searched
    :return: the position of the element if it exists, -1 otherwise
    """

    pos = 0
    found = False

    while pos < len(my_list) and found == False:
        if my_list[pos] == elem:
            found = True
        pos += 1

    if found == True and pos < len(my_list):
        return pos
    return -1


my_l = [1, 2, 3, 4, 4, 2,3 ,1,2]

print(succ_search(my_l, 1))