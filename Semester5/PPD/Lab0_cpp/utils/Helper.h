//
// Created by georg on 10/1/2019.
//

#ifndef LAB1_HELPER_H
#define LAB1_HELPER_H
#include <string>

class Helper {
private:
public:
    Helper() = default;


    /**
     * Function to create a file containing random integers
     * @param path - path to the file
     * @param size - number of integers to write
     * @param min  - min number
     * @param max  - max number
     */
    void createRandomFile(std::string& path, int size, int min, int max);

    /**
     * Function to compare two files
     * @param path1 - path to file1
     * @param path2 - path to file2
     * @param dtype - type of files
     * @return: true if the files are the same, false otherwise
     */
    bool compareFiles(std::string& path1, std::string& path2, std::string& dtype);

    /**
     * Function to write a new line to an Excel file
     * @param path -path to excel
     * @param line -line to be added
     */
    void addLineToExcel(std::string& path, std::string& line);

};


#endif //LAB1_HELPER_H
