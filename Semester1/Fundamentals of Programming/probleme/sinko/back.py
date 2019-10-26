def outputSolution(x):
    print(x)


def solution(x):
    if len(x) < 3:
        return True
    if len(x) == 3:
        a = x[0]
        b = x[1]
        c = x[2]
        if a[0] * b[1] + b[0] * c[1] + c[0] * a[1] - a[1] * b[0] - b[1] * c[0] - c[1] * a[0] == 0:
            return True
    return False


def back_rec(x, a, dim):

        if len(a) == 3:
            outputSolution(a)
        if len(a) == 0:
            start = 0
        else:
            start = x.index(a[-1]) + 1
        a.append(0)
        for elem in range(start, len(x)):
            a[-1] = x[elem]
            if solution(a):
                backRec(x, a, dim)
        a.pop()


def read():
    x = []
    n = int(input("Cate puncte? "))
    for i in range(0, n):
        x.append([int(input("abscisa ")), int(input("ordonata "))])
    back_rec(x, [], 3)


read()