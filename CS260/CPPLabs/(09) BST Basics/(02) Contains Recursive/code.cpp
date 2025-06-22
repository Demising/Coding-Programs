#include "CharBST.h"

#define for NOLOOPS
#define while NOLOOPS
#define goto NOLOOPS
// Any changes above will be ignored
// YOUR_CODE_BELOW

bool containsHelper(BSTNode<char>* curNode, char valToFind) {
  if(curNode == nullptr) // Base case: if the current node is null, return false
    return false;

  if(curNode->value ==
     valToFind) // If current node contains the value, return true
    return true;
  else if(valToFind <
          curNode->value) // If the value is less than the current node's value,
                          // search in the left subtree
    return containsHelper(curNode->left, valToFind);
  else // If the value is greater than the current node's value, search in the
       // right subtree
    return containsHelper(curNode->right, valToFind);
}

bool CharBST::containsRecursive(char valToFind) const {
  return containsHelper(
      root, valToFind); // Call the recursive helper function with the root node
}