/**
 * @author t
 * @brief t
 */

#include <iostream>

using namespace std;

struct rectangle
{
  double width;
  double length;
  double area;
  double perimeter;
};

int main() { 
  int matrix[3][2];

  for (int j = 0; j < 3; j++) {
    for (int k = 0; k < 2; k++) {
      matrix[j][k] = j + k;
    }
  }

  for (int j = 0; j < 3; j++) {
    for (int k = 0; k < 2; k++) {
      cout << matrix[j][k] << " ";
    }
  }
}