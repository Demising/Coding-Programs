/**
 * @author ClaytonMoeck
 * @brief ConditionalScorer
 */

#include <iostream>

using namespace std;

int main()
{ 
  srand(time(0));
  int number1 = rand() % 6 + 1;
  int number2 = rand() % 6 + 1;
  cout << number1 << number2 << endl;

  if (number1 == number2)
  {
    int total = (number1 + number2) * 2;
    cout << total;
  }
  else
  {
    int total = (number1 + number2);
    cout << total;
  }

  return 0;
}