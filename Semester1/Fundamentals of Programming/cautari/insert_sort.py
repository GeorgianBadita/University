"""
    @author: Badita Marin-Georgian
    @email:  geo.badita@gmail.com
    @date:   1/27/2018 00:08
"""


def insert_srot(my_list):
    """
    Function that sorts a list of elements
    :param my_list: list of elements
    :return: the list of elements sorted
    """

    for i in range(1, len(my_list)):
        ind = i - 1
        a = my_list[i]
        while ind >= 0 and a < my_list[ind]:
            my_list[ind + 1] = my_list[ind]
            ind -= 1

        my_list[ind + 1] = a
        print(my_list)
    return my_list


my_l = [5, 4, 3, 2, 1]

print(insert_srot(my_l))
