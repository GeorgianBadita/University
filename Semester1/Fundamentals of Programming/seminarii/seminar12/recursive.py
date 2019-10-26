"""
    @author: Badita Marin-Georgian
    @email:  geo.badita@gmail.com
    @date:   12/18/2017 08:28
"""
def even(l, poz = 0):
    if poz >= len(l):
        return False
    elif l[poz] % 2 == 0:
        return True
    return even(l, poz + 2)

list = [1, 1, 5, 3, 6]

print(even(list))