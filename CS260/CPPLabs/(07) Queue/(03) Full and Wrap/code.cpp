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
  start++;
  if(start >= arraySize) {
    start = 0;
  }
  return value;
}

template <class T>
bool Queue<T>::full() const {
  /// TODO - fix this return true or false based on logic
  if(end == 7 && start == 0 || start - end == 1) {
    return true;
  }

  return false; // replace me
}