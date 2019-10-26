"""
    @author: Badita Marin-Georgian
    @email:  geo.badita@gmail.com
    @date:   1/27/2018 00:00
"""


def dir_sel_sort(my_list):
    """
    Function that sorts a list of elements in increasing order
    :param my_list: list of elements
    :return: the list of elements sorted
    """

    for i in range(len(my_list) - 1):
        for j in range(i + 1, len(my_list)):
            if my_list[i] > my_list[j]:
                aux = my_list[i]
                my_list[i] = my_list[j]
                my_list[j] = aux

    return my_list

my_l = [1, 2, 3, 4, 4, 2,3 ,1,2]

print(dir_sel_sort(my_l))