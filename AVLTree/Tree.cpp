#include "stdafx.h"
#include "Tree.h"

Tree::Tree() {
	this->root = NULL;
}

Tree::~Tree() {
	if (this->root)
		delTree(this->root);
}

void Tree::delTree(node* root) {
	if (root->left)
		delTree(root->left);

	if (root->right)
		delTree(root->right);

	delete root;
}

string Tree::toString() const {
	if (!this->root)
		return "null";

	return toString(this->root);
}

string Tree::toString(const node* root) const {
	string ret;

	if (root->left)
		ret = "(" + toString(root->left) + ")<-";

	ret += to_string(root->key);

	if (root->right)
		ret += "->(" + toString(root->right) + ")";

	return ret;
}

Tree::node* Tree::newNode(const int& key) const {
	node* ret = new node();

	ret->key = key;
	ret->height = 1;
	ret->left = NULL;
	ret->right = NULL;

	return ret;
}

int Tree::minNode() const {
	if (!this->root)
		return;

	return minNode(this->root)->key;
}

Tree::node* Tree::minNode(node* root) const {
	if (root->left)
		return minNode(root->left);

	return root;
}

int Tree::maxNode() const {
	if (!this->root)
		return;

	return maxNode(this->root)->key;
}

Tree::node* Tree::maxNode(node* root) const {
	if (root->right != NULL)
		return maxNode(root->right);

	return root;
}

bool Tree::exists(const int& key) const {
	if (!this->root)
		return false;

	return exists(key, this->root);
}

bool Tree::exists(const int& key, const node* root) const {
	if (key == root->key)
		return true;
	else if (key < root->key)
		return root->left ? exists(key, root->left) : false;
	else
		return root->right ? exists(key, root->right) : false;
}

Tree::node* Tree::leftRotate(node* root) {
	node* y = root->right;
	node* T2 = y->left;

	//Update conections:
	y->left = root;
	root->right = T2;

	//Update heights:
	root->height = height_update(root);
	y->height = height_update(y);

	return y;
}

Tree::node* Tree::rightRotate(node* root) {
	node* x = root->left;
	node* T2 = x->right;

	//Update conections:
	x->right = root;
	root->left = T2;

	//Update heights:
	root->height = height_update(root);
	x->height = height_update(x);

	return x;
}

void Tree::addNode(const int& key) {
	this->root = addNode(this->root, key);
}

Tree::node* Tree::addNode(node* root, const int& key) {
	//Normal insertion:--------------------------- 
	if (root == NULL)
		return(newNode(key));

	if (key < root->key)
		root->left = addNode(root->left, key);
	else if (key > root->key)
		root->right = addNode(root->right, key);

	//Update height:---------------------------
	root->height = height_update(root);

	//Get balance factor:---------------------------
	int balance = balance_factor(root);

	//Balance this sub tree:---------------------------
	//LL Case:
	if (balance > 1 && key < root->left->key)
		return rightRotate(root);

	//RR Case:
	if (balance < -1 && key > root->right->key)
		return leftRotate(root);

	//LR Case:
	if (balance > 1 && key > root->left->key) {
		root->left = leftRotate(root->left);

		return rightRotate(root);
	}

	//RL Case:
	if (balance < -1 && key < root->right->key) {
		root->right = rightRotate(root->right);

		return leftRotate(root);
	}

	//If is balanced:
	return root;
}

void Tree::delNode(const int& key) {
	this->root = delNode(this->root, key);
}

Tree::node* Tree::delNode(node* root, const int& key) {
	//Normal deletion:---------------------------
	if (!root)
		return root;
	else if (key < root->key) //The node is on the left sub tree:
		root->left = delNode(root->left, key);
	else if (key > root->key) //The node is on the right sub tree:
		root->right = delNode(root->right, key);
	else { //The node is the current one:
		if (!root->left || !root->right) { //One or none children:
			node* aux = root->left ? root->left : root->right;

			//No child:
			if (!aux) {
				aux = root;
				root = NULL;
			}
			else //One child:
				*root = *aux;

			delete aux;
		}
		else { //Two children:
			node* aux = minNode(root->right);

			root->key = aux->key;

			root->right = delNode(root->right, aux->key);
		}
	}

	if (!root)
		return NULL;

	//Update height:---------------------------
	root->height = height_update(root);

	//Get balance factor:---------------------------
	int balance = balance_factor(root);

	//Balance this sub tree:---------------------------
	//LL Case:
	if (balance > 1 && balance_factor(root->left) >= 0)
		return rightRotate(root);

	//LR Case:
	if (balance > 1 && balance_factor(root->left) < 0) {
		root->left = leftRotate(root->left);

		return rightRotate(root);
	}

	//RR Case:
	if (balance < -1 && balance_factor(root->right) <= 0)
		return leftRotate(root);

	//RL Case:
	if (balance < -1 && balance_factor(root->right) > 0) {
		root->right = rightRotate(root->right);

		return leftRotate(root);
	}

	//If is balanced:
	return root;
}

void Tree::delMin() {
	this->root = delNode(this->root, minNode());
}

void Tree::delMax() {
	this->root = delNode(this->root, maxNode());
}

ostream& operator<<(ostream& os, const Tree& tree) {
	return os << tree.toString();
}
