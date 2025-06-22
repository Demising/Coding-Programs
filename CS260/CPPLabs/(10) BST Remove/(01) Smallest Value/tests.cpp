//Bring in unit testing code and tell it to build a main function
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
//This pragma supresses a bunch of warnings QTCreator produces (and should not)
//#pragma clang diagnostic ignored "-Woverloaded-shift-op-parentheses"
#include "doctest.h"

//Use Approx from doctest without saying doctest::Approx
using doctest::Approx;

#include "CharBST.h"

//Declare helper functions from the .cpp file so that we can directly test them
char smallestValueFrom(BSTNode<char>* curNode);
BSTNode<char>* removeSmallestHelper(BSTNode<char>* startNode);
void deleteSubTree(BSTNode<char>* curNode);
BSTNode<char>* copySubTree(BSTNode<char>* currentNode);

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


TEST_CASE( "FindSmallest" ) {
    CharBST bst;
    insertTestData(bst);            //8 nodes

    char fromB = smallestValueFrom(bst.root);
    REQUIRE( fromB == 'B' );

    char fromP = smallestValueFrom(bst.root->right);
    REQUIRE( fromP == 'J' );

    char fromY = smallestValueFrom(bst.root->right->right);
    REQUIRE( fromY == 'Y' );
}