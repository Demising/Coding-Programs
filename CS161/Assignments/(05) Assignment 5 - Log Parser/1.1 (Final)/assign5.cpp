/**
 * @author Clayton Moeck
 * @brief assign5
 */

#include <iostream>
#include <fstream>

using namespace std;

int main()
{ 
  ifstream inFile;
  inFile.open("WebLog.txt");

  if(inFile.fail())
  {
    cout << "No file has been found. Please try again" << endl;
    return 0;
  }

  cout << "Name\t\t\tDate\t\tTime\t\tMinutes" << endl;

  string ipAddress, name, month, minutesSeconds;
  char dash, colon;
  double day, hours, minutes2;

  while(!inFile.eof())
  {
    inFile >> ipAddress >> name >> day >> dash >> month >> hours >> colon >> minutesSeconds >> minutes2;

    string::size_type colonLoc = minutesSeconds.find(':');
    string minutes = minutesSeconds.substr(0, colonLoc);

    string::size_type dashLoc = month.find('-');
    string year = month.substr(dashLoc + 1, string::npos);
    string monthName = month.substr(0, dashLoc);
    
    if (monthName == "Apr")
    {;
      if (hours >= 12)
      {
        if (hours > 12)
          hours = hours - 12;

        cout << name << " \t\t" << "4/" << day << "/" << year << "\t\t" << hours << colon << minutes << "PM" << "\t\t" << minutes2 << endl;
      }
      else
        cout << name << " \t\t" << "4/" << day << "/" << year << "\t\t" << hours << colon << minutes << "AM" << "\t\t" << minutes2 << endl;
    }
    
  }

  inFile.close();
  if(!inFile.fail())
    cout << "File has successfully closed" << endl;

}