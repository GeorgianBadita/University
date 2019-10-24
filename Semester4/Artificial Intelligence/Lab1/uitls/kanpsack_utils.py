from domain.item import Item
from domain.knapsack import Knapsack


def parse_data(in_file):
    """
    Function to pare data
    :param in_file: input file
    :return: a knapsack object containing the list of objects and the maximum weight
    """

    with open(in_file, "r") as f_read:  # closes file in case of error

        f_read.readline()
        w_string = f_read.readline().split(",")
        weights = []
        for weight in w_string:
            weights.append(int(weight))
        c_string = f_read.readline().split(",")
        costs = []
        for cost in c_string:
            costs.append(int(cost))

        max_w = int(f_read.readline())

        knapsack = Knapsack(max_w)
        for i in range(0, len(costs)):
            knapsack.add_item(Item(weights[i], costs[i]))

        return knapsack


def print_result(output_file, kn, res):
    """
    Function to print the result into a file
    :param output_file: output file
    :param kn: initial items
    :param res: solution
    :return: None
    """
    with open(output_file, "w") as fw:
        bits_str = ""
        for i in range(0, len(kn.get_items())):
            if i in res:
                bits_str += "1,"
            else:
                bits_str += "0,"
        bits_str = bits_str[0:len(bits_str) - 1]

        costs_str = ""
        total_cost = 0
        for i in range(0, len(kn.get_items())):
            if i in res:
                total_cost += kn.get_items()[i].get_cost()
                costs_str += str(kn.get_items()[i].get_cost()) + ","
            else:
                costs_str += "0,"
        costs_str = costs_str[0:len(costs_str) - 1]
        fw.write(str(len(res)) + "\n")
        fw.write(bits_str+"\n")
        fw.write(costs_str+"\n")
        fw.write(str(total_cost))


def convert_input(in_file, out_file):
    """
    Function to convert an input into the desired one
    :param in_file: -input file
    :param out_file: -output file
    :return: None
    """

    with open(in_file, "r") as f:
        line = f.readline().split(" ")
        num_obj = int(line[0])
        max_w = line[1]
        weights = []
        costs = []
        for i in range(num_obj):
            line = f.readline().split(" ")
            weights.append(line[0])
            line[1] = int(line[1])
            costs.append(str(line[1]))

        with open(out_file, "w") as g:
            g.write(str(num_obj) + "\n")
            for i in range(0, num_obj - 1):
                g.write(weights[i] + ",")
            g.write(weights[num_obj - 1] + "\n")
            for i in range(0, num_obj - 1):
                g.write(costs[i] + ",")
            g.write(costs[num_obj - 1] + "\n")

            g.write(max_w)
