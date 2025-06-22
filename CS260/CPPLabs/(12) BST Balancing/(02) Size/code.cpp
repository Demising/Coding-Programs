#include "CharBST.h"

int getSubtreeSize(BSTNode<char>* node) {
  if(node == nullptr) {
    return 0;
  }

  int leftSize = getSubtreeSize(node->left);
  int rightSize = getSubtreeSize(node->right);

  return leftSize + rightSize + 1;
}