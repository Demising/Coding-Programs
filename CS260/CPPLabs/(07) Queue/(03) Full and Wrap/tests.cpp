//Bring in unit testing code and tell it to build a main function
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
//This pragma supresses a bunch of warnings QTCreator produces (and should not)
//#pragma clang diagnostic ignored "-Woverloaded-shift-op-parentheses"
#include "doctest.h"

//Use Approx from doctest without saying doctest::Approx
using doctest::Approx;

#include "Queue.h"
#include "code.cpp"     //Your code in cpplab

using namespace std;

//Add test data to list.
//Built to take existing list to avoid using copy ctor or assignment
void addTestData(Queue<char>& q) {
    for(int i = 0; i < 6; i++)
        q.enqueue(static_cast<char>('A' + i));
}

TEST_CASE( "WrapEnd" ) {
    Queue<char> q;
    addTestData(q); //A B C D E F

    q.dequeue();
    q.dequeue();

    q.enqueue('G');
    q.enqueue('H');
    q.enqueue('I');

    INFO(q.toString());
    REQUIRE( q.list[0] == 'I' );
}

TEST_CASE( "WrapStart" ) {
    Queue<char> q;
    addTestData(q); //A B C D E F
    for(int i = 0; i < 6; i++)
        q.dequeue();
    q.enqueue('G');
    q.enqueue('H');
    q.enqueue('I');
    q.enqueue('J');

    for(int i = 0; i < 3; i++)
        q.dequeue();

    INFO(q.toString());
    REQUIRE( q.start == 1 );
    REQUIRE( q.end == 2 );
}

TEST_CASE( "Full" ) {
    Queue<char> q;
    addTestData(q); //A B C D E F

    INFO(q.toString());

    REQUIRE( q.full() == false );

    q.enqueue('G');
    REQUIRE( q.full() == true );

    q.dequeue();
    REQUIRE( q.full() == false );

    q.enqueue('H');
    REQUIRE( q.full() == true );
}