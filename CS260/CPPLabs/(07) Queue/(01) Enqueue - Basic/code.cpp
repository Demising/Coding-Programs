#include "Queue.h"

template <class T>
void Queue<T>::enqueue(const T& value) {
  if(full()) {
    grow();
  }

  list[end] = value;
  end++;
}