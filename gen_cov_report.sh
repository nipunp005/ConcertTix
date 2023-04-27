#! /bin/bash

#Run the test executable to generate coverage files
./build/unit_test -c

#Run gcov for each of the class files
gcov seat.cpp
lcov --capture --directory . --output-file build/seat.info --exclude '/usr/include/g++'
gcov theatre.cpp
lcov --capture --directory . --output-file build/theatre.info --exclude '/usr/include/g++'
gcov concert.cpp
lcov --capture --directory . --output-file build/concert.info --exclude '/usr/include/g++'
gcov booking.cpp
lcov --capture --directory . --output-file build/booking.info --exclude '/usr/include/g++'

#Merge the report files to generate combined report.
lcov --add-tracefile build/seat.info --add-tracefile build/theatre.info --add-tracefile build/concert.info --add-tracefile build/booking.info --output-file build/coverage.info

#Generate html for the combined report
genhtml build/coverage.info --output-directory build/coverage/



