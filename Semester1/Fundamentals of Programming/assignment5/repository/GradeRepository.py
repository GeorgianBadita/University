

class GradeRepository:
    def __init__(self, grade_validator):
        '''
        Constructor for GradeRepository class
        :param grade_validator: validator of input data
        '''
        self.__grade_list = []
        self.__validator = grade_validator


    def delete_last_grade_rep(self):
        '''
        Function that deletes the last added grade
        :return:
        '''
        return  self.__grade_list.pop()

    def store_grade_rep(self, grade):
        '''
        Add  grade to the repository
        :param grade: grade to be added
        :return:
        '''
        self.__validator.validate_grade(grade)
        self.__grade_list.append(grade)
        return True

    def get_all_grades_rep(self):
        '''
        Get all grades in the repository in the order they were added
        :return: list of all grades in the repository
        '''
        new_list = []
        for grade in self.__grade_list:
            new_list.append(grade)
        return new_list

    def delete_gstudent_rep(self, student_id):
        '''
        Delete a student from the repository
        :param student_id: id of a student to be deleted
        '''
        list_deleted = []
        grades = self.__grade_list.copy()
        for item in grades:
            if item.student_id() == student_id:
                list_deleted.append(item)
                self.__grade_list.remove(item)

        return list_deleted

    def assign_grades_rep(self, list_grades):
        '''
        Assign more grades given as a list with id, disc and grade
        :param list_grades:
        :return:
        '''

        for grade in list_grades:
            self.store_grade_rep(grade)


    def delete_gdiscipline_rep(self, discipline_id):
        '''
        Delete all grades at a discipline from the repository
        :param discipline_id: id of the given discipline
        '''
        list_deleted = []
        disciplines = self.__grade_list.copy()
        for item in disciplines:
            if item.discipline_id() == discipline_id:
                list_deleted.append(item)
                self.__grade_list.remove(item)

        return list_deleted

    def assign_grades_disc_rep(self, list_grades):
        '''
        Reassign more grades given as a list with id, disc and grade
        :param list_grades:
        :return:
        '''

        for grade in list_grades:
            self.store_grade_rep(grade)



    def get_students_at_discipline(self, discipline_id):
        '''
        Get all students from the repository that are enrolled at a given discipline
        :param discipline_id: id of the given discipline
        :return: list of all students enrolled at the given discipline
        '''
        new_list = []
        for item in self.__grade_list:
            if item.discipline_id() == discipline_id:
                new_list.append(item.student_id())
        return new_list

    def student_average_at_discipline(self, student_id, discipline_id):
        '''
        Get a student average grade at a given discipline
        :param student_id: id of the given student
        :param discipline_id: id of the given discipline
        :return: average grade of the student
        '''
        new_list = []
        for item in self.__grade_list:
            if item.student_id() == student_id and item.discipline_id() == discipline_id:
                new_list.append(item.grade_value())
        total = 0
        for grade in new_list:
            total += grade

        return total / len(new_list)

    def student_average(self, student_id):
        '''
        Get the student average at all the disciplines he is enrolled to
        :param student_id: id of the given student
        :return: average grade
        '''
        new_list = []
        for item in self.__grade_list:
            if item.student_id() == student_id:
                new_list.append(item.grade_value())
        total = 0
        for grade in new_list:
            total += grade
        if len(new_list) > 0:
            return float(total / len(new_list))
        else:
            return 0

    def average_grade_rep(self, student_id, discipline_id):
        '''
        Get the aggregated grade of a student at a discipline
        :param student_id: id of the given student
        :param discipline_id: id of the given discipline
        :return: aggregated grade
        '''
        s = 0
        cont = 0
        for item in self.__grade_list:
            if item.student_id() == student_id and item.discipline_id() == discipline_id:
                s += item.grade_value()
                cont += 1
        if cont > 0:
            return float(s / cont)
        else:
            return 0

    def average_discipline_rep(self, discipline_id):
        '''
        Get the average of all the grades at a discipline
        :param discipline_id: id of the given discipline
        :return: average grade at the given discipline
        '''
        s = 0
        cont = 0
        for item in self.__grade_list:
            if item.discipline_id() == discipline_id:
                s += item.grade_value()
                cont += 1
        if cont > 0:
            return float(s / cont)
        else:
            return 0
