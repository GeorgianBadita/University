from finite_automata.finite_automata import FiniteAutomata, Transition


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


def fip_to_file(fip, path):
    """
    Function to convert the fip to file
    :param fip: -fip to convert to file
    :param path: - path where to write the fip
    :return: None
    """
    with open(path, "w") as f:
        string = ""
        for elem in fip:
            string += str(elem[0]) + " "
        f.write(string)