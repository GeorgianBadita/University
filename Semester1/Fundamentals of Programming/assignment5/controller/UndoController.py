
class UndoController:
    def __init__(self):
        self.__operations = []

    def store(self, undo_redo):
        '''
        Function that stores an UndoRedo object
        :param controller:
        :param counter_function:
        :param params:
        :return: doesn't return anything
        '''

        # store into the list
        self.__operations.append(undo_redo)

    def get_operations(self):
        '''
        Function that gets the operations of the undo_controller
        :return:
        '''
        return self.__operations
