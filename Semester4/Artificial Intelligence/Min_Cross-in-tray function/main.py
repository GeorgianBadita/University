from algorithm.algorithm import Algorithm
from representation.individ import generate_random_ind
from representation.population import Population


def init_pop(pop_size):
    pop_lst = []
    for i in range(pop_size):
        pop_lst.append(generate_random_ind())

    return pop_lst


POP_SIZE = 150
NUM_ITER = 150000
CROSS_PROB = 0.5
MUT_PROB = 0.1
NUM_SELECTED = 20

pop = init_pop(POP_SIZE)

population = Population(POP_SIZE, pop)
alg = Algorithm(population)

best = alg.run(NUM_ITER, NUM_SELECTED, CROSS_PROB, MUT_PROB)

print("x: " + str(best.gen.x))
print("y: " + str(best.gen.y))
print("val: " + str(best.fitness))



