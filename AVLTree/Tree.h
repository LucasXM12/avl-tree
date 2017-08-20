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
private:
	typedef struct node {
		int key;
		int height;

		node* left;
		node* right;	
	} node;

	node* root;

	void delTree(node*);

	string toString(const node*) const;

	node* minNode(node*) const;
	node* maxNode(node*) const;

	bool exists(const int&, const node*) const;

	node* leftRotate(node*);
	node* rightRotate(node*);

	node* addNode(node*, const int&);
	node* newNode(const int&) const;

	node* delNode(node*, const int&);

public:
	Tree();
	virtual ~Tree();

	string toString() const;

	void addNode(const int&);

	int minNode() const;
	int maxNode() const;

	bool exists(const int&) const;

	void delNode(const int&);
	void delMin();
	void delMax();

	friend ostream& operator<<(ostream&, const Tree&);
};

#endif // TREE_H

