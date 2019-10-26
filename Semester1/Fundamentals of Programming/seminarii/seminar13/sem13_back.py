"""
    @author: Badita Marin-Georgian
    @email:  geo.badita@gmail.com
    @date:   1/8/2018 09:18
"""

"""
Se da o lista L = l0, l1, l2... ln-1
Solutie candidat = x0, x1, ..., xk
xi in [0, n-1]
xi - pozitie in L
"""
"""
Consistent: x0, x1 ... xk
xi+1 - xi = 1
"""

"""
Solutie retinem solutia care face max, S = sum(0, k) l[xi]
"""



def back_secv(param):
    pass


def test_sub_secv_max_back():
    assert back_secv([5, -6, 3, 4, -2, 3, -3]) == 8