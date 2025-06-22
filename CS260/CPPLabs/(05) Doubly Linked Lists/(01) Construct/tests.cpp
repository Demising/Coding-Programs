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

TEST_CASE( "DLL/Constructor" ) {
    int startNodeCount = ListNode<int>::nodeCount;

    DoublyLinkedList<int> test_list;

    REQUIRE( test_list.length == 0 );
    REQUIRE( test_list.tail != nullptr );
    REQUIRE( test_list.head != nullptr );
    REQUIRE( test_list.tail->prev == test_list.head );
    REQUIRE( test_list.head->next == test_list.tail );
    REQUIRE( ListNode<int>::nodeCount - startNodeCount == 2 );           //dummies
}