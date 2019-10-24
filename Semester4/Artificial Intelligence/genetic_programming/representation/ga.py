from representation.ga_ops import gen_pop, eval_pop, selection, XO, mutate, replace_worst, get_best


class Algorithm:

    def __init__(self, num_pop, epochs, num_feat, num_sel, inputs, outputs, epoch_feed):
        self.pop_size = num_pop
        self.epochs = epochs
        self.num_feat = num_feat
        self.inputs = inputs
        self.outputs = outputs
        self.num_sel = num_sel
        self.epoch_feed = epoch_feed

    def solve_ga(self):
        pop = gen_pop(self.pop_size, self.num_feat)
        eval_pop(pop, self.inputs, self.outputs)
        best = get_best(pop)
        for i in range(self.epochs):
            m = selection(pop, self.num_sel)
            f = selection(pop, self.num_sel)
            child = XO(m, f)
            child_mut = mutate(child)
            child_mut.compute_fitness(self.inputs, self.outputs)
            replace_worst(pop, child_mut)
            if child_mut.fitness < best.fitness:
                 best = child_mut

            if i % self.epoch_feed == 0:
                print("Best at iter " + str(i) + ": " + str(best.gen))
                print("Best cost at iter " + str(i) + ": " + str(best.fitness))
                print("\n\n")

            if best.fitness < 2*1e-20:
                return best

        return best
