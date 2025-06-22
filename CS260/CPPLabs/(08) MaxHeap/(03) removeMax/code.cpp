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

template <typename T>
T MaxHeap<T>::removeMax() {
  if(heapSize == 0)
    throw std::logic_error("removeTop in empty heap");

  // Save the max value to return it later
  T maxItem = data[0];

  // Swap the first and last elements
  std::swap(data[0], data[heapSize - 1]);

  // Reduce the size of the heap
  heapSize--;

  // Percolate down the first element (now potentially violating the heap
  // property)
  int current = 0;
  int childIndex =
      largestChildIndex(current); // Find the index of the largest child

  while(childIndex != -1 && data[current] < data[childIndex]) {
    std::swap(data[current], data[childIndex]); // Swap with the largest child
    current = childIndex;                       // Update current index
    childIndex = largestChildIndex(
        current); // Find the index of the largest child of the new current
  }

  return maxItem; // Return the removed maximum value
}
