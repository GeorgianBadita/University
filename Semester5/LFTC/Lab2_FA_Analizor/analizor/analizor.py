import re

from analizor.analizor_exceptions import NotFoundException, LiteralTooLongException
from analizor.analizor_utils import is_prefix
from analizor.hashtable import Hashtable


class Analizor:

    def __init__(self, predef_table, input_file, ct_fa, id_fa):
        self.__predef_table = predef_table
        self.__input_file = input_file
        self.__fip = []
        self.__id_table = Hashtable()
        self.__ct_table = Hashtable()
        self.__ct_fa = ct_fa
        self.__id_fa = id_fa

    def __process_line(self, line, line_cnt):
        """
        Function to process line
        :param line: - line to be processed
        :param line_cnt: line number
        :return: None
        """
        line = line.replace(" ", "")
        line = line.replace("\n", "")
        curr_resolved = 0
        while curr_resolved < len(line):
            curr_line = line[curr_resolved:]
            best_len = 0
            best_match = ""
            atom_type = -1  # 0 for predef atom, 1 for ct, 2 for id
            for key in self.__predef_table:
                if key in curr_line and is_prefix(key, curr_line):
                    if len(key) > best_len:
                        best_len = len(key)
                        best_match = key
                        atom_type = 0

            if atom_type == 0:
                self.__fip.append([self.__predef_table[best_match], None])
                curr_resolved += best_len
                continue

            best_ct = self.__ct_fa.longest_prefix_accepted(curr_line)
            best_id = self.__id_fa.longest_prefix_accepted(curr_line)
            if len(best_ct) > best_len:
                best_len = len(best_ct)
                best_match = best_ct
                atom_type = 1

            if len(best_id) > best_len:
                best_len = len(best_id)
                best_match = best_id
                atom_type = 2

            if atom_type == 1:
                self.__ct_table.set(sum(map(ord, best_match)), best_match)
                self.__fip.append([self.__predef_table['CONST'], sum(map(ord, best_match))])
            elif atom_type == 2:
                self.__id_table.set(sum(map(ord, best_match)), best_match)
                self.__fip.append([self.__predef_table['ID'], sum(map(ord, best_match))])

            if best_match == "":
                raise NotFoundException("Atom is not a valid id or const on line " + str(line_cnt))
            curr_resolved += best_len

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
                self.__process_line(line, line_cnt)
                line = f.readline()
                """
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
                            raise LiteralTooLongException("Literal length is longer than 250 on line " + str(line_cnt))
                line = f.readline()
                """

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
