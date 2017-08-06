#include "stdafx.h"
#include "Tree.h"

Tree::Tree () {
	this->root = NULL;
}

Tree::~Tree () {
	if (this->root != NULL)
		delTree (this->root);
}

void Tree::delTree (node* root) {
	if (root->left != NULL)
		delTree (root->left);

	if (root->left != NULL)
		delTree (root->right);

	delete root;
}

string Tree::toString () {
	if (this->root == NULL)
		return "null";

	return toString (this->root);
}

string Tree::toString (node* root) {
	string ret;

	if (root->left != NULL)
		ret = "(" + toString (root->left) + ")<";

	ret += root->data;

	if (root->left != NULL)
		ret += ">(" + toString (root->left) + ")";

	return ret;
}

void Tree::addNode (int data) {
	addNode (this->root, data);
}

bool Tree::addNode (node* root, int data) {
	if (root == NULL) {
	} else if (data < root->data) {
		if (addNode (root->left, data)) {
		}
	} else {
		if (addNode (root->right, data)) {
		}
	}
}




