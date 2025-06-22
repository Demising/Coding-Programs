#include "LinkedList.h"

// Add your clear() function here

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

template <class T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& other) {
  if(this != &other) {
    // Clear the current contents of the list
    clear();

    // Initialize head, tail, and length for the new list
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
  // Return a reference to the current object
  return *this;
}