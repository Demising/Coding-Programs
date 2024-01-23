/**
 * @author Clayton Moeck
 * @brief CallCalculator
 */

#include <iostream>

using namespace std;

int main()
{ 
  int duration;
  cin >> duration;

  if (duration <= 10)
  {
    double cost = 5;
    cout << cost;
  }
  else if (duration <= 30)
  {
    double cost = duration * 0.5;
    cout << cost;
  }
  else if (duration > 30)
  {
    double cost = 15 + ((duration - 30) * .3);
    cout << cost;
  }

}