#include "LinkedList.h"

template <class T>
void LinkedList<T>::clear() {
  ListNode<T>* current = head;
  while(current != nullptr) {
    ListNode<T>* next = current->next; // Store the next node
    delete current;                    // Delete the current node
    current = next;                    // Move to the next node
  }
  head = nullptr; // Update head pointer to nullptr
  tail = nullptr; // Update tail pointer to nullptr
  length = 0;     // Reset the length to 0
}