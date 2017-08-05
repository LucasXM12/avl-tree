#include "stdafx.h"
#include "Tree.h"

Tree::Tree() {
	this->root = NULL;
}

Tree::~Tree() {
}

string Tree::toString() {
	if (this->root == NULL)
		return "null";

	return toString(this->root);
}

void Tree::delTree(node** root) {
}

string Tree::toString(node* root) {

}
