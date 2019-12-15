class Production:
    """
    Class to describe a production rule for a grammar
    """

    def __init__(self, left_term, right_term):
        """
        Constructor for Production class
        @param: left_term - left term of the production
        @param: right_term - right term of the production
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

    """
    Setters
    """

    def set_left_term(self, new_left):
        self.__left_term = new_left

    def set_right_term(self, new_right):
        self.__right_term = new_right

    """
    Str function
    """

    def __str__(self):
        right_str = "["
        for i in range(len(self.get_right_term())):
            if i != len(self.get_right_term()) - 1:
                right_str += self.get_right_term()[i] + ", "
            else:
                right_str += self.get_right_term()[i]
        right_str += "]"
        return self.__left_term + " -> " + right_str

    def __eq__(self, other):
        return self.__right_term == other.get_right_term() and self.__left_term == other.get_left_term()


class Grammar:
    """
    Class to describe a grammar
    """

    def __init__(self, start_symbol, terminals, non_terminals, productions):
        """
        Constructor for grammar class
        @param: start_symbol - symbol start of the grammar
        @param: terminals - terminals set
        @param: non-terminals - non_terminals set
        @param: productions list of productions for the grammar
        """

        self.__start_symbol = start_symbol
        self.__terminals = terminals
        self.__non_terminals = non_terminals
        self.__productions = productions

    """
    Getters
    """

    def get_start_symbol(self):
        return self.__start_symbol

    def get_terminals(self):
        return self.__terminals

    def get_non_terminals(self):
        return self.__non_terminals

    def get_productions(self):
        return self.__productions

    def get_productions_of(self, symbol):
        return list(filter(lambda x: x.get_left_term() == symbol, self.__productions))

    """
    Setters
    """

    def set_start_symbol(self, new_sym):
        self.__start_symbol = new_sym

    def set_terminals(self, new_terminals):
        self.__terminals = new_terminals

    def set_non_terminals(self, new_non_term):
        self.__non_terminals = new_non_term

    def set_productions(self, new_productions):
        self.__productions = new_productions

    def is_terminal(self, symbol):
        """
        Function to check if a given symbol is a terminal
        """
        return symbol in self.__terminals

    def is_non_terminal(self, symbol):
        """
        Function to check if a given symbol is a non_terminal
        """
        return symbol in self.__non_terminals

    "Str function"

    def __str__(self):
        string_prod = ""
        for prod in self.__productions:
            string_prod += str(prod) + "\n"
        string_term = ""
        for term in self.__terminals:
            string_term += term + " "
        string_non_term = ""
        for non_term in self.__non_terminals:
            string_non_term += non_term + " "

        return "Start symbol: " + self.__start_symbol + "\n" \
                                                        "Terminals: " + string_term + "\n" \
                                                                                      "Non-terminals: " + string_non_term + "\n" \
                                                                                                                            "Productions:\n" + string_prod
