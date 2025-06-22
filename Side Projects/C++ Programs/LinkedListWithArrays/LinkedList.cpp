#include "LinkedList.h"
#include "ArrayPointer.h"
#include <iostream>


LinkedList::LinkedList() {
    head = nullptr;
    tail = nullptr;
    size = 0;
}

LinkedList::LinkedList(const LinkedList& other) {
    head = nullptr;
    tail = nullptr;
    size = 0;

    Node* current = other.head;
    while (current != nullptr) {
        addNode(current->data);
        current = current->next;
    }
}

LinkedList::~LinkedList() {
    Node* current = head;
    Node* next = nullptr;
    while (current != nullptr) {
        next = current->next;
        delete current;
        current = next;
    }
}

void LinkedList::addNode(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;
    newNode->prev = nullptr;

    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    size++;
}

void LinkedList::deleteNode(int data) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data == data) {
            if (current->prev != nullptr) {
                current->prev->next = current->next;
            } else {
                head = current->next;
            }
            if (current->next != nullptr) {
                current->next->prev = current->prev;
            } else {
                tail = current->prev;
            }
            delete current;
            size--;
            return;
        }
        current = current->next;
    }
}

void LinkedList::printList() {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int LinkedList::getSize() {
    return size;
}