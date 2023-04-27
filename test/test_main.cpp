#include "CppUTest/CommandLineTestRunner.h"

int main(int argc, char** argv) {
    // This line is necessary to initialize CppUTest
    // and parse command line arguments
    return CommandLineTestRunner::RunAllTests(argc, argv);
}

