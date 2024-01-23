/**
 * @author Demising
 * @brief test2
 */

#include <iostream>

using namespace std;

int main()
{ 
  double number;
  double numberSum;
  cin >> number;

  numberSum = number;

  while (numberSum < 100)
  {
    cout << numberSum << " ";
    numberSum += number;
  }
}