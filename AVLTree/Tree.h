#pragma once

#include <string>

#ifndef TREE_H
#define TREE_H

#define max(a, b) a > b ? a : b

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

	string toString();
	void addNode(int);
private:
	node* root;

	void delTree(node*);
	string toString(node*);
	bool addNode(node*, int);
};

#endif // TREE_H

