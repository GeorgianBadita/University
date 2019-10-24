import numpy as np
import random


class Network(object):

    def __init__(self, sizes, activation, prime_activation):
        self.num_layers = len(sizes)  # number of layers
        self.sizes = sizes  # list containing the number of neurons on each layer
        self.biases = self.__init_biases(sizes)  # biases initialization
        self.weights = self.__init_weights(sizes)  # weight initialization

        self.activation = activation  # activation function
        self.prime_activation = prime_activation  # activation derivative

    def __init_biases(self, sizes):
        """
        Initializes biases with normal distribution
        :param sizes: num of neurons in each layer
        :return:
        """
        return [np.random.randn(y, 1) for y in sizes[1:]]

    def __init_weights(self, sizes):
        return [np.random.randn(y, x)
                for x, y in zip(sizes[:-1], sizes[1:])]

    def feedforward(self, a):
        """
        Feedfoward through network to find the predicted value
        :param a: activations on the input layer
        :return: activations of the output layer
        """
        for b, w in zip(self.biases, self.weights):
            a = self.activation(np.dot(w, a) + b)
        return a

    def gradient_descent(self, training_data, epochs, mini_batch_size, eta, epoch_feedback,
                         test_data=None):
        """
        Gradient descent step
        """
        if test_data: n_test = len(test_data)
        n = len(training_data)
        for j in range(epochs):
            random.shuffle(training_data)
            mini_batches = [
                training_data[k:k + mini_batch_size]
                for k in range(0, n, mini_batch_size)]
            for mini_batch in mini_batches:
                self.update_mini_batch(mini_batch, eta)
            if test_data and j % epoch_feedback == 0:
                print(
                    "Epoch {0}: {1} / {2}".format(
                        j, self.evaluate(test_data), n_test))

    def update_mini_batch(self, mini_batch, eta):
        """
        Update mini_batch using back propagation
        :param mini_batch: mini_batch
        :param eta: learning rate
        :return: None
        """
        gradient_b = [np.zeros(b.shape) for b in self.biases]
        gradient_w = [np.zeros(w.shape) for w in self.weights]
        for x, y in mini_batch:
            delta_gradient_b, delta_gradient_w = self.back_propagation(x, y)
            gradient_b = [nb + dnb for nb, dnb in zip(gradient_b, delta_gradient_b)]
            gradient_w = [nw + dnw for nw, dnw in zip(gradient_w, delta_gradient_w)]
        self.weights = [w - (eta / len(mini_batch)) * nw
                        for w, nw in zip(self.weights, gradient_w)]
        self.biases = [b - (eta / len(mini_batch)) * nb
                       for b, nb in zip(self.biases, gradient_b)]

    def back_propagation(self, x, y):
        """
        Back propagation step
        :param x: features
        :param y: real value
        :return: gradient values for biases and weights through the network
        """
        gradient_b = [np.zeros(b.shape) for b in self.biases]
        gradient_w = [np.zeros(w.shape) for w in self.weights]

        activation = x
        activations = [x]  # activations, layer by layer
        zs = []  # z vectors, layer by layer
        for b, w in zip(self.biases, self.weights):
            z = np.dot(w, activation) + b
            zs.append(z)
            activation = self.activation(z)
            activations.append(activation)

        delta = self.cost_derivative(activations[-1], y) * self.prime_activation(zs[-1])
        gradient_b[-1] = delta
        gradient_w[-1] = np.dot(delta, activations[-2].transpose())

        for l in range(2, self.num_layers):
            z = zs[-l]
            sp = self.prime_activation(z)
            delta = np.dot(self.weights[-l + 1].transpose(), delta) * sp
            gradient_b[-l] = delta
            gradient_w[-l] = np.dot(delta, activations[-l - 1].transpose())
        return gradient_b, gradient_w

    def evaluate(self, test_data):

        test_results = [(np.argmax(self.feedforward(x)), np.argmax(y))
                        for (x, y) in test_data]
        return sum(int(x == y) for (x, y) in test_results)

    def cost_derivative(self, output_activations, y):
        """
        The cost derivative
        :param output_activations: output activations
        :param y: real value
        :return: difference between predicted and actual output
        """
        return output_activations - y
