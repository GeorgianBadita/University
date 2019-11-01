import os

from utils import read_grammar_from_file, read_grammar_from_keyboard, make_finite_automata_from_grammar, make_grammar_from_finite_automata

local_path = 'grammar.txt'

PATH_TO_GRAMMAR = os.path.join(os.getcwd(), local_path)

grammar = read_grammar_from_file(PATH_TO_GRAMMAR)

fa_from_grammar = make_finite_automata_from_grammar(grammar)

print(make_grammar_from_finite_automata(fa_from_grammar))