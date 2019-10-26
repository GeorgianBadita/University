class Student:
    def __init__(self, student_id, student_name):
        '''
        constructor of Student class
        '''
        self.__student_id = student_id
        self.__student_name = student_name

    def student_id(self):
        '''
        student id getter
        :return: id of a student
        '''
        return self.__student_id

    def student_name(self):
        '''
        student name getter
        :return: name of a student
        '''
        return self.__student_name

    def set_student_name(self, new_name):
        '''
        student name setter
        :param new_name: name to be given to the student
        '''
        self.__student_name = new_name

    def __eq__(self, other):
        if not isinstance(other, Student):
            return False
        return self.__student_name == other.student_name()

    def __str__(self):
        '''
        Overload the str function
        '''
        return "Id:" + str(self.__student_id) + ", Name: " + str(self.__student_name)
