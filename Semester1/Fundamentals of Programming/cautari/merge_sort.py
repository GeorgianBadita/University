"""
    @author: Badita Marin-Georgian
    @email:  geo.badita@gmail.com
    @date:   1/27/2018 00:26
"""


def merge_sort(list):
    """
    Function that sorts a list of elements
    :param list: list of elements
    :return: the list of elements sorted
    """

    if len(list) > 1:
        mid = len(list)//2
        left = list[:mid]
        right = list[mid:]

        merge_sort(left)
        merge_sort(right)

        merge(left, right, list)


def merge(left, right, list):
    i = 0
    j = 0
    k = 0

    while i < len(left) and j < len(right):
        if left[i] < right[j]:
            list[k] = left[i]
            i += 1
            k += 1
        else:
            list[k] = right[j]
            k += 1
            j += 1

    while i < len(left):
        list[k] = left[i]
        i += 1
        k += 1

    while j < len(right):
        list[k] = right[j]
        k += 1
        j += 1

my_l = [1, 1,512, 2,3, 5, 6]

print(merge_sort(my_l))
