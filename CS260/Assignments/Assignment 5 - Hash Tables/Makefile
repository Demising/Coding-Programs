# compiler options
CXXFLAGS = -g -Wall -Wextra
CXXFLAGS += -std=c++17 -pedantic -pedantic-errors
CXXFLAGS += -Wfloat-equal -Wredundant-decls -Wshadow -Wconversion

# list .h files here
HEADERS = IndexMap.h IndexRecord.h

# list .cpp files here
PROGRAM_FILES = IndexBuilder.cpp IndexMap.cpp IndexRecord.cpp
TEST_FILES = tester.cpp IndexMap.cpp IndexRecord.cpp

.PHONY: all
all: program.exe tests.exe

program.exe: $(PROGRAM_FILES) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(PROGRAM_FILES) -o $@

tests.exe: $(TEST_FILES) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(TEST_FILES) -o $@

.PHONY: clean
clean:
	rm -f program.exe tests.exe
