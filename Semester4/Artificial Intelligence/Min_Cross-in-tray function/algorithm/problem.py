from algorithm.data import Data


class Problem:

    def __init__(self, in_file_name):
        self.data = self.load_data(in_file_name)

    def load_data(self, in_file_name):

        with open(in_file_name, "r") as f:
            length = int(f.readline())

            set_ = f.readline().split(",")
            lst = []
            for element in set_:
                lst.append(int(element))

            nr_subsets = int(f.readline())
            subsets = []
            for i in range(nr_subsets):
                line = f.readline().split(",")
                subset = []
                for element in line:
                    subset.append(int(element))
                subsets.append(subset)
        return Data(lst, subsets)
