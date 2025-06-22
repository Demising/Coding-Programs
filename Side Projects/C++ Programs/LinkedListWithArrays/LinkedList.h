#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct Node {
    int data;
    Node* next;
    Node* prev;
};

class LinkedList {
    public:
        Node* head;
        Node* tail;
        int size;
    public:
        LinkedList();
        ~LinkedList();

        LinkedList(const LinkedList& other);

        void addNode(int data);
        void deleteNode(int data);

        void printList();

        int getSize();
};

#endif