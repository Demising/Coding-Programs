#include <string>
#include <cstring>
#include <iostream>

#ifndef inZip
#define inZip
std::string getZipcode(std::string zipcode);
#endif

#ifndef stateIn
#define stateIn
std::string getStateIn(std::string cityRemain);
#endif

#ifndef cityName
#define cityName
std::string getCityName(std::string fullCity);
#endif

#ifndef pCity
#define pCity
std::string printCity(std::string city);
#endif

#ifndef sepString
#define sepString
std::string seperateString(std::string fullString);
#endif

#ifndef pnn
#define pnn
std::string postNetNumber(std::string zipcode);
#endif

#ifndef cti
#define cti
int charToInt(char digit);
#endif

#ifndef pnv
#define pnv
std::string postNetValues(int num);
#endif

#ifndef cd
#define cd
std::string containsDash(std::string zipcode);
#endif