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
void LinkedList<T>::insertAt(int index, const T& value) {
  if(index < 0 || index > length)
    throw out_of_range("Bad insert index");

  if(index == 0) {
    // Inserting at the beginning is equivalent to insertStart
    insertStart(value);
  } else if(index == length) {
    // Inserting at the end is equivalent to insertEnd
    insertEnd(value);
  } else {
    // Inserting at a specific index requires traversing the list to find the
    // position
    ListNode<T>* newNode =
        new ListNode<T>(value); // Create a new node with the given value

    // Find the node before the insertion point
    ListNode<T>* current = head;
    for(int i = 0; i < index - 1; i++) {
      current = current->next;
    }

    // Insert the new node after the node before the insertion point
    newNode->next = current->next;
    current->next = newNode;

    length++; // Increment the length of the list
  }

  // TODO - Insert value at given location of list
  // index 0 or length are special cases for insertStart/insertEnd
}