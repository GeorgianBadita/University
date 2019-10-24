from AtomNotFoundException import NotFoundException
from hashtable import Hashtable
import re
import numpy as np


class Analizor:

    def __init__(self, predef_table, input_file):
        self.__predef_table = predef_table
        self.__input_file = input_file
        self.__fip = []
        self.__id_table = Hashtable()
        self.__ct_table = Hashtable()

    def parse_program(self):
        """
        Function to parse the program
        Reads every line from the input program and parse it
        :return: None
        """
        with open(self.__input_file) as f:
            line = f.readline()
            line_cnt = 0
            while line:
                line_cnt += 1
                line = line.strip()
                elems = line.split(" ")
                for elem in elems:
                    if len(elem) > 0 and elem != "\n":
                        if elem in self.__predef_table:
                            self.__fip.append([self.__predef_table[elem], None])
                        else:
                            is_id_or_ct = self.__check_id_const(elem)
                            if not is_id_or_ct:
                                raise NotFoundException("Atom is not a valid id or const on line " + str(line_cnt))
                    else:
                        if len(elem) > 250:
                            raise NotFoundException("Literal length is longer than 250 on line " + str(line_cnt))
                line = f.readline()

    def __check_id_const(self, elem):
        """
        Check if the given element is id or constant
        :param elem: element to be checked
        :return:
        """
        patt_id = self.__check_if_id(elem)  # if it's id
        if patt_id is True:
            self.__id_table.set(sum(map(ord, elem)), elem)
            self.__fip.append([self.__predef_table['ID'], sum(map(ord, elem))])  # put the id into the id table
            return True
        patt_const = self.__check_if_const(elem)  # if it's constant
        if patt_const is True:
            self.__ct_table.set(sum(map(ord, elem)), elem)
            self.__fip.append([self.__predef_table['CONST'], sum(map(ord, elem))])  # put the constant in the constant table
            return True
        return False

    def __check_if_id(self, elem):
        pattern = re.compile('^[a-zA-Z]([a-zA-Z0-9])*$')  # regex for id
        return pattern.match(elem) is not None

    def __check_if_const(self, elem):
        if len(elem) == 1 and elem[0] == "0":  # check for 0
            return True
        pattern_int = re.compile('^[1-9]([0-9])*$')  # regex for int
        pattern_float = re.compile('^[0-9]([0-9])*.[0-9]([0-9])*$')  # regex for float
        if pattern_int.match(elem) is not None:
            return True
        if pattern_float.match(elem):
            return True
        return False

    """
    Getters
    """
    def get_predef_table(self):
        return self.__predef_table

    def get_id_table(self):
        return self.__id_table

    def get_ct_table(self):
        return self.__ct_table

    def get_fip(self):
        return self.__fip
