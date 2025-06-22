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


TEST_CASE( "addTestOne" ) {
    MaxHeap<int> h;
    buildTestHeap(h);  //100 50 60 30 20 10

    INFO(h.toString());

    h.add(15);
    REQUIRE( h.heapSize == 7 );
    REQUIRE( h.data[2] == 60 );
    REQUIRE( h.data[6] == 15 );
}

TEST_CASE( "addTestTwo" ) {
    MaxHeap<int> h;
    buildTestHeap(h);  //100 50 60 30 20 10

    INFO(h.toString());

    h.add(75);
    REQUIRE( h.heapSize == 7 );
    REQUIRE( h.data[2] == 75 );
    REQUIRE( h.data[6] == 60 );
}

TEST_CASE( "addTestTwo" ) {
    MaxHeap<int> h;
    buildTestHeap(h);  //100 50 60 30 20 10

    INFO(h.toString());

    h.add(15);
    h.add(75);
    REQUIRE( h.heapSize == 8 );
    REQUIRE( h.data[1] == 75 );
    REQUIRE( h.data[3] == 50 );
    REQUIRE( h.data[7] == 30 );
}


TEST_CASE( "addTestThree" ) {
    MaxHeap<int> h;
    buildTestHeap(h);  //100 50 60 30 20 10

    INFO(h.toString());

    h.add(15);
    h.add(15);
    h.add(15);
    h.add(200);
    REQUIRE( h.heapSize == 10 );
    REQUIRE( h.data[0] == 200 );
    REQUIRE( h.data[1] == 100 );
    REQUIRE( h.data[4] == 50 );
    REQUIRE( h.data[9] == 20 );
}