/**
 * @author Clayton Moeck
 * @brief GameRating
 */

#include <iostream>

using namespace std;

int main()
{ 
  int health1;
  int health2;
  cin >> health1;
  cin >> health2;

  if (health1 > health2 && health1 >= 10 && health2 <= 0)
    cout << "Crushing Win";
  else if (health1 > health2 && health1 < 10 && health1 > 0 && health2 <= 0)
    cout << "Win";
  else if (health1 < health2 && health1 <= 0 && health2 >= 10)
    cout << "Crushing Loss";
  else if (health1 < health2 && health1 <= 0 && health2 < 10 && health2 > 0)
    cout << "Loss";

  return 0;
}