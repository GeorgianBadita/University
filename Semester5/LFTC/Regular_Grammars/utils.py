from grammar import Production, Grammar
from finite_automata import FiniteAutomata, Transition


def read_grammar_from_file(path):
    """
    Function to read a grammar from file
    :param path: path to grammar file
    :return: the grammar from the file
    """
    with open(path, "r") as f:
        prod_rules = []
        line = f.readline().strip()
        non_terminals = [elem for elem in line.split(' ')]
        line = f.readline().strip()
        terminals = [elem for elem in line.split(' ')]
        line = f.readline().strip()
        while line != "":
            line = line.split(' ')
            if len(line) == 3:
                prod_rules.append(Production(line[0], line[2]))
            line = f.readline().strip()
        return Grammar(non_terminals, terminals, prod_rules)


def read_grammar_from_keyboard():
    """
    Function to read a grammar from user
    :return: the gramar given by the user
    """
    non_terminals = input("Give the non_terminals for Grammar (space between every non_terminal): ").split(" ")
    terminals = input("Give the terminals of the grammar (space between every terminal): ").split(" ")
    productions = []

    while True:
        elem = input("Give a production rule (leftTerm -> rightTerm), give an empty production rule to stop (? for epsilon): ").split(" ")
        if elem == ['']:
            break

        production = Production(elem[0], elem[2])

        productions.append(production)

    return Grammar(non_terminals, terminals, productions)


def read_fa_from_file(path):
    """
    Function to read a finite automata from file
    :param path: path to the finite automata
    :return: the finite automata described in the file
    :raise: FileNotFound exception if the file could not be found
    """
    states = set()
    transitions = {}
    with open(path, "r") as f:
        line = f.readline().strip()
        alphabet = line.split(' ')
        final_states = set(f.readline().strip().split(" "))
        while line != "":
            line = f.readline().strip()
            elems = line.split(" ")
            if len(elems) == 1:
                start_state = elems[0]
                return FiniteAutomata(alphabet, transitions, states, final_states, start_state)
            else:
                states.add(elems[0])
                states.add(elems[1])
                curr_line_states = transitions.get(elems[0], [])
                if not curr_line_states:
                    transitions[elems[0]] = [Transition(elems[1], elems[2])]
                else:
                    transitions[elems[0]].append(Transition(elems[1], elems[2]))
    raise FileNotFoundError(path)


def read_fa_from_user():
    """
    Function to read a finite automata from standard input
    :return: the finite automata given by the user
    """
    alphabet = input("Give the alphabet for the FA (space between every character): ").split(" ")
    final_states = set(input("Give the final states of the FA (space between every state): ").split(" "))
    transitions = {}
    states = set()

    while True:
        elem = input("Give a transition (state1 state2 symbol), give an empty transition to stop: ").split(" ")
        if elem == ['']:
            break

        transition = Transition(elem[1], elem[2])

        curr_line_states = transitions.get(elem[0], [])
        if not curr_line_states:
            transitions[elem[0]] = [transition]
        else:
            transitions[elem[0]].append(transition)

        states.add(elem[0])
        states.add(elem[1])

    start_state = input("Give the starting state of the FA: ")

    return FiniteAutomata(alphabet, transitions, states, final_states, start_state)


def make_finite_automata_from_grammar(grammar):
    """
    Function to convert a finite automata into a regular grammar
    :param grammar: grammar to be converted
    :return: the corresponding finite automata
    """
    states = [elem for elem in grammar.get_non_terminals()]
    alphabet = [elem for elem in grammar.get_terminals()]
    states.append('F')
    final_states = ['F']
    start_state = grammar.get_non_terminals()[0]
    epsilon_prod = Production(start_state, '?')
    for production in grammar.get_productions():
        if epsilon_prod.get_right_term() == production.get_right_term() and epsilon_prod.get_left_term() == production.get_left_term():
            final_states.append(start_state)

    transitions = {}
    for production in grammar.get_productions():
        if len(production.get_right_term()) == 2:
            curr_trans = transitions.get(production.get_left_term(), [])
            if not curr_trans:
                transitions[production.get_left_term()] = [Transition(production.get_right_term()[1], production.get_right_term()[0])]
            else:
                transitions[production.get_left_term()].append(Transition(production.get_right_term()[1], production.get_right_term()[0]))
        else:
            curr_trans = transitions.get(production.get_left_term(), [])
            if not curr_trans:
                transitions[production.get_left_term()] = [Transition('F', production.get_right_term()[0])]
            else:
                transitions[production.get_left_term()].append(Transition('F', production.get_right_term()[0]))

    return FiniteAutomata(alphabet, transitions, states, final_states,start_state)


def make_grammar_from_finite_automata(finite_automata):
    """
    Function to convert a finite automata to a regular grammar
    :param finite_automata: finite automata to be converted
    :return: the regular grammar corresponding to the finite automata
    """
    productions = []
    terminals = []
    non_terminals = []
    state = None
    for state in finite_automata.get_states():
        non_terminals.append(state)
        if finite_automata.get_transitions().get(state, []):
            to_trans = finite_automata.get_transitions()[state]
            terminals.append(to_trans[0].get_symbol())
            productions.append(Production(state, to_trans[0].get_symbol() + to_trans[0].get_state()))
    productions.append(Production(state, "?"))

    return Grammar(non_terminals, terminals, productions)
