#include "CharBST.h"

#define for NOLOOPS
#define while NOLOOPS
#define goto NOLOOPS

// Any changes above will be ignored
// YOUR_CODE_BELOW

#include "CharBST.h"

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

///----------------------Removal---------------------------
/// Helper function for remove - chains down, until it finds node to
/// remove. Removes that node and repairs pointers on way back up
BSTNode<char>* removeHelper(BSTNode<char>* curNode, char valToRemove) {
  if(curNode == nullptr) {
    return nullptr; // Value not in tree
  } else if(valToRemove < curNode->value) {
    curNode->left = removeHelper(curNode->left, valToRemove);
  } else if(curNode->value < valToRemove) {
    curNode->right = removeHelper(curNode->right, valToRemove);
  } else {
    // Found the value to remove
    if(curNode->left == nullptr && curNode->right == nullptr) {
      // Case 0: No children
      delete curNode;
      return nullptr;
    } else if(curNode->right == nullptr) {
      // Case 1: No right child
      BSTNode<char>* leftChild = curNode->left;
      delete curNode;
      return leftChild;
    } else if(curNode->left == nullptr) {
      // Case 2: No left child
      BSTNode<char>* rightChild = curNode->right;
      delete curNode;
      return rightChild;
    } else {
      // Case 3: Two children
      curNode->value = smallestValueFrom(curNode->right);
      curNode->right = removeHelper(curNode->right, curNode->value);
    }
  }
  return curNode; // This node still exists. Return it back to caller.
}

void CharBST::remove(char value) {
  // new root is root that results from doing removeHelper
  root = removeHelper(root, value);
}
