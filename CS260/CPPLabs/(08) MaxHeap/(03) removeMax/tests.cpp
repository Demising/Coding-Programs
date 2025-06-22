//Bring in unit testing code and tell it to build a main function
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
//This pragma supresses a bunch of warnings QTCreator produces (and should not)
//#pragma clang diagnostic ignored "-Woverloaded-shift-op-parentheses"
#include "doctest.h"

//Use Approx from doctest without saying doctest::Approx
using doctest::Approx;

#include <vector>
#include <algorithm>

#include "MaxHeap.h"
#include "code.cpp"     //Your code in cpplab

using namespace std;

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


TEST_CASE( "removeOne" ) {
    MaxHeap<int> h;
    buildTestHeap(h);  //100 50 60 30 20 10

    INFO(h.toString());

    int temp = h.removeMax();
    REQUIRE( temp == 100 );
    REQUIRE( h.data[0] == 60 );
    REQUIRE( h.data[2] == 10 );
    REQUIRE( h.heapSize == 5 );
}


TEST_CASE( "removeTwo" ) {
    MaxHeap<int> h;
    buildTestHeap(h);  //100 50 60 30 20 10

    INFO(h.toString());

    h.removeMax();
    int temp = h.removeMax();
    REQUIRE( temp == 60 );
    REQUIRE( h.data[0] == 50 );
    REQUIRE( h.data[1] == 30 );
    REQUIRE( h.data[3] == 20 );
    REQUIRE( h.heapSize == 4 );
}

TEST_CASE( "removeAll" ) {
    MaxHeap<int> h;
    buildTestHeap(h);  //100 50 60 30 20 10

    INFO(h.toString());

    h.removeMax();
    h.removeMax();
    REQUIRE( h.removeMax() == 50 );
    REQUIRE( h.removeMax() == 30 );
    REQUIRE( h.removeMax() == 20 );
    REQUIRE( h.removeMax() == 10 );
    REQUIRE( h.heapSize == 0 );
}