//----------------------------------------------------------
// CS260 Assignment 2 Starter Code
// Copyright Andrew Scholer (ascholer@chemeketa.edu)
// Neither this code, nor any works derived from it
//    may not be republished without approval.
//----------------------------------------------------------

#include "AddressLinkedList.h"
#include <sstream>
#include <exception>
#include <stdexcept>

#include <iostream>

using namespace std;
AddressListNode::AddressListNode() {
    next = nullptr;
    //data will be default initialized
}

AddressListNode::AddressListNode(const Address& value)
    : data(value)
{
    next = nullptr;
}

AddressLinkedList::AddressLinkedList() {
    head = nullptr;
    tail = nullptr;
    length = 0;
}

AddressLinkedList::AddressLinkedList(const AddressLinkedList& other) {
    head = nullptr;
    tail = nullptr;
    length = 0;
    AddressListNode* current = other.head;
    while(current != nullptr) {
        insertEnd(current->data);
        current = current->next;
    }
}

AddressLinkedList::~AddressLinkedList() {
    AddressListNode* current = head;
    while(current != nullptr) {
        AddressListNode* next = current->next;
        delete current;                    
        current = next;                    
    }
    head = nullptr; 
    tail = nullptr; 
    length = 0;     
}

void AddressLinkedList::combine(AddressLinkedList& otherList) {
    if (otherList.head == nullptr) {
        return;
    }
    if (head == nullptr) {
        head = otherList.head;
        tail = otherList.tail;
    } else {
        tail->next = otherList.head;
        tail = otherList.tail;
    }
    length += otherList.length;
    otherList.head = nullptr;
    otherList.tail = nullptr;
    otherList.length = 0;
}

int AddressLinkedList::listSize() const {
    return length;
}

void AddressLinkedList::insertEnd(const Address& value) {
    AddressListNode* newNode = new AddressListNode(value);
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
    length++;
}

Address AddressLinkedList::retrieveAt(int index) const {
    if(index < 0 || index >= length) {
        //build up error message...
        //other functions use simple string literal
        std::stringstream message;
        message << "Invalid index: " << index << " in list of length " << length;
        throw std::out_of_range(message.str());
    }
    AddressListNode* current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    return current->data;
}

void AddressLinkedList::printRange(int startIndex, int endIndex) const {
    AddressListNode* current = head;
    if (startIndex < 0 || startIndex >= length || endIndex < 0 || endIndex >= length) {
        throw std::out_of_range("Invalid index");
    }

    if (startIndex == 0) {
        for (int i = startIndex; i <= endIndex; i++) {
            cout << current->data;
            current = current->next;
        }
    } else {
        for (int i = 0; i < startIndex; i++) {
            current = current->next;
        } for (int i = startIndex; i <= endIndex; i++) {
            cout << current->data;
            current = current->next;
        }
    }
}

AddressLinkedList AddressLinkedList::extractAllMatches(const Address& itemToMatch) {
    AddressLinkedList stateMatches;
    AddressListNode* current = head;
    AddressListNode* previous = head;

    while (current != nullptr) {
        if (current->data.state == itemToMatch.state) {
            AddressListNode* toDelete = current;
            stateMatches.insertEnd(current->data);
            if (current == head) {
                current = current->next;
                previous = current;
                head = current;
                delete toDelete;
            } else if (current == tail) {
                tail = previous;
                current = previous;
                delete toDelete;
                current->next = nullptr;
                previous->next = nullptr;
            } else {
                current = current->next;
                previous->next = current;
                delete toDelete;
            }
            length--;
        } else {
            previous = current;
            current = current->next;
        }
    }

    return stateMatches;
}

// Make otherList be empty after this operation
void AddressLinkedList::interleave(AddressLinkedList& other) {
    if (other.head == nullptr) {
        return;
    } else if (head == nullptr) {
        head = other.head;
        tail = other.tail;
    } else {
        AddressListNode* current = head;
        AddressListNode* otherCurrent = other.head;
        AddressListNode* next = current->next;
        AddressListNode* otherNext = otherCurrent->next;
        while (current != nullptr && otherCurrent != nullptr) {
            current->next = otherCurrent;
            otherCurrent->next = next;
            current = next;
            otherCurrent = otherNext;
            if (next != nullptr) {
                next = next->next;
            }
            if (otherNext != nullptr) {
                otherNext = otherNext->next;
            }
        }
        if (otherCurrent != nullptr) {
            tail = other.tail;
        }
    }
    length += other.length;
    other.head = nullptr;
    other.tail = nullptr;
    other.length = 0;
}
