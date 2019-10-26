class DisciplineController:
    def __init__(self, repository):
        '''
        constructor for DisciplineController class
        :param repository: repository for disciplines
        '''
        self.__repository = repository

    def store_discipline_ctr(self, discipline):
        '''
        Add a discipline to the repository
        :param discipline: discipline to be added
        '''
        return self.__repository.store_discipline_rep(discipline)

    def delete_discipline_ctr(self, discipline):
        '''
        Delete a discipline from the repository
        :param discipline: discipline to be deleted
        '''
        return self.__repository.delete_discipline_rep(discipline)

    def find_discipline_ctr(self, discipline_id):
        '''
        find a discipline from the repository by id
        :param discipline_id: id of the searched discipline
        :return: returns discipline having the given id, if it was found, None otherwise
        '''
        return self.__repository.find_discipline_rep(discipline_id)

    def get_all_disciplines_ctr(self):
        '''
        Get all disciplines from the repository
        :return: list of all disciplines
        '''
        return self.__repository.get_all_disciplines_rep()

    def update_discipline_ctr(self, discipline, discipline_name):
        '''
        Update a discipline's name
        :param discipline:  discipline to be updated
        :param discipline_name: new name of the discipline
        '''
        return self.__repository.update_discipline_rep(discipline, discipline_name)

    def find_discipline_name_ctr(self, discipline_name):
        '''
        Find all disciplines in repository matching or partially matching a given name
        :param discipline_name: the name by which we search in the repository
        :return: a list of all disciplines matching/partially matching the given name
        '''
        return self.__repository.find_discipline_name_rep(discipline_name)

    def find_discipline_id_ctr(self, discipline_id):
        '''
        Find all disciplines in repository matching or partially matching a given id
        :param discipline_id: the id by which we search in the repository
        :return: a list of all disciplines matching/partially matching the given id
        '''
        return self.__repository.find_discipline_id_rep(discipline_id)
