import random

from utils.utils import get_best


class Population:

    def __init__(self, num_pop, pop_list):
        self.num_pop = num_pop
        self.pop_list = pop_list

    def evaluate(self):
        for i in range(self.num_pop):
            self.pop_list[i].fitness = self.pop_list[i].calc_fitness()

    def selection(self, k):
        sample = random.sample(self.pop_list, k)
        return get_best(sample)
