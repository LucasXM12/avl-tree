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
	Tree();
	virtual ~Tree();

	string toString() const;

	void addNode(const int&);
	node* newNode(const int&) const;

	int minNode() const;
	int maxNode() const;

	bool exists(const int&) const;

	void delNode(const int&);
	void delMin();
	void delMax();

	friend ostream& operator<<(ostream&, const Tree&);
private:
	node* root;

	void delTree(node*);

	string toString(const node*) const;

	node* minNode(node*) const;
	node* maxNode(node*) const;

	bool exists(const int&, const node*) const;

	node* leftRotate(node*);
	node* rightRotate(node*);

	node* addNode(node*, const int&);
	node* delNode(node*, const int&);
};

#endif // TREE_H

