#include "CharBST.h"

#define for NOLOOPS
#define while NOLOOPS
#define goto NOLOOPS
// Any changes above will be ignored
// YOUR_CODE_BELOW

BSTNode<char>* insertHelper(BSTNode<char>* curNode, char insertVal) {
  if(curNode == nullptr) { // Base case: if the current node is null, create a
                           // new node with the insertVal
    return new BSTNode<char>(insertVal);
  }

  if(insertVal < curNode->value) { // If the insertVal is less than the current
                                   // node's data, insert into the left subtree
    curNode->left = insertHelper(curNode->left, insertVal);
  } else if(insertVal >
            curNode->value) { // If the insertVal is greater than the current
                              // node's data, insert into the right subtree
    curNode->right = insertHelper(curNode->right, insertVal);
  }

  // If insertVal is equal to the current node's data, do nothing (no duplicates
  // allowed)

  return curNode; // Return the current node (unchanged if insertVal already
                  // exists)
}

void CharBST::insertRecursive(char insertVal) {
  root = insertHelper(
      root, insertVal); // Call the recursive helper function with the root node
}