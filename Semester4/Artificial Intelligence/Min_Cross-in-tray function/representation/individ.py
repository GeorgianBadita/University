from representation.genotype import Genotype
from utils.utils import random_num, calculate_exp
import random


class Individ:

    def __init__(self, gen):
        self.gen = gen
        self.fitness = None

    def calc_fitness(self):

        return calculate_exp(self.gen.x, self.gen.y)

    def mutate(self, probability):

        if random_num() < probability:
            random_sign = random_num()
            if random_sign < 0.5:
                if self.gen.x + probability/100 <= 10:
                    self.gen.x += probability/100
            else:
                self.gen.x -= probability/100

        if random_num() < probability:
            random_sign = random_num()
            if random_sign < 0.5:
                if self.gen.y + probability/100 <= 10:
                    self.gen.y += probability/100
            else:
                self.gen.y -= probability/100

    def crossover(self, mother, father, probability):

        if random_num() < probability:
            x_ = mother.gen.x
            y_ = father.gen.y
        else:
            x_ = father.gen.x
            y_ = mother.gen.y

        return Individ(Genotype(x_, y_))


def generate_random_ind():
    x = random_num()*random.randint(-10, 10)
    y = random_num()*random.randint(-10, 10)

    return Individ(Genotype(x, y))
