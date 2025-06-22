#include <iostream>

using namespace std;

/**
 * @brief mergeFunc Merge two consecutive sorted ranges within an
 * array into one sorted range
 *
 * @param arr Array with sorted ranges
 * @param low Index of start of first range (inclusive)
 * @param mid Index of end of first range (inclusive - this is part of first
 * range)
 * @param high Index of end of second range (inclusive)
 * @param temp Array to copy values into
 *
 * @pre
 * a[low]-a[mid] are sorted
 * a[mid+1]-a[high] are sorted
 * @post
 * a[low]-a[high] are sorted
 *
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