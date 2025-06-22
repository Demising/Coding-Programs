//Bring in unit testing code and tell it to build a main function
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
//This pragma supresses a bunch of warnings QTCreator produces (and should not)
//#pragma clang diagnostic ignored "-Woverloaded-shift-op-parentheses"
#include "doctest.h"

//Use Approx from doctest without saying doctest::Approx
using doctest::Approx;

#include "CharBST.h"

using namespace std;


/* Adds test data to produce this tree:
 *         _G_
 *        /   \
 *       C     P
 *        \   / \
 *         F J   Y
 */

void insertTestData(CharBST& c) {
    c.root = nullptr;   //remove (and leak!!!) any existing nodes

    c.root = new BSTNode<char>('G');
    c.root->left = new BSTNode<char>('C');
    c.root->left->right = new BSTNode<char>('F');
    c.root->right = new BSTNode<char>('P');
    c.root->right->right = new BSTNode<char>('Y');
    c.root->right->left = new BSTNode<char>('J');
}


TEST_CASE( "ContainsIterative" ) {
    CharBST bst;
    insertTestData(bst);

    REQUIRE( bst.containsIterative('G') );
    REQUIRE( bst.containsIterative('C') );
    REQUIRE( bst.containsIterative('F') );
    REQUIRE( bst.containsIterative('P') );
    REQUIRE( bst.containsIterative('Y') );
    REQUIRE( bst.containsIterative('J') );
    REQUIRE_FALSE( bst.containsIterative('A') );
    REQUIRE_FALSE( bst.containsIterative('Q') );
}