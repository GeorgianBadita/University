"""
    @author: Badita Marin-Georgian
    @email:  geo.badita@gmail.com
    @date:   12/11/2017 19:52
"""
from Domain.medicine import Medicine


class MedicineRepository:
    '''
    Class for the Medicine repository
    '''

    def __init__(self, file_name):
        '''
        Initialising the repository
        :param file_name: -the name of the file
        '''
        self.__file_name = file_name

    def load_from_file(self):
        '''
        Function which will load all Medicine from the file
        :return: list of medicine, None if te file couldn't be read
        '''
        try:
            f = open(self.__file_name, "r")
        except IOError:
            #couldn't read the file
            return

        medicines = []
        line = f.readline().strip()
        while line != "":
            params = line.split(",")
            medicine = Medicine(params[0], float(params[1]))
            medicines.append(medicine)
            line = f.readline().strip()
        f.close()
        return medicines

    def store_to_file(self, med_list):
        '''
        Function that stores to file a list of medicines
        :param med_list:
        :return:
        '''
        with open(self.__file_name, "w") as f:
            for med in med_list:
                to_write = med.get_name() + ","+ str(med.get_price())
                to_write += "\n"
                f.write(to_write)

    def get_all(self):
        '''
        Function that gets all medicines as a lsit
        :return: The list of medicines stored in the fle
        '''
        return self.load_from_file()

    def find_by_name(self, med_name):
        '''
        Function that finds all medicines by name
        :return: the found medicine if it exists, None otherwise
        '''
        med_list =[]
        all_med = self.load_from_file()
        for med in all_med:
            if med_name in med.get_name():
                med_list.append(med)
        if len(med_list) > 0:
            return med_list
        return None
