from matrix_utils.matrix_op import get_transpose, matrix_mul, get_inverse


def solve_least_squares(train_feat, res_feat):
    """
    Function to get the function coefficients
    :param res_feat: training result
    :param train_feat: training features
    :return:
    """

    training = train_feat

    result_training = res_feat

    trans = get_transpose(training)

    mat_mul_trans = matrix_mul(trans, training)

    mat_mul_trans = get_inverse(mat_mul_trans)

    second_prod = matrix_mul(mat_mul_trans, trans)

    return matrix_mul(second_prod, result_training)
