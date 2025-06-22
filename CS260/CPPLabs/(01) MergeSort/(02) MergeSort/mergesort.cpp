#include <iostream>

using namespace std;

//-------------------------------------------------
// Put your mergeFunc here!
//-------------------------------------------------

/**
 * @brief mergeSortInternal Recursive merge sort function
 * @param arr Array of ints to sort
 * @param low Index we should start sort at (inclusive)
 * @param high Index we should sort up to (inclusive)
 * @param temp Extra array that will be used to merge
 *
 * Note: we take temp in to avoid consantly allocating/deallocating
 * new arrays
 */

void mergeFunc(int arr[], int low, int mid, int high, int temp[]) {
  int i = low;     // Index for the first half
  int j = mid + 1; // Index for the second half
  int k = 0;       // Index for the temporary array

  // Merge the two halves into temp
  while(i <= mid && j <= high) {
    if(arr[i] <= arr[j]) {
      temp[k++] = arr[i++];
    } else {
      temp[k++] = arr[j++];
    }
  }

  // If the first half has remaining elements, copy them to temp
  while(i <= mid) {
    temp[k++] = arr[i++];
  }

  // If the second half has remaining elements, copy them to temp
  while(j <= high) {
    temp[k++] = arr[j++];
  }

  // Copy the merged elements from temp back to arr
  for(int p = 0; p < k; p++) {
    arr[low + p] = temp[p];
  }
}

void mergeSortInternal(int arr[], int low, int high, int temp[]) {
  if(low >= high)
    return;

  // Calculate mid index
  int mid = low + (high - low) / 2;

  // Recursively sort first half
  mergeSortInternal(arr, low, mid, temp);

  // Recursively sort second half
  mergeSortInternal(arr, mid + 1, high, temp);

  // Merge the sorted halves
  mergeFunc(arr, low, mid, high, temp);
}

/**
 * @brief mergeSort Sorts the given array by building a temporary array
 * and then calling the recursive mergeSortInternal
 */
void mergeSort(int arr[], int arrSize) {
  int* temp = new int[arrSize];
  mergeSortInternal(arr, 0, arrSize - 1, temp);
  delete[] temp;
}