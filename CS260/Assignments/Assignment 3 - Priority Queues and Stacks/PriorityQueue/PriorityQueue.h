//----------------------------------------------------------
// CS260 Assignment 3 Starter Code
// Copyright Andrew Scholer (ascholer@chemeketa.edu)
// Neither this code, nor any works derived from it
//    may not be republished without approval.
//----------------------------------------------------------

#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include <iostream>

template<typename T>
class PriorityQueue {
private:
  T* data;       // array containing the heap
  int capacity;  // maximum size
  int queueSize; // current logical size

  // Double the size of the underlying array
  void grow();

public:
  // Get a copy of the top item
  T getMax();

  // Rmove the top item and return it
  T removeMax();

  // Add the given value to the heap
  void add(const T& value);

  // Construct a max heap with initial space for 32 items
  PriorityQueue();

  // Destroy the max heap and release memory
  ~PriorityQueue();

  // You do not need to implement copy ctor and assignment operator
  //  Declared to prevent accidental use of defaults
  PriorityQueue(const PriorityQueue& other);
  PriorityQueue& operator=(const PriorityQueue& other);


  T getValue(int index);

  bool isEmpty();
};

template<typename T>
PriorityQueue<T>::PriorityQueue() {
  capacity = 32;
  queueSize = 0;
  data = new T[capacity];
}

template<typename T>
PriorityQueue<T>::PriorityQueue(const PriorityQueue& other) {
  capacity = other.capacity;
  queueSize = other.queueSize;
  data = new T[capacity];
  for (int i = 0; i < queueSize; i++) {
    data[i] = other.data[i];
  }
}

template<typename T>
PriorityQueue<T>& PriorityQueue<T>::operator=(const PriorityQueue& other) {
  if (this != &other) {
    delete[] data;
    capacity = other.capacity;
    queueSize = other.queueSize;
    data = new T[capacity];
    for (int i = 0; i < queueSize; i++) {
      data[i] = other.data[i];
    }
  }
  return *this;
}

template<typename T>
PriorityQueue<T>::~PriorityQueue() {
  delete[] data;
}

template<typename T>
T PriorityQueue<T>::getValue(int index) {
  return data[index];
}

template<typename T>
void PriorityQueue<T>::grow() {
  T* newData = new T[capacity * 2];
  for (int i = 0; i < queueSize; i++) {
    newData[i] = data[i];
  }
  delete[] data;
  data = newData;
  capacity *= 2;
}

template<typename T>
T PriorityQueue<T>::getMax() {
  if (queueSize == 0) {
    throw std::out_of_range("Queue is empty");
  }
  return data[0];
}

template<typename T>
T PriorityQueue<T>::removeMax() {
  if (queueSize == 0) {
    throw std::out_of_range("Queue is empty");
  }
  T max = data[0];
  data[0] = data[queueSize - 1];
  queueSize--;
  int i = 0;
  while (i < queueSize) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int largest = i;
    if (left < queueSize && data[left] > data[largest]) {
      largest = left;
    }
    if (right < queueSize && data[right] > data[largest]) {
      largest = right;
    }
    if (largest == i) {
      break;
    }
    std::swap(data[i], data[largest]);
    i = largest;
  }
  return max;
}

template<typename T>
bool PriorityQueue<T>::isEmpty() {
  return queueSize == 0;
}

template<typename T>
void PriorityQueue<T>::add(const T& value) {
  if (queueSize == capacity) {
    grow();
  }
  data[queueSize] = value;
  int i = queueSize;
  queueSize++;
  while (i > 0 && data[i] > data[(i - 1) / 2]) {
    std::swap(data[i], data[(i - 1) / 2]);
    i = (i - 1) / 2;
  }
}
#endif // PRIORITYQUEUE_H
