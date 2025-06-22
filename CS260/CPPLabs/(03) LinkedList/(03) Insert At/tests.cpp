//Bring in unit testing code and tell it to build a main function
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
//This pragma supresses a bunch of warnings QTCreator produces (and should not)
//#pragma clang diagnostic ignored "-Woverloaded-shift-op-parentheses"
#include "doctest.h"

//Use Approx from doctest without saying doctest::Approx
using doctest::Approx;

#include "LinkedList.h"
#include "insertat.cpp"     //Your code in cpplab

using namespace std;

//Add test data to list.
//Built to take existing list to avoid using copy ctor or assignment
void buildTestIntList(LinkedList<int>& list) {
    list.insertStart(3);
    list.insertStart(2);
    list.insertStart(1);
}


TEST_CASE( "LL/InsertAt" ) {
    LinkedList<int> test_list;
    buildTestIntList(test_list);  //1, 2, 3

    test_list.insertAt(2, 10);
    REQUIRE( test_list.length == 4 );
    REQUIRE( test_list.retrieveAt(2) == 10 );
    REQUIRE( test_list.retrieveAt(3) == 3 );

    test_list.insertAt(1, 20);
    REQUIRE( test_list.length == 5 );
    REQUIRE( test_list.retrieveAt(1) == 20 );
    REQUIRE( test_list.retrieveAt(2) == 2 );
    REQUIRE( test_list.retrieveAt(3) == 10 );
}


TEST_CASE( "LL/InsertAtSpecialCases" ) {
    LinkedList<int> test_list;
    buildTestIntList(test_list);  //1, 2, 3

    //Inserting at the start with insertAt
    test_list.insertAt(0, 10);
    REQUIRE( test_list.length == 4 );
    REQUIRE( test_list.retrieveAt(0) == 10 );
    REQUIRE( test_list.retrieveAt(1) == 1 );

    //Inserting at the end with insertAt
    test_list.insertAt(4, 20);
    REQUIRE( test_list.length == 5 );
    REQUIRE( test_list.retrieveAt(3) == 3 );
    REQUIRE( test_list.retrieveAt(4) == 20 );
    //Make sure tail is updated
    REQUIRE( test_list.tail->data == 20 );
}