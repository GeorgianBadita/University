"""
    @author: Badita Marin-Georgian
    @email:  geo.badita@gmail.com
    @date:   12/9/2017 22:19
"""
class RepositoryException(Exception):
    pass

class ClientRepository:
    '''
    Class to control data about clients (data manager)
    '''

    def __init__(self, client_Validator):
        '''

        :param entity_validator: the validator for the Client class
        '''
        self.__list = {}
        self.__validator = client_Validator

    def store_client(self, client):
        '''
        Class to store the client into the list
        Raises RepositoryException if the client already in list
        :post - Client added to the repository
        :param client:
        :return:
        '''
        if not client.get_cl_id() in self.__list:
            self.__validator.validate(client)
            self.__list[client.get_cl_id()] = client
        else:
            raise RepositoryException("Duplicated ID!")

    def get_all_clients(self):
        return list(self.__list.values())

    def find_client(self, client_id):
        '''
        Function that finds a client by id
        :return: returns the client if it's in list, None otherwise
        '''
        client_list = self.get_all_clients()
        for client in client_list:
            if client_id == client.get_cl_id():
                return client
        return None

    def delete_client(self, client_id):
        '''
        Function that deletes a client by id if it exists
        Returns the deleted client, None otherwise
        :param client_id:
        :return:
        '''
        client_ret = self.find_client(client_id)
        if client_ret is not None:
            del self.__list[client_id]
            return client_ret
        else:
            return None