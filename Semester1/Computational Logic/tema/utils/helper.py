

def atrib_huge(numar):
    """
    Functie care creeaza o lista cu cifrele unui numar
    :param numar: un obiect de tip Numar
    :return: sirul cifrelor in ordine inversa, iar pe pozitia 0, numarul acestora
    """
    hexa = {"0":0, "1":1, "2":2, "3":3, "4":4, "5":5,
            "6":6, "7":7, "8":8, "9":9, "A":10, "B":11,
            "C":12, "D":13, "E":14, "F":15
            }
    H = []

    H.append(0)
    string = numar.get_val()
    for i in range(len(string)-1, -1, -1):
        H[0] += 1
        H.append(hexa[string[i]])

    return H


def compute_number(digits):
    """
    Functie care returneaza numarul extras din sirul cifrelor unui numar
    :param digits:
    :return: numarul format din concatenarea cifrelor numarului
    :pre: cifrele trebuie sa fie in baza 10!
    """
    num = 0
    for digit in digits:
        num = num * 10 + int(digit)

    return num


def to_str(digits):
    """
    Functie care transofrma un sir de cifre, in numarul corespunzator
    :param digits: sir de cifre
    :return: sir de caractere, reprezentand numarul
    """
    hexa_d = "0123456789ABCDEF"
    string = ""
    for i in range(1, digits[0]+1):
        string += hexa_d[digits[i]]

    return string[::-1]


def from10_q(number, q):
    """
    Functie care trece un numar din baza 10 in baza q prin impartiri repetate
    :param number: numarul in forma zecimala
    :param q: baza in care se va trece
    :return: numarul sub forma sirului sau de cifre
    """
    number = compute_number(number)
    string = []
    while number != 0:
        string += [number%q]
        number //= q

    string.reverse()
    return string

def fromq_10(number, q):
    """
    Functie care trece un numar dintr-o baza oarecare in baza 10 prin impartiri
    :param number: un numar dat prin lista de cifre in baza q
    :param q: baza in care se aflat numarul
    :return: numarul in baza 10
    """

    base_10 = 0
    power = 1
    for i in range(1, number[0] + 1):
        base_10 += number[i]*power
        power *= q

    string = []
    while base_10:
        string += [base_10%10]
        base_10 //= 10

    string.reverse()
    return string


def conv_2_4(digits):
    """
    Functie care converteste rapid un numar din baza 2 in baza 4 dat prin sirul cifrelor
    :return: numarul in baza 4
    """
    base_4_dict = {"00":0, "01":1, "10":2, "11":3}

    string = ""
    if len(digits) % 2 == 0:
        for i in range(0, len(digits) - 1, 2):
            key = digits[i] + digits[i+1]
            string += str(base_4_dict[key])

    else:
        new_digits = ['0']
        new_digits += digits
        for i in range(0, len(new_digits) - 1, 2):
            key = new_digits[i] + new_digits[i + 1]
            string += str(base_4_dict[key])

    return string


def conv_4_2(digits):
    """
    Functie care converteste rapid un numar din baza 4 in baza 2 dat prin sirul cifrelor
    :return: numarul in baza 2
    """

    dict_base_4 = {"0":"00", "1":"01", "2":"10", "3":"11"}
    string = ""
    for i in digits:
        string += dict_base_4[i]

    return string


def conv_2_8(digits):
    """
    Functie care converteste rapid un numar din baza 2 in baza 8 dat prin sirul cifrelor
    :return: numarul in baza 8
    """
    dict_base_8 = {"000":"0", "001":"1", "010":"2", "011":"3",
                   "100":"4", "101":"5", "110":"6", "111":"7"
                   }
    string = ""
    if len(digits) % 3 == 0:
        for i in range(0, len(digits)-2, 3):
            key = digits[i] + digits[i + 1] + digits[i + 2]
            string += dict_base_8[key]
    else:
        zeros = 3 - len(digits) % 3
        new_digits = ['0']*zeros
        new_digits += digits
        for i in range(0, len(new_digits)-2, 3):
            key = new_digits[i] + new_digits[i + 1] + new_digits[i + 2]
            string += dict_base_8[key]

    return string


def conv_8_2(digits):
    """
    Functie care converteste rapid un numar din baza 8 in baza 2 dat prin sirul cifrelor
    :return: numarul in baza 2
    """

    dict_base_8 = {"0":"000", "1":"001", "2":"010", "3":"011",
                   "4":"100","5":"101", "6":"110", "7":"111"
                   }

    string = ""
    for i in digits:
        string += dict_base_8[i]

    return string

def conv_2_16(digits):
    """
    Functie care converteste rapid un numar din baza 2 in baza 16 dat prin sirul cifrelor
    :return: numarul in baza 16
    """

    dict_base_16 = {"0000":"0", "0001":"1", "0010":"2", "0011":"3",
                    "0100":"4", "0101":"5", "0110":"6", "0111":"7",
                    "1000":"8", "1001":"9", "1010":"A", "1011":"B",
                    "1100":"C", "1101":"D", "1110":"E", "1111":"F"
                    }

    string = ""
    if len(digits) % 4 == 0:
        for i in range(0, len(digits) - 3, 4):
            key = digits[i] + digits[i + 1] + digits[i + 2] + digits[i + 3]
            string += dict_base_16[key]
    else:
        zeros = 4 - len(digits) % 4
        new_digits = ['0']*zeros
        new_digits += digits
        for i in range(0, len(new_digits) - 3, 4):
            key = new_digits[i] + new_digits[i + 1] + new_digits[i + 2] + new_digits[i + 3]
            string += dict_base_16[key]

    return string


def conv_16_2(digits):
    """
    Functie care converteste rapid un numar din baza 16 in baza 2 dat prin sirul cifrelor
    :return: numarul in baza 2
    """

    dict_base_16 = {"0":"0000", "1":"0001", "2":"0010", "3":"0011",
                    "4":"0100", "5":"0101", "6":"0110", "7":"0111",
                    "8":"1000", "9":"1001", "A":"1010", "B":"1011",
                    "C":"1100", "D":"1101", "E":"1110", "F":"1111"
                    }

    string = ""
    for i in digits:
        string += dict_base_16[i]

    return string


def read_int(prompt):
    """
    Functie care citeste un numar intreg
    :return: numarul intreg citit
    """
    while True:
        try:
            nr = int(input(prompt))
            return nr
        except ValueError:
            print("\nValoarea citita trebuie sa fie un numar natural intre 2 si 16\n")


def to_upper(text):
    """
    Functie care transforma un text din litere mari in litere mici
    :param text:
    :return:
    """
    string = ""
    for letter in text:
        if letter >= 'a' and letter <= 'z':
            string += letter.upper()
        else:
            string += letter

    return string


def compare(num1, num2):
    """
    Functie care compara doua numere in aceeasi baa
    :param num1: numar, dat prin sir de caractere
    :param num2: numar, dat prin sir de caractere
    :return: True, daca num1 >= num2, False altfel
    """
    num1 = compute_number(num1)
    num2 = compute_number(num2)

    if num1 >= num2:
        return True
    return False
