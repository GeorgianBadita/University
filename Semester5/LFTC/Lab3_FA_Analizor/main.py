from analizor.analizor import Analizor
from analizor.analizor_utils import parse_table_from_file
import os

from finite_automata.utils import read_fa_from_file

CURR_DIR = os.getcwd()

PATH_TO_PREDEF = os.path.join(CURR_DIR, r'files\analizor_files\atom_table.json')  # path to predef table
PATH_TO_IN_FILE = os.path.join(CURR_DIR, r'files\analizor_files\p3.txt')  # path to program
PATH_TO_CT_FA = os.path.join(CURR_DIR, r'files\fa_files\CT_FA.in')  # path to constant finite automaton
PATH_TO_ID_FA = os.path.join(CURR_DIR, r'files\fa_files\ID_FA.in')  # path to ID finite automaton

predef_table = parse_table_from_file(PATH_TO_PREDEF)  # parse predef table

ct_fa = read_fa_from_file(PATH_TO_CT_FA)  # constant FA
id_fa = read_fa_from_file(PATH_TO_ID_FA)  # id FA

analizor = Analizor(predef_table, PATH_TO_IN_FILE, ct_fa, id_fa)  # instantiate analizor
analizor.parse_program()  # parse program

print("PREDEF TABLE: ")
print(analizor.get_predef_table())  # predef table
print()
print("FIP")
for elem in analizor.get_fip():  # fip
    print(elem)
print()
print("ID_TABLE")
print(analizor.get_id_table())  # id table
print()
print("CT_TABLE")
print(analizor.get_ct_table())  # ct table
