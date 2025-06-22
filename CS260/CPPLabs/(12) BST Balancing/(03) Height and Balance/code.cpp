#include "CharBST.h"

int getHeight(BSTNode<char>* node) {
  if(node == nullptr) {
    return -1;
  }
  int leftHeight = getHeight(node->left);
  int rightHeight = getHeight(node->right);

  return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

// Function to get the balance factor of the node
int getBalance(BSTNode<char>* node) {
  if(node == nullptr) {
    return 0;
  }
  int leftHeight = getHeight(node->left);
  int rightHeight = getHeight(node->right);

  return rightHeight - leftHeight;
}
