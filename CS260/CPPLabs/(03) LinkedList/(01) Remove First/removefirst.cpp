#include "LinkedList.h"

template <class T>
void LinkedList<T>::removeFirst() {
  if(head == nullptr)
    throw out_of_range("Can't remove from empty list");

  ListNode<T>* temp = head; // Store the current head
  head = head->next;        // Move head to the next node
  delete temp;              // Delete the old head
  length--;                 // Update the length of the list

  // If head is now nullptr, the list is empty, so tail should also be nullptr
  if(head == nullptr)
    tail = nullptr;
  // TODO - Remove first item in list
}