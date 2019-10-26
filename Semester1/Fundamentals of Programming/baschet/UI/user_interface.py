"""
    @author: Badita Marin-Georgian
    @email:  geo.badita@gmail.com
    @date:   1/28/2018 16:40
"""
from utils.utils import read_int


class UserInterface(object):
    """
    Clasa pentru interfata de utilizator
    """

    def __init__(self, service):
        self.__service = service

    def print_menu(self):
        """
        Functie care printeaza meniul de utilizator
        :return:
        """
        string = "\t 1. Pentru a adauga un jucator nou \n" \
                 "\t 2. Pentru a modifica inaltimea unui jucator\n" \
                 "\t 3. Pentru a printa jucatorii din fisier\n" \
                 "\t 4. Pentru a forma echipa cu cea mai mare medie de inaltime\n" \
                 "\t 5. Pentru a importa jucatorii din fisier"
        print(string)

    def show_ui(self):
        """
        Functie pentru controlul UI
        :return:
        """

        while True:
            self.print_menu()
            cmd = input("Va rugam dati una din urmatoarele comenzi: \n")
            if cmd == '1':
                self.adaugare_jucator_ui()
            elif cmd == '2':
                self.modificare_h_jucator_ui()
            elif cmd == '3':
                self.print_jucatori_ui()
            elif cmd == '4':
                self.format_echipa()
            elif cmd == '5':
                self.import_jucatori()
            else:
                print("Comanda introdusa nu este valida!")

    def import_jucatori(self):
        last_path = self.__service.get_path_serv()
        new_path = input("Dati numele fisierului din care vreti sa importati jucatorii: ")
        self.__service.set_path_service(new_path)
        importati = self.__service.import_serv()
        if importati is None:
            print("Nu s-a putut gasi niciun jucator in fisier!")
        else:
            for jc in importati:
                print(jc)
            print(len(importati))
        self.__service.set_path_service(last_path)

    def format_echipa(self):
        """
        Functie care afiseaza echipa cu cea mai mare medie de inaltime
        :return:
        """
        echipa = self.__service.formeaza_echipa()
        if echipa is None:
            print("Nu se poate forma o echipa cu jucatorii din fisier! ")
        for juc in echipa:
            print(juc)

    def adaugare_jucator_ui(self):
        nume = input("Dati va rog un nume pentru jucator: ")
        prenume = input("Dati va rog un prenume pentru jucator: ")
        inaltime = read_int("Dati va rog inaltimea jucatorului: ")
        post = input("Dati va rog postul jucatorului (Fundas, Pivot sau Extrema): ")
        adaugat = self.__service.adauga_jucator_serv(nume, prenume, inaltime, post)


    def modificare_h_jucator_ui(self):
        nume = input("Dati va rog numele jucatorului: ")
        prenume = input("Dati va rog prenumele jucatorului: ")
        new_h = read_int("Dati va rog noua inaltime a jucatorului: ")
        modificat = self.__service.modifica_h_serv(nume, prenume, new_h)
        if modificat is None:
            print("Jucatorul introdus nu exista!\n")
        else:
            print(modificat.get_nume() + " a fost modificat\n")

    def print_jucatori_ui(self):
        list_jc = self.__service.get_all_serv()
        for jc in list_jc:
            print(jc)