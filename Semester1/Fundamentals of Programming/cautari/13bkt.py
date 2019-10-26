"""
    @author: Badita Marin-Georgian
    @email:  geo.badita@gmail.com
    @date:   1/28/2018 11:45
"""


def consistent(x):
    if len(x) > 1:
        last = x[-1]
        for i in range(len(x) - 1):
            if x[i] == last:
                return False
    return True


def solution(l, x, dim):
    if len(x) != dim:
        return False

    y = []
    for i in range(len(x)):
        y.append(l[x[i]])

    maxim = y[0]
    for i in range(1, len(y)):
        if y[i] > maxim:
            maxim = y[i]

    max_index = y.index(maxim)
    for i in range(max_index - 1):
        if y[i] > y[i + 1]:
            return False

    for i in range(max_index, len(y) - 1):
        if y[i] < y[i + 1]:
            return False
    return True


def print_sol(l, x):
    string = ""
    for i in range(len(x)):
        string += str(l[x[i]])
        string += " "
    print(string)

def bkt(x, l):
    x.append(0)
    for i in range(len(l)):
        x[-1] = i
        if consistent(x):
            if solution(l, x, len(l)):
                print_sol(l, x)
            bkt(x, l)
    x.pop()

l = [10, 7, 27, 5, 1]
#bkt([], l)

def even_num_dei(l):
    """
    Returneaza numarul de elemente pare din lista
    :param l:
    :return:
    """

    if len(l) == 0:
        return 0
    if len(l) == 1:
        if l[0] % 2 == 0:
            return 1
        else:
            return 0
    m = len(l)//2
    return even_num_dei(l[:m]) + even_num_dei(l[m:])


print(even_num_dei([1, 2, 3]))