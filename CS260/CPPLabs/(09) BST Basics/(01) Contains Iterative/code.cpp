#include "CharBST.h"

bool CharBST::containsIterative(char valToFind) const {
  BSTNode<char>* curNode = root; // Start from the root node

  while(curNode != nullptr) {
    if(curNode->value ==
       valToFind) // If current node contains the value, return true
      return true;
    else if(valToFind <
            curNode->value) // If the value is less than the current
                            // node's value, move to the left subtree
      curNode = curNode->left;
    else // If the value is greater than the current node's value, move to the
         // right subtree
      curNode = curNode->right;
  }

  return false; // If the loop exits without finding the value, return false
}
