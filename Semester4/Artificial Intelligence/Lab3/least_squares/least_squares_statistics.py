from matrix_utils.matrix_op import matrix_mean, matrix_square_diff, matrix_mul


def get_statistics(coefficients, test_set, test_res):
    """
    Function to get statistics
    :param coefficients: coefficients of the linear function
    :param test_set: test_features
    :param test_res: test_results
    :return: statistics about predictions
    """
    return matrix_mean(matrix_square_diff(matrix_mul(test_set, coefficients), test_res))

    '''
    squared = 0
    for test in range(len(test_set)):
        calculated_res = 0
        for i in range(len(coefficients)):
            calculated_res += coefficients[i][0]*test_set[test][i]
        squared += (calculated_res - test_res[test][0])**2
        print("Expected: " + str(test_res[test][0]) + " Predicted: " + str(calculated_res))

    return squared/len(test_set)
    '''