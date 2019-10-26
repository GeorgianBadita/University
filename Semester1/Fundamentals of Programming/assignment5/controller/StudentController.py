class StudentController:
    def __init__(self, repository):
        '''
        constructor for StudentController class
        :param repository: repository for students
        '''
        self.__repository = repository

    def store_student_ctr(self, student):
        '''
        Add a student to the repository
        :param student: student to be added
        '''
        return self.__repository.store_student_rep(student)

    def delete_student_ctr(self, student):
        '''
        Delete a student from the repository
        :param student: student to be deleted
        '''
        print(student)
        return self.__repository.delete_student_rep(student)

    def find_student_ctr(self, student_id):
        '''
        Find a student from the repository by id
        :param student_id: id to search by
        :return: student having the given id, if it was found, None otherwise
        '''
        return self.__repository.find_student_rep(student_id)

    def get_all_students_ctr(self):
        '''
        Get all students from the repository
        :return: list of all students
        '''
        return self.__repository.get_all_students_rep()

    def update_student_ctr(self, student, student_name):
        '''
        Update a student's name
        :param student: student to be updated
        :param student_name: new name of student
        '''
        return self.__repository.update_student_rep(student, student_name)

    def find_student_name_ctr(self, student_name):
        '''
        Find all students in the repository matching/partially matching a given name
        :param student_name: the given name
        :return: a list of all students matching/partially matching the given name
        '''
        return self.__repository.find_student_name_rep(student_name)

    def find_student_id_ctr(self, student_id):
        '''
        Find all students in the repository matching/partially matching a given id
        :param student_id: the given id
        :return: a list of all students matching/partially matching the given id
        '''
        return self.__repository.find_student_id_rep(student_id)




