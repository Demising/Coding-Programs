//Bring in unit testing code and tell it to build a main function
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
//This pragma supresses a bunch of warnings QTCreator produces (and should not)
//#pragma clang diagnostic ignored "-Woverloaded-shift-op-parentheses"
#include "doctest.h"

//Use Approx from doctest without saying doctest::Approx
using doctest::Approx;

#include "LinkedList.h"
#include "removefirst.cpp"     //Your code in cpplab

using namespace std;

//Add test data to list.
//Built to take existing list to avoid using copy ctor or assignment
void buildTestIntList(LinkedList<int>& list) {
    list.insertStart(3);
    list.insertStart(2);
    list.insertStart(1);
}

TEST_CASE( "LL/RemoveFirst" ) {
    LinkedList<int> test_list;
    buildTestIntList(test_list);  //1, 2, 3

    int startNodeCount = ListNode<int>::nodeCount;

    test_list.removeFirst();
    REQUIRE( test_list.length == 2 );
    REQUIRE( startNodeCount - ListNode<int>::nodeCount == 1 );

    test_list.removeFirst();
    REQUIRE( test_list.length == 1 );
    REQUIRE( test_list.retrieveAt(0) == 3 );
    REQUIRE( startNodeCount - ListNode<int>::nodeCount == 2 );

    test_list.removeFirst();
    REQUIRE( test_list.length == 0 );
    REQUIRE( test_list.head == nullptr );
    REQUIRE( test_list.tail == nullptr );
    REQUIRE( startNodeCount - ListNode<int>::nodeCount == 3 );
}