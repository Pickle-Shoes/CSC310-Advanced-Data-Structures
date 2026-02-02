#include <iostream>
#include <fstream>
using namespace std;

#include "bst.h"



// allocate a new node
//   not part of the class
treenode *makeatreenode( int x )
{
	//Crate a pointer and point it to a dynamically allocated node.
	treenode *node;
	node = new treenode;

	//Initialize Values
	node->dat = x;
	node->lchild = NULL;
	node->rchild = NULL;

	//Return the Pointer.
	return node;
}



bstree::bstree()
{
	root = NULL;
}

void bstree::printBST(){
	if(root == nullptr){
		return;
	}

	printBST(root, 0);

}

void bstree::printBST(treenode *i, int depth){

	if(i == nullptr){
		return;
	}
	else{
	printBST(i->rchild, depth + 1);

	for(int k = 0; k < depth; k++){
        cout << "  "; //for indentation
    }
	cout << i->dat << endl;

	printBST(i->lchild, depth + 1);
	}
}

void bstree::in(treenode *t)
{
	if(t == NULL)
		return;
	else
	{
		in(t->lchild);
		cout << t->dat << " ";
		in(t->rchild);
	}
}

void bstree::pre(treenode *t)
{
	if(t == NULL)
		return;
	else
	{
		cout << t->dat << " ";
		pre(t->lchild);
		pre(t->rchild);
	}
}

void bstree::post(treenode *t)
{
	if(t == NULL)
		return;
	else
	{
		post(t->lchild);
		post(t->rchild);
		cout << t->dat << " ";
	}
}

void bstree::in()
{
	cout << "In: ";
	in(root);
	cout << endl;
}

void bstree::pre()
{
	cout << "Pre: ";
	pre(root);
	cout << endl;
}

void bstree::post()
{
	cout << "Post: ";
	post(root);
	cout << endl;
}

void bstree::insert(int val)
{
	treenode *t = root;

	if(root == NULL)
	{
		root = makeatreenode(val);
		return;
	}

	if(val == t->dat)
		return;
	insert(t, val);
}

void bstree::insert(treenode *t, int val )
{
	if(val < t->dat)
		if(t->lchild == NULL)
			t->lchild = makeatreenode(val);
		else
			insert(t->lchild,val);
	else
		if(t->rchild == NULL)
			t->rchild = makeatreenode(val);
		else
			insert(t->rchild,val);
}

void bstree::remove(int val)
{
	treenode *walk = root;

	if(root == NULL)
		return;

	if(walk->dat == val) //The Val is the Root Node
	{
		if(walk->lchild == NULL && walk->rchild == NULL)
		{
			root = NULL;
			delete walk;
		}
		else if(walk->lchild != NULL && walk->rchild == NULL)
		{
			root = walk->lchild;
			delete walk;
		}
		else if(walk->lchild == NULL && walk->rchild != NULL)
		{
			root = walk->rchild;
			delete walk;
		}
		else
		{
			root->dat = getMin(root->rchild);
		
		}
		return;
	}

	//If not root, goes to the location right before the val
	while(walk != NULL && (walk->lchild != NULL || walk->rchild != NULL))
	{
		if(walk->lchild != NULL)
			if(walk->lchild->dat == val)
				break;

		if(walk->rchild != NULL)
			if(walk->rchild->dat == val)
				break;


		if(val < walk->dat)
			walk = walk->lchild;
		else
			walk = walk->rchild;
	}

	if(walk == NULL)
		return;

	

	treenode *tmp = walk;

	if(walk->lchild != NULL && walk->lchild->dat == val)
	{
		tmp = walk->lchild;
		if(tmp->lchild == NULL && tmp->rchild == NULL)
		{
			walk->lchild = NULL;
			delete tmp;
		}
		else if(tmp->lchild != NULL && tmp->rchild == NULL)
		{
			walk->lchild = tmp->lchild;
			delete tmp;
		}
		else if(tmp->lchild == NULL && tmp->rchild != NULL)
		{
			walk->lchild = tmp->rchild;
			delete tmp;
		}
		else
		{
			tmp->dat = getMin(tmp->rchild);
			
		}
	}
	else
	{
		tmp = walk->rchild;
		if(tmp->lchild == NULL && tmp->rchild == NULL)
		{
			walk->rchild = NULL;
			delete tmp;
		}
		else if(tmp->lchild != NULL && tmp->rchild == NULL)
		{
			walk->rchild = tmp->lchild;
			delete tmp;
		}
		else if(tmp->lchild == NULL && tmp->rchild != NULL)
		{
			walk->rchild = tmp->rchild;
			delete tmp;
		}
		else
		{
			tmp->dat = getMin(tmp->rchild);
			
		}
	}
}

bool bstree::search( int val )
{
	//return searchI(val);
	return searchR(root, val); //Passes where to start and what value to search for
}

bool bstree::searchR(treenode *t, int val)
{
	if(t == NULL)
		return false;

	if(t->dat == val)
		return true;

	if(val < t->dat)
		return searchR(t->lchild, val);
	else
		return searchR(t->rchild, val);
}

bool bstree::searchI(int val)
{
	treenode *t = root; //root is the class object of the beginning of the tree

	while(t != NULL) //only keeps going if the node isn't empty
	{
		if(t->dat == val)
			return true;
		if( val < t->dat)
			t = t->lchild;
		else
			t = t->rchild;
	}

	return false;
}

int bstree::numnodes()
{
	if(root == NULL)
		return 0;

	return numnodes(root);
}

int bstree::numnodes(treenode *t)
{
	if(t->lchild == NULL)
		if(t->rchild == NULL)
			return 1;
		else
			return 1 + numnodes(t->rchild);
	else if(t->rchild == NULL)
		return 1 + numnodes(t->lchild);
	else
		return 1 + numnodes(t->lchild) + numnodes(t->rchild);
}

int bstree::height()
{
	return height(root);
}

int bstree::height(treenode *t)
{
	if(t == NULL) //am I empty?
		return 0;

	if(t->lchild == NULL && t->rchild == NULL) //am I a leaf node?
		return 1;

	int hL, hR;
	hL = height(t->lchild);
	hR = height(t->rchild);

	if(hL >= hR)
		return 1 + hL;
	else
		return 1 + hR;

	
}

int bstree::taller()
{
	treenode *t = root;

	int hL, hR;
	hL = height(t->lchild);
	hR = height(t->rchild);

	if(hL > hR)
		return -1;
	else if (hR > hL)
		return 1;
	else
		return 0;
}

int bstree::getMin(treenode *walk)
{
	if(walk == NULL)
		return 0;

	while(walk->lchild != NULL) //If walk has a left child, go there, otherwise stop.
		walk = walk->lchild;

	int save; //Saves the number of the smallest node to return for mapping.
	save = walk->dat;
	remove(save);	//Calls the remove function to remove the smallest node from the tree.

	return save;
}
