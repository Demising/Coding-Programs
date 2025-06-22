/**
 * @author Clayton Moeck
 * @brief LinkedListsWArrays
 */

#include <iostream>
#include "LinkedList.h"
#include "ArrayPointer.h"

using namespace std;

int main() { 
    cout << "--------------------Section 1--------------------" << endl;

    LinkedList list;
    for (int i = 1; i <= 5; i++) {
        list.addNode(i * 5);
    }

    cout << "Contents of Linked List: ";
    list.printList();
    cout << "Size of Linked List: " << list.getSize() << endl;

    cout << "--------------------Section 2--------------------" << endl;

    LinkedList listb(list);

    cout << "Contents of Linked List B: ";
    listb.printList();
    cout << "Size of Linked List B: " << listb.getSize() << endl;

    listb.deleteNode(15);
    cout << "New Contents of Linked List B: ";
    listb.printList();
    cout << "Size of Linked List B: " << listb.getSize() << endl;

    cout << "--------------------Section 3--------------------" << endl;

    ArrayPointer arr(list);
    cout << "Contents of Array Pointer: ";
    for (int i = 0; i < arr.getSize(); i++) {
        if (i == arr.getSize() - 1) { 
            cout << arr.getItem(i) << endl;
        } else {
            cout << arr.getItem(i) << " ";
        }
    }

    cout << "--------------------Section 4--------------------" << endl;
    LinkedList listc(list);
    ArrayPointer arr2(list);

    cout << "Contents of List C: ";
    listc.printList();

    cout << "Contents of Array Pointer 2: ";
    for (int i = 0; i < arr.getSize(); i++) {
        if (i == arr.getSize() - 1) { 
            cout << arr.getItem(i) << endl;
        } else {
            cout << arr.getItem(i) << " ";
        }
    }

    listc.deleteNode(25);

    cout << "Contents of List C After Delete: ";
    listc.printList();
    
    cout << "Contents of Array Pointer 2 After Delete: ";
    for (int i = 0; i < arr.getSize(); i++) {
        if (i == arr.getSize() - 1) { 
            cout << arr.getItem(i) << endl;
        } else {
            cout << arr.getItem(i) << " ";
        }
    }
}