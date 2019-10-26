"""
    @author: Badita Marin-Georgian
    @email:  geo.badita@gmail.com
    @date:   1/6/2018 23:46
"""

class UI:
    """
    Class for the user interface
    """

    def __init__(self, st_service, disc_service):
        self.__st_service = st_service
        self.__disc_service = disc_service

    def print_menu(self):
        """
        Function that prints a menu
        :return:
        """
        menu = "\t Please select a command:\n" \
               "\t 1. Add Student\n" \
               "\t 2. Add Discipline\n" \
               "\t 3. Print Students\n" \
               "\t 4. Print Disciplines\n" \
               "\t 5. Delete Student\n" \
               "\t 6. Delete Discipline\n" \
               "\t 7. Edit Student\n" \
               "\t 8. Edit Discipline\n"

        print(menu)


    def __add_st(self):
        """
        Function that adds a student in the user interface
        :return:
        """
        id_st = input("Please give a valid id: ")
        name_st = input("Please give a valid name: ")
        added_st = self.__st_service.create_student(id_st, name_st)
        if added_st is not None:
            print(added_st.get_st_name() + " was added :)\n")

    def __add_disc(self):
        """
        Function that adds a discipline in the user interface
        :return:
        """
        id_disc = input("Please give a valid id: ")
        name_disc = input("Pleaes give a valid name: ")
        prof = input("Please give the name of the professor: ")
        added_disc = self.__disc_service.create_discipline(id_disc, name_disc, prof)
        if added_disc is not None:
            print(added_disc.get_dis_name() + " was added :)\n")

    def __print_st(self):
        """
        Function that prints all the students
        :return:
        """
        st_list = self.__st_service.get_all_st()
        print(*st_list)
        print("\n")

    def __print_disc(self):
        """
        Function that prints all the disciplines
        :return:
        """
        disc_list = self.__disc_service.get_all_disc()
        print(*disc_list)
        print("\n")

    def __delete_st(self):
        """
        Function that deletes a student
        :return: the deleted student if it exists, else prints a message
        """
        id_st = input("Please give the id of the student to be deleted: ")
        del_st = self.__st_service.delete_student(id_st)
        if del_st is None:
            print("There is no student with this id!")
        else:
            print("Student " + del_st.get_st_name() + " was deleted")

    def __delete_disc(self):
        """
        Function that deletes a discipline by a given id
        :return: the deleted discipline if it exists, else prints a message
        """
        id_disc = input("Please give the id of the discipline to be deleted: ")
        del_disc = self.__disc_service.delete_discipline(id_disc)
        if del_disc is None:
            print("There is no discipline with this id!")
        else:
            print("Discipline " + del_disc.get_dis_name() + " was deleted")

    def __update_st(self):
        """
        Function that updates a student
        :return: the updated student
        """
        id_st = input("Please give the id of the student to pe updated: ")
        name_st = input("Please give the new name of the student: ")
        up_st = self.__st_service.update_student(id_st, name_st)
        if up_st is not None:
            print("Student with id " + up_st.get_st_id() + " was updated!")

    def show_ui(self):
        """
        Function that controls the user interface actions
        :return:
        """
        self._add_data()
        while True:
            self.print_menu()
            cmd = input()
            if cmd == '1':
                self.__add_st()
            elif cmd == '2':
                self.__add_disc()
            elif cmd == '3':
                self.__print_st()
            elif cmd == '4':
                self.__print_disc()
            elif cmd == '5':
                self.__delete_st()
            elif cmd == '6':
                self.__delete_disc()
            elif cmd == '7':
                self.__update_st()


    def _add_data(self):
        """
        Function that adds data to the application
        :return:
        """
        self.__st_service.create_student("ab123", "Alexandru")
        self.__st_service.create_student("cd125", "Roberta Stefana")
        self.__st_service.create_student("zx124", "Hogea Cristina")
        self.__st_service.create_student("bm199", "Badita Marin-Georgian")
        self.__st_service.create_student("ra561", "Rafaila Alexandru")
        self.__st_service.create_student("ra123", "Razi Alexis")
        self.__st_service.create_student("gm151", "Gabi Matko")

        self.__disc_service.create_discipline("1", "FP", "Istvan")
        self.__disc_service.create_discipline("2", "Analiza", "Berinde Stefan")
        self.__disc_service.create_discipline("3", "Algebra", "Modoi Cirprian")
        self.__disc_service.create_discipline("4", "Logica Computationala", "Mihis Andreea")
        self.__disc_service.create_discipline("5", "ASC", "Alexandru Vancea")
        self.__disc_service.create_discipline("6", "Teoria Grafurilor", "Suciu Mihai")
        self.__disc_service.create_discipline("7", "Sisteme de Operare", "Danciuc Mihai")


