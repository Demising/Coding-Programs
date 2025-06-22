#include "CharBST.h"

#define for NOLOOPS
#define while NOLOOPS
#define goto NOLOOPS
// Any changes above will be ignored
// YOUR_CODE_BELOW

// Helper used by copy ctor and assignment operator
BSTNode<char>* copySubTree(BSTNode<char>* currentNode) {
  if(currentNode ==
     nullptr) // Base case: if the current node is null, return null
    return nullptr;

  // Create a new node with the same value as currentNode
  BSTNode<char>* newNode = new BSTNode<char>(currentNode->value);

  // Recursively copy the left subtree and assign it to the left child of
  // newNode
  newNode->left = copySubTree(currentNode->left);

  // Recursively copy the right subtree and assign it to the right child of
  // newNode
  newNode->right = copySubTree(currentNode->right);

  return newNode; // Return the root of the copied subtree
}