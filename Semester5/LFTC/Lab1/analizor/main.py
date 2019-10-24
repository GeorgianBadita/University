from analizor import Analizor
from utils import parse_table_from_file

PATH_TO_PREDEF = r"C:\Users\georg\Desktop\An3_sem1\LFTC\Lab1\atom_table.txt"  # path to predef table
PATH_TO_IN_FILE = r"C:\Users\georg\Desktop\An3_sem1\LFTC\Lab1\p1.txt"  # path to program

PREDEF_TABLE = parse_table_from_file(PATH_TO_PREDEF)  # parse predef table
analizor = Analizor(PREDEF_TABLE, PATH_TO_IN_FILE)  # instantiate analizor
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
