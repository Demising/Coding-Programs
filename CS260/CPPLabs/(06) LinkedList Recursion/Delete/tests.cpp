//Bring in unit testing code and tell it to build a main function
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
//This pragma supresses a bunch of warnings QTCreator produces (and should not)
//#pragma clang diagnostic ignored "-Woverloaded-shift-op-parentheses"
#include "doctest.h"

//Use Approx from doctest without saying doctest::Approx
using doctest::Approx;

#include "SimpleLinkedList.h"

using namespace std;

//Add test data to list.
//Built to take existing list to avoid using copy ctor or assignment
void buildTestIntList(SimpleLinkedList& list) {
    list.insertStart(30);
    list.insertStart(20);
    list.insertStart(10);
}


TEST_CASE( "LL/destruct" ) {

    int startNodeCount = ListNode::nodeCount;
    {
        SimpleLinkedList test_list;
        buildTestIntList(test_list);
        //test_list leaves scope and destructed
    }

    REQUIRE( ListNode::nodeCount - startNodeCount == 0 );
}