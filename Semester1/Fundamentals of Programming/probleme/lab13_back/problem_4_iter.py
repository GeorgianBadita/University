"""
    @author: Badita Marin-Georgian
    @email:  geo.badita@gmail.com
    @date:   1/4/2018 18:24
    Se dă o listă de numere întregi a1,...an, determinați toate sub-secvențele (ordinea
    elementelor este menținută) strict crescătoare.

"""

my_lst = []



def print_sol(solution):
    """
    Function tht prints a found solution
    :param solution: the solution
    :return: nothing
    """
    string = ""
    for elem in solution:
        string += str(my_lst[elem]) + " "
    print(string + "\n")


def check_sol(solution):
    """
    Function
    :param solution: solution to be checked
    :return: True if the solution is valid, False otherwise
    :condition: We need to check if the last two components are in increasing order, if there are
    2 ore more elements
    """
    if len(solution) == 0:
        return False
    if len(solution) < 2:
        return True

    dim = len(solution) - 1
    if my_lst[solution[dim]] <= my_lst[solution[dim - 1]]:
        return False

    if solution[dim] - solution[dim - 1] == 1:
        return True
    return False


def back_iter(list, sol):
    """
    The backtracking function
    :return:
    """
    sol = [None]
    start = 0
    while len(sol) > 0:
        choosed = False
        for elem in range(start, len(list)):
            sol[-1] = elem
            choosed = check_sol(sol)

            if choosed is True:
                start = list.index(my_lst[sol[-1]]) + 1
                break

        if choosed:
            print_sol(sol)
            sol.append(None)
        else:
            sol = sol[:-1]
            if len(sol) != 0:
                start = list.index(my_lst[sol[-1]]) + 1


def read_data():
    """
    Funtion that reads the input
    :return: the number of elements of the list
    """
    n = int(input("Please give the number of elements: "))

    for elem in range(n):
        x = int(input("Give a number: "))
        my_lst.append(x)
    return n


def solve():
    """
    Function that solves the problem using iterative backtracking
    :param n: number of elements in list
    :return:
    """

    back_iter(my_lst, [])

read_data()
solve()
