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
#include <string>

using namespace std;



TEST_CASE( "Grow" ) {
    StringHashTable t;
    //Add a tombstone
    t.buckets[2] = "#";

    //Add all items from this list - F should trigger grow
    vector<string> items = {"A", "B", "C", "D", "E", "F"};
    for(string s : items) {
        t.insert(s);
    }

    //Are they all still there?
    for(string s : items) {
        REQUIRE( t.contains(s) );
    }

    REQUIRE( t.size() == 6 );

    //Add a few more items, also add to our vector
    items.push_back("G");
    t.insert("G");
    items.push_back("H");
    t.insert("H");
    items.push_back("I");
    t.insert("I");
    items.push_back("J");
    t.insert("J");

    //Check everything again
    for(string s : items) {
        REQUIRE( t.contains(s) );
    }
}


//Return next string in alphabetic order
// AAA, AAB, AAC..., AAZ, ABA, ABB,...
string nextString(string s) {
    for(int i = static_cast<int>(s.length() - 1); i >= 0; i--) {
        if(s[i] < 'Z') {
            s[i]++;
            break;
        }
        else
            s[i] = 'A';
    }
    return s;
}

TEST_CASE( "GrowStressTest" ) {
    StringHashTable t;

    string s = "AAA";
    for(int i = 0; i < 100; i++) {
        t.insert(s);
        s = nextString(s);
    }

    //Are they all still there?
    REQUIRE( t.size() == 100 );
    s = "AAA";
    for(int i = 0; i < 100; i++) {
        REQUIRE( t.contains(s) );
        s = nextString(s);
    }
}