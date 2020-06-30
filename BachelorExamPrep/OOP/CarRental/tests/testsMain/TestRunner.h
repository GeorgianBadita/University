//
// Created by geo on 15.06.2020.
//

#ifndef CARRENTAL_TESTRUNNER_H
#define CARRENTAL_TESTRUNNER_H

#include <vector>
#include "Test.h"
#include "../domain/entities/TestCar.h"
#include "../repository/TestRepository.h"
#include "../service/TestService.h"

class TestRunner {
private:
    std::vector<Test *> tests = {new TestCar(), new TestRepository(), new TestService()};

public:
    ~TestRunner() {
        for (const auto &test : this->tests) {
            delete test;
        }
    }

/**
 * Function to run all tests
 */
    void runTests();
};


#endif //CARRENTAL_TESTRUNNER_H
