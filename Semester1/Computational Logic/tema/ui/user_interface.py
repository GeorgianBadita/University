"""
Modul pentru interfata de utilizator
"""
from domain.numar import Numar
from domain.validator import ValidatorException, NumarValidator
from utils.helper import read_int, compare


class UI(object):
    """
    Clasa pentru interfata de utilizator
    """

    def _print_menu(self):
        """
        Functie ce va printa meniul de utilizator sub forma de text
        :return: None
        """
        menu = "\t 1. Pentru a aduna doua numere intr-o anumita baza\n" \
               "\t 2. Pentru a scadea doua numere intr-o anumita baza\n" \
               "\t 3. Pentru a inmulti un numar cu o cifra intr-o anumita baza\n" \
               "\t 4. Pentru a imparti un numar la o cifra intr-o anumita baza\n" \
               "\t 5. Pentru a transforma un numar dintr-o baza in alta\n" \
               "\t 6. Pentru a transforma rapid un numar din baza 2 in baza 4 sau invers\n" \
               "\t 7. Pentru a transforma rapid un numar din baza 2 in baza 8 sau invers\n" \
               "\t 8. Pentru a transforma rapid un numar din baza 2 in baza 16 sau invers\n" \
               "\t 9. Pentru a iesi din aplicatie"

        print(menu)

    def __read_number_add_sub(self, rank):
        """
        Functie care citeste un obiect de tip Numar de la tastatura
        :param rank: rangul numarului citit
        :return:
        """
        numar1 = input("Introduceti " + rank + " numar: ")
        baza1 = read_int("Introduceti baza numarului: ")
        nr1 = Numar(numar1, baza1)
        val = NumarValidator()
        try:
            val.validate(nr1)
            return nr1
        except ValidatorException as ex:
            print("\n")
            print(ex.get_errs())
            print("\n")
        except ValueError:
            print("\nEroare la bazele celor doua numere\n")


    def __read_number_mul_div(self, rank):
        """
        Functie care citeste un obiect de tip Numar pentru inmultire/impartire
        :param rank:
        :return:
        """
        numar1 = input("Introduceti " + rank)
        baza1 = read_int("Introduceti baza: ")
        nr1 = Numar(numar1, baza1)
        val = NumarValidator()
        try:
            val.validate(nr1)
            return nr1
        except ValidatorException as ex:
            print("\n")
            print(ex.get_errs())
            print("\n")
        except ValueError:
            print("\nEroare la bazele celor doua numere\n")

    def __add(self):
        """
        Functie care aduna doua numere date in anumite baze, intr-o baza data de la tastatura
        :return: numarul in baza introdusa
        """
        nr1 = self.__read_number_add_sub("primul")
        if nr1 is None:
            return
        nr2 = self.__read_number_add_sub("al doilea")
        if nr2 is None:
            return
        baza3 = read_int("Dati baza in care se vor aduna numerele: ")
        nr1 = nr1.b_p_q(baza3)
        nr2 = nr2.b_p_q(baza3)
        sum = nr1 + nr2
        print("\nSuma numerelor in baza " + str(sum.get_baza()) + " este: ")
        print(nr1.get_val() + " + " + nr2.get_val() + " = " + sum.get_val() + "\n")


    def __sub(self):
        """
        Functie care scade doua numere date in anumite baza, intr-o baza data de la tastatura
        :return: numarul in baza introdusa, reprezentand diferenta numerelor
        """
        nr1 = self.__read_number_add_sub("primul")
        if nr1 is None:
            return
        nr2 = self.__read_number_add_sub("al doilea")
        if nr2 is None:
            return
        baza3 = read_int("Dati baza in care se vor scadea numerele: ")
        nr1 = nr1.b_p_q(baza3)
        nr2 = nr2.b_p_q(baza3)
        if compare(nr1.get_val(), nr2.get_val()) is True:
            dif = nr1 - nr2
            print("\nDiferenta numerelor in baza " + str(dif.get_baza()) + " este: ")
            print(nr1.get_val() + " - " + nr2.get_val() + " = " + dif.get_val() + "\n")
        else:
            dif = nr2 - nr1
            print("\nDiferenta numerelor in baza " + str(dif.get_baza()) + " este: ")
            print(nr1.get_val() + " - " + nr2.get_val() + " = -" + dif.get_val() + "\n")

    def __mult(self):
        """
        Functie care inmulteste un numar intr-o anumita baza cu o cifra
        :return: rezultatul inmultirii
        """
        nr1 = self.__read_number_mul_div("primul numar: ")
        if nr1 is None:
            return
        nr2 = self.__read_number_mul_div("cifra: ")
        if nr2 is None:
            return

        baza3 = read_int("Dati baza in care se vor inmulti numerele: ")
        nr1 = nr1.b_p_q(baza3)
        nr2 = nr2.b_p_q(baza3)
        try:
            mult = nr1*nr2
            print("\nProdusul numerelor in baza " + str(mult.get_baza()) + " este: ")
            print(nr1.get_val() + " * " + nr2.get_val() + " = " + mult.get_val() + "\n")
        except ValueError:
            print("\nAl doilea numar, are mai mult de o cifra!\n")

    def __div(self):
        """
        Functie care imparte un numar intr-o anumita baza la o cifra
        :return: rezultatul impartirii
        """
        nr1 = self.__read_number_mul_div("primul numar: ")
        if nr1 is None:
            return
        nr2 = self.__read_number_mul_div("cifra: ")
        if nr2 is None:
            return

        baza3 = read_int("Dati baza in care se vor imparti numerele: ")
        nr1 = nr1.b_p_q(baza3)
        nr2 = nr2.b_p_q(baza3)
        try:
            div = nr1/nr2
            print("\nCatul numerelor in baza " + str(div[0].get_baza()) + " este: ")
            print(nr1.get_val() + " / " + nr2.get_val() + " = " + div[0].get_val() + "\n")
            print("\nRestul impartirii in baza " + str(div[0].get_baza()) + " este: ")
            print(nr1.get_val() + " % " + nr2.get_val() + " = " + div[1].get_val() + "\n")
        except ValueError:
            print("\nAl doilea numar, are mai mult de o cifra!\n")

    def __change_base(self):
        """
        Functie care schimba baza unui numar dintr-o baza p intr-o baza q
        :return:
        """
        nr = self.__read_number_mul_div("numarul: ")
        if nr is None:
            return

        new_base = read_int("Dati noua baza a numarului: ")
        changed = nr.b_p_q(new_base)
        val = NumarValidator()
        try:
            val.validate(changed)
            print("\nNumarul " + nr.get_val() + " in baza " + str(new_base) + " este " + changed.get_val() + "\n")
        except ValidatorException as ex:
            print("\n" + ex.get_errs() + "\n")

    def __fast_2_4(self):
        """
        Functie care converteste rapid un numar din baza 2 in baza 4 sau invers
        :pre: numarul trebue dat in baza 2 pentru a fi rapid convertit in baza 4, si invers
        in baza 4 pentru a fi convertit in baza 2
        :return: numarul rapid convertit in baza 2 sau baza 4
        """
        nr = self.__read_number_mul_div("numarul: ")
        if nr is None:
            return
        if nr.get_baza() != 2 and nr.get_baza() != 4:
            print("\nBaza nu poate fi decat 2 sau 4!\n")
            return

        if nr.get_baza() == 2:
            new_base = 4
        else:
            new_base = 2

        changed = nr.b_p_q(new_base)
        val = NumarValidator()
        try:
            val.validate(changed)
            print("\nNumarul " + nr.get_val() + " in baza " + str(new_base) + " este " + changed.get_val() + "\n")
        except ValidatorException as ex:
            print("\n" + ex.get_errs() + "\n")

    def __fast_2_8(self):
        """
        Functie care converteste rapid un numar din baza 2 in baza 8 sau invers
        :pre: numarul trebue dat in baza 2 pentru a fi rapid convertit in baza 8, si invers
        in baza 8 pentru a fi convertit in baza 2
        :return: numarul rapid convertit in baza 2 sau baza 8
        """
        nr = self.__read_number_mul_div("numarul: ")
        if nr is None:
            return
        if nr.get_baza() != 2 and nr.get_baza() != 8:
            print("\nBaza nu poate fi decat 2 sau 8!\n")
            return

        if nr.get_baza() == 2:
            new_base = 8
        else:
            new_base = 2

        changed = nr.b_p_q(new_base)
        val = NumarValidator()
        try:
            val.validate(changed)
            print("\nNumarul " + nr.get_val() + " in baza " + str(new_base) + " este " + changed.get_val() + "\n")
        except ValidatorException as ex:
            print("\n" + ex.get_errs() + "\n")

    def __fast_2_16(self):
        """
        Functie care converteste rapid un numar din baza 2 in baza 16 sau invers
        :pre: numarul trebue dat in baza 2 pentru a fi rapid convertit in baza 16, si invers
        in baza 16 pentru a fi convertit in baza 2
        :return: numarul rapid convertit in baza 2 sau baza 16
        """
        nr = self.__read_number_mul_div("numarul: ")
        if nr is None:
            return
        if nr.get_baza() != 2 and nr.get_baza() != 16:
            print("\nBaza nu poate fi decat 2 sau 16!\n")
            return

        if nr.get_baza() == 2:
            new_base = 16
        else:
            new_base = 2

        changed = nr.b_p_q(new_base)
        val = NumarValidator()
        try:
            val.validate(changed)
            print("\nNumarul " + nr.get_val() + " in baza " + str(new_base) + " este " + changed.get_val() + "\n")
        except ValidatorException as ex:
            print("\n" + ex.get_errs() + "\n")

    def show_menu(self):
        """
        Functie care controleaza actiuniile utilizatorului
        :return:
        """
        while True:
            self._print_menu()
            cmd = input("Dati va rog o comanda: ")
            if cmd == "" or cmd == None:
                continue
            if cmd == "1":
                self.__add()
            elif cmd == "2":
                self.__sub()
            elif cmd == "3":
                self.__mult()
            elif cmd == "4":
                self.__div()
            elif cmd == "5":
                self.__change_base()
            elif cmd == "6":
                self.__fast_2_4()
            elif cmd == "7":
                self.__fast_2_8()
            elif cmd == "8":
                self.__fast_2_16()
            elif cmd == "9":
                exit()
            else:
                print("\nComanda gresita, va rugam incercati din nou!\n")

