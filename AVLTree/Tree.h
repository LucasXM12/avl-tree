#pragma once

#include <string>

#ifndef TREE_H
#define TREE_H

#define max(a, b) (a > b ? a : b)
#define height(n) (n == NULL ? 0 : n->height) 
#define height_update(n) (max(height(n->left), height(n->right)) + 1)
#define balance_factor(n) (n == NULL ? 0 : (height(n->left) - height(n->right)))

using namespace std;

class Tree {
	typedef struct node {
		int data;

		node* left;
		node* right;

		int height;
	} node;
public:
	Tree ();
	virtual ~Tree ();

	string toString () const;

	void addNode (int);
	node* newNode (int) const;

	int minNode () const;
	int maxNode () const;

	bool exists (int) const;

	void delNode (int);
private:
	node* root;

	void delTree (node*);

	string toString (node*) const;

	node* minNode (node*) const;
	node* maxNode (node*) const;

	bool exists (int, node*) const;

	node* leftRotate (node*);
	node* rightRotate (node*);

	node* addNode (node*, int);
	node* delNode (node*, int);
};

#endif // TREE_H

