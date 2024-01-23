//----------------------------------------------------------
// CS161 Assignment Starter Code
// Copyright Andrew Scholer (ascholer@chemeketa.edu)
// Neither this code, nor any works derived from it
//    may be republished without approval.
//----------------------------------------------------------

//Bring in unit testing code and tell it to build a main function
//If you have multiple unit test files, only one should have this define
///-----------------------------------------------------------------------
/// Test Function Code
///-----------------------------------------------------------------------

//Bring in unit testing code and tell it to build a main function
//If you have multiple unit test files, only one should have this define
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "hikeFunctions.h"

//Use Approx from doctest without saying doctest::Approx
using doctest::Approx;

//-----------------------------------------------------------------------------------

#include <iostream>
#include <sstream>
using namespace std;

///----------------------------------------------------------------------------------
/// Tests
///----------------------------------------------------------------------------------

const int TEST_ARR1_SIZE = 9;
const int TEST_ARR1[TEST_ARR1_SIZE] = {1200, 1650, 3450, 2800, 2900, 1650, 1140, 1650, 1200};
const int TEST_ARR2_SIZE = 12;
const int TEST_ARR2[TEST_ARR2_SIZE] = {1650, 950, 1400, 1350, 1800, 1650, 1950, 1850, 2200, 2100, 1950, 2150};
const int TEST_ARR3_SIZE = 12;
const int TEST_ARR3[TEST_ARR3_SIZE] = {1650, 950, 1400, 1350, 1500, 1650, 1950, 1850, 2200, 2100, 1950, 2150};
const int TEST_ARR5_SIZE = 16;
const int TEST_ARR5[TEST_ARR5_SIZE] = {750, 1750, 1825, 1435, 750, 1550, 1650, 750, 950, 1250, 750, 1650, 1350, 1650, 1200, 1650};
const int TEST_ARR6_SIZE = 4;
const int TEST_ARR6[TEST_ARR6_SIZE] = {750, 950, 1050, 1150};


TEST_CASE( "highestPointBetween" ) {
    cout << "1: highestPointBetween" << endl;
    CHECK( highestPointBetween(TEST_ARR1, 3, 5) == 2900 );
}

TEST_CASE( "average" ) {
    cout << "2: average" << endl;
    CHECK( average(TEST_ARR1, 5, 8) == Approx(1410) );
    CHECK( average(TEST_ARR1, 3, 7) == Approx(2028) );
    CHECK( average(TEST_ARR1, 1, 3) == Approx(2633.33) );
    CHECK( average(TEST_ARR1, 0, 8) == Approx(1960) );
}

TEST_CASE( "isPeak" ) {
    cout << "3: isPeak" << endl;
    CHECK( isPeak(TEST_ARR1, TEST_ARR1_SIZE,  4) == true );
    CHECK( isPeak(TEST_ARR1, TEST_ARR1_SIZE,  3) == false );
    CHECK( isPeak(TEST_ARR1, TEST_ARR1_SIZE,  2) == true );
    CHECK( isPeak(TEST_ARR1, TEST_ARR1_SIZE,  7) == true );
    CHECK( isPeak(TEST_ARR1, TEST_ARR1_SIZE,  8) == false );
    CHECK( isPeak(TEST_ARR1, TEST_ARR1_SIZE,  0) == false );
}

TEST_CASE( "restingSpot" ) {
    cout << "4: restingSpot" << endl;
    CHECK( restingSpot(TEST_ARR1, TEST_ARR1_SIZE) == 4 );
    CHECK( restingSpot(TEST_ARR2, TEST_ARR2_SIZE) == 4 );
    CHECK( restingSpot(TEST_ARR3, TEST_ARR3_SIZE) == 6 );
}

TEST_CASE( "numSteepSegments" ) {
    cout << "5: numSteepSegments" << endl;
    CHECK( numSteepSegments(TEST_ARR1, TEST_ARR1_SIZE) == 2 );
    CHECK( numSteepSegments(TEST_ARR2, TEST_ARR2_SIZE) == 0 );
    CHECK( numSteepSegments(TEST_ARR3, TEST_ARR3_SIZE) == 0 );
}

TEST_CASE( "totalElevationChange" ) {
    cout << "6: totalElevationChange" << endl;
    CHECK( totalElevationChange(TEST_ARR1, 1, 3) == 2450 );
    CHECK( totalElevationChange(TEST_ARR1, 1, 5) == 3800 );
    CHECK( totalElevationChange(TEST_ARR2, 3, 6) == 900 );
    CHECK( totalElevationChange(TEST_ARR2, 9, 11) == 350 );
}

TEST_CASE( "getData" ) {
    cout << "7: getData" << endl;

    const int TEST_ARR4_SIZE = 4;
    int TEST_ARR4[TEST_ARR4_SIZE];

    stringstream input("100 200 300 400");
    getData(input, TEST_ARR4, 4);
    CHECK( TEST_ARR4[0] == 100 );
    CHECK( TEST_ARR4[3] == 400 );
}

TEST_CASE( "mostCommonElevation" ) {
    cout << "8: mostCommonElevation" << endl;
    CHECK( mostCommonElevation(TEST_ARR1, TEST_ARR1_SIZE) == 1650 );
    CHECK( mostCommonElevation(TEST_ARR2, TEST_ARR2_SIZE) == 1650 );
    CHECK( mostCommonElevation(TEST_ARR5, TEST_ARR5_SIZE) == 750 );
    CHECK( mostCommonElevation(TEST_ARR6, TEST_ARR6_SIZE) == 750 );
    
}



