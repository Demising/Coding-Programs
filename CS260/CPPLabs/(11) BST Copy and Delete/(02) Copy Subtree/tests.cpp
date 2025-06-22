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




TEST_CASE( "CopySubTreeNull" ) {
    CharBST bst;
    insertTestData(bst);            //8 nodes

    //Make sure null is handled
    BSTNode<char>* copyOfNull = copySubTree(nullptr);
    REQUIRE( copyOfNull == nullptr );
}

TEST_CASE( "CopySubTreeSingle" ) {
    CharBST bst;
    insertTestData(bst);            //8 nodes

    //Copy one node
    BSTNode<char>* copyOfB = copySubTree(bst.root->left->left);
    //Should new node with same value, but NOT be the same node
    REQUIRE( copyOfB->value == 'B' );
    REQUIRE( copyOfB != bst.root->left->left );
}

TEST_CASE( "CopySubTree" ) {
    CharBST bst;
    insertTestData(bst);            //8 nodes

    //Copy three nodes
    int startNodeCount = BSTNode<char>::nodeCount;
    BSTNode<char>* copyOfC = copySubTree(bst.root->left);
    REQUIRE( copyOfC->value == 'C' );
    REQUIRE( copyOfC->left->value == 'B' );
    REQUIRE( copyOfC->right->value == 'F' );
    int newNodeCount = BSTNode<char>::nodeCount;
    REQUIRE( newNodeCount - startNodeCount == 3 );
}

TEST_CASE( "Copy" ) {
    CharBST bst;
    insertTestData(bst);            //8 nodes

    int startNodeCount = BSTNode<char>::nodeCount;

    CharBST copy = bst;  //calls copy constructor

    int newNodeCount = BSTNode<char>::nodeCount;
    REQUIRE( newNodeCount - startNodeCount == 8 );

    //Check a few nodes
    REQUIRE( copy.root != nullptr );
    REQUIRE( copy.root != bst.root );
    REQUIRE( copy.root->value == 'G' );

    REQUIRE( copy.root->right != nullptr );
    REQUIRE( copy.root->right->value == 'P' );

    REQUIRE( copy.root->right->left != nullptr );
    REQUIRE( copy.root->right->left->value == 'J' );

    REQUIRE( copy.root->right->left->right != nullptr );
    REQUIRE( copy.root->right->left->right ->value == 'M' );
}