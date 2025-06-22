#include "Queue.h"

template <class T>
void Queue<T>::enqueue(const T& value) {
  if(full()) {
    grow();
  }

  list[end] = value;
  end++;
  if(end >= arraySize) {
    end = 0;
  }
}

template <class T>
T Queue<T>::dequeue() {
  if(empty()) {
    throw out_of_range("Dequeue on empty queue");
  }

  T value = list[start];
  start = (start + 1) % arraySize; // Update start using modular arithmetic
  return value;
}

template <class T>
bool Queue<T>::full() const {
  // Queue is full if end is just before start (circular), taking into account
  // wrap-around
  return ((end + 1) % arraySize) == start;
}

template <class T>
void Queue<T>::grow() {
  int newSize = arraySize * 2;
  T* newArray = new T[newSize]; // Allocate new storage

  // Copy existing elements to the new array
  int index = 0;
  while(!empty()) {
    newArray[index++] = dequeue();
  }

  // Update variables
  delete[] list; // Clean up old storage
  list = newArray;
  arraySize = newSize;
  start = 0;
  end = index; // Update end to reflect the new position after copying elements
}
