"""
    @author: Badita Marin-Georgian
    @email:  geo.badita@gmail.com
    @date:   1/8/2018 08:06
"""

"""
Lista si element, nr de aparitii al elementului in lista
"""


def nr_ap_div_conq(lst, elem):
    """
    Calculeaza numarul de aparitii al lui elem lst
    :param lst: lista de elemente
    :param elem: elemntul de contorizat
    :return: numarul de aparitii
    """
    if len(lst) == 1:
        if lst[0] == elem:
            return 1
        else:
            return 0
    m = len(lst)//2
    st = nr_ap_div_conq(lst[:m], elem)
    dr = nr_ap_div_conq(lst[m:], elem)
    return st + dr


def test_nr_ap():
    lst = [2, 2, 2, 3, 2, 4, 2, 2]
    assert nr_ap_div_conq(lst, 2) == 6
    assert nr_ap_div_conq(lst, 3) == 1
    assert nr_ap_div_conq(lst, 0) == 0

#test_nr_ap()



def sum_elem_div3_conq(lst, st, dr):
    """
    Calculeaza suma elementelor de pe pozitii divizibile cu 3
    :param lst: lista
    :return:
    """
    if st == dr and st % 3 == 0:
        return lst[st]
    elif st == dr:
        return 0
    elif dr < st:
        return 0

    m = (st + dr)//2
    return sum_elem_div3_conq(lst, st, m) + sum_elem_div3_conq(lst, m+1, dr)


def test_sum_elem():
    #print(sum_elem_div3_conq([1, 2, 3, 4, 5], 0, 4))
    assert sum_elem_div3_conq([1,2,3,4,5], 0, 4) == 5


test_sum_elem()


def sum_max_din(lst):
    """
    Calculeaza subsecventa de suma maxima (programare dinamica)
    :param lst:
    :return:
    """
    max = lst[0]
    sum = lst[0]

    if sum < 0:
        sum = 0

    for i in range(1, len(lst)):
        sum += lst[i]
        if sum > max:
            max = sum
        if sum < 0:
            sum = 0

    return max


def crossing_sum(list, poz):
    sum = 0
    left = -100000
    for i in range(len(list) - 1, poz, -1):
        sum += list[i]
        if sum > l:
            left = sum

    sum = 0


def my_max(s1, s2, s3):
    pass


def sum_max_conq(lst):
    """
    Calculeza subsecventa de suma maxima (div and conq)
    :param lst:
    :return:
    """
    if lst == []: return None
    if len(lst) == 1: return lst[0]

    m = len(lst)//2

    s1 = crossing_sum(list, poz)
    s2 = sum_max_conq(l[:m])
    s3 = sum_max_conq(l[m:])

    return my_max(s1, s2, s3)

def test_sum_max():
    assert sum_max_din([5, -6, 3, 4, -2, 3, -3]) == 8
    assert sum_max_conq([5, -6, 3, 4, -2, 3, -3]) == 8


test_sum_max()