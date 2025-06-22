#include <iostream>

using namespace std;

/**
 * @brief partitionFunct partitions a range in array and returns pivot location
 * @param arr array to partition
 * @param low index to start the partition at (inclusive)
 * @param high index to end the partition at (inclusive)
 * @return pivot final index of pivot value
 *
 * @post
 * for all i < p, arr[i] <= arr[p]
 * for all i > p, arr[i] >= arr[p]
 * where p is index of pivot value
 */
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