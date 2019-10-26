"""
    @author: Badita Marin-Georgian
    @email:  geo.badita@gmail.com
    @date:   1/28/2018 00:22
"""


def dinamic(a, b):
    """
    calculeaza cel mai lung subsir comun a doua siruri
    :param a: primul sir
    :param b: al 2-lea sir
    :return: cel mai lung subsir comun a doua siruri
    """

    dp = [[0 for i in range(len(b))] for j in range(len(a))]

    for i in range(0, len(a)):
        for j in range(0, len(b)):
            if i == 0:
                if a[i] == b[j] and dp[i][j] == 0:
                    dp[i][j] = 1
                else:
                    dp[i][j] = 0
            elif j == 0:
                if a[i] == b[j] and dp[i][j] == 0:
                    dp[i][j] = 1
                else:
                    dp[i][j] = 0
            elif a[i] == b[j]:
                dp[i][j] = 1 + dp[i-1][j-1]
            else:
                dp[i][j] = max(dp[i-1][j], dp[i][j-1])

    return dp


def print_sol(a, b):
    """
    Printeaza solutia
    :param a:
    :param b:
    :return:
    """
    i = len(a) - 1
    j = len(b) - 1
    dp = dinamic(a, b)
    print(*dp)
    sol = dp[i][j]
    while sol != 0:
        if dp[i-1][j] == sol:
            i -= 1
        elif dp[i][j-1] == sol:
            j -= 1
        else:
            print(a[i])
            i -= 1
            j -= 1
            sol -= 1


a = [1, 7, 3, 9, 8]
b = [7, 5, 8]

print_sol(a, b)

# dp = dinamic(a, b)
# print(*dp)