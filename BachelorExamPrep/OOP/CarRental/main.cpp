#include <iostream>
#include "tests/testsMain/TestRunner.h"
#include "repository/AbstractRepository.h"
#include <vector>
#include <string>


class A {
public:
    virtual void print() {
        std::cout << "A";
    }
};

class B {
public:
    virtual void print() {
        std::cout << "B";
    }
};

class C : public A, B {
public:
    void print() override {

        std::cout << "C";
    }
};


//Template<OBJ> - T getID(), setID(T id);
//Car<int>; Car<std::string>
//


int main() {

    TestRunner().runTests();
    std::string str = "err";
    std::string str1 = "err1";
    std::vector<std::string> errs = {str, str1};
    return 0;
}