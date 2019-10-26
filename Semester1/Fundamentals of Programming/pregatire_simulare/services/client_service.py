"""
    @author: Badita Marin-Georgian
    @email:  geo.badita@gmail.com
    @date:   12/9/2017 22:49
"""
from domain.entities import Client
from repository.client_repository import RepositoryException
from domain.validators import ValidatorException

class ClientService:
    '''
    Class which controlls the Client class performed actions
    '''

    def __init__(self, cl_rep):
        '''

        :param cl_rep: ClientRepository
        '''
        self.__rep = cl_rep

    def add_cl_srv(self, id, name, addr):
        '''
        Function that stores a client into the repository, using ClientRepository
        Creates a new Client object and adds it into repository
        post: client will be added to the repository
        :param: id - int
        :param: name - string
        :param: addr - string
        :return:
        '''
        client = Client(id, name, addr)
        try:
            self.__rep.store_client(client)
        except RepositoryException as ex:
            print(ex)
        except ValidatorException as ex:
            print(ex.args)

    def get_all_clients(self):
        '''
        Function that returs a list with all clients
        :return:
        '''
        return self.__rep.get_all_clients()

    def del_cl_srv(self, client_id):
        '''
        Function that deletes a client by a given id, using
        the delete function from repository
        :param client_id:
        :return:
        '''
        del_client = self.__rep.delete_client(client_id)
        if del_client is None:
            print("There is no client with this id! ")
        else:
            return del_client

    def find_cl_srv(self, client_id):
        '''
        Function that fins a client by a given id, using the find function
        from the repository
        :return:
        '''
        find_cl = self.__rep.find_client(client_id)
        if find_cl is None:
            print("There is no client with this id!")
        else:
            return find_cl