import matplotlib.pyplot as plt
import numpy as np

from gradient_descent.gradient_descent import normalize


def plot_cost(costs, size):
    """

    :param costs:
    :return:
    """
    plt.title('Cost function', size=30)
    plt.xlabel('Iterations', size=20)
    plt.ylabel('Cost', size=40)
    plt.plot(costs[:size])
    plt.show()


def get_gd_statistics(coeff, test_features, test_res):
    """

    :param coeff:
    :param test_features:
    :param test_res:
    :return:
    """
    test_features = np.asarray(test_features)
    # test_features = normalize(test_features.T).T
    test_res = np.asarray(test_res).T[0]
    return ((np.dot(test_features, coeff) - test_res)**2).mean()
