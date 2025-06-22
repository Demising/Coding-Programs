#include "LinkedList.h"

#ifndef ARRAYPOINTER_H
#define ARRAYPOINTER_H


class ArrayPointer {
    private:
        int capacity;
        Node** arr;
        int size;
    public:
        ArrayPointer();
        // ~ArrayPointer();

        ArrayPointer(const LinkedList& list);

        void growArray();

        int getSize();

        int getItem(int index);
};

#endif