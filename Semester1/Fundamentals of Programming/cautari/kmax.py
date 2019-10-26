"""
    @author: Badita Marin-Georgian
    @email:  geo.badita@gmail.com
    @date:   1/28/2018 14:08
"""



def bestCandidate(c, k):
    if k > 0:
        return -min(c)
    else:
        return min(c)


def acceptable(b):
    return True


def solution(b, c):
    return len(b) == len(c)


def greedy(c, k):
    b = []
    while not solution(b, c) and c != []:
        candidat = bestCandidate(c, k)
        if k > 0:
            c.remove(-candidat)
        else:
            c.remove(candidat)
        k -= 1
        if acceptable(b + [candidat]):
            b.append(candidat)

    return b


def sum(b):
    sum = 0
    for elem in b:
        sum += elem
    return sum


n = input()
c = list(map(int, input().split()))
k = int(input())

print(sum(greedy(c, k)))