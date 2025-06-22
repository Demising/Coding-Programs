#include "SimpleLinkedList.h"
#include <iostream>
using namespace std;

#define while heckno
#define for youshouldntneedme

// Any changes above will be ignored
// YOUR_CODE_BELOW

string recursiveReverseToString(ListNode* current) {
  // TODO: Fix me
  if(current->next == nullptr) {
    return to_string(current->data);
  }

  // Recursive call: reverse the rest of the list and concatenate the current
  // node's data
  return recursiveReverseToString(current->next) + " " +
         to_string(current->data);
}

string SimpleLinkedList::reverseToString() {
  if(head == nullptr)
    return "";
  return recursiveReverseToString(head);
}
