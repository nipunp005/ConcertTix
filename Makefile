# Compiler and flags
CC=g++
#CFLAGS=-std=c++17 -Wall -Wextra -pedantic -Iinc
CFLAGS=-std=c++17 -Iinc -I/usr/local/include/CppUTest

# Directories
SRCDIR=src
INCDIR=inc
BUILDDIR=build
TESTDIR=test

# Files
EXECUTABLE=$(BUILDDIR)/booking_app
TEST_EXECUTABLE=$(BUILDDIR)/unit_test
SOURCES=$(wildcard $(SRCDIR)/*.cpp)
TEST_SOURCES=$(wildcard $(TESTDIR)/*.cpp)
OBJECTS=$(patsubst $(SRCDIR)/%.cpp,$(BUILDDIR)/%.o,$(SOURCES))
TEST_OBJECTS=$(patsubst $(TESTDIR)/%.cpp,$(BUILDDIR)/%.o,$(TEST_SOURCES))

# Libraries
LIBS=-L /usr/local/lib -lCppUTest -lCppUTestExt

# Targets
.PHONY: all clean

all: $(EXECUTABLE) $(TEST_EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@

$(TEST_EXECUTABLE): $(TEST_OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILDDIR)/%.o: $(TESTDIR)/%.cpp
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILDDIR)

