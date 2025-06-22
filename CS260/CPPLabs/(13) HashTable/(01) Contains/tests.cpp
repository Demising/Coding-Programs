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

TEST_CASE( "Contains" ) {
    StringHashTable t;
    t.buckets[t.getBucket("A")] = "A";

    INFO(t);
    REQUIRE( t.contains("A") );
}

TEST_CASE( "ContainsProbe" ) {
    StringHashTable t;

    //Find something that does NOT occupy the last location
    string key = "A";
    int targetBucket = t.getBucket(key);
    while(targetBucket == t.tableCapacity - 1) {
        key += "A";
        targetBucket = t.getBucket(key);
    }

    //Fill bucket the value should be in
    t.buckets[targetBucket] = "No";

    //Place key in next bucket
    int nextBucket = targetBucket + 1;
    t.buckets[nextBucket] = key;

    INFO(t);
    REQUIRE( t.contains(key) );
}


TEST_CASE( "ContainsProbeWithWrap" ) {
    StringHashTable t;

    //Find something that should occupy next to last location
    string key = "A";
    int targetBucket = t.getBucket(key);
    while(targetBucket != t.tableCapacity - 2) {
        key += "A";
        targetBucket = t.getBucket(key);
    }

    //Now fill that location and last location
    t.buckets[targetBucket] = "No";
    t.buckets[targetBucket + 1] = "No";

    //Place key in location 0 and see if we find it
    t.buckets[0] = key;

    INFO(t);
    REQUIRE( t.contains(key) );
}