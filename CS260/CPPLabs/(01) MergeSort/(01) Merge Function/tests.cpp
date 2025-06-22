//Bring in unit testing code and tell it to build a main function
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
//This pragma supresses a bunch of warnings QTCreator produces (and should not)
//#pragma clang diagnostic ignored "-Woverloaded-shift-op-parentheses"
#include "doctest.h"

//Use Approx from doctest without saying doctest::Approx
using doctest::Approx;

//Declare functions we will test
void mergeFunc(int arr[], int low, int mid, int high, int temp[]);
void mergeSort(int arr[], int arrSize);

#include <algorithm>
#include <random>

using namespace std;

TEST_CASE( "Merge/AllEqualHalves" ) {
    int mergeArr[]  = {1, 3, 5, 2, 4, 6};
    const int size = 6;

    //Copy to compare against
    int key[size];
    std::copy(mergeArr, mergeArr + size, key);
    std::sort(key, key + size);

    int temp[size] = {};
    mergeFunc(mergeArr, 0, 2, 5, temp);

    bool isSorted = std::is_sorted(mergeArr, mergeArr + size);
    REQUIRE( isSorted == true );

    bool correctVals = std::equal(mergeArr, mergeArr + size, key);
    INFO("Your array does not have the right elements!");
    REQUIRE( correctVals == true );
}

TEST_CASE( "Merge/AllUnequalHalves" ) {
    int mergeArr[]  = {1, 8, 10, 20, 6, 7, 15};
    const int size = 7;

    //Copy to compare against
    int key[size];
    std::copy(mergeArr, mergeArr + size, key);
    std::sort(key, key + size);

    int temp[size] = {};
    mergeFunc(mergeArr, 0, 3, 6, temp);

    bool isSorted = std::is_sorted(mergeArr, mergeArr + size);
    REQUIRE( isSorted == true );

    bool correctVals = std::equal(mergeArr, mergeArr + size, key);
    INFO("Your array does not have the right elements!");
    REQUIRE( correctVals == true );
}

TEST_CASE( "Merge/AllUnequalHalves2" ) {
    int mergeArr[]  = {1, 3, 2, 4, 6, 8, 10};
    const int size = 7;

    //Copy to compare against
    int key[size];
    std::copy(mergeArr, mergeArr + size, key);
    std::sort(key, key + size);

    int temp[size] = {};
    mergeFunc(mergeArr, 0, 1, 6, temp);

    bool isSorted = std::is_sorted(mergeArr, mergeArr + size);
    REQUIRE( isSorted == true );

    bool correctVals = std::equal(mergeArr, mergeArr + size, key);
    INFO("Your array does not have the right elements!");
    REQUIRE( correctVals == true );
}

TEST_CASE( "Merge/Partial" ) {
    //Test to see if sorting just a partial range works
    int mergeArr[]  = {999, 999, 4, 8, 3, 12, 999};
    const int size = 7;

    //Copy to compare against
    int key[size];
    std::copy(mergeArr, mergeArr + size, key);
    //sort just the relevent part
    std::sort(key + 2, key + (size - 1));

    int temp[size] = {};
    mergeFunc(mergeArr, 2, 3, 5, temp);

    //see if 2-5 are sorted
    bool isSorted = std::is_sorted(mergeArr + 2, mergeArr + 6);
    REQUIRE( isSorted == true );

    bool correctVals = std::equal(mergeArr, mergeArr + size, key);
    INFO("Your array does not have the right elements!");
    REQUIRE( correctVals == true );
}