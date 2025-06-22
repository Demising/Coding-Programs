/**
 * @author CM
 * @brief recursiveMax
 */

#include "SimpleLinkedList.h"
#include <iostream>
using namespace std;

// Any changes above will be ignored
// YOUR_CODE_BELOW

int recursiveMax(ListNode* current) {
  if (current == nullptr) {
        // You can return any suitable default value. Here, I'm using negative infinity.
        return -1;
    }

    // Get the maximum value from the rest of the list
    int maxOfRest = recursiveMax(current->next);

    // Compare the maximum value from the rest of the list with the current node's data
    return max(maxOfRest, current->data);
}

// int recursiveMax(ListNode* current) {
//   // TODO: Fix me
//   int max = current->data;
//   if(current == nullptr) {
//     return -1;
//   }
//   max = recursiveMax(current->next);

//   if(max > current->data) {
//     max = current->data;
//   }

//   return max;
// }

int SimpleLinkedList::getMaxValue() {
  return recursiveMax(head);
}