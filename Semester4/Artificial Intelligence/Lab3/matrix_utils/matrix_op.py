def get_transpose(matrix):
    """
    Function to calculate the transpose of a matrix
    :param matrix: matrix to transpose
    :return: transposed matrix
    """

    transposed = []
    for col in range(len(matrix[0])):
        trans_row = []
        for row in range(len(matrix)):
            trans_row.append(matrix[row][col])
        transposed.append(trans_row)
    return transposed


def get_matrix_minor(matrix, i, j):
    """
    Get the minor of the given matrix without ith line and jth column
    :param matrix: matrix
    :param i: row
    :param j: column
    :return: minor of the matrix at i,j
    """
    return [row[:j] + row[j + 1:] for row in (matrix[:i] + matrix[i + 1:])]


def get_determinant(matrix):
    """
    Function to calculate the determinant of a matrix
    :param matrix: matrix to calculate its determinant
    :return: a real number representing the determinant
    """
    if len(matrix) == 2:
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0]

    determinant = 0
    for c in range(len(matrix)):
        determinant += ((-1) ** c) * matrix[0][c] * get_determinant(get_matrix_minor(matrix, 0, c))
    return determinant


def get_inverse(matrix):
    """
    Function to get matrix inverse
    :param matrix: matrix
    :return: inverse of the given matrix
    """
    # a b => transpose #a c => A* = a -b
    # c d              #b d        -c  d

    determinant = get_determinant(matrix)
    if determinant == 0:
        return None
    if len(matrix) == 2:
        return [matrix[1][1] / determinant, -matrix[0][1] / determinant,
                -matrix[1][0] / determinant, matrix[0][0] / determinant]

    adj_matrix = [[0] * len(matrix) for i in range(len(matrix))]
    transpose = get_transpose(matrix)
    for i in range(len(transpose)):
        for j in range(len(transpose[0])):
            adj_matrix[i][j] = ((-1) ** (i + j)) * get_determinant(get_matrix_minor(transpose, i, j))
            adj_matrix[i][j] /= determinant
    return adj_matrix


def matrix_mul(X, Y):
    """
    :param X:
    :param Y:
    :return:
    """
    return [[sum(a * b for a, b in zip(X_row, Y_col)) for Y_col in zip(*Y)] for X_row in X]


'''
def matrix_mul(matrix1, matrix2):
    """
    Function to calculate product of two matrices
    :param matrix1: first matrix
    :param matrix2: second matrix
    :return: product of matrices
    """
    rez_mat = []
    for i in range(len(matrix1)):
        lst = []
        for j in range(len(matrix2[0])):
            elem = 0
            for k in range(len(matrix2)):
                elem += matrix1[i][k] * matrix2[k][j]
            lst.append(elem)
        rez_mat.append(lst)

    return rez_mat
'''


def matrix_square_diff(matrix1, matrix2):
    """
    Function to calculate the squared difference between two matrices
    :param matrix1: first matrix
    :param matrix2: second matrix
    :return: matrix
    """

    if len(matrix2) != len(matrix1):
        return None
    if len(matrix1[0]) != len(matrix2[0]):
        return None

    rez = []
    for i in range(len(matrix1)):
        rez_line = []
        for j in range(len(matrix1[0])):
            rez_line.append((matrix1[i][j] - matrix2[i][j]) ** 2)
        rez.append(rez_line)
    return rez


def matrix_mean(matrix):
    """
    Function to calculate the matrix_mean in respect with matrix number of lines
    :param matrix: matrix
    :return: rea number
    """
    if len(matrix) == 0:
        return None

    sum_elem = sum(map(sum, matrix))
    return sum_elem / len(matrix)

