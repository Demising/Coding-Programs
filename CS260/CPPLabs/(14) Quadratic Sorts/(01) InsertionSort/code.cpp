#include <iostream>
#include <utility> //for std::swap

using namespace std;

void insertionSort(int arr[], int arrSize) {
  for(int i = 1; i < arrSize; ++i) {
    int j = i;
    while(j > 0 && arr[j] < arr[j - 1]) {
      std::swap(arr[j], arr[j - 1]);
      --j;
    }
  }
}