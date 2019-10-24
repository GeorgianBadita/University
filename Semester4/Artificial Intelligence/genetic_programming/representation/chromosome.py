import random
import warnings
import numpy as np

warnings.filterwarnings("error")

MAX_NUM_PARAMS = 30
FUNC_SET = [[], ['sin', 'cos', 'tg', 'ln', 'arcsin', 'arccos', 'tanh', 'arctg', 'e', 'abs'], ['+', '-', '*', '^', '/']]
TERMINAL_SET = [str(i) for i in range(MAX_NUM_PARAMS)]
D_MAX = 4


class Chromosome:

    def __init__(self, size=0):
        self.gen = []
        self.fitness = None
        self.size = size
        if size != 0:
            self.__grow()

    def __full(self, curr_level=0):
        if curr_level == D_MAX:
            self.gen.append(random.choice(TERMINAL_SET[:self.size]))
        else:   
            val = random.choice(FUNC_SET[2] + FUNC_SET[1])
            if val in FUNC_SET[2]:
                self.gen.append(random.choice(FUNC_SET[2]))
                self.__full(curr_level + 1)
                self.__full(curr_level + 1)
            else:
                self.gen.append(random.choice(FUNC_SET[2]))
                self.__full(curr_level + 1)

    def __grow(self, curr_level=0):
        if curr_level == D_MAX:
            self.gen.append(random.choice(TERMINAL_SET[:self.size]))
        else:
            if random.random() > 0.3:
                val = random.choice(FUNC_SET[2] + FUNC_SET[1])
                if val in FUNC_SET[2]:
                    self.gen.append(val)
                    self.__grow(curr_level + 1)
                    self.__grow(curr_level + 1)
                else:
                    self.gen.append(val)
                    self.__grow(curr_level + 1)
            else:
                val = random.choice(TERMINAL_SET[:self.size])
                self.gen.append(val)

    def evaluate(self, input, poz=0):
        if self.gen[poz] in TERMINAL_SET:
            return input[int(self.gen[poz])], poz
        elif self.gen[poz] in FUNC_SET[2]:
            poz_op = poz
            left, poz = self.evaluate(input, poz + 1)
            right, poz = self.evaluate(input, poz + 1)
            if self.gen[poz_op] == '+':
                return left + right, poz
            elif self.gen[poz_op] == '-':
                return left - right, poz
            elif self.gen[poz_op] == '*':
                return left * right, poz
            elif self.gen[poz_op] == '^':
                return left ** right, poz
            elif self.gen[poz_op] == '/':
                return left / right, poz
        else:
            poz_op = poz
            (left, poz) = self.evaluate(input, poz + 1)
            if self.gen[poz_op] == 'sin':
                return np.sin(left), poz
            elif self.gen[poz_op] == 'cos':
                return np.cos(left), poz
            elif self.gen[poz_op] == 'ln':
                return np.log(left), poz
            elif self.gen[poz_op] == 'tg':
                return np.tan(left), poz
            elif self.gen[poz_op] == 'arcsin':
                return np.arcsin(left), poz
            elif self.gen[poz_op] == 'arccos':
                return np.arccos(left), poz
            elif self.gen[poz_op] == 'tanh':
                return np.tanh(left), poz
            elif self.gen[poz_op] == 'arctg':
                return np.arctan(left), poz
            elif self.gen[poz_op] == 'e':
                return np.exp(left), poz
            elif self.gen[poz_op] == 'abs':
                return np.abs(left), poz

    def compute_fitness(self, inputs, outoputs):

        sum_ = 0
        for i in range(len(inputs)):
            try:
                sum_ += (self.evaluate(inputs[i])[0] - outoputs[i][0]) ** 2
            except RuntimeWarning:
                self.gen = []
                self.__grow()
                self.compute_fitness(inputs, outoputs)
            except ZeroDivisionError:
                self.gen = []
                self.__grow()
                self.compute_fitness(inputs, outoputs)
            except OverflowError:
                self.gen = []
                self.__grow()
                self.compute_fitness(inputs, outoputs)
            except TypeError:
                self.gen = []
                self.__grow()
                self.compute_fitness(inputs, outoputs)

        inputs = inputs + inputs
        self.fitness = sum_ / len(inputs)
        return self.fitness
