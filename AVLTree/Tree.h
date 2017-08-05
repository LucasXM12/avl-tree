#pragma once
#include <string>

using namespace std;

class Tree {
	typedef struct node {
		node* left;
		node* right;

		node* parent;

		int height;
	} node;

public:
	Tree();
	virtual ~Tree();

	string toString();
	void delTree(node**);
private:
	node* root;

	string toString(node*);
} tree;

