"""
Clasa pentru numar
"""
from utils.helper import atrib_huge, to_str, from10_q, fromq_10, conv_2_4, conv_4_2, conv_2_8, conv_8_2, conv_2_16, \
    conv_16_2, to_upper


class Numar(object):


    def __init__(self, val, baza):
        """

        :param val: sirul cifrelor numarului
        :param baza: baza in care este scris numarul
        """
        self.__val = to_upper(val)
        self.__baza = baza

    def get_val(self):
        """
        :return: valoarea numarului
        """
        return self.__val

    def get_baza(self):
        """
        :return: baza in care este numarul
        """
        return self.__baza

    def set_baza(self, new_base):
        """
        Functie care seteaza o noua baza pentru un numar
        :param new_base: noua baza setata pentru numar
        :return: None
        """
        self.__baza = new_base

    def __add__(self, other):
        """
        Functie ce redefineste adunarea a 2 numere in aceeasi baza
        :param other: obiect Numar
        :return: rezultatul adunarii celor 2 numere, fiind tot un obiect Numar
        :raise: ValueError daca numerele nu sunt in aceeasi baza
        """

        if self.__baza != other.get_baza():
            raise ValueError()

        base = self.__baza
        A = atrib_huge(self)
        B = atrib_huge(other)
        T = 0 #Transportul (daca este necesar)

        if B[0] > A[0]:
            for i in range(A[0] + 1, B[0] + 1):
                A.append(0)
            A[0] = B[0]
        else:
            for i in range(B[0] + 1, A[0] + 1):
                B.append(0)

        for i in range(1, A[0] + 1):
            A[i] += B[i]+T
            T = A[i]//base
            A[i] %= base

        if T != 0:
            A[0] += 1
            A.append(T)

        sum = to_str(A)
        new_numar = Numar(sum, base)
        return new_numar

    def __sub__(self, other):
        """
        Functie ce redefineste scaderea a 2 numere in aceeasi baza
        :param other: obiect Numar
        :return: rezultatul scaderii celor 2 numere, fiind tot un obiect Numar
        :raise: ValueError daca numerele nu sunt in aceeasi baza
        """

        if self.__baza != other.get_baza():
            raise ValueError()

        base = self.__baza
        A = atrib_huge(self)
        B = atrib_huge(other)
        T = 0 #Transport, daca va fi cazul

        for i in range(B[0] + 1, A[0] + 1):
            B.append(0)

        for i in range(1, A[0] + 1):
            A[i] = A[i] - (B[i] + T)
            if A[i] < 0:
                T = 1
            else:
                T = 0
            if T != 0:
                A[i] += base

        while A[A[0]] == 0:
            A[0] -= 1

        if A[0] <= 0:
            diff = "0"
            A[0] = 1
        else:
            diff = to_str(A)
        new_numar = Numar(diff, base)
        return new_numar

    def __mul__(self, other):
        """
        Functie ce redefineste inmultirea unui numar intr-o baza cu o cifra
        :param other: obiect Numar
        :return: rezultatul inmultirii numarului cu o cifra, fiind tot un obiect Numar
        :raise: ValueError daca parametrul other nu e cifra
        """

        base = self.__baza
        A = atrib_huge(self)
        B = atrib_huge(other)
        if B[0] != 1:
            raise ValueError()
        X = B[1]

        T = 0 #transport in caz ca este necesar

        for i in range(1, A[0] + 1):
            A[i] = A[i]*X + T
            T = A[i]//base
            A[i] %= base

        while T != 0:
            A[0] += 1
            A.append(T%base)
            T //= base

        cmp = [0]*(len(A) - 1)
        if A[0] > 0 and A[1:] == cmp:
            prod = "0"
        else:
            prod = to_str(A)
        new_numar = Numar(prod, base)
        return new_numar

    def __truediv__(self, other):
        """
        Functie ce redefineste impartirea unui numar intr-o baza cu o cifra
        :param other: obiect Numar
        :return: rezultatul impartirii numarului cu o cifra, fiind fiind 2 obj de tip Numar (catul, restul)
        :raise: ValueError daca parametrul other nu e cifra sau daca cifra other este 0
        """

        base = self.__baza
        A = atrib_huge(self)
        B = atrib_huge(other)
        if B[0] != 1 or B[1] == 0:
            raise ValueError()
        X = B[1]
        R = 0 #restul impartirii

        for i in range(A[0], 0, -1):
            R = base*R + A[i]
            A[i] =R // X
            R %= X

        while A[A[0]] == 0 and A[0] > 1:
            A[0] -= 1

        div = to_str(A)
        new_div = Numar(div, base)
        new_rem = [1, R]
        rem = to_str(new_rem)
        new_rem = Numar(rem, base)
        return [new_div, new_rem]

    def b_10_q(self, base):
        """
        Functie care trece un numar din baza 10 intr-o baza oarecare prin impartiri repetate
        :return: un obiect de tip Numar
        """

        number = self.__val
        dig_list = from10_q(number, base)
        dig_list.reverse()
        new_lst = [len(dig_list)]
        new_lst += dig_list
        number = to_str(new_lst)
        number = Numar(number, base)
        return number

    def b_q_10(self):
        """
        Functie care trece un numar dintr-o baza oarecare in baza 10, prin substitutie
        :return:
        """
        number = atrib_huge(self)
        dig_list = fromq_10(number, self.__baza)
        dig_list.reverse()
        new_lst = [len(dig_list)]
        new_lst += dig_list
        number = to_str(new_lst)
        number = Numar(number, self.__baza)
        return number

    def b_p_q(self, q):
        """
        Functie care transforma un numar din baza p in baza q
        :pre: baza in care este numarul este deja p
        :return: un obj de tip Numar in baza q
        """
        tmp_nr = self.b_q_10()
        return tmp_nr.b_10_q(q)

    def fast_2_4(self):
        """
        Functie care face trecerea rapida de la baza 2 la baza 4 si invers, daca baza curenta a numarului este 2
        se face trecerea la baza 4, daca baza curenta este 4 se face trecerea la baza 2
        :return: numarul rapid convertit in bza 2 sau baza 4
        """

        curr_base = self.__baza
        if curr_base == 2:
            new_number = conv_2_4(self.__val)
            new_base = 4
        elif curr_base == 4:
            new_number = conv_4_2(self.__val)
            new_base = 2

        num = Numar(new_number, new_base)
        return num

    def fast_2_8(self):
        """
        Functie care face trecerea rapida de la baza 2 la baza 8 si invers, daca baza curenta a numarului este 2
        se face trecerea la baza 8, daca baza curenta este 8 se face trecerea la baza 2
        :return: numarul rapid convertit in bza 2 sau baza 8
        """
        curr_base = self.__baza
        if curr_base == 2:
            new_number = conv_2_8(self.__val)
            new_base = 8
        elif curr_base == 8:
            new_number = conv_8_2(self.__val)
            new_base = 2

        num = Numar(new_number, new_base)
        return num

    def fast_2_16(self):
        """
        Functie care face trecerea rapida de la baza 2 la baza 16 si invers, daca baza curenta a numarului este 2
        se face trecerea la baza 16, daca baza curenta este 16 se face trecerea la baza 2
        :return: numarul rapid convertit in bza 2 sau baza 16
        """
        curr_base = self.__baza
        if curr_base == 2:
            new_number = conv_2_16(self.__val)
            new_base = 16
        elif curr_base == 16:
            new_number = conv_16_2(self.__val)
            new_base = 2

        num = Numar(new_number, new_base)
        return num
