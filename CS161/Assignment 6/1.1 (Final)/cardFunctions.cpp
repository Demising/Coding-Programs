/**
* @brief cardFunctions
* @name Clayton Moeck
*/

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
#include <cstring>
using namespace std;

/**
 * @brief Converts char "digit" to a int.
 * @param Number becomes the ASCII code of digit.
 *
 * @return int number to the function that called it.
*/
int charToInt(char digit)
{
  int number = digit - '0';

  return number;
}

/**
 * @brief Returns a doubled number from an input
 * @param If doubled number is less than 10, store it as doubled.
 * @param If doubled number is 10 or greater, find the sum
 *        of the first digit and second digit, and store it
 *        as sum.
 * 
 * @return Return either doubled, or sum, depending on the circumstances
 *          met.
*/
int doubledDigitValue(int number)
{
  int doubled = number * 2;
  if (doubled < 10)
    return doubled;
  else
  {
    int digit2 = doubled % 10;
    int digit1 = doubled / 10;
    int sum = digit1 + digit2;

    return sum;
  }
}

/**
 * @brief Take in a card number, and find the card type.
 * @param cardNumber Find the first and second digit of the
 *        credit card number.
 * 
 * @return Return either Visa, Mastercard, American Express,
 *          or Unkown if the first and second digit meet the
 *          parameters.
*/
string cardType(const string& cardNumber)
{
  if (cardNumber.empty())
    return "Unknown";

  string digit1 = cardNumber.substr(0, 1);
  string digit2 = cardNumber.substr(1,1);

  if (digit1 == "3")
    {
      if (digit2 == "4" || digit2 == "7")
        return "American Express";
      else
        return "Unknown";
    }
  else if (digit1 == "4" || digit1 == "5")
    {
      if (digit1 == "4")
        return "Visa";
      else if (digit1 == "5")
        return "Mastercard";
    }
  else
    return "Unknown";

  
  return cardNumber;
}

/**
 * @brief Find the luhnDigitSum of the card.
 * @param cardNumber Take in the full string of
 *        the card number, and find it's length.
 * @param length Depending on length and i = length - n, call
 *        to functions (charToInt) and (doubledDigitValue).
 * @param i i either equals length - 1, or length - 2, and
 *        decrements by 2 each time the "for" loops run.
 * 
 * @return returns the totalSum, which is found by adding oddSum
 *          and even sum together.
*/
int luhnDigitSum(const string& cardNumber)
{
  int totalSum = 0;
  int evenSum = 0;
  int oddSum = 0;
  int length = cardNumber.size();

  for (int i = length - 1; i >= 0; i -= 2)
  {
    char digit = cardNumber[i];
    int num = charToInt(digit);

    oddSum += num;
  }

  for (int i = length - 2; i >= 0; i -= 2)
  {
    char digit = cardNumber[i];
    int num = charToInt(digit);
    int doubled = doubledDigitValue(num);

    evenSum += doubled;
  }

  totalSum = evenSum + oddSum;
  return totalSum;
}

/**
 * @brief We check if the luhnDigitSum is valid now
 * @param cardNumber We use cardNumber and call to the function
 *        luhnDigitSum with it, and place it's value in luhnSum.
 * 
 * @return We return a true ("1") or false ("0") value.
*/
bool isValid (const string& cardNumber)
{
  int luhnSum = luhnDigitSum(cardNumber);

  return (luhnSum % 10 == 0);
}

/**
 * @brief We print the card information of the cardNumber
 *        by calling to previous functions.
 * @param cardNumber We take card number and call to the functions (isValid)
 *        and (cardType) and display our answer to the console.
*/
void printCardInfo(const string& cardNumber)
{
  bool valid = isValid(cardNumber);
  string type = cardType(cardNumber);
  string validS;

  if (valid)
    validS = "Valid";
  else
    validS = "Invalid";

  cout << cardNumber << " : " << validS << " " << type << endl;
}


///----------------------------------------------------------------------------------
/// Tests
/// Uncomment tests to work on them. Make sure any test that does not compile or
/// causes a crash gets commented back out. Any test that runs should be left
/// on (uncommented), even if the test fails.
///----------------------------------------------------------------------------------

 TEST_CASE( "charToInt" ) {
     cout << "1: charToInt" << endl;
     //Not an exhaustive test, but should verify function is doing the right kind of thing
     CHECK( charToInt('0') == 0 );
     CHECK( charToInt('1') == 1 );
     CHECK( charToInt('4') == 4 );
     CHECK( charToInt('9') == 9 );
 }

 TEST_CASE( "doubledDigitValue" ) {
     cout << "2a: doubledDigitValue - basic" << endl;

     //Again, not exhaustive
     CHECK( doubledDigitValue(0) == 0 );
     CHECK( doubledDigitValue(2) == 4 );
     CHECK( doubledDigitValue(3) == 6 );
     CHECK( doubledDigitValue(5) == 1 );
     CHECK( doubledDigitValue(8) == 7 );
 }

 TEST_CASE( "doubledDigitValue multidigit" ) {
     cout << "2b: doubledDigitValue - handle multidigits" << endl;

     CHECK( doubledDigitValue(5) == 1 );
     CHECK( doubledDigitValue(8) == 7 );
 }

 TEST_CASE( "cardType" ) {
     cout << "3: cardType" << endl;

     CHECK( cardType("40000" ) == "Visa" );
     CHECK( cardType("50000" ) == "Mastercard" );
     CHECK( cardType("34000" ) == "American Express" );
     CHECK( cardType("38000" ) == "Unknown" );
     CHECK( cardType("70000" ) == "Unknown" );
     CHECK( cardType("2") == "Unknown" );
     CHECK( cardType("") == "Unknown" );
 }

 TEST_CASE( "luhnDigitSum - odd length" ) {
     cout << "4a: luhnDigitSum - odd length" << endl;

     CHECK( luhnDigitSum("123") == 8 );
     CHECK( luhnDigitSum("26173") == 14 );
     CHECK( luhnDigitSum("79927398713") == 70 );
 }

 TEST_CASE( "luhnDigitSum - even length" ) {
     cout << "4b: luhnDigitSum - even length" << endl;

     CHECK( luhnDigitSum("34") == 10 );
     CHECK( luhnDigitSum("6123") == 11 );
     CHECK( luhnDigitSum("12345671234567") == 57 );
 }

 TEST_CASE( "isValid" ) {
     cout << "5: isValid" << endl;

     CHECK( isValid("123") == false );
     CHECK( isValid("653") == true );
     CHECK( isValid("79927398713") == true );
     CHECK( isValid("31789372997") == true );
     CHECK( isValid("31789372597") == false );
 }

 TEST_CASE( "printCard" ) {
     cout << "6: printCard" << endl;

     //Not really a unit test. Need to verify output manually
     cout << "Expect: 41689372997 : Valid Visa" << endl;
     cout << "Result: ";
     printCardInfo("41689372997");
     cout << endl << "Expect: 586 : Invalid Mastercard" << endl;
     cout << "Result: ";
     printCardInfo("586");
     cout << endl << "Expect: 31789372997 : Valid Unknown" << endl;
     cout << "Result: ";
     printCardInfo("31789372997");
 }
