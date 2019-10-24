class Knapsack:
    """
    Class for Knapsack - contains a list of items
    """

    def __init__(self, max_weight):
        """
        Constructor for Knapsack class
        :param max_weight: maximum weight of the knapsack
        """
        self.__items = []
        self.__max_weight = max_weight

    def add_item(self, item):
        """
        Function to adda an item to the knapsack
        :return: the added item
        """
        self.__items.append(item)
        return item

    def del_item(self, item):
        """
        Function to delete an item
        :param item: the item to be deleted
        :return: the deleted item
        """

        self.__items.remove(item)
        return item

    def get_items(self):
        """
        Function to get all items from the knapsack
        :return: a list containing all items from the knapsack
        """
        return self.__items

    def get_max_weight(self):
        """
        Function to get the maximum weight of the knapsack
        :return: maximum weight of the knapsack
        """
        return self.__max_weight

    def set_items(self, items):
        """
        Function to set knapsack's items
        :param items: new list of items
        :return: None
        """
        self.__items = items
