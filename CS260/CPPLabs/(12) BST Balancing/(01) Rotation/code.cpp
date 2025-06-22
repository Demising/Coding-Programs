#include "CharBST.h"

BSTNode<char>* rotateLeft(BSTNode<char>* parent) {
  BSTNode<char>* newParent = parent->right;

  parent->right = newParent->left;
  newParent->left = parent;

  return newParent;
}

// Rotate the subtree rooted with 'parent' to the right.
// This means 'parent' will become the right child of its left child.
BSTNode<char>* rotateRight(BSTNode<char>* parent) {
  BSTNode<char>* newParent = parent->left;

  parent->left = newParent->right;
  newParent->right = parent;

  return newParent;
}