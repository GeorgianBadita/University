import numpy as np


def linear_activation(z):
    # return z * (z > 0)
    return z


def linear_prime(z):
    return np.full_like(z, 1)
    # return 1. * (z > 0)


def leaky_relu(z):
    for elem in range(len(z)):
        if z[elem] < 0:
            z[elem] *= 0.1
    return z


def leaky_relu_prime(z):
    x = z
    for elem in range(len(x)):
        if x[elem] < 0:
            x[elem] = 0.1
        else:
            x[elem] = 1
    return x


def sigmoid(z):
    """The sigmoid function."""
    return 1.0 / (1.0 + np.exp(-z))


def sigmoid_prime(z):
    """Derivative of the sigmoid function."""
    return sigmoid(z) * (1 - sigmoid(z))
