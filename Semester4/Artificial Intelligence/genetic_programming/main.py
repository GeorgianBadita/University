from numpy.ma import arange
import numpy as np
from representation.chromosome import Chromosome
from representation.ga import Algorithm
from representation.ga_ops import XO
import matplotlib.pyplot as plt

from utils.read_data_utils import read_data

"""
def x_squared(x):
    return x ** 2


x_train = [x for x in arange(-10, 10, 0.1)]
y_train = [x_squared(x) for x in x_train]

c1 = Chromosome(1)
c2 = Chromosome(1)
c3 = XOR(c1, c2)

print(c1.gen)
print(c2.gen)
print(c3.gen)

inputs = [[3], [4]]
print(c1.evaluate(inputs[0]))
print(c2.evaluate(inputs[0]))
print(c3.evaluate(inputs[0]))
print(c1.compute_fitness(inputs, [[2], [4]]))
"""

"==================VARS================"
#n_ft = 1
x_train, y_train, n_ft = read_data('files/train_file.txt')
x_test, y_test, _ = read_data('files/test_file.txt')
POP_SIZE = 100
EPOCHS = 2000
NUM_FEAT = n_ft
NUM_SELECTED = POP_SIZE // 4
EPOCH_FEED = 100
"==================VARS================"

#x_train = [[x] for x in arange(-10, 10, 0.01)]
# y_train = [[x[0]**2] for x in x_train]
# y_train = [[x[0] ** 5 + x[0] ** 4] for x in x_train]
# y_train = [[3*x[0]**3 * np.sin(7*x[0]**2) + 5] for x in x_train]
# y_train = [[np.sin(x[0]) / x[0]] for x in x_train]
# y_train = [[np.exp(x[0]) + x[0]**2] for x in x_train]
# y_train = [[np.log(x[0])] for x in x_train]
#y_train = [[np.ceil(np.log(np.abs(x[0])))] for x in x_train]
#y_train = [[np.sin(x[0]) * x[0] * x[0]] for x in x_train]

#plt.scatter(x_train, y_train)

alg = Algorithm(POP_SIZE, EPOCHS, NUM_FEAT, NUM_SELECTED, x_train, y_train, EPOCH_FEED)

best = alg.solve_ga()

# y_res = [[best.evaluate(x)[0]] for x in x_test]

print(best.compute_fitness(x_test, y_test))

#plt.scatter(x_train, y_res, c='red')
#plt.show()
