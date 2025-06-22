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

template <class T>
LinkedList<T>::LinkedList(const LinkedList<T>& other) {
  head = nullptr;
  tail = nullptr;
  length = 0;

  // Iterate over each node in the other list
  ListNode<T>* current = other.head;
  while(current != nullptr) {
    // Create a new node with the same data as the current node in the other
    // list
    ListNode<T>* newNode = new ListNode<T>(current->data);

    // If the new list is empty, set both head and tail to the new node
    if(head == nullptr) {
      head = newNode;
      tail = newNode;
    } else {
      // Otherwise, append the new node to the end of the new list
      tail->next = newNode;
      tail = newNode;
    }

    // Move to the next node in the other list
    current = current->next;

    // Increment the length of the new list
    length++;
  }
}