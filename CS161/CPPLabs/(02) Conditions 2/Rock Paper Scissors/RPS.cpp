/**
 * @author Clayton Moeck
 * @brief RPS
 */

#include <iostream>

using namespace std;

int main()
{ 
  srand(time(0));
  int player1 = rand() % 3 + 1;
  int player2 = rand() % 3 + 1;
  cout << player1 << " " << player2 << endl;

  if (player1 == player2)
    cout << "tie";
  else if (player1 == 3 && player2 == 2)
    cout << "A";
  else if (player1 == 2 && player2 == 1)
    cout << "A";
  else if (player1 == 1 && player2 == 3)
    cout << "A";
  else
    cout << "B";
}