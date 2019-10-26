"""
    @author: Badita Marin-Georgian
    @email:  geo.badita@gmail.com
    @date:   12/12/2017 08:22
"""


'''
----------------
|User interface|
----------------
'''

class ConcertUI:
    '''
    Class to controll the user interface
    '''
    
    def __init__(self, ctr):
        self.__con_ctr = ctr
    
    def print_menu(self):
        '''
        Function that prints the menu
        :return: 
        '''
        str = "1. Pentru a vizualiza toate concertele la o locatie \n" \
              "2. Pentru a vizualiza raportul privind concertele\n" \
              "x  Pentru a iesi din aplicatie\n\n"
        print(str)
    
    def __aggregate_location(self):
        '''
        Function that prints the concets at a location
        :return: 
        '''
        location = input("Dati va rog o locatie: ")
        concerts = self.__con_ctr.aggregate_location(location)
        if concerts is None:
            print("Nu exista niciun concert la locatia " + location)
        else:
            for concert in concerts:
                print(concert)
            print("\n\n")
                

    def __view_conc(self):
        '''
        Functoion that sorts all concerts by the total value
        :return:
        '''
        sorted_concerts = self.__con_ctr.sort_by_value_ctr()
        for concert in sorted_concerts:
            print(concert)
        print("\n\n")

    def show_ui(self):
        '''
        COntorls the user operations
        :return: 
        '''
        while True:
            self.print_menu()
            cmd = input("Dati o comanda: ")
            if cmd == '1':
                self.__aggregate_location()
            elif cmd == '2':
                self.__view_conc()
            elif cmd == 'x':
                exit()
            else:
                print("Comanda incorecta!")
        