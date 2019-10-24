import random
import numpy as np

from representation.chromosome import Chromosome, TERMINAL_SET, FUNC_SET


def gen_pop(pop_size, num_feat):
    pop = []
    for _ in range(pop_size):
        pop.append(Chromosome(num_feat))
    return pop


def eval_pop(pop, inputs, outputs):
    for i in range(len(pop)):
        pop[i].compute_fitness(inputs, outputs)


def selection(pop, num_sel):
    sample = random.sample(pop, num_sel)

    best = sample[0]
    for i in range(1, len(sample)):
        if pop[i].fitness < best.fitness:
            best = pop[i]
    return best


def traversal(poz, lst):
    if lst[poz] in TERMINAL_SET:
        return poz + 1
    elif lst[poz] in FUNC_SET[1]:
        return traversal(poz + 1, lst)
    else:
        new_poz = traversal(poz + 1, lst)
        return traversal(new_poz, lst)


def XO(m, f):
    child = Chromosome(m.size)
    start_m = np.random.randint(len(m.gen))
    start_f = np.random.randint(len(f.gen))
    end_m = traversal(start_m, m.gen)
    end_f = traversal(start_f, f.gen)

    child.gen = m.gen[:start_m] + f.gen[start_f: end_f] + m.gen[end_m:]
    return child


def mutate(chrom):
    poz = np.random.randint(len(chrom.gen))
    if chrom.gen[poz] in FUNC_SET[1] + FUNC_SET[2]:
        if chrom.gen[poz] in FUNC_SET[1]:
            chrom.gen[poz] = random.choice(FUNC_SET[1])
        else:
            chrom.gen[poz] = random.choice(FUNC_SET[2])
    else:
        chrom.gen[poz] = random.choice(TERMINAL_SET[:chrom.size])
    return chrom


def replace_worst(population, ind):

    worst = population[0]
    worst_ind = 0
    for i in range(1, len(population)):
        if population[i].fitness > worst.fitness:
            worst = population[i]
            worst_ind = i

    if worst.fitness > ind.fitness:
        population[worst_ind] = ind


def get_best(population):

    best = population[0]
    for i in range(1, len(population)):
        if population[i].fitness < best.fitness:
            best = population[i]

    return best
