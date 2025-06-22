# compiler options
CXXFLAGS = -g -Wall -Wextra
CXXFLAGS += -std=c++17 -pedantic -pedantic-errors
CXXFLAGS += -Wfloat-equal -Wredundant-decls -Wshadow -Wconversion

# list .h files here
HEADERS = Address.h AddressArrayList.h AddressLinkedList.h Arraylist.h

# list .cpp files here
PROGRAM_FILES = main.cpp AddressLinkedList.cpp AddressArrayList.cpp Address.cpp

TEST_FILES = tests.cpp Address.cpp AddressArrayList.cpp AddressLinkedList.cpp

.PHONY: all
all: program.exe tests.exe

program.exe: $(PROGRAM_FILES) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(PROGRAM_FILES) -o $@

tests.exe: $(TEST_FILES) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(TEST_FILES) -o $@

.PHONY: clean
clean:
	rm -f program.exe tests.exe
