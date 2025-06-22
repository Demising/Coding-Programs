//Bring in unit testing code and tell it to build a main function
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
//This pragma supresses a bunch of warnings QTCreator produces (and should not)
//#pragma clang diagnostic ignored "-Woverloaded-shift-op-parentheses"
#include "doctest.h"

//Use Approx from doctest without saying doctest::Approx
using doctest::Approx;

#include "CharBST.h"

//Declare  functions from the .cpp file so that we can directly test them
BSTNode<char>* rotateLeft(BSTNode<char>* parent);
BSTNode<char>* rotateRight(BSTNode<char>* parent);
int getHeight(BSTNode<char>* node);
int getBalance(BSTNode<char>* node);
int getSubtreeSize(BSTNode<char>* node);

using namespace std;

/* Adds test data to produce this tree:
 *         _G_
 *        /   \
 *       C     P
 *      / \   / \
 *     B   F J   Y
 *            \
 *             M
 */

void insertTestData(CharBST& c) {
    c.root = nullptr;   //remove (and leak!!!) any existing nodes

    c.root = new BSTNode<char>('G');

    c.root->left = new BSTNode<char>('C');
    c.root->left->left = new BSTNode<char>('B');
    c.root->left->right = new BSTNode<char>('F');

    c.root->right = new BSTNode<char>('P');
    c.root->right->right = new BSTNode<char>('Y');
    c.root->right->left = new BSTNode<char>('J');
    c.root->right->left->right = new BSTNode<char>('M');
}


TEST_CASE( "Size" ) {
    CharBST bst;
    insertTestData(bst);

    int FSize = getSubtreeSize(bst.root->left->right);
    REQUIRE( FSize == 1 );

    int JSize = getSubtreeSize(bst.root->right->left);
    REQUIRE( JSize == 2 );

    int fullSize = getSubtreeSize(bst.root);
    REQUIRE( fullSize == 8 );
}