#include "ArrayPointer.h"
#include "LinkedList.h"
#include <iostream>

ArrayPointer::ArrayPointer() {
    capacity = 10;
    size = 0;
    arr = new Node*[capacity];
}

void ArrayPointer::growArray() {
    capacity *= 2;
    Node** newArr = new Node*[capacity];

    for (int i = 0; i < size; i++) {
        newArr[i] = arr[i];
    }
    delete[] arr;
    arr = newArr;
}

ArrayPointer::ArrayPointer(const LinkedList& list) {
    capacity = 10;
    size = 0;
    arr = new Node*[capacity];

    Node* current = list.head;
    while (current != nullptr) {
        if (size >= capacity) {
            growArray();
        }
        arr[size] = current;
        size++;
        current = current->next;
    }
}

int ArrayPointer::getSize() {
    return size;
}

int ArrayPointer::getItem(int index) {
    return arr[index]->data;
}