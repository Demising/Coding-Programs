#include "SimpleLinkedList.h"
#include <iostream>
using namespace std;

#define while heckno
#define for youshouldntneedme

// Any changes above will be ignored
// YOUR_CODE_BELOW

void recursiveDelete(ListNode* current) {
  // TODO: Fix me
  if(current == nullptr) {
    return;
  }
  recursiveDelete(current->next);
  delete current;
}

SimpleLinkedList::~SimpleLinkedList() {
  recursiveDelete(head);
  head = nullptr;
}