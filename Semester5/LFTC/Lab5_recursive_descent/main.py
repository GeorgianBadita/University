import os

from grammar_utils import read_grammar_from_file
from recursive_descent_alg import recursive_descent

path_to_grammar = os.path.join(os.getcwd(), 'grammar.txt')

grammar = read_grammar_from_file(path_to_grammar)
print(grammar)
input = '()'

good, prods = recursive_descent(grammar, input)
print(good, prods)
