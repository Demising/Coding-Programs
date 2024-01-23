.PHONY: all tests
CPP = g++
CPP_FLAGS = -std=c++17 -g
WARNINGS = -Wall -Wextra -Wmissing-include-dirs -Wfloat-equal -Wredundant-decls -Winit-self -Wshadow -Wconversion
STANDARDS = -pedantic -pedantic-errors
TESTER_NAME = tests.exe
PROGRAM_NAME: program.exe

TEST_FILES = testingHike.cpp
PROGRAM_FILES: testingHike.cpp
INCLUDE_DIRS = .
SHARED_FILES = 

all: tests

tests:
	$(CPP) $(CPP_FLAGS) $(STANDARDS) $(WARNINGS) -I $(INCLUDE_DIRS) -o $(TESTER_NAME) $(SHARED_FILES) $(TEST_FILES)