import random

import math


def readData(fileName):
    """
    :param fileName: fisier ce contine date de intrare(x=[x1...xn]) si date de iesire (y)
    :return: matrice ce contine datele de intrare si matrice ce contine datele de iesire
    """
    with open(fileName) as f:
        n = int(f.readline()) - 1
        N = int(f.readline())
        y = []
        x_matrix = []
        for line in f:
            x = []
            if len(line.strip()) == 0:
                return
            for num in line.split(","):
                x.append(float(num))
            y.append(x[-1])
            del x[-1]
            x_matrix.append(x)
        return x_matrix, y


def normalizeDataIn(input):
    """
    :param input: matrice ce contine datele de intrare
    :return: datele de intrare normalizate
    """
    list_means = []
    noAttributes = len(input[0])
    n = len(input)
    for i in range(noAttributes):
        input_sum = 0
        for el in input:
            input_sum = input_sum + el[i]
        list_means.append(input_sum / n)
    list_deviation = []
    for i in range(noAttributes):
        input_sum = 0
        for el in input:
            input_sum = input_sum + (el[i] - list_means[i]) ** 2
        list_deviation.append(math.sqrt(input_sum / (n - 1)))
    normalized_dataIn = []
    for i in range(n):
        li = []
        for j in range(len(input[i])):
            li.append((input[i][j] - list_means[j]) / list_deviation[j])
        normalized_dataIn.append(li)
    return [normalized_dataIn, list_means, list_deviation]


def normalize_oneData(data, list_means, list_deviation):
    """
    :param data: matrice ce contine datele de test
    :return: datele de test normalizate
    """
    for i in range(len(data)):
        for j in range(len(data[i])):
            data[i][j] = (data[i][j] - list_means[j]) / list_deviation[j]
    return data


def normalizeDataOut(dataOut):
    """
    :param dataOut: lista ce contine datele de iesire : y=[y1 y2 ... yn]
    :return: datele de iesire normalizate
    """
    n = len(dataOut)
    input_sum = 0
    for i in range(n):
        input_sum = input_sum + dataOut[i]
    mean = input_sum / n
    dev = 0
    for i in range(n):
        dev = dev + (dataOut[i] - mean) ** 2
    dev_rate = math.sqrt(dev / (n - 1))
    normalized_dataOut = []
    for i in range(n):
        normalized_dataOut.append((dataOut[i] - mean) / dev_rate)
    return [normalized_dataOut, mean, dev_rate]


def normalize_oneDataOut(data, mean, deviation):
    """
    :param data: lista ce contine date de iesire din fisierul de test
    :param mean: media datelor de iesire din fisierul de train
    :param deviation: deviatia datelor de iesire din fisierul de train
    :return: datele de iesire din fisierul de test normalizate
    """
    for i in range(len(data)):
        data[i] = (data[i] - mean) / deviation
    return data


class Chromosome:
    """
        clasa pentru reprezentarea unui cromozom
    """

    def __init__(self, max_depth, terminal_set, function_set):
        """
        :param max_depth: adancimea maxima a arborelui (reprezentarea unui cromozom - forma prefixata)
        :param terminal_set: multime ce contine terminalii posibili pentru nodurile arborelui
        :param function_set: multime ce contine operatiile binare posibile pentru nodurile arborelui (+, -, *)
        """
        self.representation = []
        self.fitness = 0.0
        self.max_depth = max_depth
        self.terminal_set = terminal_set
        self.function_set = function_set

    def grow(self, crtDepth):
        """
        :param crtDepth: adancimea curenta a reprezentarii cromozomului
        se construieste arborele din reprezentarea cromozomului
        """
        if crtDepth == self.max_depth:
            terminal = random.choice(self.terminal_set)
            self.representation.append(terminal)
        else:
            function = random.choice(self.function_set)
            self.representation.append(function)
            self.grow(crtDepth + 1)
            self.grow(crtDepth + 1)

    def eval(self, inExample, pos):
        """
        :param inExample: exemplu cu date de intrare
        :param pos: pozitia curenta din arbore
        :return: rezultatul obtinut in urma evaluarii expresiei din arbore
        """
        if self.representation[pos] in self.terminal_set:
            return inExample[self.representation[pos]], pos
        else:
            left, left_pos = self.eval(inExample, pos + 1)
            right, right_pos = self.eval(inExample, left_pos + 1)
            if self.representation[pos] == "+":
                return left + right, right_pos
            elif self.representation[pos] == "-":
                return left - right, right_pos
            else:
                return left * right, right_pos


class GP:
    """
        clasa pentru algoritmul genetic
    """

    def __init__(self, trainInput):
        """
        :param trainInput: datele de intrare
        se initializeaza adancimea maxima, multimea de operatii si multimea de terminali
        """
        self.MAX_DEPTH = 2
        self.FUNCTION_SET = ["+", "-", "*"]
        self.TERMINAL_SET = [i for i in range(len(trainInput[0]))]

    def init(self, popSize):
        """
        :param popSize: dimensiunea populatiei
        :return: populatia initializata
        """
        pop = []
        for i in range(popSize):
            c = Chromosome(self.MAX_DEPTH, self.TERMINAL_SET, self.FUNCTION_SET)
            c.grow(0)
            pop.append(c)
        return pop

    def computeFitness(self, input, chrom, output):
        """
        functie de calculare a fitness-ului
        :param input: date de intrare
        :param chrom: cromozom
        :param output: date de iesire
        :return: initializarea fitness-ului unui cromozom cu diferenta patratica a erorii
        """
        err = 0.0
        for i in range(0, len(input)):
            exCrt = input[i]
            rez = output[i]
            rezC, p = chrom.eval(exCrt, 0)
            err += (rezC - rez) ** 2
        chrom.fitness = err / len(input)

    def evalPop(self, pop, trainInput, trainOutput):
        """
        functie de evaluare a populatiei
        :param pop: populatia
        :param trainInput: datele de intrare din fisierul de antrenament
        :param trainOutput: datele de iesire pentru datele de antrenament
        se evalueaza fiecare individ al populatiei
        """
        for indiv in pop:
            self.computeFitness(trainInput, indiv, trainOutput)

    def selection(self, population):
        """
        selectie prin turnir
        :param population: populatia
        :return: un individ al populatiei (cel mai bun individ din 10% indivizi ai populatiei alesi random)
        """
        turnir_size = int(1 / 10 * len(population))
        candidates = random.sample(population, turnir_size)
        return min(candidates, key=lambda x: x.fitness)

    def traverse(self, representation, pos):
        """
        :param representation: reprezentarea unui cromozom (arbore)
        :param pos: pozitia curenta
        :return: pozitia unde se termina traversarea reprezentarii pentru o operatie
        """
        if representation[pos] in self.TERMINAL_SET:
            return pos + 1
        else:
            pos = self.traverse(representation, pos + 1)
            pos = self.traverse(representation, pos)
            return pos

    def crossover(self, M, F):
        """
        procesul de incrucisare
        :param M: cromozomul mama
        :param F: cromozomul tata
        :return: un nou cromozom obtinut din cei doi parinti
        """
        off = Chromosome(self.MAX_DEPTH, self.TERMINAL_SET, self.FUNCTION_SET)
        startM = random.randrange(len(M.representation))
        endM = self.traverse(M.representation, startM)

        startF = random.randrange(len(F.representation))
        endF = self.traverse(F.representation, startF)

        for i in range(0, startM):
            off.representation.append(M.representation[i])
        for i in range(startF, endF):
            off.representation.append(F.representation[i])
        for i in range(endM, len(M.representation)):
            off.representation.append(M.representation[i])
        return off

    def mutation(self, off):
        """
        procesul de mutatie al unui cromozom
        :param off: offspring (cromozom)
        :return: cromozomul obtinut in urma aplicarii mutatiei
        """
        pos = random.randrange(len(off.representation))
        if off.representation[pos] in self.TERMINAL_SET:
            terminal = random.choice(self.TERMINAL_SET)
            off.representation[pos] = terminal
        else:
            function = random.choice(self.FUNCTION_SET)
            off.representation[pos] = function
        return off

    def bestSolution(self, pop):
        """
        :param pop: populatia
        :return: cel mai bun individ din populatie
        """
        best = pop[0]
        for indiv in pop:
            if indiv.fitness < best.fitness:
                best = indiv
        return best

    def EA_generational(self, popSize, noGenerations, trainIn, trainOut):
        """
        algoritm genetic generational
        :param popSize: dimensiunea populatiei
        :param noGenerations: nr de generatii
        :param trainIn: datele de intrare din fisierul de antrenament
        :param trainOut: datele de iesire din fisierul de antrenament
        :return: cel mai bun individ din populatie
        """
        pop = self.init(popSize)
        self.evalPop(pop, trainIn, trainOut)
        for g in range(0, noGenerations):
            print(self.bestSolution(pop).fitness)
            for k in range(0, popSize):
                M = self.selection(pop)
                F = self.selection(pop)
                off = self.crossover(M, F)
                off = self.mutation(off)
                self.computeFitness(trainIn, off, trainOut)
                crtBest = self.bestSolution(pop)
                if off.fitness < crtBest.fitness:
                    crtBest = off
        sol = self.bestSolution(pop)
        return sol


def runEA(trainFile, testFile, popSize, noGen):
    """
    wrapper pentru EA
    :param trainFile: fisier ce contine datele de antrenament
    :param testFile: fisier ce contine datele de test
    :param popSize: dimensiunea populatiei
    :param noGen: nr de generatii
    :return: performanta algoritmului (eroarea medie patratica)
    """
    inputTrain, outputTrain = readData(trainFile)
    inputTest, outputTest = readData(testFile)
    inputTrain, means, deviations = normalizeDataIn(inputTrain)
    inputTest = normalize_oneData(inputTest, means, deviations)
    outputTrain, means_test, deviations_test = normalizeDataOut(outputTrain)
    outputTest = normalize_oneDataOut(outputTest, means_test, deviations_test)

    gp = GP(trainFile)
    learnt_model = gp.EA_generational(popSize, noGen, inputTrain, outputTrain)
    gp.computeFitness(inputTest, learnt_model, outputTest)
    return learnt_model.fitness / len(inputTest)


runEA("files/train_file.txt", "files/test_file.txt", 1000, 1000)
