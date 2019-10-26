"""
    @author: Badita Marin-Georgian
    @email:  geo.badita@gmail.com
    @date:   1/28/2018 11:24
"""


a = [1, 2, 5, 10, 50]
s = 20


def consistent(x, a, s):
    sum = 0
    for i in range(len(x)):
        sum += a[x[i]]
    return sum <= s

def solution(x, a, s):
    sum = 0
    for i in range(len(x)):
        sum += a[x[i]]
    return sum == s


def print_sol(x, a):
    string = ""
    for i in range(len(x) - 1):
        string += str(a[x[i]])
        string += "+"
    string += str(a[x[len(x)-1]])
    print(string)

def bkt(x, s, a):
    x.append(0)
    for i in range(len(a)):
        x[-1] = i
        if consistent(x, a, s):
            if solution(x, a, s):
                print_sol(x, a)
            bkt(x, s, a)
    x.pop()

bkt([], s, a)