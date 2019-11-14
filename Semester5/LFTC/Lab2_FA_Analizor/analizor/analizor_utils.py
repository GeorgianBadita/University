import json


def parse_table_from_file(in_file):
    """
    Function to parse the predefined table from file
    :param in_file: file where the predefined table is stored
    :return: a map containing (key, value) pairs with key = atom, value = atom's code
    """
    with open(in_file, 'r') as f:
        predef_table = json.load(f)
        return predef_table


def is_prefix(a, b):
    """
    Function to check if a is a prefix o b
    :param a: string
    :param b: string
    :return: True if a is prefix of b, False otherwise
    """
    if len(b) < len(a):
        return False
    for i in range(len(a)):
        if a[i] != b[i]:
            return False
    return True
