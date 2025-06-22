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


TEST_CASE( "Remove" ) {
    StringHashTable t;
    t.insert("C");
    t.remove("C");

    INFO(t);
    REQUIRE( !t.contains("C") );
    REQUIRE( t.currentSize == 0 );
}


TEST_CASE( "RemoveAndInsert" ) {
    StringHashTable t;
    t.insert("C");

    //Make a tombstone
    t.remove("C");

    unsigned int targetBucket = t.getBucket("C");

    //Find something that should occupy same location
    string key = "B";
    while(targetBucket != t.getBucket(key)) {
        key += "B";
    }

    //Should replace the tombstone at location targetBucket
    t.insert(key);

    INFO(t);
    REQUIRE( t.buckets[targetBucket] == key );
    REQUIRE( t.currentSize == 1 );
}

TEST_CASE( "ContainsWithTombstone" ) {
    StringHashTable t;

    unsigned int targetBucket = t.getBucket("C");

    //Find something that should occupy same location
    string key = "B";
    while(targetBucket != t.getBucket(key)) {
        key += "B";
    }

    //Insert blocker, then C and remove leaving a tombstone
    t.insert(key);
    t.insert("C");
    t.remove(key);


    INFO(t);
    REQUIRE( t.contains("C") );
    REQUIRE( t.currentSize == 1 );
}