class UndoRedo:
    '''
    Class for UndoRedo operation
    '''

    def __init__(self, function, counter_function, params_function, params_counter):
        '''
        UndoRedo class constructor
        :param function: controller of the class
        :param params:  parameters of the called function
        '''
        self.__function = function
        self.__counter_function = counter_function
        self.__counter_sub_function = None
        self.__params_function = params_function
        self.__params_counter = params_counter

    def get_sub_counter_function(self):
        '''
        Function that gets the second counter function if needed
        :return:
        '''
        return  self.__counter_sub_function


    def get_params_counter(self):
        '''
        Function that gets the parameters for the counter function
        :return:
        '''
        return self.__params_counter

    def get_function(self):
        '''
        gets the controller of the UndoRedo operations
        :return: the controller
        '''
        return  self.__function

    def get_counter_function(self):
        '''
        gets the counter_function of the controller functon
        :return:
        '''
        return  self.__counter_function

    def get_params_function(self):
        '''
        gets the parameters of the called function
        :return: the parameters of the called function
        '''
        return  self.__params_function

    def set_sub_counter_function(self, sub_func):
        '''
        Function that sets the value of the sub_counter_functon field
        :return:
        '''
        self.__counter_sub_function = sub_func

    def set_params(self, new_params):
        '''
        Function that sets the value of the parameters
        :param new_params:
        :return:
        '''
        self.__params_function = new_params