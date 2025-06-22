#include "DoublyLinkedList.h"

// Constructor here!!!

template <class T>
DoublyLinkedList<T>::DoublyLinkedList() {
  // TODO - make dummy nodes, attach to each other
  head = new ListNode<T>(); // Dummy head
  tail = new ListNode<T>(); // Dummy tail

  // Connect dummy nodes to each other
  head->next = tail;
  tail->prev = head;

  // Initialize other variables
  length = 0;
}

template <class T>
void DoublyLinkedList<T>::insertAt(int index, const T& value) {
  if(index > length || index < 0)
    throw out_of_range("Bad index in insertAt");

  // Create a new node with the given value
  ListNode<T>* newNode = new ListNode<T>(value);

  // Traverse the list to the desired index
  ListNode<T>* current = head;
  for(int i = 0; i < index; ++i) {
    current = current->next;
  }

  // Insert the new node
  newNode->next = current->next;
  newNode->prev = current;
  current->next->prev = newNode;
  current->next = newNode;

  // Increment the length of the list
  length++;
}