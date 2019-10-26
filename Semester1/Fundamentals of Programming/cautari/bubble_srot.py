"""
    @author: Badita Marin-Georgian
    @email:  geo.badita@gmail.com
    @date:   1/27/2018 00:21
"""


def bubble_sort(l):
    """
    Function that sorts a list of elements
    :param l: list of elements
    :return: the sorted list
    """

    sorted = False

    while not sorted:
        sorted = True
        for i in range(len(l) - 1):
            if l[i] > l[i + 1]:
                aux = l[i]
                l[i] = l[i + 1]
                l[i + 1] = aux
                sorted = False

    return l

my_l = [1, 1,512, 2,3, 5, 6]

print(bubble_sort(my_l))