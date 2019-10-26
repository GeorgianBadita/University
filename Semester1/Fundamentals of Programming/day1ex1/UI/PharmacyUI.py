"""
    @author: Badita Marin-Georgian
    @email:  geo.badita@gmail.com
    @date:   12/11/2017 20:27
"""
class PharmacyUI:
    '''
    Class that contorls the UI of the Pharmacy
    '''

    def __init__(self, pharm_serv):
        self.__pharm_serv = pharm_serv

    def print_menu(self):
        '''
        Function that prints the UI menu
        :return: None
        '''
        string = "1. To search for a medicine\n" \
                 "2. To create a recipe\n\n"
        print(string)


    def __search_med_name(self):
        '''
        Function that searches for a medicine by name
        :return:
        '''
        name = input("Please give the name of the medicine: ")
        med = self.__pharm_serv.look_up(name)
        if med is None:
            print("Sorry there is no medicine called " + name)
        else:
            for md in med:
                print(md)

    def __create_recipe(self):
        '''
        function that creates a recipe
        :return: the total price of the recipe
        '''
        num = input("Please give the number of medicines: ")
        meds = []
        for i in range(int(num)):
            name = input("Please give the name of the medicine: ")
            name = self.__pharm_serv.look_up(name)
            if name is None:
                print("Please try again with valid names!")
                break
            else:
                meds.append(name[0])
        for med in meds:
            print(med)
        print("\n")
        print(self.__pharm_serv.create_recipe(meds))

    def show_ui(self):
        '''
        Function that controls the menu functionality
        :return:
        '''
        while True:
            self.print_menu()
            cmd = input("Please give a command: ")
            if cmd == '1':
                self.__search_med_name()
            elif cmd == '2':
                self.__create_recipe()
            else:
                print("Sorry wrong command!")