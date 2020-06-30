//
// Created by geo on 15.06.2020.
//

#include "TestRunner.h"

void TestRunner::runTests() {
    for (const auto &test : this->tests) {
        test->runTest();
    }
}
