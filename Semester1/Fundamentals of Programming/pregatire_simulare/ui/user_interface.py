"""
    @author: Badita Marin-Georgian
    @email:  geo.badita@gmail.com
    @date:   12/9/2017 22:49
"""
from utils.helper import readInt


class UI:
    '''
    Class that controls the User Interface functionality
    '''

    def __init__(self, car_serv, cl_serv, rt_serv):
        '''
        initialise UI with the entities services
        :param car_serv:
        :param cl_serv:
        '''
        self.__car_serv = car_serv
        self.__cl_serv = cl_serv
        self.__rt_serv = rt_serv

    def __print_ui(self):
        '''
        Function that prints the menu
        :return:
        '''
        print("\t\n" + "1. To add a car" +
              "\t\n" + "2. To add a client" +
              "\t\n" + "3. To delete a car" +
              "\t\n" + "4. To delete a client" +
              "\t\n" + "5. To find a car by id" +
              "\t\n" + "6. To find a client by id" +
              "\t\n" + "7. To list all cars" +
              "\t\n" + "8. To list all clients" +
              "\t\n" + "9. To rent a car" +
              "\t\n" + "10.To print rentals" +
              "\t\n" + "11.To print rentals sorted by client Id" + "\n\n")

    def __add_car(self):
        '''
        Function that adds a car
        :return:
        '''
        id = readInt("Please give an id: ")
        model = input("Please give a model: ")
        year = readInt("Please give a year: ")
        engine = input("Please give a engine: ")
        self.__car_serv.add_car_srv(id, model, year, engine)

    def __add_client(self):
        '''
        Function that adds a client
        :return:
        '''
        id = readInt("Please give an id: ")
        name = input("Please give a name: ")
        addr = input("Please give an address: ")
        self.__cl_serv.add_cl_srv(id, name, addr)

    def __delete_car(self):
        '''
        Function that deletes a car
        :return:
        '''
        id = readInt("Please give the id: ")
        self.__car_serv.del_car_srv(id)


    def __delete_client(self):
        '''
        Function that deletes a client
        :return:
        '''
        id = readInt("Please give the id: ")
        self.__cl_serv.del_cl_srv(id)

    def __find_car_id(self):
        '''
        Function that finds a car by id
        :return:
        '''
        id = readInt("Please give the id: ")
        find_car = self.__car_serv.find_car_srv(id)
        if find_car is not None:
            print(find_car)

    def __find_client_id(self):
        '''
        Function that finds a client by id
        :return:
        '''
        id = readInt("Please give the id: ")
        find_cl = self.__cl_serv.find_cl_srv(id)
        if find_cl is not None:
            print(find_cl)


    def __list_cars(self):
        '''
        Function that lists all cars
        :return:
        '''
        cars_l = self.__car_serv.get_all_cars()
        for car in cars_l:
            print(car)

    def __list_clients(self):
        '''
        Function that lists all clients
        :return:
        '''
        cl_l = self.__cl_serv.get_all_clients()
        for cl in cl_l:
            print(cl)

    def __add_rental(self):
        '''
        Function that adds a rental
        :return:
        '''
        id_car = readInt("Pleas give the car id: ")
        car = self.__car_serv.find_car_srv(id_car)
        if car is None:
            print("There is no car with this id!")
            pass
        id_cl = readInt("Please give the client id: ")
        cl = self.__cl_serv.find_cl_srv(id_cl)
        if cl is None:
            print("There is no client with this id! ")
            pass
        self.__rt_serv.add_rent_srv(id_car, id_cl)


    def __list_rentals(self):
        '''
        Function that lists all rentals
        :return:
        '''
        rental_list = self.__rt_serv.list_rental_srv()
        if rental_list is None:
            print("There is no rental yet!")
        else:
            for rt in rental_list:
                print(rt.get_car().get_car_model() + " was rented by " + rt.get_cl().get_cl_name())

    def __list_sorted_rentals(self):
        '''
        Function that prints rentals sorted by client id
        :return:
        '''
        sorted_lsit = self.__rt_serv.list_sorted_srv()
        if sorted_lsit is None:
            print("There is no rental yet!")
        else:
            for rt in sorted_lsit:
                print(rt.get_car().get_car_model() + " was rented by " + rt.get_cl().get_cl_name())

    def show_ui(self):
        '''
        Function that shows the user interface
        :return:
        '''
        self.__add_data()
        while True:
            self.__print_ui()
            cmd = readInt("Please give command: ")
            if cmd == 1:
                self.__add_car()
            elif cmd == 2:
                self.__add_client()
            elif cmd == 3:
                self.__delete_car()
            elif cmd == 4:
                self.__delete_client()
            elif cmd == 5:
                self.__find_car_id()
            elif cmd == 6:
                self.__find_client_id()
            elif cmd == 7:
                self.__list_cars()
            elif cmd == 8:
                self.__list_clients()
            elif cmd == 9:
                self.__add_rental()
            elif cmd == 10:
                self.__list_rentals()
            elif cmd == 11:
                self.__list_sorted_rentals()
            else:
                print("Sorry, invalid command!")

    def __add_data(self):
        '''
        Function that populates with data
        :return:
        '''
        car1 = self.__car_serv.add_car_srv(1, "BMW", 1999, "1.9")
        car2 = self.__car_serv.add_car_srv(2, "Dacia", 2011, "2.2")
        car3 = self.__car_serv.add_car_srv(3, "Merceds", 2020, "3.0")
        car4 = self.__car_serv.add_car_srv(4, "Buggati", 1998, "3.1")
        car5 = self.__car_serv.add_car_srv(5, "Mazda", 2006, "2.9")

        cl1 = self.__cl_serv.add_cl_srv(1, "Geo", "Valcea")
        cl2 = self.__cl_serv.add_cl_srv(2, "Alina", "Cluj")
        cl3 = self.__cl_serv.add_cl_srv(3, "Marcel", "Bucuresti")
        cl4 = self.__cl_serv.add_cl_srv(4, "Adina", "Sibiu")
        cl5 = self.__cl_serv.add_cl_srv(5, "Andrei", "Oradea")

        rt1 = self.__rt_serv.add_rent_srv(2, 3)
        rt2 = self.__rt_serv.add_rent_srv(4, 5)
        rt3 = self.__rt_serv.add_rent_srv(1, 2)
        rt4 = self.__rt_serv.add_rent_srv(3, 4)


