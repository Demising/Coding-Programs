//----------------------------------------------------------
// CS260 Assignment Starter Code
// Copyright Andrew Scholer (ascholer@chemeketa.edu)
// Neither this code, nor any works derived from it
//    may not be republished without approval.
//----------------------------------------------------------
#ifndef MYSET_H
#define MYSET_H

#include <iostream>
#include <vector>

// Node node for Set
template<class T>
struct SetNode {
  T data;
  SetNode<T>* left;
  SetNode<T>* right;

  SetNode(const T& value);
};

// Set based on a BST
template<class T>
class MySet {
private:
  SetNode<T>* root;

public:
  // Construct empty set
  MySet();

  // Helper function for copy constructor
  SetNode<T>* copyHelper(SetNode<T>* node);

  // Copy constructor
  MySet(const MySet<T>& other);

  // Assignment operator - implement if needed
  MySet<T>& operator=(const MySet<T>& other);

  // Helper function for destructor
  void destructorHelper(SetNode<T>* node);

  // Destructor
  ~MySet();

  int getSize(SetNode<T>* node) const;

  // get number of items contained
  int size() const;

  // Helper function for depth
  int depthHelper(SetNode<T>* node) const;

  // get depth of underlying tree
  int depth() const;

  // Add item to set
  //   Do not add duplicates of existing items - ignore any duplicate add
  void add(const T& item);

  // Check if item is in the set
  bool contains(const T& item) const;

  // Helper function for remove
  void removeHelper(SetNode<T>*& node, const T& item);

  // Remove given item from the set if it exists
  void remove(const T& item);

  // Function made to compare the BST with a vector of IP addresses
  // And return the number of Local IP addresses that are in the BST.
  // This was designed to make sure that the Local IPs were being stored properly.
  int localCount(std::vector<T> localIPs);

  // Helper function for the print function
  // That is no longer in use.
  void printHelper(SetNode<T>* node) const;

  // Function that servers no purpose in the end.
  // Was only designed to test if smaller sets of IP addresses were being stored properly.
  void print() const;

  // Either helper function for getSmallest, or helper for removeHelper.
  // Recursive approach for getSmallest
  T getSmallestHelper(SetNode<T>* node) const;

  // returns the smallest item from the set (does not remove it)
  T getSmallest() const;

  // removes the largest item from the set and returns it
  T removeLargest();

  // Helper function for unionWith
  // Recursive approach for unionWith
  void unionWithHelper(SetNode<T>* otherNode, MySet<T>& result) const;

  // Generates a new set containing all the items that are in either
  //   this set or another set
  //   intersections of {A, B, C, D} and {B, D, F} would be {A, B, C, D, F}
  //   Both original sets are left unmodified
  MySet<T> unionWith(const MySet<T>& other) const;
  
  // Helper function for intersectionWith
  // Recursive approach for intersectionWith
  void intersectionWithHelper(SetNode<T>* otherNode, const MySet<T>& other, MySet<T>& result) const;

  // Helper function for intersectionWith
  // Recursive approach for intersectionWith
  // ================================================================
  // Vector implementation
  void intersectionWithHelper(SetNode<T>* otherNode, const MySet<T>& other, std::vector<T>& result) const;

  // Generates a new set containing all the items that are in both
  //   this set and another set
  //   intersections of {A, B, C, D} and {B, D, F} would be {B, D}
  //   Both original sets are left unmodified
  MySet<T> intersectionWith(const MySet<T>& other) const;

  // Helper function for getRange
  // Recursive approach for getRange
  void getRangeHelper(SetNode<T>* node, const T& startValue, const T& endValue, std::vector<T>& result) const;

  // Returns a vector of items in the set that are >= start and < end
  std::vector<T> getRange(const T& startValue, const T& endValue) const;
};

//--------------------------------------------------------------------
// SetNode implementations
//--------------------------------------------------------------------

template<class T>
SetNode<T>::SetNode(const T& value): data(value)
{
  left = nullptr;
  right = nullptr;
}

//--------------------------------------------------------------------
// Set Implementations
//--------------------------------------------------------------------

template<class T>
MySet<T>::MySet() {
  root = nullptr;
}

template<class T>
SetNode<T>* MySet<T>::copyHelper(SetNode<T>* node) {
  if (node == nullptr)
    return nullptr;

  SetNode<T>* newNode = new SetNode<T>(node->data);
  newNode->left = copyHelper(node->left);
  newNode->right = copyHelper(node->right);

  return newNode;
}

template<class T>
MySet<T>::MySet(const MySet<T>& other) {
  root = copyHelper(other.root);
}

template<class T>
void MySet<T>::destructorHelper(SetNode<T>* node) {
  if (node == nullptr)
    return;

  destructorHelper(node->left);
  destructorHelper(node->right);

  delete node;
}

template<class T>
MySet<T>::~MySet() {
  destructorHelper(root);
}

template<class T>
int MySet<T>::getSize(SetNode<T>* node) const {
  if (node == nullptr)
    return 0;

  return 1 + getSize(node->left) + getSize(node->right);
}

template<class T>
int MySet<T>::size() const {
  return getSize(root);
}

template<class T>
int MySet<T>::depthHelper(SetNode<T>* node) const {
    if (node == nullptr) {
        return -1;
    }

    return std::max(depthHelper(node->left), depthHelper(node->right)) + 1;
}

template<class T>
int MySet<T>::depth() const {
    return depthHelper(root);
}

template<class T>
void MySet<T>::add(const T& item) {
  SetNode<T>* newNode = new SetNode<T>(item);

  if (root == nullptr) {
    root = newNode;
    return;
  }

  SetNode<T>* current = root;
  SetNode<T>* parent = nullptr;

  while (current != nullptr) {
    parent = current;
    if (item < current->data)
      current = current->left;
    else if (item > current->data)
      current = current->right;
    else {
      delete newNode;
      return;
    }
  }

  if (item < parent->data)
    parent->left = newNode;
  else
    parent->right = newNode;
}

template<class T>
bool MySet<T>::contains(const T& item) const {
  SetNode<T>* current = root;

  while (current != nullptr) {
    if (item < current->data)
      current = current->left;
    else if (item > current->data)
      current = current->right;
    else
      return true;
  }

  return false;
}

template<class T>
void MySet<T>::removeHelper(SetNode<T>*& node, const T& item) {
  if (node == nullptr) {
    return;
  }

  if (item < node->data) {
    removeHelper(node->left, item);
  } else if (item > node->data) {
    removeHelper(node->right, item);
  } else {
    if (node->left == nullptr && node->right == nullptr) {
      delete node;
      node = nullptr;
    } else if (node->left == nullptr) {
      SetNode<T>* temp = node->right;
      delete node;
      node = temp;
    } else if (node->right == nullptr) {
      SetNode<T>* temp = node->left;
      delete node;
      node = temp;
    } else {
      node->data = getSmallestHelper(node->right);
      removeHelper(node->right, node->data);
    }
  }
}

template<class T>
void MySet<T>::remove(const T& item) {
  removeHelper(root, item);
}

//Recursive function for getSmallest
template<class T>
T MySet<T>::getSmallestHelper(SetNode<T>* node) const {
  if (node->left == nullptr)
    return node->data;

  return getSmallestHelper(node->left);
}

template<class T>
T MySet<T>::getSmallest() const {
  SetNode<T>* current = root;

  // Iterative approach
  while (current->left != nullptr)
    current = current->left;
  
  return current->data;

  // Recursive approach
  // return getSmallestHelper(root);
}

template<class T>
T MySet<T>::removeLargest() {
  SetNode<T>* current = root;
  SetNode<T>* parent = nullptr;

  while (current->right != nullptr) {
    parent = current;
    current = current->right;
  }
  T largest = current->data;
  parent->right = current->left;

  delete current;

  return largest;
}

template<class T>
int MySet<T>::localCount(std::vector<T> toCount) {
  int count = 0;
  for (int i = 0; i < toCount.size(); i++) {
    if (contains(toCount[i])) {
      count++;
    }
  }
  return count;
}

template<class T>
void MySet<T>::getRangeHelper(SetNode<T>* node, const T& startValue, const T& endValue, std::vector<T>& result) const {
  if (node == nullptr)
    return;

    getRangeHelper(node->left, startValue, endValue, result);
    if (node->data >= startValue && node->data < endValue) {
      result.push_back(node->data);
    }
    getRangeHelper(node->right, startValue, endValue, result);
}

template<class T>
std::vector<T> MySet<T>::getRange(const T& startValue, const T& endValue) const {
  std::vector<T> result;
  getRangeHelper(root, startValue, endValue, result);
  return result;
}

template<class T>
void MySet<T>::unionWithHelper(SetNode<T>* otherNode, MySet<T>& result) const {
  if (otherNode == nullptr) {
    return;
  }

  unionWithHelper(otherNode->left, result);
  result.add(otherNode->data);
  unionWithHelper(otherNode->right, result);
}

template<class T>
MySet<T> MySet<T>::unionWith(const MySet<T>& other) const {
  MySet<T> result = *this;

  SetNode<T>* otherNode = other.root;
  unionWithHelper(otherNode, result);

  return result;
}

template<class T>
void MySet<T>::intersectionWithHelper(SetNode<T>* node, const MySet<T>& other, MySet<T>& result) const {
  if (node == nullptr) {
    return;
  }

  if (other.contains(node->data)) {
    result.add(node->data);
  }
  intersectionWithHelper(node->left, other, result);
  intersectionWithHelper(node->right, other, result);

}

template<class T>
MySet<T> MySet<T>::intersectionWith(const MySet<T>& other) const {
  MySet<T> result;
  intersectionWithHelper(this->root, other, result);

  return result;
}

// template<class T>
// void MySet<T>::intersectionWithHelper(SetNode<T>* node, const MySet<T>& other, std::vector<T>& intersection) const {
//   if (node == nullptr) {
//     return;
//   }

//   if (other.contains(node->data)) {
//     intersection.push_back(node->data);
//   }
//   intersectionWithHelper(node->left, other, intersection);
//   intersectionWithHelper(node->right, other, intersection);

// }

// template<class T>
// MySet<T> MySet<T>::intersectionWith(const MySet<T>& other) const {
//   MySet<T> result;
//   std::vector<T> intersection;
//   intersectionWithHelper(this->root, other, intersection);

//   for (int i = 0; i < intersection.size(); i++) {
//     result.add(intersection[i]);
//   }

//   return result;
// }

template<class T>
void MySet<T>::printHelper(SetNode<T>* node) const {
  if (node == nullptr)
    return;

  printHelper(node->left);
  std::cout << node->data << std::endl;
  printHelper(node->right);
}

template<class T>
void MySet<T>::print() const {
  printHelper(root);
}
#endif // MYSET_H
