"""
    @author: Badita Marin-Georgian
    @email:  geo.badita@gmail.com
    @date:   1/26/2018 23:30
"""


def seq_search(my_list, elem):
    """
    Function that checks if a given element is in the list
    :param my_list: list of integers
    :param elem: the element to be searched
    :return: the position of the element if it exists, else returns -1
    """

    pos = -1
    for i in range(len(my_list)):
        if my_list[i] == elem:
            pos = i

    return pos


my_l = [1, 2, 3, 4, 4, 2,3 ,1,2]

print(seq_search(my_l, 10))

