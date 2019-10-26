class Discipline:
    def __init__(self, discipline_id, discipline_name):
        '''
        constructor of Discipline class
        '''
        self.__discipline_id = discipline_id
        self.__discipline_name = discipline_name

    def discipline_name(self):
        '''
        discipline name getter
        :return: name of the discipline
        '''
        return self.__discipline_name

    def discipline_id(self):
        '''
        discipline id getter
        :return: id of the discipline
        '''
        return self.__discipline_id

    def set_discipline_name(self, new_name):
        '''
        discipline id setter
        :param new_name: name to be given to the discipline
        :return:
        '''
        self.__discipline_name = new_name

    def __eq__(self, other):
        if not isinstance(other, Discipline):
            return False
        return self.__discipline_name == other.discipline_name()

    def __str__(self):
        '''
        Overload the str function
        '''
        return "ID:" + str(self.__discipline_id) + ", Name: " + str(self.__discipline_name)