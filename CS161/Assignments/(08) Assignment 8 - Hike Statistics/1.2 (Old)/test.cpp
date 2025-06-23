//----------------------------------------------------------
// CS161 Assignment Starter Code
// Copyright Andrew Scholer (ascholer@chemeketa.edu)
// Neither this code, nor any works derived from it
//    may be republished without approval.
//----------------------------------------------------------

//Bring in unit testing code and tell it to build a main function
//If you have multiple unit test files, only one should have this define
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"

//Use Approx from doctest without saying doctest::Approx
using doctest::Approx;

//-----------------------------------------------------------------------------------

#include <iostream>
#include <sstream>
using namespace std;

#include "hikeFunctions.h"

///----------------------------------------------------------------------------------
/// Tests
///----------------------------------------------------------------------------------

const int TEST_ARR1_SIZE = 9;
const int TEST_ARR1[TEST_ARR1_SIZE] = {1200, 1650, 3450, 2800, 2900, 1650, 1140, 1650, 1200};


TEST_CASE( "highestPointBetween" ) {
    cout << "1: highestPointBetween" << endl;
    CHECK( highestPointBetween(TEST_ARR1, 3, 5) == 2900 );
}

//TEST_CASE( "average" ) {
//    cout << "2: average" << endl;
//    CHECK( average(TEST_ARR1, 5, 8) == Approx(1410) );
//}

//TEST_CASE( "isPeak" ) {
//    cout << "3: isPeak" << endl;
//    CHECK( isPeak(TEST_ARR1, TEST_ARR1_SIZE,  4) == true );
//}

//TEST_CASE( "restingSpot" ) {
//    cout << "4: restingSpot" << endl;
//    CHECK( restingSpot(TEST_ARR1, TEST_ARR1_SIZE) == 4 );
//}

//TEST_CASE( "numSteepSegments" ) {
//    cout << "5: numSteepSegments" << endl;
//    CHECK( numSteepSegments(TEST_ARR1, TEST_ARR1_SIZE) == 2 );
//}

//TEST_CASE( "totalElevationChange" ) {
//    cout << "6: totalElevationChange" << endl;
//    CHECK( totalElevationChange(TEST_ARR1, 1, 3) == 2450 );
//}

//TEST_CASE( "getData" ) {
//    cout << "7: getData" << endl;
//
//    const int TEST_ARR2_SIZE = 4;
//    int TEST_ARR2[TEST_ARR2_SIZE];
//
//    stringstream input("100 200 300 400");
//    getData(input, TEST_ARR2, 4);
//    CHECK( TEST_ARR2[0] == 100 );
//}

//TEST_CASE( "mostCommonElevation" ) {
//    cout << "8: mostCommonElevation" << endl;
//    CHECK( mostCommonElevation(TEST_ARR1, TEST_ARR1_SIZE) == 1650 );
//}