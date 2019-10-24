class Item:

    def __init__(self, weight, cost):
        """
        Constructor for item class
        :param cost: -cost of the item
        :param weight: -weight of the item
        """
        self.__weight = weight
        self.__cost = cost

    # Getters and setters
    def get_cost(self):
        return self.__cost

    def get_weight(self):
        return self.__weight

    def set_cost(self, new_cost):
        self.__cost = new_cost

    def set_weight(self, new_weight):
        self.__weight = new_weight

    # Overriding __eq__
    def __eq__(self, other):
        return self.__weight == other.get_weight() and self.__cost == other.get_cost()

