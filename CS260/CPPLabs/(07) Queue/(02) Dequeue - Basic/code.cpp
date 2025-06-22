#include "Queue.h"

template <class T>
void Queue<T>::enqueue(const T& value) {
  if(full()) {
    grow();
  }

  list[end] = value;
  end++;
}

template <class T>
T Queue<T>::dequeue() {
  if(empty()) {
    throw out_of_range("Dequeue on empty queue");
  }

  T value = list[start];
  start++;
  return value;
}