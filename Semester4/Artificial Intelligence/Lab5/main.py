from network.activations import linear_activation, linear_prime, sigmoid, sigmoid_prime
from data_utils.print_data import print_result
from network.network import Network
from data_utils.read_data import get_features_from_file, get_data_generic

"""""""""""""PARAMS"""""""""""""""""""
# train_data,_ = get_data_generic("files/train_file.txt")
train_data, first_layer = get_features_from_file("files/CTG.xls")
LAYERS = [first_layer, 100, 50, 25, 3]
L_RATE = 0.000001
EPOCHS = 3000
BATCH_SIZE = 50
EPOCH_FEEDBACK = 40
ACTIVATION = sigmoid
ACTIVATION_PRIME = sigmoid_prime

"""""""""""""PARAMS"""""""""""""""""""


# train_data = get_features_from_teacher("files/weight_height.txt")
# test_data = get_features_from_teacher("files/weight_height.txt")


# results = [net.feedforward(x) for x in x_train]

# results = np.asarray(results).T[0][0]

# print(results)
# plt.scatter(x_train, results, c='red')
# plt.show()


def solve(train, test):
    net = Network(LAYERS, ACTIVATION, ACTIVATION_PRIME)

    net.gradient_descent(train, EPOCHS, BATCH_SIZE, L_RATE, EPOCH_FEEDBACK, test)

    print("FINAL COST: {0}".format(net.evaluate(test)))

    print_result("files/result.txt", str(net.evaluate(test)))


solve(train_data, train_data)
