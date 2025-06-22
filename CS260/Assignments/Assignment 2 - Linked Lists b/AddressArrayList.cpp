//----------------------------------------------------------
// CS260 Assignment 2 Starter Code
// Copyright Andrew Scholer (ascholer@chemeketa.edu)
// Neither this code, nor any works derived from it
//    may not be republished without approval.
//----------------------------------------------------------

#include "AddressArrayList.h"

#include <iostream>
#include <algorithm>

using namespace std;


void printListRange(const ArrayList<Address>& list, int startIndex, int endIndex) {
    if(endIndex == -1)
        endIndex = list.listSize() - 1;
    for(int i = startIndex; i <= endIndex; i++) {
        cout << list.retrieveAt(i);
    }
}


template <>
void ArrayList<Address>::combine(ArrayList<Address>& otherList) {
    for (int i = 0; i < otherList.listSize(); i++) {
        insertEnd(otherList.retrieveAt(i));
    }
    otherList.clear();
}

template <>
ArrayList<Address> ArrayList<Address>::extractAllMatches(const Address& itemToMatch) {
    ArrayList<Address> stateMatch;
    int lShift = 0;
    for (int i = 0; i < listSize(); i++) {
        if (retrieveAt(i).state == itemToMatch.state) {
            stateMatch.insertEnd(list[i]);
            lShift++;
        } else {
            list[i - lShift] = list[i];
        }
    }
    length = length - lShift;
    return stateMatch;
}
