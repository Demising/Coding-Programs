#include "CharBST.h"

void CharBST::insertIterative(char insertVal) {
  BSTNode<char>* newNode = new BSTNode<char>(
      insertVal); // Create a new node with the value to insert

  if(root == nullptr) { // If the tree is empty, set the new node as the root
    root = newNode;
    return;
  }

  BSTNode<char>* curNode = root;
  BSTNode<char>* parent = nullptr;

  while(curNode != nullptr) {
    parent = curNode;
    if(insertVal < curNode->value)
      curNode = curNode->left;
    else if(insertVal > curNode->value)
      curNode = curNode->right;
    else { // If the value already exists, delete the new node and return
      delete newNode;
      return;
    }
  }

  // Attach the new node to the appropriate position
  if(insertVal < parent->value)
    parent->left = newNode;
  else
    parent->right = newNode;
}