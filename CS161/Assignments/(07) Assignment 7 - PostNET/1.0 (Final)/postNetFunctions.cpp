#include "postNetFunctions.h"
#include <string>
#include <cstring>
#include <iostream>

/**
 * @brief Finds the string of the zip code.
 * @param firstComma Finds the first comma string.
 * @param secondComma Finds the second comma string.
 * @param zipcodeFinal Finds the zipcode by substringing "zipcode" at start position "secondComma".
 * @return "zipcodeFinal" returns to whichever function called it.
*/
std::string getZipcode(std::string zipcode)
{
    std::size_t firstComma = zipcode.find(',');
    std::size_t secondComma = zipcode.find(',', firstComma + 1);
    std::string zipcodeFinal = zipcode.substr(secondComma + 1);

    return zipcodeFinal;
}


/**
 * @brief Finds the string of the zip code.
 * @param firstComma Finds the first comma string.
 * @param secondComma Finds the second comma string.
 * @param stateInitialFinal Finds the state initial by substringing "initials" at start position "fistComma" and finishing at the length value of "secondComma".
 * @return "stateInitialFinal" returns to whichever function called it.
*/
std::string getStateIn(std::string initials)
{
    std::size_t firstComma = initials.find(',');
    std::size_t secondComma = initials.find(',', firstComma + 1);
    std::string stateInitialsFinal = initials.substr(firstComma + 1, secondComma - firstComma - 1);
    
    return stateInitialsFinal;
}

/**
 * @brief Finds just the string of city from "fullCity".
 * @param cityNamed is the final result, and it is found by substringing at initial point "0",
 *        up to "firstComma".
 * @return "cityNamed" returns to whichever function called it.
*/
std::string getCityName(std::string fullCity)
{
    std::size_t firstComma = fullCity.find(',');
    std::string cityNamed = fullCity.substr(0, firstComma);

    return cityNamed;
}

/**
 * @brief This is the "hub" for the "fullCity" string. Here, 3 separate functions are called,
 *        each finding their own piece of information needed for city.
 * @param name value is gathered from function "getCityName"
 * @param state value is gathered from function "getStateIn"
 * @param zipcode value is gathered from function "getZipcode"
 * @param separatedString made by combining the strings of "name" "state" and "zipcode" together.
 * @return "separatedString" returns to whichever function called it
*/
std::string seperateString(std::string fullString)
{
    std::string name = getCityName(fullString);
    std::string state = getStateIn(fullString);
    std::string zipcode = getZipcode(fullString);
    std::string separatedString = name + ", " + state + " " + zipcode;

    return separatedString;
}

/**
 * @brief Finds out whether the zipcode is a 5 digit or 9 digit.
 * @param length The size of variable "zipcode".
 * @param zip1 Found by substringing "zipcode" from position 0 to dash.
 * @param zip2 Found by substringing "zipcode" from the position of dash + 1 to the end.
 * @param zipcode zip1 and zip2 combine into a single zipcode.
 * @return "zipcode" returns to whichever function called it.
*/
std::string containsDash(std::string zipcode)
{
    int length = zipcode.size();
    if (length > 5)
    {
        std::size_t dash = zipcode.find('-');
        std::string zip1 = zipcode.substr(0, dash);
        std::string zip2 = zipcode.substr(dash + 1);

        zipcode = zip1 + zip2;

        return zipcode;
    }

    else
        return zipcode;
}


/**
 * @brief case switch function for postNET values.
 * @param result postNet number.
 * @return "result" returns to whichever function called it.
*/
std::string postNetValues(int num)
{
    std::string result;

    switch (num)
    {
        case 0:
            result = "11000";
            break;
        case 1:
            result = "00011";
            break;
        case 2:
            result = "00101";
            break;
        case 3:
            result = "00110";
            break;
        case 4:
            result = "01001";
            break;
        case 5:
            result = "01010";
            break;
        case 6:
            result = "01100";
            break;
        case 7:
            result = "10001";
            break;
        case 8:
            result = "10010";
            break;
        case 9:
            result = "10100";
            break;
    }

    return result;
}

/**
 * @brief Simple variable digit to ASCII converter.
 * @param number result of digit - ASCII '0'.
 * @return "number" returns to whichever function called it
*/
int charToInt(char digit)
{
    int number = digit - '0';

    return number;
}

/**
 * @brief postNET Number calculator.
 * @param length size of the variable "zipcode".
 * @param postNetNum string for the postNET number. Starts with "1".
 * @param digit found by finding the value of "zipcode[i]".
 * @param num ASCII converted number.
 * @param postNetValue postNET of a ASCII number..
 * @param postNetNum concatenated with "postNetValue" constantly. Finishes with "1" concatenated at the end.
 * @return "postNetNum" returns to the function that called it.
*/
std::string postNetNumber(std::string zipcode)
{
    int length = zipcode.size();
    std::string postNetNum = "1";

    for (int i = 0; i < length; i += 1)
    {
        char digit = zipcode[i];
        int num = charToInt(digit);
        std::string postNetValue = postNetValues(num);
        postNetNum += postNetValue;
    }

    postNetNum += "1";

    return postNetNum;
}

/**
 * @brief Central Hub function to print off city information.
 * @param fullCity string that was information gathered from "seperateString" function.
 * @param zipcode separately available zipcode from "getZipCode" function.
 * @param postNet value determined by result of "zipcode" going into "postNetNumber" function.
 * @param fullDetails a string value that is oncatenated together by the strings "fullCity" and "postNet", and separated by "\n".
 * @return "fullDetails" is returned to whichever function called it.     
*/
std::string printCity(std::string city)
{
    std::string fullCity = seperateString(city);
    std::string zipcode = getZipcode(city);
    zipcode = containsDash(zipcode);
    std::string postNet = postNetNumber(zipcode);

    std::string fullDetails = fullCity + "\n" + postNet;

    return fullDetails;
}