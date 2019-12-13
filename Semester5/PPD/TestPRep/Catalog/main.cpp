#include <iostream>
#include <thread>
#include <algorithm>
#include "Student.h"
#include "LinkedList.h"
#include <time.h>
#include <map>

int n = 10;
int studentsNum = 400;
bool done = false;
LinkedList<std::string, Student> studentList;
LinkedList<char, std::map<std::string, std::vector<std::string>>> friends;

std::string random_string( size_t length )
{
    auto randchar = []() -> char
    {
        const char charset[] =
                "0123456789"
                "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                "abcdefghijklmnopqrstuvwxyz";
        const size_t max_index = (sizeof(charset) - 1);
        return charset[ rand() % max_index ];
    };
    std::string str(length,0);
    std::generate_n( str.begin(), length, randchar );
    return str;
}


bool filterGrades(Student st){
    return st.getFinalGrade() > 7;
}

void generateAndAdd(int num, LinkedList<std::string, Student>* students){
    std::vector<int> grades;
    for(int i = 0; i<num; i++){
        grades.clear();
        for(int j = 0; j<5; j++){
            grades.push_back(1 + rand() % 10);
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(20));
        std::string name = random_string(6);
        auto student = Student(name, grades);
        students->pushBack(name, student);
    }
}

void reader(LinkedList<std::string, Student>* students){
    while(!done){
        students->printFilteredList(filterGrades);
        std::this_thread::sleep_for(std::chrono::milliseconds(20));
    }
}

int main() {
    srand(time(nullptr));
    int perThread = studentsNum / n;
    int rem = studentsNum % n;
    std::vector<std::thread> threads;
    for(int i = 0; i<n; i++){
        int forThread = perThread;
        if(rem > 0){
            forThread ++;
        }
        std::thread th(generateAndAdd, forThread, &studentList);
        threads.push_back(std::move(th));
    }

    std::thread th(reader, &studentList);

    for(auto & thread : threads){
        thread.join();
    }
    done = true;
    th.join();

    std::vector<std::string> names;
    names.emplace_back("asda");
    std::map<std::string, std::vector<std::string>> mapp;
    mapp.insert(std::make_pair("andrei", names));

    friends.pushBack('a', mapp);
    auto head = friends.getHead();
    while(head != nullptr){
        std::cout << head->getKey() << '\n';
        for(const auto& x : head->getValue()){
            std::string name = x.first;
            std::cout << name << '\n';
            for(const auto& y : x.second){
                std::cout << y << ' ';
            }
        }
        head = head->getNext();
    }
    return 0;
}
