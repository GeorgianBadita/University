def configure(n):
    number = 0
    while n != 0:
        #aplic sau logic pentru bitul n % 10, transformandu-l in 1
        number |= (1 << (n % 10))
        n //= 10
    return number


def sameDigits(a, b):
    c = configure(a)
    d = configure(b)
    '''daca numerele c si d care reprezinta 
    configuratiile lui a si b sunt egale
    atunci a si b au aceleasi cifre in b10'''
    return c == d


a = int(input("Dati un numar: "))
b = int(input("Dati un numar: "))

if sameDigits(a, b) == False:
    print("Numerele " + str(a) + " si " + str(b) + " nu au proprietatea P")
else:
    print("Numerele " + str(a) + " si " + str(b) + " au proprietatea P")
