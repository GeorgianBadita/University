from utils.utils import replace_worst, get_best, get_best_from_pop


class Algorithm:

    def __init__(self, population):
        self.population = population

    def iteration(self, k, cross_prob, mutate_prob):
        mother = self.population.selection(k)
        father = self.population.selection(k)
        offspring = mother.crossover(mother, father, cross_prob)
        offspring.mutate(mutate_prob)
        offspring.fitness = offspring.calc_fitness()
        self.population = replace_worst(self.population, offspring)

    def run(self, iter_num, k, cross_prob, mutate_prob):
        self.population.evaluate()
        best = get_best_from_pop(self.population)
        for i in range(iter_num):
            self.iteration(k, cross_prob, mutate_prob)
            iter_best = get_best_from_pop(self.population)
            if iter_best.fitness < best.fitness:
                best = iter_best
        return best

    def statistics(self):
        #   TODO implement this
        pass


