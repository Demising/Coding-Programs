/**
 * @author Demising
 * @brief test1
 */

#include <iostream>

using namespace std;

int main()
{ 
  char status;
  int grade;
  cin >> status >> grade;

  if (status == 'M')
    {
      if (grade > 0 && grade <= 69)
        cout << "Letter grade is F" << endl;
      else if (grade < 90)
        cout << "Letter grade is C" << endl;
      else if (grade <= 100)
        cout << "Letter grade is A" << endl;
      else
        cout << "Invalid Input" << endl;
      
      return 0;
    }
  
  else if (status == 'N')
    {
      if (grade > 0 && grade <= 59)
        cout << "Letter grade is F" << endl;
      else if (grade < 85)
        cout << "Letter grade is C" << endl;
      else if (grade <= 100)
        cout << "Letter grade is A" << endl;
      else
        cout << "Invalid input" << endl;
      
      return 0;
    }
  else 
    cout << "Invalid input" << endl;

  return 0;
}