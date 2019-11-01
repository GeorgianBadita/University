class Transition:
    """
    Function to represent a transition
    """

    def __init__(self, state, symbol):
        """
        Transition constructor
        :param state: state to transit
        :param symbol: symbol
        """
        self.__state = state
        self.__symbol = symbol

    "Getters"

    def get_state(self):
        return self.__state

    def get_symbol(self):
        return self.__symbol

    """
    Setters
    """

    def set_state(self, state):
        self.__state = state

    def set_symbol(self, sym):
        self.__symbol = sym

    def __repr__(self):
        return "To: " + str(self.__state) + " " + "Symbol: " + str(self.__symbol)


class FiniteAutomata:
    """
    Class for representing a finite automata
    """

    def __init__(self, alphabet, transitions, states, final_states, start_state):
        """
        Constructor for FiniteAutomata class
        :param alphabet: alphabet accepted by the FA
        :param transitions: FA's transitions (state1, state2, s) - means, from state1 go to state2 with the symbol s
        :param states: set of FA's states
        :param final_states: set of FA's final states
        :param start_state: starting state
        """
        self.__alphabet = alphabet
        self.__transitions = transitions
        self.__states = states
        self.__final_states = final_states
        self.__start_state = start_state

    """
    Getters
    """

    def get_alphabet(self):
        return self.__alphabet

    def get_transitions(self):
        return self.__transitions

    def get_states(self):
        return self.__states

    def get_final_states(self):
        return self.__final_states

    def get_start_state(self):
        return self.__start_state

    """
    Setters
    """

    def set_alphabet(self, alph):
        self.__alphabet = alph

    def set_transitions(self, trans):
        self.__transitions = trans

    def set_states(self, states):
        self.__states = states

    def set_start_state(self, state):
        self.__start_state = state

    def set_final_states(self, fin_states):
        self.__final_states = fin_states

    def __repr__(self):
        trans_str = ""
        for trans in self.__transitions:
            for t in self.__transitions[trans]:
                trans_str += "Transition: " + "From: " + trans + " " + str(t) + "\n"
        return "Alphabet: " + str(self.get_alphabet()) + "\n" + \
               "Transitions:\n" + trans_str + "States: " + str(self.__states) + \
               "\nFinal_states: " + str(self.__final_states) + \
               "\nStart state: " + str(self.__start_state)
