"""
    @author: Badita Marin-Georgian
    @email:  geo.badita@gmail.com
    @date:   1/27/2018 00:23
"""


def q_sort(l):
    """
    Function that sorts a list of elements
    :param l: list of elements
    :return: the list of elements sorted
    """

    if l == []:
        return l
    else:
        left = q_sort([x for x in l[1:] if x < l[0]])
        right = q_sort([x for x in l[1:] if x >= l[0]])
        return left + [l[0]] + right


my_l = [1, 1,512, 2,3, 5, 6]

print(q_sort(my_l))