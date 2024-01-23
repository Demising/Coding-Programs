/**
 * @author CM
 * @brief test2F
 */

#include <iostream>

using namespace std;

int main() { 
  const int sizeA = 4;
  const int sizeB = 6;

  int data[sizeA][sizeB] = { {2, 3, 4, 5, 2, 2}, {3, 3, 3, 3, 4, 3,}, {4, 4, 4, 4, 4, 4}, {5, 5, 5, 4, 4, 4}};

  for (int i = 0; i < sizeA; i++) {
    int firstValue = data[i][0];
    cout << firstValue << " ";
    int tempValue = data[i][0];
    for (int j = 0; j < sizeB; j++) {
      if (data[i][0] != data[i][j] && tempValue != data[i][j]) {
        tempValue = data[i][j];
        cout << data[i][j] << " ";
      }
    }
    cout << endl;
  }
}