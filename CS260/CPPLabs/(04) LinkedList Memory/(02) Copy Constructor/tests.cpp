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



TEST_CASE( "LL/CopyConstructor" ) {
    LinkedList<int> test_list;
    buildTestIntList(test_list);  //1, 2, 3

    int startNodeCount = ListNode<int>::nodeCount;

    LinkedList<int> copy(test_list);

    REQUIRE( copy.retrieveAt(0) == 1 );
    REQUIRE( copy.retrieveAt(1) == 2 );
    REQUIRE( copy.retrieveAt(2) == 3 );
    REQUIRE( copy.length == 3 );
    REQUIRE( ListNode<int>::nodeCount - startNodeCount == 3 );

    //Make sure removal from one does not affect other
    test_list.removeAt(1);
    REQUIRE( copy.retrieveAt(0) == 1 );
    REQUIRE( copy.retrieveAt(1) == 2 );
    REQUIRE( copy.retrieveAt(2) == 3 );
    REQUIRE( copy.length == 3 );
}