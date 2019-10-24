import os
import sys

LANG = sys.argv[1]
PATH_TO_RUN = sys.argv[2]
NUMBER_OF_RUNS = int(sys.argv[3])

print("PATH: " + PATH_TO_RUN)
for _ in range(NUMBER_OF_RUNS):
    print("RUN:" + str(_))
    if LANG.lower() == "java":
        print("OUTPUT: ")
        os.system("java -jar " + PATH_TO_RUN)
    elif LANG.lower() == "cpp" or LANG.lower() == "c++":
        print("OURPUT: ")
        os.system(PATH_TO_RUN)
    print()
