"""
    @author: Badita Marin-Georgian
    @email:  geo.badita@gmail.com
    @date:   12/10/2017 21:00
"""
from domain.entities import Client
from repository.car_repository import RepositoryException

class ClientFileRepository:
    '''
    Class for Client File Repository
    '''

    def __init__(self, path):
        '''
        Initialise the repository
        :param path: -string, the name of the file
        '''
        self.__path = path

    def __load_from_file(self):
        '''
        Function that opens a file and loads the clients from it
        :return: None if the file doesn't exists, the objects otherwise
        '''

        try:
            f = open(self.__path, "r")
        except IOError:
            #file doesn't exists
            return

        clients = []
        line = f.readline().strip()

        while line != "":
            params = line.split(",")
            cl = Client(int(params[0]), params[1], params[2])
            clients.append(cl)
            line = f.readline().strip()
        f.close()
        return clients

    def __store_to_file(self, allC):
        '''
        Function that stores to file, all Clients objects from Allc
        :param allC:
        :return:
        '''
        with open(self.__path, "w") as f:
            for client in allC:
                to_write = str(client.get_cl_id()) + "," + client.get_cl_name() + "," + client.get_cl_address()
                to_write += "\n"
                f.write(to_write)


    def store_client(self, client):
        '''
        Class to store the client into the list
        Raises RepositoryException if the client already in list
        :post - Client added to the repository
        :param client:
        :return:
        '''
        client_id = client.get_cl_id()
        allC = self.__load_from_file()
        if self.find_client(client_id) is not None:
            raise RepositoryException("Duplicated id!")
        else:
            allC.append(client)
            self.__store_to_file(allC)

    def get_all_clients(self):
        '''
        Function that gets all clients as a list
        :return:
        '''
        return self.__load_from_file()

    def remove_all(self):
        '''
        Function that removs all clients
        :return:
        '''
        self.__store_to_file([])

    def find_client(self, client_id):
        '''
        Function that finds a client by id
        :return: returns the client if it's in list, None otherwise
        '''
        client_list = self.__load_from_file()
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
        allC = self.__load_from_file()
        pos = -1
        for cl in allC:
            if cl.get_cl_id() == client_id:
                pos = i
        if pos == -1:
            return None
        to_ret = allC[pos]
        del allC[pos]
        self.__store_to_file()
        return to_ret