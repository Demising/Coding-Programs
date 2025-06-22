#include "CharBST.h"

#include <iostream>
#include <stdexcept>
using namespace std;

///----------------------CON/DE STRUCTORS----------------------------
CharBST::CharBST() {
    root = nullptr;
}


void deleteSubTree(BSTNode<char>* curNode) {
    //TODO - fixme
}

CharBST::~CharBST() {
    deleteSubTree(root);
    root = nullptr;
}

//Helper used by copy ctor and assignment operator
BSTNode<char>* copySubTree(BSTNode<char>* currentNode) {
    //TODO - FIXME
    return nullptr;
}


CharBST::CharBST(const CharBST& other) {
    root = copySubTree(other.root);
}

CharBST& CharBST::operator=(const CharBST& other) {
    if(this != &other) {
        //remove any existing nodes
        deleteSubTree(root);
        //copying nodes of other tree
        root = copySubTree(other.root);
    }
    return *this;
}



///----------------------Print----------------------------
///Nonmember helper function
string toStringHelper(BSTNode<char>* curNode) {
    if(curNode == nullptr)
        return "";

    string result = toStringHelper(curNode->left);
    result += to_string(curNode->value)+ " ";
    result += toStringHelper(curNode->right);

    return result;
}

string CharBST::toString() const {
    return toStringHelper(root);
}



///----------------------RemoveSmallest---------------------------



///----------------------Smallest---------------------------



///----------------------Removal---------------------------




bool CharBST::isEmpty() {
    return root == nullptr;
}