//Bring in unit testing code and tell it to build a main function
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
//This pragma supresses a bunch of warnings QTCreator produces (and should not)
//#pragma clang diagnostic ignored "-Woverloaded-shift-op-parentheses"
#include "doctest.h"

//Use Approx from doctest without saying doctest::Approx
using doctest::Approx;

#include "DoublyLinkedList.h"
#include "code.cpp"     //Your code in cpplab

using namespace std;

TEST_CASE( "DLL/removeEnd" ) {
    //Requires working constructor!
    DoublyLinkedList<int> test_list;
    test_list.insertStart(40);
    test_list.insertStart(30);
    test_list.insertStart(20);
    test_list.insertStart(10);

    int startNodeCount = ListNode<int>::nodeCount;

    test_list.removeEnd();

    REQUIRE( test_list.length == 3 );
    REQUIRE( test_list.retrieveAt(0) == 10 );
    REQUIRE( test_list.retrieveAt(2) == 30 );
    REQUIRE( startNodeCount - ListNode<int>::nodeCount == 1 );

    test_list.removeEnd();
    test_list.removeEnd();

    REQUIRE( test_list.length == 1 );
    REQUIRE( test_list.retrieveAt(0) == 10 );
    REQUIRE( startNodeCount - ListNode<int>::nodeCount == 3 );

    test_list.removeEnd();

    REQUIRE( test_list.length == 0 );
    REQUIRE( startNodeCount - ListNode<int>::nodeCount == 4 );
}