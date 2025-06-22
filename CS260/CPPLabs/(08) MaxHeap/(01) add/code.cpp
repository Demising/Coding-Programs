#include "MaxHeap.h"
#include <cmath>

using namespace std;

template <typename T>
void MaxHeap<T>::add(const T& value) {
  if(heapSize == capacity)
    grow(); // Assuming you have implemented the grow() function to increase the
            // capacity of the heap if necessary

  // Add the new element to the bottom of the heap
  data[heapSize] = value;
  int currentIndex = heapSize;
  heapSize++;

  // Swap with parent as long as necessary
  while(currentIndex > 0 && data[currentIndex] > data[(currentIndex - 1) / 2]) {
    swap(data[currentIndex], data[(currentIndex - 1) / 2]);
    currentIndex = (currentIndex - 1) / 2;
  }
}