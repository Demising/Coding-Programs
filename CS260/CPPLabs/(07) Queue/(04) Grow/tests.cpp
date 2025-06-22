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


TEST_CASE( "Grow" ) {
    Queue<char> q;
    addTestData(q); //A B C D E F
    for(int i = 0; i < 20; i++)
        q.enqueue('A');

    INFO(q.toString());
    REQUIRE( q.dequeue() == 'A' );
    REQUIRE( q.dequeue() == 'B' );
    REQUIRE( q.dequeue() == 'C' );
    REQUIRE( q.dequeue() == 'D' );
    REQUIRE( q.dequeue() == 'E' );
    REQUIRE( q.dequeue() == 'F' );
    REQUIRE( q.dequeue() == 'A' );
}

TEST_CASE( "GrowAfterWrap" ) {
    Queue<char> q;
    addTestData(q); //A B C D E F
    for(int i = 0; i < 6; i++)
        q.dequeue();
    q.enqueue('G');
    q.enqueue('H');
    q.enqueue('I');
    q.enqueue('J');
    for(int i = 0; i < 20; i++)
        q.enqueue('A');

    INFO(q.toString());
    REQUIRE( q.dequeue() == 'G' );
    REQUIRE( q.dequeue() == 'H' );
    REQUIRE( q.dequeue() == 'I' );
    REQUIRE( q.dequeue() == 'J' );
    REQUIRE( q.dequeue() == 'A' );
}