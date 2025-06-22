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


TEST_CASE( "Height" ) {
    CharBST bst;
    insertTestData(bst);

    int FHeight = getHeight(bst.root->left->right);
    REQUIRE( FHeight == 0 );

    int JHeight = getHeight(bst.root->right->left);
    REQUIRE( JHeight == 1 );

    int fullHeight = getHeight(bst.root);
    REQUIRE( fullHeight == 3 );
}


TEST_CASE( "Balance" ) {
    CharBST bst;
    insertTestData(bst);

    int FBal = getBalance(bst.root->left->right);
    REQUIRE( FBal == 0 );

    int JBal = getBalance(bst.root->right->left);
    REQUIRE( JBal == 1 );

    int PBal = getBalance(bst.root->right);
    REQUIRE( PBal == -1 );

    int fullBal = getBalance(bst.root);
    REQUIRE( fullBal== 1 );
}