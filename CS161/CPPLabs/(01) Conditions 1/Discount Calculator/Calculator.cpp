/**
 * @author claytonmoeck
 * @brief Discount Calculator
 */

#include <iostream>

using namespace std;

int main()
{
  double price;
  cin >> price;

  if (price < 100)
  cout << price;

  if (price >= 100)
  cout << price * 0.9;

  return 0;
}