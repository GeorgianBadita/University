"""
    @author: Badita Marin-Georgian
    @email:  geo.badita@gmail.com
    @date:   1/26/2018 23:39
"""


def binary_search(my_list, elem):
    """
    Function that searches an element into a list
    :param my_list: list of integers
    :param elem: element to be searched
    :return: the position of the element if it is in the list, -1 otherwise
    :pre: the elements of my_list must be sorted
    """

    if len(my_list) == 0:
        return -1

    if len(my_list) == 1 and my_list[-1] == elem:
        return 0

    left = 0
    right = len(my_list) - 1
    while left <= right:
        mid = (left + right)//2
        if my_list[mid] == elem:
            return mid
        elif my_list[mid] > elem:
            right = mid - 1
        else:
            left = mid + 1
    return -1

my_l = [9]

print(binary_search(my_l, 9))