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