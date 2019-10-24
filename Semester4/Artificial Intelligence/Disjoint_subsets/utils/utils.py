import math
import os


def random_num():
    return int.from_bytes(os.urandom(8), byteorder='big') / ((1 << 64) - 1)


def get_best(sample):
    best_fit = sample[0].fitness
    best_ind = sample[0]
    for i in range(1, len(sample)):
        if sample[i].fitness < best_fit:
            best_fit = sample[i].fitness
            best_ind = sample[i]
    return best_ind


def get_best_from_pop(population):
    best_fit = population.pop_list[0].fitness
    best_ind = population.pop_list[0]
    for i in range(1, len(population.pop_list)):
        if population.pop_list[i].fitness < best_fit:
            best_fit = population.pop_list[i].fitness
            best_ind = population.pop_list[i]
    return best_ind


def get_worst_from_pop(sample):
    worst_fit = sample.pop_list[0].fitness
    worst_ind = sample.pop_list[0]
    for i in range(1, len(sample.pop_list)):
        if sample.pop_list[i].fitness > worst_fit:
            worst_fit = sample.pop_list[i].fitness
            worst_ind = sample.pop_list[i]
    return worst_ind


def get_worst(sample):
    worst_fit = sample[0].fitness
    worst_ind = sample[0]
    for i in range(1, len(sample)):
        if sample[i].fitness > worst_fit:
            worst_fit = sample[i].fitness
            worst_ind = sample[i]
    return worst_ind


def replace_worst(population, individ):
    worst = get_worst_from_pop(population)

    if individ.fitness > worst.fitness:
        return population

    for i in range(0, len(population.pop_list)):
        if population.pop_list[i].gen.x == worst.gen.x and \
                population.pop_list[i].gen.y == worst.gen.y and \
                population.pop_list[i].fitness == worst.fitness:
            population.pop_list[i] = individ
            break
    return population




def calculate_exp(x, y):
    fract = math.sqrt(x ** 2 + y ** 2) / math.pi
    exponent = math.exp(100 - fract)
    return -0.0001 * (math.fabs(math.sin(x) * math.sin(y) * exponent) + 1) ** 0.1
