#include "CppUTest/TestHarness.h"
#include "theatre_def.hpp"

TEST_GROUP(TheaterTestGroup) {

};

TEST(TheaterTestGroup, TestConstructor)
{
    Theater theater1("Test Theater", 100);
    CHECK_EQUAL("Test Theater", theater1.getName());
    CHECK_EQUAL(100, theater1.getCapacity());
}

TEST(TheaterTestGroup, TestSetCapacity)
{
    Theater theater2("Test Theater", 100);
    theater2.setCapacity(200);
    CHECK_EQUAL(200, theater2.getCapacity());
}

