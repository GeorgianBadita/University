class Production:
    """
    Class for representing a production
    """

    def __init__(self, left_term, right_term):
        """
        Constructor for production class
        :param left_term: left term of the production
        :param right_term: right term of the production
        """
        self.__left_term = left_term
        self.__right_term = right_term

    """
    Getters
    """

    def get_left_term(self):
        return self.__left_term

    def get_right_term(self):
        return self.__right_term

    def __repr__(self):
        return self.get_left_term() + " --> " + self.get_right_term()


class Grammar:
    """
    Class for representing a grammar
    """

    def __init__(self, non_terminals, terminals, productions):
        """
        Constructor for Grammar class
        :param non_terminals: non_terminals set
        :param terminals: terminals set
        :param productions: production rules
        """
        self.__non_terminals = non_terminals
        self.__terminals = terminals
        self.__productions = productions

    """
    Getters
    """

    def get_non_terminals(self):
        return self.__non_terminals

    def get_terminals(self):
        return self.__terminals

    def get_productions(self):
        return self.__productions

    def is_regular(self):
        """
        Function which verifies if the grammar is regular
        :return: True if the grammar is regular, false otherwise
        """
        for production in self.__productions:
            right_term = production.get_right_term()
            if len(right_term) > 2:
                return False
            if len(right_term) == 1 and right_term[0] not in self.__terminals:
                return False
            if len(right_term) == 2 and (right_term[0] not in self.__terminals or right_term[1] not in self.__non_terminals):
                return False

        return True

    def get_productions_of(self, symbol):
        """
        Function to get the productions of a given symbol
        :param symbol: symbol for which we want the production rules
        :return: a list containing the production rules of a given symbol
        """
        prods = []
        for prod in self.__productions:
            if prod.get_left_term() == symbol:
                prods.append(prod)

        return prods

    def __repr__(self):
        production_str = "\n"
        for production in self.__productions:
            production_str += str(production) + "\n"
        return "Terminals: " + str(self.__terminals) + "\n" + "Non-terminals: " + str(self.__non_terminals) + \
               "\nProduction rules: " + production_str
