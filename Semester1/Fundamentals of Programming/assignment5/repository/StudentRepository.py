class StudentRepositoryException(Exception):
    '''
    Class for exceptions at the level of StudentRepository
    '''
    def __init__(self, message):
        self.__message = message

    def __str__(self):
        return self.__message


class StudentRepository:
    def __init__(self, student_validator):
        '''
        constructor of StudentRepository class
        :param student_validator:
        '''
        self.__student_list = {}
        self.__validator = student_validator

    def store_student_rep(self, student):
        '''
        Add a new student to the repository
        :param student: student to be added
        '''
        if student.student_id() in self.__student_list:
            raise StudentRepositoryException("A student with this ID already exists! ")
        self.__validator.validate_student(student)
        self.__student_list[student.student_id()] = student
        return True

    def delete_student_rep(self, student):
        '''
        Delete a student from the repository
        :param student: student to be deleted
        '''
        if student in self.__student_list.values():
            del self.__student_list[student.student_id()]
            return student
        else:
            return None

    def find_student_rep(self, student_id):
        '''
        Search a student in the repository by id
        :param student_id: id of the student to be searched
        :return: the searched student, if it was found, None otherwise
        '''
        for index in self.__student_list:
            if index == student_id:
                return self.__student_list[index]
        return False

    def get_all_students_rep(self):
        '''
        Get all the students from the repository
        :return: a list of all students from the repository
        '''
        new_list = []
        for student in self.__student_list.values():
            new_list.append(student)
        return new_list

    def update_student_rep(self, student, student_name):
        '''
        Change the name of a student in the repository
        :param student: searched student
        :param student_name: new name of the student
        '''
        if student.student_id() in self.__student_list:
            student.set_student_name(student_name)
            return True
        return False

    def find_student_name_rep(self, student_name):
        '''
        Searching all students matching/partially matching a given name
        :param student_name: given name
        :return: a list of all students matching/partially matching a given name
        '''
        new_list = []
        for student in self.__student_list.values():
            if str.lower(student_name) in str.lower(student.student_name()):
                new_list.append(student.__str__())
        if len(new_list) > 0:
            return new_list
        else:
            raise StudentRepositoryException("There is no matching student! ")

    def find_student_id_rep(self, student_id):
        '''
        Searching all students matching/partially matching a given id
        :param student_id: given id
        :return: a list of all students matching/partially matching a given id
        '''
        new_list = []
        for student in self.__student_list.values():
            if str(student_id) in str(student.student_id()):
                new_list.append(student.__str__())
        if len(new_list) > 0:
            return new_list
        else:
            raise StudentRepositoryException("There is no matching student! ")
