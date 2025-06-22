//----------------------------------------------------------
// CS260 Assignment 2 Starter Code
// Copyright Andrew Scholer (ascholer@chemeketa.edu)
// Neither this code, nor any works derived from it
//    may not be republished without approval.
//----------------------------------------------------------
#include <iostream>
#include <ctime>

#include "Address.h"
#include "ArrayList.h"
#include "AddressArrayList.h"
#include "AddressLinkedList.h"

using namespace std;

int main()
{
    int size = 0;
    cout << "Enter problem size:" << endl;
    cin >> size;

    ArrayList<Address> aListA;
    ArrayList<Address> aListB;

    AddressFactory aFactory("25000AddressesA.txt");
    AddressFactory aFactory2("25000AddressesB.txt");

    for (int i = 0; i < size / 2; i++)
    {
        Address a = aFactory.getNext();
        aListA.insertEnd(a);
        Address a2 = aFactory2.getNext();
        aListB.insertEnd(a2);
    }
    cout << "aListA Length initially: " << aListA.listSize() << endl;
    cout << "aListB Length initially: " << aListB.listSize() << endl;

    // Testing to see what the output would be for a size of 4.
    // for (int i = 0; i < size / 2; i++) {
    //     cout << aListA.retrieveAt(i) << " " << aListB.retrieveAt(i) << endl;
    // }

    cout << "-----------------------------Section 1----------------------------" << endl;
    cout << "Applying the combine algorithm of ArrayList<Address>." << endl;
    // clock_t start = clock();
    aListA.combine(aListB);
    cout << "aListA Length: " << aListA.listSize() << endl;
    cout << "aListB Length: " << aListB.listSize() << endl;
    // clock_t end = clock();

    // cout << "Time to combine: " << (double)(end - start) / CLOCKS_PER_SEC << " seconds" << endl;
    // Tested with a size of 4 to make sure the combine function works.
    // for (int i = 0; i < size; i++) {
    //     cout << aListA.retrieveAt(i) << endl;
    // }

    printListRange(aListA, size / 2 - 2, size / 2 + 1);

    cout << "-----------------------------Section 2----------------------------" << endl;
    cout << "Applying the algorithm to extract all matches of a state from aListA." << endl;

    ArrayList<Address> aListC;
    int oregonArrayIndex = 0;
    clock_t start = clock();
    for (int i = 0; i < aListA.listSize(); i++)
    {
        if (aListA.retrieveAt(i).state == "OR")
        {
            break;
        }
        oregonArrayIndex++;
    }

    if (aListA.retrieveAt(oregonArrayIndex).state == "OR")
    {
        aListC = aListA.extractAllMatches(aListA.retrieveAt(oregonArrayIndex));
    }

    clock_t end = clock();
    cout << "Time to extract: " << (double)(end - start) / CLOCKS_PER_SEC << " seconds" << endl;
    cout << "aListA Length: " << aListA.listSize() << endl;
    cout << "aListC Length: " << aListC.listSize() << endl;

    printListRange(aListC, 0, 1);

    cout << "-----------------------------Section 3----------------------------" << endl;
    cout << "Creating the first set of linked lists for use later on." << endl;

    AddressFactory aLinkedFactory("25000AddressesA.txt");
    AddressFactory aLinkedFactory2("25000AddressesB.txt");
    AddressLinkedList linkedListA;
    AddressLinkedList linkedListB;

    for (int i = 0; i < size / 2; i++)
    {
        Address b = aLinkedFactory.getNext();
        linkedListA.insertEnd(b);
        Address b2 = aLinkedFactory2.getNext();
        linkedListB.insertEnd(b2);
    }

    cout << "Linked List A" << endl;
    linkedListA.printRange(2, 4);
    cout << "----" << endl;
    cout << "Linked List B" << endl;
    linkedListB.printRange(2, 4);

    cout << "-----------------------------Section 4----------------------------" << endl;
    cout << "Applying the combine algorithm of AddressLinkedList with two newly created lists copied from the original two, linkedListC and linkedListD." << endl;

    AddressLinkedList linkedListC(linkedListA);
    AddressLinkedList linkedListD(linkedListB);

    // cout << "Linked List C" << endl;
    // linkedListC.printRange(2, 4);
    // cout << "Linked List D" << endl;
    // linkedListD.printRange(2, 4);

    clock_t start1 = clock();
    linkedListC.combine(linkedListD);
    clock_t end1 = clock();
    cout << "Time to combine: " << (double)(end1 - start1) / CLOCKS_PER_SEC << " seconds" << endl;
    linkedListC.printRange(size / 2 - 2, size / 2 + 1);

    cout << "-----------------------------Section 5----------------------------" << endl;
    cout << "Applying the algorithm to extract all matches of a state from linkedListC." << endl;

    int firstOregonIndex = 0;

    clock_t start2 = clock();
    while (firstOregonIndex < linkedListC.listSize())
    {
        if (linkedListC.retrieveAt(firstOregonIndex).state == "OR")
        {
            break;
        }
        firstOregonIndex++;
    }

    // clock_t start2 = clock();
    AddressLinkedList linkedListE = linkedListC.extractAllMatches(linkedListC.retrieveAt(firstOregonIndex));
    clock_t end2 = clock();

    cout << "Time to extract: " << (double)(end2 - start2) / CLOCKS_PER_SEC << " seconds" << endl;

    cout << "linkedListC length: " << linkedListC.listSize() << endl;
    cout << "linkedListE length: " << linkedListE.listSize() << endl;
    linkedListE.printRange(0, 1);

    cout << "-----------------------------Section 6----------------------------" << endl;
    cout << "Applying the interleave algorithm of AddressLinkedList with the two original Linked Lists." << endl;

    // cout << linkedListA.listSize() << endl;
    linkedListA.interleave(linkedListB);
    // cout << linkedListA.listSize() << endl;
    // cout << linkedListB.listSize() << endl;
    linkedListA.printRange(0, 4);

    return 0;
}
