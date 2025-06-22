#include "DoublyLinkedList.h"

// Constructor here!!!
#include "DoublyLinkedList.h"

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
void DoublyLinkedList<T>::removeEnd() {
  if(length == 0)
    throw out_of_range("List is empty, cannot remove from end");

  // Get the node before the current tail
  ListNode<T>* beforeTail = tail->prev;

  // Update pointers to skip over the current tail
  beforeTail->next =
      nullptr; // Update the next pointer of the node before tail to nullptr
  delete tail; // Delete the current tail

  // Update tail to point to the new last node
  tail = beforeTail;

  // Update length
  length--;
}
