# compiler options
CXXFLAGS = -g -Wall -Wextra
CXXFLAGS += -std=c++17 -pedantic -pedantic-errors
CXXFLAGS += -Wfloat-equal -Wredundant-decls -Wshadow -Wconversion

# list .h files here
HEADERS = PriorityQueue.h DataStream.h

# list .cpp files here
PROGRAM_FILES = DataStream.cpp processPackets.cpp

TEST_FILES = tests.cpp DataStream.cpp

.PHONY: all
all: program.exe test.exe

program.exe: $(PROGRAM_FILES) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(PROGRAM_FILES) -o $@

test.exe: $(TEST_FILES) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(TEST_FILES) -o $@

.PHONY: clean
clean:
	rm -f program.exe test.exe
