class Grade:
    def __init__(self, discipline_id, student_id, grade_value):
        '''
        constructor of Grade class
        '''
        self.__discipline_id = discipline_id
        self.__student_id = student_id
        self.__grade_value = grade_value

    def discipline_id(self):
        '''
        discipline id getter
        :return:  id of the discipline
        '''
        return self.__discipline_id

    def student_id(self):
        '''
        student id getter
        :return: id of the student
        '''
        return self.__student_id

    def grade_value(self):
        '''
        grade value getter
        :return: value of the grade
        '''
        return self.__grade_value

    def __str__(self):
        '''
        Overload the str function
        '''
        return "Discipline ID:" + str(self.__discipline_id) + ", Student ID:" + str(self.__student_id) +\
               ", Grade:" + str(self.__grade_value)
