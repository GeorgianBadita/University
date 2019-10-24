from uitls.kanpsack_utils import parse_data, print_result, convert_input


def get_child(knapsack, top):
    """
    Function to get children for a given node
    :param knapsack: initial  items + knapsack max weight
    :param top: current node
    :return: a list containing all children of a node
    """
    used = [False for i in range(len(knapsack.get_items()))]
    top_sum = 0
    for i in range(0, len(top)):
        top_sum += knapsack.get_items()[top[i]].get_weight()
        used[top[i]] = True

    best_ind = -1
    best_rap = -1
    for i in range(0, len(used)):
        if used[i] is False and top_sum + knapsack.get_items()[i].get_weight() <= knapsack.get_max_weight():
            best_ind = i
            best_rap = knapsack.get_items()[i].get_cost() / knapsack.get_items()[i].get_weight()
            break

    start = best_ind
    for i in range(start, len(used)):
        if used[i] is False and top_sum + knapsack.get_items()[i].get_weight() <= knapsack.get_max_weight() and \
                knapsack.get_items()[i].get_cost() / knapsack.get_items()[i].get_weight() > best_rap:
            best_ind = i
            best_rap = knapsack.get_items()[i].get_cost() / knapsack.get_items()[i].get_weight()

    return best_ind


def knapsack_greedy(knapsack):
    """
    Function to solve the knapsack problem using bfs approach
    :param knapsack: knapsack object containing the initial list of items and the maximum weight
    :return: list of indices of the selected items
    """
    queue = []  # queue for storing tree nodes
    result = []
    res_sum = 0
    queue.append([])
    while len(queue) > 0:
        top = queue.pop(0)
        child = get_child(knapsack, top)
        if child < 0:
            continue
        queue = [top + [child]]
        res_sum = res_sum + knapsack.get_items()[child].get_cost()
        result += [child]

    return result


def main():
    """
    main function ot solve the problem
    :return: None
    """
   # convert_input("/home/geolica/Desktop/An2_sem2/AI/Lab1/input.txt", "/home/geolica/Desktop/An2_sem2/AI/Lab1/input.txt")
    file = input("Give file: ")
    kn = parse_data(file)
    res = knapsack_greedy(kn)
    print_result("/home/geolica/Desktop/An2_sem2/AI/Lab1/output.txt", kn, res)


main()
