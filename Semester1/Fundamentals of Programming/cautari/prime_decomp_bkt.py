"""
    @author: Badita Marin-Georgian
    @email:  geo.badita@gmail.com
    @date:   1/28/2018 12:53
"""
import math


def is_prime(x):
    if x < 2:
        return False
    if x == 2:
        return True
    if x % 2 == 0:
        return False
    for i in range(3, int(math.sqrt(x))+1):
        if x % i == 0:
            return False
    return True

def consistent(x, s):
    if is_prime(x[-1]) is False:
        return False

    curr = x[-1]
    for i in range(len(x) - 1):
        if curr == x[i]:
                return False

    sum = 0
    for prime in x:
        sum += prime
    return sum <= s

def solution(x, s):
    sum = 0
    for prime in x:
        sum += prime
    return sum == s

def bkt(x, n):
    x.append(0)
    for i in range(n):
        x[-1] = i
        if consistent(x, n):
            if solution(x, n):
                print(x)
            bkt(x, n)
    x.pop()

bkt([], 15)