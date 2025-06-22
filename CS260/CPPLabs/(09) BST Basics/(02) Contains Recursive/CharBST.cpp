#include "CharBST.h"

#include <iostream>
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


///----------------------Search---------------------------



///----------------------insert---------------------------