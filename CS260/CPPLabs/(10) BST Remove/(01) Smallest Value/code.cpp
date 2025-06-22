#include "CharBST.h"

#define for NOLOOPS
#define while NOLOOPS
#define goto NOLOOPS

// Any changes above will be ignored
// YOUR_CODE_BELOW

char smallestValueFrom(BSTNode<char>* curNode) {
  // Base case: if the current node is null, return a placeholder value
  if(curNode == nullptr)
    return '?';

  // If the left child exists, recursively traverse to the left
  if(curNode->left != nullptr)
    return smallestValueFrom(curNode->left);

  // If there is no left child, the current node contains the smallest value
  return curNode->value;
}