#include "CppUTest/TestHarness.h"
#include "seat_def.hpp"

TEST_GROUP(SeatTests) {
   
};

TEST(SeatTests, GetNameTest) {
    Seat s1("A1", true);
    CHECK(s1.getName() == "A1");
}

TEST(SeatTests, IsAvailableTest) {
    Seat s2("A2", false);
    CHECK(s2.isAvailable() == false);
}

TEST(SeatTests, ReserveTest) {
    Seat s3("A3", true);
    s3.reserve();
    CHECK(s3.isAvailable() == false);
}

