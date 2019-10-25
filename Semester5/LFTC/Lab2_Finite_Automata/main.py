import os

#  PATH TO FINITE AUTOMATA FILE
from utils import read_fa_from_file, read_fa_from_user

fa_path = os.path.join(os.getcwd(), "fa.in")

finite_automata = read_fa_from_file(fa_path)

print(finite_automata)

print(finite_automata.longest_prefix_accepted('10'))
