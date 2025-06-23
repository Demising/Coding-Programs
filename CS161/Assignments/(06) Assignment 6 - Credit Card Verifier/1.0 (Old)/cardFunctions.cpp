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

#include <string>
using namespace std;

//Your functions here
int charToInt(char digit)
{
  int length = strlen(digit)

  for (int i = 0; i < length; i++)
  {
    int number[i] = digit[i] - '0';
  }
}


///----------------------------------------------------------------------------------
/// Tests
/// Uncomment tests to work on them. Make sure any test that does not compile or
/// causes a crash gets commented back out. Any test that runs should be left
/// on (uncommented), even if the test fails.
///----------------------------------------------------------------------------------

// TEST_CASE( "charToInt" ) {
//     cout << "1: charToInt" << endl;
//     //Not an exhaustive test, but should verify function is doing the right kind of thing
//     CHECK( charToInt('0') == 0 );
//     CHECK( charToInt('1') == 1 );
//     CHECK( charToInt('4') == 4 );
//     CHECK( charToInt('9') == 9 );
// }

// TEST_CASE( "doubledDigitValue" ) {
//     cout << "2a: doubledDigitValue - basic" << endl;

//     //Again, not exhaustive
//     CHECK( doubledDigitValue(0) == 0 );
//     CHECK( doubledDigitValue(2) == 4 );
//     CHECK( doubledDigitValue(3) == 6 );
//     CHECK( doubledDigitValue(5) == 1 );
//     CHECK( doubledDigitValue(8) == 7 );
// }

// TEST_CASE( "doubledDigitValue multidigit" ) {
//     cout << "2b: doubledDigitValue - handle multidigits" << endl;

//     CHECK( doubledDigitValue(5) == 1 );
//     CHECK( doubledDigitValue(8) == 7 );
// }

// TEST_CASE( "cardType" ) {
//     cout << "3: cardType" << endl;

//     CHECK( cardType("40000" ) == "Visa" );
//     CHECK( cardType("50000" ) == "Mastercard" );
//     CHECK( cardType("34000" ) == "American Express" );
//     CHECK( cardType("38000" ) == "Unknown" );
//     CHECK( cardType("70000" ) == "Unknown" );
//     CHECK( cardType("2") == "Unknown" );
//     CHECK( cardType("") == "Unknown" );
// }

// TEST_CASE( "luhnDigitSum - odd length" ) {
//     cout << "4a: luhnDigitSum - odd length" << endl;

//     CHECK( luhnDigitSum("123") == 8 );
//     CHECK( luhnDigitSum("26173") == 14 );
//     CHECK( luhnDigitSum("79927398713") == 70 );
// }

// TEST_CASE( "luhnDigitSum - even length" ) {
//     cout << "4b: luhnDigitSum - even length" << endl;

//     CHECK( luhnDigitSum("34") == 10 );
//     CHECK( luhnDigitSum("6123") == 11 );
//     CHECK( luhnDigitSum("12345671234567") == 57 );
// }

// TEST_CASE( "isValid" ) {
//     cout << "5: isValid" << endl;

//     CHECK( isValid("123") == false );
//     CHECK( isValid("653") == true );
//     CHECK( isValid("79927398713") == true );
//     CHECK( isValid("31789372997") == true );
//     CHECK( isValid("31789372597") == false );
// }

// TEST_CASE( "printCard" ) {
//     cout << "6: printCard" << endl;

//     //Not really a unit test. Need to verify output manually
//     cout << "Expect: 41689372997 : Valid Visa" << endl;
//     cout << "Result: ";
//     printCardInfo("41689372997");
//     cout << endl << "Expect: 586 : Invalid Mastercard" << endl;
//     cout << "Result: ";
//     printCardInfo("586");
//     cout << endl << "Expect: 31789372997 : Valid Unknown" << endl;
//     cout << "Result: ";
//     printCardInfo("31789372997");
// }
