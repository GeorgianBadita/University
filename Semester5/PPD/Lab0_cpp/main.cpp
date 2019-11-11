#include "utils/Helper.h"

int main() {
    std::string path_to_a = R"(C:\Users\georg\Desktop\University\Semester5\PPD\big_num_add_MPI\BigNumAddMPI\BigNumAddMPI\num_file_a.in)"; //path to first number
    std::string path_to_b = R"(C:\Users\georg\Desktop\University\Semester5\PPD\big_num_add_MPI\BigNumAddMPI\BigNumAddMPI\num_file_b.in)"; //path to second number
    std::string path3 = R"(C:\Users\georg\Desktop\An3_sem1\PPD\Lab1_java\src\num_file_b.txt)";
    std::string path4 = R"(C:\Users\georg\Desktop\An3_sem1\PPD\Lab1_java\src\num_file_a.txt)";
    std::string dtype = "int";
    auto helper = Helper();
    helper.createRandomFile(path_to_a, 1000 , 0, 9);
    helper.createRandomFile(path_to_b, 1000 , 0, 9);

    //std::cout << helper.compareFiles(path1, path2, dtype);
    return 0;
}