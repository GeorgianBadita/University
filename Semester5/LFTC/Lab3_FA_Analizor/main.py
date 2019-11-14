import string

from analizor.analizor import Analizor
from analizor.analizor_utils import parse_table_from_file
import os

from finite_automata.utils import read_fa_from_file


def gen_id_fa():
    alphabet = "a b c d e f g h i j k l m n o p q r s t u v w x y z A B C D E F G H I J K L M N O P Q R S T U V W X Y Z 0 1 2 3 4 5 6 7 8 9"
    final_states = ["q" + str(i + 1) for i in range(250)]
    start_state = "q0"
    transitions = ""
    lower = list(string.ascii_lowercase)
    big = list(string.ascii_uppercase)
    dig = list(string.digits)
    for i in range(250):
        if i == 0:
            for lower_letter in lower:
                transitions += "q0 q1 " + lower_letter + "\n"
            for big_letter in big:
                transitions += "q0 q1 " + big_letter + "\n"
        else:
            for lower_letter in lower:
                transitions += "q" + str(i) + " q" + str(i + 1) + " " + lower_letter + "\n"
            for big_letter in big:
                transitions += "q" + str(i) + " q" + str(i + 1) + " " + big_letter + "\n"
            for digit in dig:
                transitions += "q" + str(i) + " q" + str(i + 1) + " " + digit + "\n"

    with open(r"C:\Users\georg\Desktop\University\Semester5\LFTC\Lab3_FA_Analizor\files\fa_files\ID_FA.in", "w") as f:
        f.write(alphabet)
        f.write(" ".join(final_states))
        f.write(transitions)
        f.write(start_state)
    #print(final_states)
    #print(transitions)


CURR_DIR = os.getcwd()

PATH_TO_PREDEF = os.path.join(CURR_DIR, r'files\analizor_files\atom_table.json')  # path to predef table
PATH_TO_IN_FILE = os.path.join(CURR_DIR, r'files\analizor_files\p1.txt')  # path to program
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

