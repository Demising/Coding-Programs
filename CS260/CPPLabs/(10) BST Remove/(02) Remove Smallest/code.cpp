#include "CharBST.h"

#define for NOLOOPS
#define while NOLOOPS
#define goto NOLOOPS

// Any changes above will be ignored
// YOUR_CODE_BELOW

#include "CharBST.h"

// Recursive function to remove smallest value starting from indicated node
BSTNode<char>* removeSmallestHelper(BSTNode<char>* curNode) {
  // Base case: if the current node is null, return null
  if(curNode == nullptr)
    return nullptr;

  // Case 1: If the current node has no left child, it's the smallest node
  if(curNode->left == nullptr) {
    // Store the right child to return
    BSTNode<char>* rightChild = curNode->right;
    // Delete the current node
    delete curNode;
    // Return the right child (which may be nullptr)
    return rightChild;
  }

  // Case 2: If the current node has a left child, recursively remove smallest
  // from left subtree
  curNode->left = removeSmallestHelper(curNode->left);
  // Return the updated current node
  return curNode;
}

void CharBST::removeSmallest() {
  if(root != nullptr)
    root = removeSmallestHelper(root);
}