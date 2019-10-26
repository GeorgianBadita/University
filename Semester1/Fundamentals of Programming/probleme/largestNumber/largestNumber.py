def primeFactors(n):
    if n == 1 or n == 2:
        return [n]
    factors = []
    f = 3
    nr = 0
    while(n % 2 == 0):
        n //= 2
        nr += 1
    if nr > 0:
        factors.append(2)
    while f * f <= n:
        nr = 0
        while n % f == 0:
            n //= f
            nr += 1
        if nr > 0:
            factors.append(f)
        f += 2
    if n != 1:
        factors.append(n)
    return  factors

def constrSeq(n):
    sum = 0
    count = 1
    while sum < n:
        l = primeFactors(count)
        sum += len(l)
        if sum > n:
            sum -= len(l)
            break
    diff = n - sum
    if diff == 0:
        print(l)


n = int(input("Give a number: "))


print(constrSeq(n))

