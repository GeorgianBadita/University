from controller.UndoController import UndoController
from domain.Discipline import Discipline
from domain.Grade import Grade
from domain.Student import Student
from validator.Validator import ValidatorException
from domain.UndoRedo import UndoRedo


class UI:

    def __init__(self, student_controller, discipline_controller, grade_controller):
        '''
        constructor of UI class
        '''
        self.__student_controller = student_controller
        self.__discipline_controller = discipline_controller
        self.__grade_controller = grade_controller
        self.__undo = UndoController()
        self.__redo = UndoController()

    @staticmethod
    def print_menu():

        '''
        creating the menu with all the available commands
        '''

        string = '\nAvailable commands:\n'
        string += '\t 1 - Add student\n'
        string += '\t 2 - Add discipline\n'
        string += '\t 3 - Remove student\n'
        string += '\t 4 - Remove discipline\n'
        string += '\t 5 - List students \n'
        string += '\t 6 - List disciplines\n'
        string += '\t 7 - Update student \n'
        string += '\t 8 - Update discipline\n'
        string += '\t 9 - Grade student\n'
        string += '\t 10 - Search student by ID\n'
        string += '\t 11 - Search student by name \n'
        string += '\t 12 - Search discipline by ID \n'
        string += '\t 13 - Search discipline by name \n'
        string += '\t 14 - Show all students enrolled at a discipline\n'
        string += '\t 15 - Show failing students \n'
        string += '\t 16 - Show best students\n'
        string += '\t 17 - Show ordered disciplines\n'
        string += '\t 18 - Show grades\n'
        string += '\t 19 - Undo last operation\n'
        string += '\t 20 - Redo last operation\n'
        string += '\t 0 - Exit\n'
        print(string)

    @staticmethod
    def print_submenu():
        string = '\t 1 - By average grade\n'
        string += '\t 2 - Alphabetically\n'
        print(string)

    def main_menu(self):
        while True:
            try:
                self.print_menu()
                command = input("Enter command: ")
                if command == '1':
                    self.__add_student()
                elif command == '2':
                    self.__add_discipline()
                elif command == '3':
                    self.__remove_student()
                elif command == '4':
                    self.__remove_discipline()
                elif command == '5':
                    self.__list_students()
                elif command == '6':
                    self.__list_disciplines()
                elif command == '7':
                    self.__update_student()
                elif command == '8':
                    self.__update_discipline()
                elif command == '9':
                    self.__grade_student()
                elif command == '10':
                    self.__search_student_id()
                elif command == '11':
                    self.__search_student_name()
                elif command == '12':
                    self.__search_discipline_id()
                elif command == '13':
                    self.__search_discipline_name()
                elif command == '14':
                    self.__students_at_discipline()
                elif command == '15':
                    self.__failing_students(True)
                elif command == '16':
                    self.__best_students()
                elif command == '17':
                    self.__sorted_disciplines()
                elif command == '18':
                    self.__print_grades()
                elif command == '19':
                    self.__undo_operation()
                elif command == '20':
                    self.__redo_operation()
                elif command == '0':
                    exit()
                else:
                    print("Invalid command! ")
            except Exception as exc:
                print("Error encountered " + str(exc))

    def __add_student(self):
        '''
        function for adding a new student, after validating the input data
        '''
        s_id = input("Enter student ID: ")
        student_name = input("Enter student name: ")
        if str.isalpha(student_name):
            try:
                student_id = int(s_id)
                try:
                    student = Student(student_id, student_name)
                    self.__student_controller.store_student_ctr(student)
                    undo_redo = UndoRedo(self.__student_controller.store_student_ctr,
                                         self.__student_controller.delete_student_ctr, student, [student, []])
                    undo_redo.set_sub_counter_function(self.__grade_controller.delete_gstudent_ctr)
                    self.__undo.store(undo_redo)
                except ValidatorException as ex:
                    print(ex.args)
            except ValueError:
                print("An id must be an integer. ")
        else:
            print("A name must contain only letters. ")

    def __remove_student(self):
        '''
        remove a student by his id, if it exists
        '''
        s_id = input("Enter student ID: ")
        try:
            student_id = int(s_id)
            student = self.__student_controller.find_student_ctr(student_id)
            print(student)
            if student is not False:
                self.__student_controller.delete_student_ctr(student)
                list_deleted = self.__grade_controller.delete_gstudent_ctr(student_id)
                params = [student, list_deleted]
                undo_store = UndoRedo(self.__student_controller.delete_student_ctr,
                                      self.__student_controller.store_student_ctr, params, student)
                undo_store.set_sub_counter_function(self.__grade_controller.assign_grades_ctr)
                self.__undo.store(undo_store)

            else:
                print("The student does not exist! ")
        except ValueError:
            print("Invalid input. ")

    def __update_student(self):
        '''
        search a student by his id and if he exists, update his name
        '''
        s_id = input("Enter student ID: ")
        try:
            student_id = int(s_id)
            student = self.__student_controller.find_student_ctr(student_id)
            if student is not False:
                student_name = input("Enter new name: ")
                if str.isalpha(student_name):
                    params = [student, student.student_name(), student_name]
                    undo_redo = UndoRedo(self.__student_controller.update_student_ctr,
                                         self.__student_controller.update_student_ctr, params, params)
                    self.__student_controller.update_student_ctr(student, student_name)
                    self.__undo.store(undo_redo)
                else:
                    print("A name must contain only letters. ")
            else:
                print("Student doesn't exist! ")
        except ValueError:
            print("Invalid input. ")

    def __add_discipline(self):
        '''
        add a new discipline
        '''
        d_id = input("Enter discipline ID: ")
        discipline_name = input("Enter discipline name: ")
        if str.isalpha(discipline_name):
            try:
                discipline_id = int(d_id)
                try:
                    discipline = Discipline(discipline_id, discipline_name)
                    self.__discipline_controller.store_discipline_ctr(discipline)
                    undo_redo = UndoRedo(self.__discipline_controller.store_discipline_ctr,
                                         self.__discipline_controller.delete_discipline_ctr, discipline,
                                         [discipline, []])
                    undo_redo.set_sub_counter_function(self.__grade_controller.delete_gdiscipline_ctr)
                    self.__undo.store(undo_redo)
                except ValidatorException as ex:
                    print(ex.args)
            except ValueError:
                print("An ID must be an integer. ")
        else:
            print("A name must contain only letters. ")

    def __remove_discipline(self):
        '''
        remove a discipline
        '''
        d_id = input("Enter discipline ID: ")
        try:
            discipline_id = int(d_id)
            discipline = self.__discipline_controller.find_discipline_ctr(discipline_id)
            if discipline is not False:
                self.__discipline_controller.delete_discipline_ctr(discipline)
                list_del = self.__grade_controller.delete_gdiscipline_ctr(discipline_id)
                params = [discipline, list_del]
                undo_redo = UndoRedo(self.__discipline_controller.delete_discipline_ctr,
                                     self.__discipline_controller.store_discipline_ctr, params, discipline)
                undo_redo.set_sub_counter_function(self.__grade_controller.assign_grades_disc_ctr)
                self.__undo.store(undo_redo)
            else:
                print("The discipline does not exist! ")
        except ValueError:
            print("Invalid input. ")

    def __update_discipline(self):
        '''
        update a discipline
        '''
        d_id = input("Enter discipline ID: ")
        try:
            discipline_id = int(d_id)
            discipline = self.__discipline_controller.find_discipline_ctr(discipline_id)
            if discipline is not False:
                discipline_name = input("Enter new name: ")
                if str.isalpha(discipline_name):
                    params = [discipline, discipline.discipline_name(), discipline_name]
                    self.__discipline_controller.update_discipline_ctr(discipline, discipline_name)
                    undo_redo = UndoRedo(self.__discipline_controller.update_discipline_ctr,
                                         self.__discipline_controller.update_discipline_ctr, params, params)
                    self.__undo.store(undo_redo)
                else:
                    print("A name must contain only letters. ")
            else:
                print("Discipline doesn't exist! ")
        except ValueError:
            print("Invalid input. ")

    def __list_students(self):
        '''
        list all existent students
        '''
        all_students = self.__student_controller.get_all_students_ctr()
        if len(all_students) == 0:
            print("Currently there are no students. ")
        else:
            for student in all_students:
                print(student.__str__())

    def __list_disciplines(self):
        '''
        list all existing disciplines
        '''
        all_disciplines = self.__discipline_controller.get_all_disciplines_ctr()
        if len(all_disciplines) == 0:
            print("Currently there are no disciplines. ")
        else:
            for discipline in all_disciplines:
                print(discipline.__str__())

    def __grade_student(self):
        '''
        give a grade to a student at a discipline
        '''
        d_id = input("Enter discipline ID: ")
        s_id = input("Enter student ID: ")
        try:
            discipline_id = int(d_id)
            student_id = int(s_id)
            discipline = self.__discipline_controller.find_discipline_ctr(discipline_id)
            student = self.__student_controller.find_student_ctr(student_id)
            if discipline is not False and student is not False:
                g_value = input("Enter grade: ")
                try:
                    grade_value = float(g_value)
                    grade = Grade(discipline_id, student_id, grade_value)
                    self.__grade_controller.store_grade_ctr(grade)
                    undo_redo = UndoRedo(self.__grade_controller.store_grade_ctr,
                                         self.__grade_controller.delete_one_grade_ctr, grade, grade)
                    self.__undo.store(undo_redo)

                except ValueError:
                    print("A grade must be a number. ")
            elif discipline is False:
                print("There's no such discipline. ")
            elif student is False:
                print("There's no such student. ")
        except ValueError:
            print("Invalid input. ")

    def __search_student_id(self):
        '''
        search for a student by id
        '''
        s_id = input("Enter student ID: ")
        try:
            student_id = int(s_id)
            print(self.__student_controller.find_student_id_ctr(student_id))
        except ValueError:
            print("Invalid input. ")

    def __search_discipline_id(self):
        '''
        search for a discipline by id
        '''
        d_id = input("Enter discipline ID: ")
        try:
            discipline_id = int(d_id)
            print(self.__discipline_controller.find_discipline_id_ctr(discipline_id))
        except ValueError:
            print("Invalid input. ")

    def __search_student_name(self):
        '''
        search for a student by name
        '''
        student_name = input("Enter student name: ")
        print(self.__student_controller.find_student_name_ctr(student_name))

    def __search_discipline_name(self):
        '''
        search for a discipline by name
        '''
        discipline_name = input("Enter discipline name: ")
        print(self.__discipline_controller.find_discipline_name_ctr(discipline_name))

    def __students_at_discipline(self):
        '''
        get all students enrolled at a discipline
        '''
        self.print_submenu()
        command = input("Enter option: ")
        d_id = input("Enter discipline ID: ")
        try:
            discipline_id = int(d_id)
            if self.__discipline_controller.find_discipline_ctr(discipline_id):
                if command == '1':
                    grade_list = []
                    student_ids = self.__grade_controller.get_students_at_discipline(discipline_id)
                    for student_id in set(student_ids):
                        grade_list.append(Grade(discipline_id, student_id,
                                                self.__grade_controller.get_student_average_at_discipline(student_id,
                                                                                                          discipline_id)))
                    grade_list.sort(key=lambda x: x.grade_value(), reverse=True)
                    for student_average in grade_list:
                        print(student_average.__str__())

                elif command == '2':
                    student_ids = self.__grade_controller.get_students_at_discipline(discipline_id)
                    students = self.__student_controller.get_all_students_ctr()
                    students.sort(key=lambda x: x.student_name())
                    for student in students:
                        if student.student_id() in student_ids:
                            print('Discipline ID:' + str(discipline_id) + " " + student.__str__())
                else:
                    print("Invalid command. ")
            else:
                print("Discipline doesn't exist. ")
        except ValueError:
            print("Invalid ID input. ")

    def __failing_students(self, show_all):
        '''
        get all students who are failing at a least one discipline
        '''
        students = self.__student_controller.get_all_students_ctr()
        disciplines = self.__discipline_controller.get_all_disciplines_ctr()
        failing_students = []
        failing = 0
        for student in students:
            avg_list = []
            ok = 0
            for discipline in disciplines:
                avg_list.append(
                    self.__grade_controller.average_grade_ctr(student.student_id(), discipline.discipline_id()))
            for item in avg_list:
                if float(item) < 5.0 and item != 0:
                    ok = 1
            if ok == 1:
                failing = 1
                if show_all:
                    print(student.__str__())
                failing_students.append(student.student_id())
        if failing == 0:
            print("There are no failing students. ")
        return failing_students

    def __best_students(self):
        '''
        get all students having the aggregated grade >= to 5
        '''
        students = self.__student_controller.get_all_students_ctr()
        disciplines = self.__discipline_controller.get_all_disciplines_ctr()
        failing_students = self.__failing_students(False)
        best_grade = []
        for student in students:
            if student.student_id() not in failing_students:
                s = 0
                cont = 0
                avg_list = []
                for discipline in disciplines:
                    avg_list.append(
                        self.__grade_controller.average_grade_ctr(student.student_id(), discipline.discipline_id()))
                for item in avg_list:
                    if item != 0:
                        s += float(item)
                        cont += 1
                if cont != 0:
                    final_grade = float(s / cont)
                    if final_grade > 5.0:
                        best_grade.append([student.__str__(), format(final_grade, '.2f')])
        best_grade.sort(key=lambda x: x[1], reverse=True)
        if len(best_grade) > 0:
            for student in best_grade:
                print(student.__str__())
        else:
            print("There are no best students. ")

    def __sorted_disciplines(self):
        '''
        get all disciplines sorted by the average grade of all students enrolled at each discipline
        '''
        disciplines = self.__discipline_controller.get_all_disciplines_ctr()
        avg_list = []
        for discipline in disciplines:
            avg_grade = self.__grade_controller.average_discipline_ctr(discipline.discipline_id())
            if avg_grade != 0:
                avg_list.append((discipline.__str__(), format(avg_grade, '.2f')))
        if len(avg_list) > 0:
            avg_list.sort(key=lambda x: x[1], reverse=True)
            for discipline in avg_list:
                print(discipline)
        else:
            print("Currently there are no grades at any discipline. ")

    def __print_grades(self):
        grades = self.__grade_controller.get_all_grades_ctr()
        for grade in grades:
            print(grade)

    def __undo_operation(self):
        '''
        Function that controls the undo functionality
        :return:
        '''

        if not self.__undo.get_operations():  # if the undo list is empty
            # we can't do more undo
            print("Can't do more undo!")
            return

        stack = self.__undo.get_operations()  # stack represents the operations list
        previous = stack.pop()  # previous is the last operation made
        self.__redo.store(previous)
        function = previous.get_counter_function()  # we must apply the counter_function
        # of the last operations
        params = previous.get_params_function()  # we get the parameters needed for the function
        if previous.get_function() == self.__student_controller.delete_student_ctr or previous.get_function() == self.__discipline_controller.delete_discipline_ctr:
            function(params[0])
            sub_function = previous.get_sub_counter_function()
            sub_function(params[1])
        elif previous.get_function() == self.__student_controller.store_student_ctr or previous.get_function() == self.__discipline_controller.store_discipline_ctr:
            function(params)
            sub_function = previous.get_sub_counter_function()
            if function == self.__discipline_controller.delete_discipline_ctr:
                id_deleted = params.discipline_id()
            else:
                id_deleted = params.student_id()
            sub_function(id_deleted)
        elif function == self.__student_controller.update_student_ctr or function == self.__discipline_controller.update_discipline_ctr:
            function(params[0], params[1])
        else:
            function(params)

    def __redo_operation(self):
        '''
        Function that controls the redo functionality
        :return:
        '''

        if not self.__redo.get_operations():
            print("Can't do more redo!")
            return

        stack = self.__redo.get_operations()
        next = stack.pop()
        self.__undo.store(next)
        function = next.get_function()
        params = next.get_params_counter()
        if function == self.__student_controller.delete_student_ctr or function == self.__discipline_controller.delete_discipline_ctr:
            function(params)
            if function == self.__student_controller.delete_student_ctr:
                id_deleted = params.student_id()
                sub_function = self.__grade_controller.delete_gstudent_ctr
            else:
                id_deleted = params.discipline_id()
                sub_function = self.__grade_controller.delete_gdiscipline_ctr
            sub_function(id_deleted)
        elif function == self.__student_controller.store_student_ctr or function == self.__discipline_controller.store_discipline_ctr:
            function(params[0])
            sub_function = next.get_sub_counter_function()
            sub_function(params[1])
        elif function == self.__student_controller.update_student_ctr or function == self.__discipline_controller.update_discipline_ctr:
            function(params[0], params[2])
        else:
            function(params)
