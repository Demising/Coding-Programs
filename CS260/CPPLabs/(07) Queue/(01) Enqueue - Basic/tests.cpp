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

TEST_CASE( "Enqueue1" ) {
    Queue<char> q;

    q.enqueue('A');
    INFO(q.toString());
    REQUIRE( q.start == 0 );
    REQUIRE( q.end == 1 );
    REQUIRE( q.list[q.start] == 'A' );
}

TEST_CASE( "Enqueue2" ) {
    Queue<char> q;

    q.enqueue('A');
    q.enqueue('B');

    INFO(q.toString());
    REQUIRE( q.start == 0 );
    REQUIRE( q.end == 2 );
    REQUIRE( q.list[q.start] == 'A' );
    REQUIRE( q.list[q.end - 1] == 'B' );
}

TEST_CASE( "Enqueue3" ) {
    Queue<char> q;

    q.enqueue('A');
    q.enqueue('B');
    q.enqueue('C');

    INFO(q.toString());
    REQUIRE( q.start == 0 );
    REQUIRE( q.end == 3 );
    REQUIRE( q.list[q.start] == 'A' );
    REQUIRE( q.list[q.end - 1] == 'C' );
}