#include "concert_def.hpp"
#include "CppUTest/TestHarness.h"

TEST_GROUP(Concert) {
};

TEST(Concert, Constructor) {

    Concert c1("Concert Name", "Artist Name", "2023-05-01");
    CHECK_EQUAL("Concert Name", c1.getName());
    CHECK_EQUAL("Artist Name", c1.getArtist());
    CHECK_EQUAL("2023-05-01", c1.getDate());
}

TEST(Concert, Getters) {

    Concert c2("Concert Name", "Artist Name", "2023-05-01");
    CHECK_EQUAL("Concert Name", c2.getName());
    CHECK_EQUAL("Artist Name", c2.getArtist());
    CHECK_EQUAL("2023-05-01", c2.getDate());
}

