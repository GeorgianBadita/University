import numpy as np


def normalize(x):
    """
    function that normalizes each row of the matrix x to have unit length.

    Args:
     ``x``: A numpy matrix of shape (n, m)

    Returns:
     ``x``: The normalized (by row) numpy matrix.
    """
    return x/np.linalg.norm(x, ord=2, axis=1, keepdims=True)


def solve_gradient_descent(feat, res, learning_rate, epsilon, epochs):
    """
    Function to solve the concrete problem using gradient descent
    :param feat: features matrix
    :param res: result matrix
    :param learning_rate: learning rate
    :param epsilon:
    :param epochs: number of epochs
    :return:
    """

    features = np.asarray(feat)
    result = np.asarray(res[:]).T[0]
    n = result.size
    predictions = []
    costs = [1e10]
    coeffs = np.random.rand(len(features[0]))
   # features = normalize(features.T).T

    # result = normalize(result)
    it = 0

    for _ in range(epochs):
        prediction = np.dot(features, coeffs)
        predictions.append(prediction)
        error = prediction - result
        cost = 1.0 / n * np.dot(error.T, error)
        costs.append(cost)
        coeffs = coeffs - (learning_rate * (2.0 / n) * np.dot(features.T, error))

        if costs[it] - costs[it + 1] < epsilon:
            break
        it += 1

    costs.pop(0)

    return [coeffs, costs, predictions]
