import timeit
from uitls.kanpsack_utils import parse_data, print_result, convert_input


def get_children(curr_weight, top, knapsack):
    """
    Function to get children for a given node
    :param curr_weight: current weight of the top node
    :param knapsack: initial  items + knapsack max weight
    :param top: current node
    :return: a list containing all children of a node
    """

    if top == "0":
        return ["00", "01", "1"]

    if len(top) == len(knapsack.get_items()):
        return None
    children = []
    child1 = top + "1"
    child2 = top + "0"

    if knapsack.get_items()[len(child1) - 1].get_weight() + curr_weight <= knapsack.get_max_weight():
        children.append(child1)

    children.append(child2)
    return children


def convert_result(result):
    """
    Function to convert a string of bits in integer positions
    :param result: - string of bits
    :return: - array of positions
    """
    new_res = []
    for i in range(0, len(result)):
        if result[i] == '1':
            new_res.append(i)

    return new_res


def get_bin_sum(top, kn):
    """
    Function to get the sum and weight of the current node
    :param top: - current node
    :param kn: - the knapsack
    :return: - a list containing the cost and weight of the current node
    """
    sum_ = 0
    weight = 0
    for i in range(0, len(top)):
        if top[i] == '1':
            sum_ = sum_ + kn.get_items()[i].get_cost()
            weight += kn.get_items()[i].get_weight()

    return [sum_, weight]


def knapsack_bfs(knapsack, root):
    """
    Function to get the result - string of bits where a 1 bit on pos i means we take object i
    :param knapsack: knapsack object
    :param root: root of the tree
    :return: returns the result of dfs search
    """
    stack = [root]  # stack for storing tree nodes
    curr_cost = 0
    result = 0
    num = 0
    while len(stack) > 0:
        top = stack.pop()
        num += 1
        metrics = get_bin_sum(top, knapsack)
        if metrics[0] > curr_cost and metrics[1] <= knapsack.get_max_weight():
            curr_cost = metrics[0]
            result = top
        children = get_children(metrics[1], top, knapsack)
        if children is None:
            continue

        stack += children

    result = convert_result(result)
   # print(num)
    return result


def main():
    """
    main function ot solve the problem
    :return: None
    """

   # convert_input("/home/geolica/Desktop/An2_sem2/AI/Lab1/input.txt", "/home/geolica/Desktop/An2_sem2/AI/Lab1/input.txt")
    start = timeit.default_timer()
    file = input("Give a file: ")
    kn = parse_data(file)
   # kn.set_items(sorted(kn.get_items(), reverse=True, key=lambda x : x.get_cost()/x.get_weight()))
    res = knapsack_bfs(kn, '0')
   # print(res)
    print_result("/home/geolica/Desktop/An2_sem2/AI/Lab1/output.txt", kn, res)
    stop = timeit.default_timer()
    print("Time: ", stop - start)


main()
