"""
    @author: Badita Marin-Georgian
    @email:  geo.badita@gmail.com
    @date:   1/26/2018 23:57
"""


def selection_sort(my_list):
    """
    Function that sorts a lsit
    :param my_list: list of elements
    :return: the list sorted my_list[0] < my_list[1]...
    """

    for i in range(len(my_list) - 1):
        ind = i
        for j in range(i + 1, len(my_list)):
            if my_list[j] < my_list[ind]:
                ind = j

        if i < ind:
            aux = my_list[ind]
            my_list[ind] = my_list[i]
            my_list[i] = aux

    return my_list


my_l = [1, 2, 3, 4, 4, 2,3 ,1,2]

print(selection_sort(my_l))