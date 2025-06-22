//Bring in unit testing code and tell it to build a main function
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
//This pragma supresses a bunch of warnings QTCreator produces (and should not)
//#pragma clang diagnostic ignored "-Woverloaded-shift-op-parentheses"
#include "doctest.h"

//Use Approx from doctest without saying doctest::Approx
using doctest::Approx;

#include "LinkedList.h"
#include "code.cpp"     //Your code in cpplab

using namespace std;

//Add test data to list.
//Built to take existing list to avoid using copy ctor or assignment
void buildTestIntList(LinkedList<int>& list) {
    list.insertStart(3);
    list.insertStart(2);
    list.insertStart(1);
}


TEST_CASE( "LL/AssignmentOperator" ) {
    LinkedList<int> test_list;
    buildTestIntList(test_list);    //1, 2, 3

    LinkedList<int> test_list2;
    test_list2.insertStart(10);
    test_list2.insertStart(20);     //10 20

    int startNodeCount = ListNode<int>::nodeCount;

    test_list2 = test_list;         //Overwrite existing test_list2

    REQUIRE( test_list2.retrieveAt(0) == 1 );
    REQUIRE( test_list2.retrieveAt(1) == 2 );
    REQUIRE( test_list2.retrieveAt(2) == 3 );
    REQUIRE( test_list2.length == 3 );
    REQUIRE( ListNode<int>::nodeCount - startNodeCount == 1 ); //created 3, deleted 2

    //Make sure removal from one does not affect other
    test_list.removeAt(1);
    REQUIRE( test_list2.retrieveAt(0) == 1 );
    REQUIRE( test_list2.retrieveAt(1) == 2 );
    REQUIRE( test_list2.retrieveAt(2) == 3 );
    REQUIRE( test_list2.length == 3 );
}