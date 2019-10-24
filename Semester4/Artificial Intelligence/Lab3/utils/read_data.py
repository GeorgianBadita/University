import pandas as pd


def get_features_from_file(in_file):
    """
    Function to retrieve data from file
    :param in_file: input file
    :return: a matrix of features
    """
    df = pd.read_excel(in_file)

    f1 = list(df['Cement (component 1)(kg in a m^3 mixture)'][:])
    f2 = list(df['Blast Furnace Slag (component 2)(kg in a m^3 mixture)'][:])
    f3 = list(df['Fly Ash (component 3)(kg in a m^3 mixture)'][:])
    f4 = list(df['Water  (component 4)(kg in a m^3 mixture)'][:])
    f5 = list(df['Superplasticizer (component 5)(kg in a m^3 mixture)'][:])
    f6 = list(df['Coarse Aggregate  (component 6)(kg in a m^3 mixture)'][:])
    f7 = list(df['Fine Aggregate (component 7)(kg in a m^3 mixture)'][:])
    f8 = list(df['Age (day)'][:])

    matrix = [[1, f1[i], f2[i], f3[i], f4[i], f5[i], f6[i], f7[i], f8[i]] for i in range(len(f1))]

    return matrix


def get_result_matrix(in_file):
    """
    Function to retrieve the results from the file
    :param in_file: in file
    :return: a matrix (1, n)
    """
    df = pd.read_excel(in_file)
    lst = list(df['Concrete compressive strength(MPa, megapascals) '][:])
    matrix = []
    for elem in lst:
        matrix.append([elem])
    return matrix


def get_training_data(data):
    """

    :param data:
    :return:
    """
    num = len(data)*0.8

    return data[:int(num)]


def get_test_data(data):
    """

    :param data:
    :return:
    """
    training = get_training_data(data)
    return data[len(training):]


def get_properties(prop_file):
    """
    Function to get the starting properties
    :param prop_file: path to file
    :return: a dictionary containing prop => value
    """
    props = {}
    with open(prop_file, "r") as f:
        num_props = int(f.readline().strip())
        for prop in range(num_props):
            line = f.readline().split(":")
            props[line[0]] = line[1]
    return props
