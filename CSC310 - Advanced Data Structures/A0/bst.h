// Base Code - linked binary search tree

#include <iostream>
#include <fstream>
using namespace std;


// tree node for linked BST
struct treenode
{
    int dat;
    treenode *lchild;
    treenode *rchild;
};


// Class for binary search tree
// Private will be treenode * to the root

class bstree
{
 public:
	bstree();
	void in( );
	void pre( );
	void post( );
	void insert( int x );
	void remove( int x );
	bool search( int x );
	int numnodes(); // must compute, not a variable in class
	int height();   // must compute, not a variable in class
	void height( int x ); // returns the height of a specific node
	int getMin();
	int taller();
	void printBST(); //user called
	bool isBalanced(); //checks if tree is balanced
	bool worstCase(); //checks if tree is in worst case
	void traverseAll();
 private:
	void insert(treenode *t, int x);
	bool searchI(int x);
	bool searchR(treenode *t, int x);
	treenode *searchForNode(int val);
	void in(treenode *t);
	void pre(treenode *t);
	void post(treenode *t);
	int height(treenode *t);
	int numnodes(treenode *t);
	int getMin(treenode *t);
	void printBST(treenode *i, int depth); //called from printBST() without params
	void traverseAll(treenode *t); //traverses all the nodes to see if the tree is in the worst case
	treenode *root;

};

