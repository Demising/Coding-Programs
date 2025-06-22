//Bring in unit testing code and tell it to build a main function
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
//This pragma supresses a bunch of warnings QTCreator produces (and should not)
//#pragma clang diagnostic ignored "-Woverloaded-shift-op-parentheses"
#include "doctest.h"

//Use Approx from doctest without saying doctest::Approx
using doctest::Approx;

#include <vector>
#include <algorithm>

using namespace std;

#include "MaxHeap.h"
#include "code.cpp"     //Your code in cpplab


/*
 * Forcibly set heap to known state:
 *       100
 *      /   \
 *     50    60
 *    / \    /
 *   30 20  10
*/
//Built to take existing heap to avoid using copy ctor or assignment
void buildTestHeap(MaxHeap<int>& h) {
    delete [] h.data;
    h.heapSize = 6;
    h.capacity = 32;
    //Intentionally has extra 100... not technically part of heap
    h.data = new int[32] {100, 50, 60, 30, 20, 10, 100};
}


TEST_CASE( "largestChildIndex" ) {
    MaxHeap<int> h;
    buildTestHeap(h);  //100 50 60 30 20 10

    INFO(h.toString());
    REQUIRE( h.largestChildIndex(0) == 2 );
    REQUIRE( h.largestChildIndex(1) == 3 );
    REQUIRE( h.largestChildIndex(2) == 5 );
    REQUIRE( h.largestChildIndex(3) == -1 );
    REQUIRE( h.largestChildIndex(4) == -1 );
    REQUIRE( h.largestChildIndex(5) == -1 );
}