class DisciplineRepositoryException(Exception):
    '''
    class for errors at the level of DisciplineRepository
    '''
    def __init__(self, message):
        self.__message = message

    def __str__(self):
        return self.__message


class DisciplineRepository:
    def __init__(self, discipline_validator):
        '''
         constructor for DisciplineRepository class
        :param discipline_validator:  validator of input data
        '''
        self.__discipline_list = {}
        self.__validator = discipline_validator

    def store_discipline_rep(self, discipline):
        '''
        Add a discipline to the repository
        :param discipline: discipline to be added
        '''
        if discipline.discipline_id() in self.__discipline_list:
            raise DisciplineRepositoryException("A discipline with this ID already exists. ")
        self.__validator.validate_discipline(discipline)
        self.__discipline_list[discipline.discipline_id()] = discipline
        return True

    def delete_discipline_rep(self, discipline):
        '''
        Delete discipline from the repository
        :param discipline: discipline to be deleted
        '''
        if discipline in self.__discipline_list.values():
            del self.__discipline_list[discipline.discipline_id()]
            return discipline
        else:
            return None

    def find_discipline_rep(self, discipline_id):
        '''
        Find a discipline in the repository by its id
        :param discipline_id: discipline's id
        :return: searched discipline if it was found, None otherwise
        '''
        for index in self.__discipline_list:
            if index == discipline_id:
                return self.__discipline_list[index]
        return False

    def get_all_disciplines_rep(self):
        '''
        Get all the disciplines in the repository in the order they were added
        :return: a list of all disciplines
        '''
        new_list = []
        for discipline in self.__discipline_list.values():
            new_list.append(discipline)
        return new_list

    def update_discipline_rep(self, discipline, discipline_name):
        '''
        Change the name of a discipline in the repository
        :param discipline: searched discipline
        :param discipline_name: new name of discipline
        '''
        if discipline.discipline_id() in self.__discipline_list:
            discipline.set_discipline_name(discipline_name)
            return True
        return False

    def find_discipline_name_rep(self, discipline_name):
        '''
        Searching all disciplines in the repository matching/partially matching a given name
        :param discipline_name: discipline name to search by
        :return: a list of all disciplines that match the criteria
        '''
        new_list = []
        for discipline in self.__discipline_list.values():
            if str.lower(discipline_name) in str.lower(discipline.discipline_name()):
                new_list.append(discipline.__str__())
        if len(new_list) > 0:
            return new_list
        else:
            raise DisciplineRepositoryException("There is no matching discipline! ")

    def find_discipline_id_rep(self, discipline_id):
        '''
        Searching all disciplines in the repository matching/partially matching a given id
        :param discipline_id: discipline id to search by
        :return: a list of all disciplines that match the criteria
        '''
        new_list = []
        for discipline in self.__discipline_list.values():
            if str(discipline_id) in str(discipline.discipline_id()):
                new_list.append(discipline.__str__())
        if len(new_list) > 0:
            return new_list
        else:
            raise DisciplineRepositoryException("There is no matching discipline! ")
