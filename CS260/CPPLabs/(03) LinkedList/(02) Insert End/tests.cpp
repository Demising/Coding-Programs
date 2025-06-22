//Bring in unit testing code and tell it to build a main function
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
//This pragma supresses a bunch of warnings QTCreator produces (and should not)
//#pragma clang diagnostic ignored "-Woverloaded-shift-op-parentheses"
#include "doctest.h"

//Use Approx from doctest without saying doctest::Approx
using doctest::Approx;

#include "LinkedList.h"
#include "insertend.cpp"     //Your code in cpplab

using namespace std;

//Add test data to list.
//Built to take existing list to avoid using copy ctor or assignment
void buildTestIntList(LinkedList<int>& list) {
    list.insertStart(3);
    list.insertStart(2);
    list.insertStart(1);
}

TEST_CASE( "LL/InsertEnd" ) {
    LinkedList<int> test_list;
    buildTestIntList(test_list);  //1, 2, 3

    test_list.insertEnd(10);
    REQUIRE( test_list.length == 4 );
    REQUIRE( test_list.retrieveAt(3) == 10 );
    REQUIRE( test_list.tail->data == 10 );       //check tail pointer
    REQUIRE( test_list.tail->next == nullptr ); //check after tail

    test_list.insertEnd(20);
    REQUIRE( test_list.length == 5 );
    REQUIRE( test_list.retrieveAt(4) == 20 );
    REQUIRE( test_list.tail->data == 20 );       //check tail pointer
    REQUIRE( test_list.tail->next == nullptr ); //check after tail
}

TEST_CASE( "LL/InsertEndEmptyList" ) {
    LinkedList<int> test_list;

    test_list.insertEnd(10);
    REQUIRE( test_list.head != nullptr );       //check head pointer
    REQUIRE( test_list.length == 1 );
    REQUIRE( test_list.retrieveAt(0) == 10 );
    REQUIRE( test_list.head->data == 10 );       //check head pointer
    REQUIRE( test_list.tail->data == 10 );       //check tail pointer
    REQUIRE( test_list.tail->next == nullptr ); //check after tail
}