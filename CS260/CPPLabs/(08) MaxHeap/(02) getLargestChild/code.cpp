#include "MaxHeap.h"
#include <cmath>

using namespace std;

template <typename T>
int MaxHeap<T>::largestChildIndex(int current) const {
  int leftChildIndex = 2 * current + 1; // Calculate the index of the left child
  int rightChildIndex =
      2 * current + 2; // Calculate the index of the right child

  // Check if the left child exists
  if(leftChildIndex < heapSize) {
    // If the right child exists
    if(rightChildIndex < heapSize) {
      // Compare values of left and right children
      if(data[leftChildIndex] > data[rightChildIndex]) {
        return leftChildIndex; // Return index of the larger child
      } else {
        return rightChildIndex; // Return index of the larger child
      }
    } else {
      return leftChildIndex; // Only left child exists, return its index
    }
  } else {
    return -1; // No valid children, return -1
  }
}