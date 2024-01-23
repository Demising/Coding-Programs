/**
 * @author Demising
 * @brief test3
 */

#include <iostream>

using namespace std;

int main()
{ 
  double highestNum, number;
  highestNum = 0;

  cout << "Please enter 15 numbers" << endl;
  for (int i = 0; i < 15; i++)
  {
    cin >> number;
    if (number > highestNum)
      highestNum = number;
  }

  cout << "Highest number is: " << highestNum << endl;

  return 0;
}