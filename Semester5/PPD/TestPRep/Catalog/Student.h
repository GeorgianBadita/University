//
// Created by geo on 12.12.2019.
//

#ifndef CATALOG_STUDENT_H
#define CATALOG_STUDENT_H


#include <vector>
#include <string>
#include <ostream>

class Student {

public:
    std::string name;
    std::vector<int> grades;

    Student(){
        name = '-';
    }

    Student(std::string& name, std::vector<int>& grades): name{name},
        grades{grades}{}
    std::string getName() {return this->name;}
    std::vector<int> getGrades() {return this->grades;}
    int getFinalGrade() {
        int grade = 0;
        for(const auto& x : this->grades){
            grade += x;
        }
        if(this->grades.size() > 0) {
            return grade / this->grades.size();
        }
        else{
            return -1;
        }
    }

    friend std::ostream& operator<< (std::ostream& stream, Student student) {
        stream << "Name: " << student.name << "; Grades: ";
        for (int i = 0; i < student.grades.size(); i++)
        {
            stream << student.grades[i] << " ";
        }
        stream << "; Final grade: " << student.getFinalGrade() << ";";
        return stream;
    }
};


#endif //CATALOG_STUDENT_H
