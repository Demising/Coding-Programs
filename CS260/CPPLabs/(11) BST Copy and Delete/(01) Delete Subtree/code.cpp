#include "CharBST.h"

#define for NOLOOPS
#define while NOLOOPS
#define goto NOLOOPS
// Any changes above will be ignored
// YOUR_CODE_BELOW

void deleteSubTree(BSTNode<char>* curNode) {
  if(curNode == nullptr) // Base case: if the current node is null, return
    return;

  // Delete left subtree
  deleteSubTree(curNode->left);

  // Delete right subtree
  deleteSubTree(curNode->right);

  // Delete current node
  delete curNode;
}