"""
    @author: Badita Marin-Georgian
    @email:  geo.badita@gmail.com
    @date:   1/15/2018 08:22
"""


#l = [-9, 3, 2, -3, 1, 4]
#sol candidat x0, x1... xk
#xi pozitie in [0, len(l)-1]
#consistent oricare ar fi x(i), x(i) = x(i+1)
#maximizam suma de la i la k din L[x[i]]


#SSM-DP
#[-9, 3, 2, -3, 1,4]
#[-9+7, 3+4, 2+2, -3+5, 1+4, 4]     S[i] = | li, li > li+s[i+1]
                                        #  |
                                        #  | li + s[i+1]


def sum_max_DP(l):
    s = [0]*len(l)
    s[-1] = l[-1]

    for i in range(len(l)-2, -1, -1):
        if l[i] > l[i] + s[i+1]:
            s[i] = l[i]
        else:
            s[i] = l[i]+s[i+1]

    return max(s)

print(sum_max_DP([-9,3,2,-3,1,4]))