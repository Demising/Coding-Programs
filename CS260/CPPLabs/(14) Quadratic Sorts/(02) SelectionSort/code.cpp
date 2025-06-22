#include <iostream>
#include <utility> //for std::swap

using namespace std;

void selectionSort(int arr[], int arrSize) {
  // TODO - fixme
  for(int i = 0; i < arrSize - 1; ++i) {
    int minIndex = i;
    // int lastIndex = ((arrSize - 1) - i);
    for(int j = i + 1; j < arrSize; ++j) {
      if(arr[j] < arr[minIndex]) {
        minIndex = j;
      }
    }
    if(minIndex != i) {
      std::swap(arr[i], arr[minIndex]);
    }
  }
}
