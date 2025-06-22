#include "LinkedList.h"

template <class T>
void LinkedList<T>::insertEnd(const T& value) {
  // TODO - Fixme
  ListNode<T>* newNode =
      new ListNode<T>(value); // Create a new node with the given value

  if(head == nullptr) {
    // If the list is empty, set both head and tail to the new node
    head = newNode;
    tail = newNode;
  } else {
    // If the list is not empty, append the new node to the end and update tail
    tail->next = newNode;
    tail = newNode;
  }

  length++; // Increment the length of the list
}
