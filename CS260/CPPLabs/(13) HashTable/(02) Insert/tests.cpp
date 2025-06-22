//Bring in unit testing code and tell it to build a main function
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
//This pragma supresses a bunch of warnings QTCreator produces (and should not)
//#pragma clang diagnostic ignored "-Woverloaded-shift-op-parentheses"
#include "doctest.h"

//Use Approx from doctest without saying doctest::Approx
using doctest::Approx;

#include "StringHashTable.h"
//#include "code.cpp"     //Your code in cpplab

#include <vector>

using namespace std;


TEST_CASE( "Insert" ) {
    StringHashTable t;
    t.insert("B");

    unsigned int targetBucket = t.getBucket("B");
    INFO(targetBucket);
    INFO(t);
    REQUIRE( t.buckets[targetBucket] == "B" );
    REQUIRE( t.currentSize == 1 );
}


TEST_CASE( "InsertWithProbe" ) {
    StringHashTable t;

    //Find something that occupies location 1
    string key = "B";
    int targetBucket = t.getBucket(key);
    while(targetBucket != 1) {
        key += "B";
        targetBucket = t.getBucket(key);
    }

    //Fill that and next two
    t.buckets[1] = "No";
    t.buckets[2] = "No";
    t.buckets[3] = "No";
    t.currentSize = 3;

    //Then add item
    t.insert(key);

    INFO(t);
    REQUIRE( t.buckets[4] == key );
    REQUIRE( t.currentSize == 4 );
}


TEST_CASE( "InsertWith Wrap" ) {
    StringHashTable t;

    //Find something that should occupy last location
    string key = "B";
    int targetBucket = t.getBucket(key);
    while(targetBucket != t.tableCapacity - 1) {
        key += "B";
        targetBucket = t.getBucket(key);
    }

    //Now fill that location and location 0
    t.buckets[t.tableCapacity - 1] = "No";
    t.buckets[0] = "No";
    t.currentSize = 2;

    //Place key
    t.insert(key);

    INFO(t);
    REQUIRE( t.buckets[1] == key );
    REQUIRE( t.currentSize == 3 );
}


TEST_CASE( "InsertWithProbe" ) {
    StringHashTable t;

    //Find something that occupies location 1
    string key = "B";
    int targetBucket = t.getBucket(key);
    while(targetBucket != 1) {
        key += "B";
        targetBucket = t.getBucket(key);
    }

    //Fill that and next two
    t.buckets[1] = "No";
    t.buckets[2] = "No";
    t.buckets[3] = "No";
    t.currentSize = 3;

    //Then add item
    t.insert(key);

    INFO(t);
    REQUIRE( t.buckets[4] == key );
    REQUIRE( t.currentSize == 4 );
}