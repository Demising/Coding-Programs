//Bring in unit testing code and tell it to build a main function
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
//This pragma supresses a bunch of warnings QTCreator produces (and should not)
//#pragma clang diagnostic ignored "-Woverloaded-shift-op-parentheses"
#include "doctest.h"

//Use Approx from doctest without saying doctest::Approx
using doctest::Approx;

//Declare functions we will test
int partitionFunct(int arr[], int low, int high);
void quickSort(int arr[], int arrSize);

#include <algorithm>
#include <random>

using namespace std;


TEST_CASE( "QuickSort/Simple" ) {
    int list[] = {12, 9, 16, 2, 1, 16, 18, 7};
    const int size = 8;

    //Copy to compare against
    int list_key[size];
    std::copy(list, list + size, list_key);
    std::sort(list_key, list_key + size);

    quickSort(list, size);

    bool isSorted = std::is_sorted(list, list + size);
    REQUIRE( isSorted == true );

    bool correctVals = std::equal(list, list + size, list_key);
    INFO("Your array does not have the right elements!");
    REQUIRE( correctVals == true );
}

//get value 0-999,999
int randInt() {
    static default_random_engine generator;
    static uniform_int_distribution<int> distribution(0,999999);
    return distribution(generator);
}

TEST_CASE( "QuickSort/Big" ) {
    const int size = 10001;
    int* list = new int[size];
    //Fill with random numbers
    std::generate(list, list + size, randInt);

    //Copy to compare against
    int* list_key = new int[size];
    std::copy(list, list + size, list_key);
    std::sort(list_key, list_key + size);

    quickSort(list, size);

    bool isSorted = std::is_sorted(list, list + size);
    REQUIRE( isSorted == true );

    bool correctVals = std::equal(list, list + size, list_key);
    INFO("Your array does not have the right elements!");
    REQUIRE( correctVals == true );
}