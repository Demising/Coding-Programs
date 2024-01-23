/**
 * @author CM
 * @brief test7
 */

#include <iostream>

using namespace std;

int main() { 
  const int size = 4;
  int nums[size] = {5, 2, 7, 9};
  int reverse[size];


  for (int i = 0; i < size; i++) {
    reverse[i] = nums[size - 1 - i];
  }

  for (int i = 0; i < size; i++) {
    cout << nums[i] << " ";
  }

  cout << endl;

  for (int i = 0; i < size; i++) {
    cout << reverse[i] << " ";
  }

}