import timeit

from uitls.kanpsack_utils import parse_data, print_result, convert_input


def get_children(knapsack, top):
    """
    Function to get children for a given node
    :param knapsack: initial  items + knapsack max weight
    :param top: current node
    :return: a list containing all children of a node
    """
    top_weight = 0
    top_cost = 0
    for i in range(0, len(top)):
        top_weight += knapsack.get_items()[top[i]].get_weight()
        top_cost += knapsack.get_items()[top[i]].get_cost()

    best_child = None
    best_child_sum = -1
    children = []
    start = 0
    if top:
        start = top[len(top) - 1] + 1

    for i in range(start, len(knapsack.get_items())):
        if top_weight + knapsack.get_items()[i].get_weight() <= knapsack.get_max_weight():
            children.append(top + [i])
            if top_cost + knapsack.get_items()[i].get_cost() > best_child_sum:
                best_child = top + [i]
                best_child_sum = top_cost + knapsack.get_items()[i].get_cost()

    return [children, best_child, best_child_sum]


def knapsack_bfs(knapsack):
    """
    Function to solve the knapsack problem using dfs approach
    :param knapsack: knapsack object containing the initial list of items and the maximum weight
    :return: list of indices of the selected items
    """
    stack = []  # stack for storing tree nodes
    result = []
    res_sum = 0
    stack.append([])
    while len(stack) > 0:
        top = stack.pop()
        children = get_children(knapsack, top)
        if not children:
            continue
        stack += children[0]
        # best = get_best(children, knapsack.get_items())

        if children[2] > res_sum:
            res_sum = children[2]
            result = children[1]

    return result


def main():
    """
    main function ot solve the problem
    :return: None
    """

    # convert_input("input.txt", "input.txt")
    start = timeit.default_timer()
    file = input("Give a file: ")
    kn = parse_data(file)
    res = knapsack_bfs(kn)
    print_result("/home/geolica/Desktop/An2_sem2/AI/Lab1/output.txt", kn, res)
    stop = timeit.default_timer()
    print("Time: ", stop - start)



main()
