class GradeController:
    def __init__(self, repository):
        '''
        constructor for GradeController class
        :param repository: repository for grades
        '''
        self.__repository = repository

    def store_grade_ctr(self, grade):
        '''
        Add a new grade to the repository
        :param grade: grade to be added
        '''
        return self.__repository.store_grade_rep(grade)

    def delete_gstudent_ctr(self, student_id):
        '''
        Delete all grades of a student from the repository
        :param student_id: the id of the student
        '''
        print(student_id)
        return self.__repository.delete_gstudent_rep(student_id)

    def delete_gdiscipline_ctr(self, discipline_id):
        '''
        Delete all grades to a discipline from the repository
        :param discipline_id: id of the discipline
        '''
        return self.__repository.delete_gdiscipline_rep(discipline_id)

    def get_all_grades_ctr(self):
        '''
        Get all grades from the repository in order of adding
        :return: a list of all grades from the repository
        '''
        return self.__repository.get_all_grades_rep()

    def delete_one_grade_ctr(self, arg):
        '''
        Deletes the last added grade
        :return:
        '''
        return  self.__repository.delete_last_grade_rep()

    def get_students_at_discipline(self, discipline_id):
        '''
        Search for all students from the repository which are enrolled to a discipline
        :param discipline_id: id of the given discipline
        :return: a list of all students enrolled at the given discipline
        '''
        return self.__repository.get_students_at_discipline(discipline_id)

    def get_student_average_at_discipline(self, student_id, discipline_id):
        '''
        Get from the repository all grades of a student to a discipline that he is enrolled to
        :param student_id: id of the given student
        :param discipline_id: if of the given discipline
        :return: the average grade of the student's grades
        '''
        return self.__repository.student_average_at_discipline(student_id, discipline_id)

    def get_student_average(self, student_id):
        '''
        Get from the repository all grades of a student to all the disciplines that he is enrolled to
        :param student_id: id of the given student
        :return: average grade of the student's grades
        '''
        return self.__repository.student_average(student_id)

    def average_grade_ctr(self, student_id, discipline_id):
        '''
        Get the average of a student's grades at a given discipline
        :param student_id: id of the given student
        :param discipline_id: id of the given discipline
        :return: return the average grade
        '''
        return self.__repository.average_grade_rep(student_id, discipline_id)

    def average_discipline_ctr(self, discipline_id):
        '''
        Get the average of the grades of all students at a given discipline
        :param discipline_id: the id of the given discipline
        :return: average grade of the discipline
        '''
        return self.__repository.average_discipline_rep(discipline_id)

    def assign_grades_ctr(self, list_grades):
        '''
        Assign a list of grades
        :param list_grade:
        :return:
        '''
        self.__repository.assign_grades_rep(list_grades)

    def assign_grades_disc_ctr(self, list_grades):
        '''
        Assign a list of grades
        :param list_grade:
        :return:
        '''

        self.__repository.assign_grades_disc_rep(list_grades)