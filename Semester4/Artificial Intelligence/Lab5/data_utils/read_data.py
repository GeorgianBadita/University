import pandas as pd
import numpy as np

import xlrd
from sklearn.preprocessing import normalize


def normalize_data(X):
    trans = X.T
    for i in range(len(trans)):
        trans[i] = normalize(trans[i].reshape(1, -1), norm="l2")

    return trans.T


def get_features_from_file(in_file):
    """
    Function to retrieve data from file
    :param in_file: input file
    :return: a matrix of features
    """
    df = pd.read_excel(in_file, sheet_name="Raw Data")
    LB = np.asarray(df['LB'])
    AC = np.asarray(df['AC'])
    FM = np.asarray(df['FM'])
    UC = np.asarray(df['UC'])
    DL = np.asarray(df['DL'])
    DS = np.asarray(df['DS'])
    DP = np.asarray(df['DP'])
    ASTV = np.asarray(df['ASTV'])
    MSTV = np.asarray(df['MSTV'])
    ALTV = np.asarray(df['LB'])
    MLTV = np.asarray(df['MLTV'])
    Width = np.asarray(df['Width'])
    Min = np.asarray(df['Min'])
    Max = np.asarray(df['Max'])
    Nmax = np.asarray(df['Nmax'])
    Nzeros = np.asarray(df['Nzeros'])
    Mode = np.asarray(df['Mode'])
    Mean = np.asarray(df['Mean'])
    Median = np.asarray(df['Median'])
    Variance = np.asarray(df['Variance'])
    Tendency = np.asarray(df['Tendency'])
    matrix = [
        [LB[i], AC[i], FM[i], UC[i], DL[i], DS[i], DP[i], ASTV[i], MSTV[i], ALTV[i], MLTV[i], Width[i], Min[i],
         Max[i], Nmax[i]
            , Nzeros[i], Mode[i], Mean[i], Median[i], Variance[i], Tendency[i]] for i in range(1, len(LB) - 3)]
    #matrix = normalize_data(np.array(matrix))
    train_in = [np.reshape(x, (len(matrix[0]), 1)) for x in matrix]
    train_out = [vectorized_result(x - 1) for x in get_result_matrix(in_file)]
    rez = list(zip(train_in, train_out))
    return rez, len(matrix[0])


def vectorized_result(j):
    """Return a 3-dimensional unit vector with a 1.0 in the jth
    position and zeroes elsewhere.  This is used to convert a digit
    (0...2) into a corresponding desired output from the neural
    network."""
    e = np.zeros((3, 1))
    e[int(j)] = 1.0
    return e


def get_result_matrix(in_file):
    """
    Function to retrieve the results from the file
    :param in_file: in file
    :return: a matrix (1, n)
    """
    df = pd.read_excel(in_file, sheet_name="Raw Data")
    NSP = np.asarray(df['NSP'])
    result = np.asarray([NSP[i] for i in range(1, len(NSP) - 3)])

    return result


def get_training_data(data):
    """

    :param data:
    :return:
    """
    num = len(data) * 0.8

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


"================================================="


def get_features_from_teacher(in_file):
    """
    Function to get features from teacher file
    :param in_file: in_file
    :return:
    """

    with open(in_file, "r") as f:

        n_features = int(f.readline().strip())
        num_rows = int(f.readline().strip())
        matrix = []
        for i in range(num_rows):
            line = f.readline().split(",")
            matrix_row = []

            for row in line:
                matrix_row.append(float(row))

            matrix.append(matrix_row)

        train_in = [np.reshape(x[0], (1, 1)) for x in matrix]
        train_out = [np.reshape(x[1], (1, 1)) for x in matrix]
        return [(x, y) for x, y in zip(train_in, train_out)]


def getData(fileName):
    file = open(fileName, "r")

    n_features = int(file.readline().strip())
    num_rows = int(file.readline().strip())

    line = file.readline()
    X = []
    Y = []

    while line:
        parts = line.split(",")
        parts = [float(part) for part in parts[2:]]
        X.append(parts[2:-1])
        Y.append(parts[-1])

        line = file.readline()

    file.close()

    train_in = [np.reshape(x, (n_features, 1)) for x in X]
    train_out = [np.reshape(x, (1, 1)) for x in Y]

    # train_in = [normalize_data(np.reshape(x, (n_features, 1))) for x in X]
    # train_out = [normalize_data(np.reshape(x, (1, 1))) for x in Y]
    return [(x, y) for x, y in zip(train_in, train_out)]


def get_data_generic(fileName):
    file = open(fileName, "r")

    n_features = int(file.readline().strip())
    num_rows = int(file.readline().strip())

    line = file.readline()
    X = []
    Y = []

    while line:
        parts = line.split(",")
        parts = [float(part) for part in parts[:]]
        X.append(parts[:-1])
        Y.append(parts[-1])

        line = file.readline()

    file.close()

    train_in = [np.reshape(x, (n_features - 1, 1)) for x in X]
    train_out = [np.reshape(x, (1, 1)) for x in Y]
    return [(x, y) for x, y in zip(train_in, train_out)], n_features - 1


def get_result_matrix_from_teacher(in_file):
    """
     In file
     :param in_file:
     :return:
    """

    with open(in_file, "r") as f:
        n_features = int(f.readline().strip())
        num_rows = int(f.readline().strip())
        matrix = []
        for i in range(num_rows):
            line = f.readline().split(",")
            matrix.append(float(line[len(line) - 1]))

        return np.asarray(matrix)


def write_to_file(file, content):
    """

    :param content:
    :param file:
    :return:
    """
    fd = open(file, "w")
    fd.write(content + "\n")
    fd.close()


def get_data(fileName):
    file = open(fileName, "r")
    X = []
    Y = []

    file.readline()  # eliminate column name
    line = file.readline()

    while line:
        data = line.split("\n")[0].split(",")
        if data[0] == '"Male"':
            data[0] = 1
        else:
            data[0] = 0

        for i in range(1, len(data)):
            data[i] = float(data[i])

        X.append([1] + data[1:])
        Y.append(data[0])

        line = file.readline()

    file.close()
    return np.asarray(X), np.asarray(Y)
