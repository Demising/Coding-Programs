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


TEST_CASE( "ContainsRecursive" ) {
    CharBST bst;
    insertTestData(bst);

    REQUIRE( bst.containsRecursive('G') );
    REQUIRE( bst.containsRecursive('C') );
    REQUIRE( bst.containsRecursive('F') );
    REQUIRE( bst.containsRecursive('P') );
    REQUIRE( bst.containsRecursive('Y') );
    REQUIRE( bst.containsRecursive('J') );
    REQUIRE_FALSE( bst.containsRecursive('A') );
    REQUIRE_FALSE( bst.containsRecursive('Q') );
}