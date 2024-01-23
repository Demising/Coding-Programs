/**
 * @author Clayton Moeck
 * @brief Unit tests for assign7
 */

//-----------------------------------------------------------------------------------
//Bring in unit testing code and tell it to build a main function
//If you have multiple unit test files, only one should have this line
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
//#define

#include "doctest.h"
#include "postNetFunctions.h"
#include <string>
#include <cstring>
#include <iostream>

//Use Approx from doctest without saying doctest::Approx
using doctest::Approx;
//-----------------------------------------------------------------------------------

TEST_CASE( "test getCityName" )
{
    std::cout << "1: getCityName" << std::endl;

    CHECK( getCityName("Newport,OR,97365") == "Newport");
    CHECK( getCityName("Portland,OR,97212") == "Portland");
    CHECK( getCityName("Los Angeles,CA,90001") == "Los Angeles");
}

TEST_CASE( "test getStateIn" )
{
    std::cout << "2: getStateIn" << std::endl;

    CHECK( getStateIn("Newport,OR,97365") == "OR");
    CHECK( getStateIn("Portland,OR,97212") == "OR");
    CHECK( getStateIn("Los Angeles,CA,90001") == "CA");
}

TEST_CASE ( "test getZipcode" )
{
    std::cout << "3: getZipcode" << std::endl;

    CHECK( getZipcode("Newport,OR,97365") == "97365");
    CHECK( getZipcode("Portland,OR,97212") == "97212");
    CHECK( getZipcode("Los Angeles,CA,90001") == "90001");
}

TEST_CASE ( "test seperateString" )
{
    std::cout << "4: seperateString" << std::endl;

    CHECK( seperateString("Newport,OR,97365") == "Newport, OR 97365");
    CHECK( seperateString("Portland,OR,97212") == "Portland, OR 97212");
    CHECK( seperateString("Los Angeles,CA,90001") == "Los Angeles, CA 90001");
}

TEST_CASE( "test containsDash" )
{
    std::cout << "5: containsDash" << std::endl;

    CHECK( containsDash("68970") == "68970");
    CHECK( containsDash("97212") == "97212");
    CHECK( containsDash("78651-4976") == "786514976");
    CHECK( containsDash("99954-9001") == "999549001");
}

TEST_CASE( "test postNetValues" )
{
    std::cout << "6: postNetValues" << std::endl;

    CHECK( postNetValues(0) == "11000");
    CHECK( postNetValues(1) == "00011");
    CHECK( postNetValues(2) == "00101");
    CHECK( postNetValues(3) == "00110");
    CHECK( postNetValues(4) == "01001");
    CHECK( postNetValues(5) == "01010");
    CHECK( postNetValues(6) == "01100");
    CHECK( postNetValues(7) == "10001");
    CHECK( postNetValues(8) == "10010");
    CHECK( postNetValues(9) == "10100");
}

TEST_CASE( "test charToInt" )
{
    std::cout << "7: charToInt" << std::endl;

    CHECK( charToInt('4') == 4);
    CHECK( charToInt('7') == 7);
    CHECK( charToInt('3') == 3);
    CHECK( charToInt('9') == 9);
    CHECK( charToInt('4') == 4);
}

TEST_CASE( "test postNetNumber" )
{
    std::cout << "8: postNetNumber" << std::endl;

    CHECK( postNetNumber("76964") == "110001011001010001100010011");
    CHECK( postNetNumber("97458") == "110100100010100101010100101");
    CHECK( postNetNumber("44566") == "101001010010101001100011001");
    CHECK( postNetNumber("769647458") == "11000101100101000110001001100010100101010100101");
    CHECK( postNetNumber("947256479") == "11010001001100010010101010011000100110001101001");
    CHECK( postNetNumber("342567489") == "10011001001001010101001100100010100110010101001");
}

TEST_CASE( "test printCity" )
{
    std::cout << "9: Testing Full Details" << std::endl;

    CHECK( printCity("Newport,OR,97365") == "Newport, OR 97365\n110100100010011001100010101");
    CHECK( printCity("Portland,OR,97212") == "Portland, OR 97212\n110100100010010100011001011");
    CHECK( printCity("Los Angeles,CA,90001") == "Los Angeles, CA 90001\n110100110001100011000000111");
    CHECK( printCity("Colorado Springs,CO,80916-7815") == "Colorado Springs, CO 80916-7815\n11001011000101000001101100100011001000011010101");
}