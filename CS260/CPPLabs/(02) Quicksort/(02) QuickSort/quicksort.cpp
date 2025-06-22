#include <iostream>

using namespace std;

//-------------------------------------------------
int partitionFunct(int arr[], int low, int high) {
  int pivot = arr[low];

  // Set up i at low + 1, and j at high
  int i = low + 1, j = high;

  // While i and j have not crossed over
  while(i <= j) {
    // Until i is at something larger than pivot or passes j, increment it
    while(i <= j && arr[i] <= pivot) {
      i++;
    }
    // Until j is at something smaller than pivot or passes i, decrement it
    while(i <= j && arr[j] > pivot) {
      j--;
    }
    // If i and j have not crossed, swap those elements
    if(i < j) {
      int temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
    }
  }

  // Swap low and j to place pivot
  arr[low] = arr[j];
  arr[j] = pivot;

  // Return new location of pivot
  return j;
}
//-------------------------------------------------

/**
 * @brief quickSortInternal sorts itms between low and high with quicksort
 * @param arr array to sort
 * @param low start of range to sort (inclusive)
 * @param high end of range to sort (inclusive)
 */
void quickSortInternal(int arr[], int low, int high) {
  if(low >= high)
    return; // base case : 1 or less item

  // Call partitionFunction to partition range low - high
  int pivotIndex = partitionFunct(arr, low, high);

  // Recursively sort from low to pivot - 1
  quickSortInternal(arr, low, pivotIndex - 1);

  // Recursively sort from pivot + 1 to high
  quickSortInternal(arr, pivotIndex + 1, high);
}

void quickSort(int arr[], int arrSize) {
  quickSortInternal(arr, 0, arrSize - 1);
}
